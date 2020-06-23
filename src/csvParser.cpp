#include "csvParser.h"

csvParser::csvParser()
{
}
csvParser::csvParser(std::string extension)
{
    if(extension == "tsv")
    {
        _delimiter = '\x09';
    }
    else
    {
        _delimiter = ',';
    }
}

csvParser::~csvParser()
{
}
void csvParser::loadColumns()
{
    std::string line; 
    std::string column;
    //get first line with columns
    std::getline(_in, line);
    std::stringstream ss(line);
    while (ss){
        if (ss.peek() == '"') {
            //store the quote
            char temp; 
            ss >> temp;
            column.push_back(temp);
            //keep storing characters until last quote is found
            while(ss.peek() != '"')
            {
                //retain the spaces
                if(ss.peek() == '\x20')
                {
                    column.push_back('\x20');
                }
                ss >> temp;
                column.push_back(temp);  
            }
            //add last quote to end of string
            ss >> temp;
            column.push_back(temp);
            //parse tab or comma so we have a fresh getline
            
            if(ss.peek() != '\x09')
            {
                ss >> temp;
            }
            std::cout << "Poorly formatted Column: " << column << std::endl;
        }
        else 
        {
            std::getline(ss, column, _delimiter);
        }
        Utilities::sanitize(column);
        Utilities::spacesToUnderscores(column);
        Utilities::removeComma(column);
        _columns.push_back(column);
        column = "";
    }
     _columnTotal = _columns.size();
}

void csvParser::loadInput(std::string input)
{
	csvParser::setInputFile(input);
	std::map<std::string, std::string> pair;
    csvParser::loadColumns(); 
    std::string line; 
    std::string value; 
    int fieldCount = 0; 
    while(getline(_in, line))
    {
        std::stringstream ss(line);
        while (ss >> std::ws) {
            std::string csvElement;

            if (ss.peek() == '"') {
                value = "";
                char temp; 
                ss >> temp;
                value.push_back(temp);
                while(ss.peek() != '"')
                {
                    ss >> temp; 
                    value.push_back(temp);  
                }
                //add last quote to end of string
                ss >> temp;
                value.push_back(temp);
                //parse comma so we have a fresh getline
                ss >> temp; 
            }
            else 
            {
                std::getline(ss, value, _delimiter);
            }
            Utilities::sanitize(value);
            pair.insert(std::pair<std::string, std::string>(_columns[fieldCount], value));
            fieldCount++;
        }
        /*
        while(std::getline(ss, value, _delimiter))
        {
            Utilities::sanitize(value);
            pair.insert(std::pair<std::string, std::string>(_columns[fieldCount], value));
            fieldCount++; 
        }
        */
        //add to _records
        _records.push_back(pair);
        //clear pair and reset field count
        pair.clear();
        fieldCount = 0; 
    }
	
}
//displays all pairs for a given record
void csvParser::showPairs(std::map<std::string, std::string> keyValuePairs)
{
	for(std::map<std::string,std::string>::const_iterator it = keyValuePairs.begin();
		it != keyValuePairs.end(); ++it)
		{
			std::cout << it->first << " : " << it->second << std::endl;
		}
}

//displays all records
void csvParser::showRecords()
{
	for (std::vector<std::map<std::string, std::string>>::const_iterator it = _records.begin();
	it != _records.end(); ++it) 
	{
		csvParser::showPairs(*it);
		std::cout << std::endl << std::endl;
	}
}

//display colnames
void csvParser::showColumns()
{
    for(std::vector<std::string>::const_iterator it = _columns.begin(); 
        it != _columns.end(); it++)
    {
        if(it != _columns.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << std::endl; 
}

