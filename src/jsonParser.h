#ifndef JSON_PARSER_INCLUDED
#define JSON_PARSER_INCLUDED
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <iterator>
#include "utilities.h"

class jsonParser
{
	private:
		std::ifstream _in; 
		std::vector<std::map<std::string,std::string>> _records;

		
	public:
		jsonParser();
		~jsonParser();
		
		//getters
		std::vector<std::map<std::string,std::string>> getRecords(){ return _records;}
		
		//setters
		void loadInput(std::string input);
		void setInputFile(std::string fileName)
		{ 
			_in.open(fileName);
		}		
		
		std::string getKey(std::string value);
		std::string getValue(std::string line);
		bool isEndOfObject(std::string line);
		bool isNewObject(std::string line);
		bool isEndOfFile(std::string line);
		void showPairs(std::map<std::string, std::string> keyValuePairs);
		void showRecords();

};
#endif