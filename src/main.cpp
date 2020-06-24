#include <iostream>
#include <fstream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <map>
#include "jsonParser.h"
#include "csvParser.h"
#include "SqlBuilder.h"


void validateFileType(std::string extension, std::string server, std::vector<std::string> validFileTypes, std::string fileName);
void validateServerType(std::string& serverType);
std::string getExtension(std::string filePath);
std::string getFileName(std::string filePath);

int main(int argc, char* argv[])
{
	std::vector<std::string> validFileTypes = {"json", "csv"};
	//code to get filename information
	std::string extension = "";
	std::string fileName = ""; 
	std::string filePath = ""; 
	std::string flag = ""; 
	std::string serverType  = "";
	if(argc > 1)
	{
		filePath = argv[1];
		fileName = getFileName(filePath);
		extension = getExtension(fileName);
		flag = argv[2];
		if(flag == "-s")
		{
			serverType = argv[3];
		}
	}
	validateServerType(serverType);
	validateFileType(extension, serverType, validFileTypes, fileName);	
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
void validateFileType(std::string extension, std::string server, std::vector<std::string> validFileTypes, std::string fileName)
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
			std::cout << "This is a JSON file. Parsing JSON File..." << std::endl;
			jsonParser jsonFile;
			jsonFile.loadInput(fileName);
			jsonFile.showRecords();
			records = jsonFile.getRecords();
		}
		if(*it == "csv")
		{
			std::cout << "This is a Comma-Separated File. Parsing CSV File..." << std::endl;
			csvParser csvFile("csv"); 
			csvFile.loadInput(fileName);
			csvFile.showRecords();
			records = csvFile.getRecords();

		}
		std::string title = ""; 
		std::string table = ""; 
		std::cout << "Type the name of the sqlfile " << std::endl; 
		std::cin >> title;
		std::cout << "Type the name of the table to insert into." << std::endl; 
		std::cin >> table; 
		std::cout << "Creating file " << title << "." << std::endl;
		SQLBuilder sqlFile(title, table, records, server); 
		sqlFile.createSQLFile();
	}

else
	{
		std::cout << "Extension " << extension << " is not a valid file type. Exitting program..." << std::endl;
		return;
	}
}

void validateServerType(std::string &serverType)
{
	if(serverType == "mssql")
	{
		std::cout << "SQL file will be created to work with MS SQL Server. " << std::endl;
	}
	else if(serverType == "mysql")
	{
		std::cout << "SQL file will be created to work with MYSQL Server. " << std::endl;
	}
	else if(serverType == "sqlite" || serverType == "sqlite3")
	{
		std::cout << "SQL file will be created to work with SQLite. " << std::endl;
	}
	else
	{
		std::cout << "SQL file will be created to work with MYSQL Server. " << std::endl;
		serverType = "mysql";
	}
}