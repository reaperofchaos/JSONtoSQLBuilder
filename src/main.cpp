#include <iostream>
#include <fstream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include "jsonParser.h"
#include "csvParser.h"
#include "SqlBuilder.h"

void validateFileType(std::string extension, std::vector<std::string> 
					  validFileTypes, std::string fileName, bool verbose,
					  std::string server, std::string outputFile, 
					  std::string tableName);
bool isValidDatabase(std::string& serverType);
void validateOutputFile(std::string &fileName);
std::string getExtension(std::string filePath);
std::string getFileName(std::string filePath);
std::string getFlag(std::string flag, int& argc, char**& argv);

int main(int argc, char* argv[])
{
	std::vector<std::string> validFileTypes = {"json", "csv"};
	//code to get filename information
	std::string extension = "";
	std::string fileName = ""; 
	std::string filePath = ""; 
	std::string flag = ""; 
	std::string serverType  = "";
	std::string outputFile = ""; 
	std::string tableName = ""; 
	bool verbose = false;
	if(argc > 1)
	{
		filePath = argv[1];
		fileName = getFileName(filePath);
		extension = getExtension(fileName);
		//specifies the database server type
		serverType = getFlag("-s", argc, argv);
		//specifies output file
		outputFile = getFlag("-o", argc, argv);
		//specifies table to insert into
		tableName = getFlag("-table", argc, argv);
		//check if verbose mode is on. used to show records found
		verbose = (getFlag("-v", argc, argv) == "on") ? true : false;
	}
	validateFileType(extension, validFileTypes, fileName,
					 verbose, serverType, outputFile, 
					 tableName);	
}

//get extension from path
std::string getFileName(std::string filePath)
{
	std::size_t foundPath = filePath.find_last_of("/\\");
	std::string path = filePath.substr(0, foundPath); 
	std::string fileName = filePath.substr(foundPath + 1); 
	return fileName; 
}

std::string getExtension(std::string fileName)
{
	//get extension from file name
	std::size_t foundExt = fileName.find_last_of(".");
	std::string file = fileName.substr(0, foundExt);
	std::string extension = fileName.substr(foundExt + 1);
	return extension; 
}

//check if valid extension and run parser
void validateFileType(std::string extension,
					  std::vector<std::string> validFileTypes,
					  std::string fileName, bool verbose,
					  std::string server, std::string outputFile,
					  std::string tableName)
{
	std::vector<std::map<std::string, std::string>> records;
	//check if a valid file type
	std::vector<std::string>::iterator it;
	it = std::find(validFileTypes.begin(),
				   validFileTypes.end(),
				   extension);
				   
	if(it != validFileTypes.end())
	{
		std::cout << "Extension " << extension << " is a valid file type." << std::endl;
		if(*it == "json")
		{
			std::cout << "Parsing JSON File..." << std::endl;
			jsonParser jsonFile;
			jsonFile.loadInput(fileName);
			if(verbose)
			{
				jsonFile.showRecords();
			}
			records = jsonFile.getRecords();
		}
		if(*it == "csv")
		{
			std::cout << "Parsing CSV File..." << std::endl;
			csvParser csvFile("csv"); 
			csvFile.loadInput(fileName);
			if(verbose)
			{
				csvFile.showRecords();
			}
			records = csvFile.getRecords();
		}
		std::cout << std::endl << std::endl;
		std::string table = ""; 
		//request server if server is not set, display database types if OPTIONS is typed
		bool validDatabase = isValidDatabase(server);
		while(server == "OPTIONS" || !validDatabase)
		{
			if(!validDatabase && (server != ""))
			{
				std::cout << server 
						  << " is not a supported database. "
						  << "Choose another database or type OPTIONS "
						  << "for a list of supported databases." 
						  << std::endl
						  << std::endl;
			}
			if(server == "OPTIONS")
			{
				std::cout << std::endl << std::endl;
				std::cout << "Currently Supported Databases: " << std::endl;
				std::cout << "MYSQL - type mysql" << std::endl;
				std::cout << "MS SQL Server - type mssql" << std::endl;
				std::cout << "SQLite - type sqlite" << std::endl;
				std::cout << "Postgres SQL - type pgsql" << std::endl;
				std::cout << std::endl;
			}
			std::cout << "Please type the database you are using. Type OPTIONS for supported databases" << std::endl; 
			std::cin >> server;
			validDatabase = isValidDatabase(server);
		}

		while(tableName == "")
		{
			std::cout << "Type the name of the table to insert records into." << std::endl; 
			//std::getline(std::cin, table);
			std::cin >> tableName;
		}

		while(outputFile == "")
		{
			std::cout << "Type a name for your output sql file." << std::endl; 
			//std::getline(std::cin, outputFile);
			std::cin >> outputFile;
			validateOutputFile(outputFile);
		}
		 
		std::cout << "Creating file " << outputFile << "." << std::endl;
		SQLBuilder sqlFile(outputFile, tableName, records, server); 
		sqlFile.createSQLFile();
	}
else
	{
		std::cout << "Extension " << extension << " is not a valid file type. Exitting program..." << std::endl;
		return;
	}
}

bool isValidDatabase(std::string &serverType)
{
	std::vector<std::string> supportedDatabases = {
		"mssql",
		"mysql", 
		"sqlite", 
		"pgsql"
	};
	std::vector<std::string>::const_iterator it = std::find(
		supportedDatabases.begin(), supportedDatabases.end(), serverType);
	bool isValid = (it == supportedDatabases.end()) ? false : true;
	return isValid;
}

std::string getFlag(std::string flag, int& argc, char**& argv)
{
	const std::vector<std::string> args(argv+1,argv+argc);
	std::vector<std::string>::const_iterator it = std::find(args.begin(), args.end(), flag);
	it++; 
	return *it; 
}
void validateOutputFile(std::string &fileName)
{
	//check fileName
	std::size_t foundExt = fileName.find_last_of(".");
	std::string file = fileName.substr(0, foundExt);
	std::string extension = fileName.substr(foundExt + 1);
	if(extension != "sql")
	{
		fileName += ".sql";
	}
}