#include <iostream>
#include <fstream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <map>
#include "jsonParser.h"
#include "SqlBuilder.h"

void validateFileType(std::string extension, std::vector<std::string> validFileTypes, std::string fileName);
std::string getExtension(std::string filePath);
std::string getFileName(std::string filePath);

int main(int argc, char* argv[])
{
	std::vector<std::string> validFileTypes = {"json", "csv", "tsv"};
	//code to get filename information
	std::string extension = "";
	std::string fileName = ""; 
	std::string filePath = ""; 
	if(argc > 1)
	{
		filePath = argv[1];
		fileName = getFileName(filePath);
		extension = getExtension(fileName);
	}
	validateFileType(extension, validFileTypes, fileName);	
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
void validateFileType(std::string extension, std::vector<std::string> validFileTypes, std::string fileName)
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
		}
		if(*it == "tsv")
		{
			std::cout << "This is a Tab-Separated File. Parsing TSV File..." << std::endl;
		}
		std::string title = ""; 
		std::string table = ""; 
		std::cout << "Type the name of the sqlfile " << std::endl; 
		std::cin >> title;
		std::cout << "Type the name of the table to insert into." << std::endl; 
		std::cin >> table; 
		std::cout << "Creating file " << title << "." << std::endl;
		SQLBuilder sqlFile(title, table, records); 
		sqlFile.createSQLFile();
	}

else
	{
		std::cout << "Extension " << extension << " is not a valid file type. Exitting program..." << std::endl;
		return;
	}
}