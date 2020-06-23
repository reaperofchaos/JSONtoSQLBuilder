#ifndef CSV_PARSER_INCUDED
#define CSV_PARSER_INCLUDED
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <regex>
#include <iterator>
#include <string>
#include <algorithm>
#include <iomanip>
#include "utilities.h"

class csvParser
{
    private:
        char _delimiter; 
        std::ifstream _in;
		std::vector<std::map<std::string,std::string>> _records;
        std::vector<std::string> _columns; 
        int _columnTotal;

    public:
        csvParser();
        csvParser(std::string extension);
        ~csvParser();
        
        //getters
        std::vector<std::map<std::string,std::string>> getRecords(){ return _records;};

        //setters
		void loadInput(std::string input);
		void setInputFile(std::string fileName)
		{ 
			_in.open(fileName);
		}
        void loadColumns(); 

        std::string getKeys(std::string value);
        void showPairs(std::map<std::string, std::string> keyValuePairs);
		void showRecords();
        void showColumns();

};
#endif