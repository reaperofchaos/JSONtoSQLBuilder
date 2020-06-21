#include "jsonParser.h"

jsonParser::jsonParser()
{
}

jsonParser::~jsonParser()
{
}

void jsonParser::loadInput(std::string input)
{
	jsonParser::setInputFile(input);
	std::vector<std::string> objectLines;
	std::map<std::string, std::string> pair;
	std::string line; 
	std::string key;
	std::string value;
	bool endOfFile = false;
	while(_in)
	{
		getline(_in,line);
		//find start of object { and create a vector of lines
		if(jsonParser::isNewObject(line))
		{
			//std::cout << "Starting new object..." << std::endl;
		}
		else // if not start, add line to vector
		{
			objectLines.push_back(line);
		}
		//if end of object, parse all lines into key value pairs
		if(jsonParser::isEndOfObject(line) && !endOfFile)
		{
			for(std::string l : objectLines)
			{
				//create key pair matches
				key = jsonParser::getKey(l);
				value = jsonParser::getValue(l);
				if(key != "")
				{
					pair.insert(std::pair<std::string, std::string>(key, value));
				}
			}
			//iterate map pairs
			//jsonParser::showPairs(pair);
			//add map to vector
			_records.push_back(pair);
			//clear map, and vector of lines
			pair.clear();
			objectLines.erase(objectLines.begin(),objectLines.end());
			//std::cout << "Ending Object..." <<std::endl <<std::endl;
			if(jsonParser::isEndOfFile(line))
			{
				endOfFile = true; 
				std::cout<<"JSON file has been parsed." << std::endl;
			}
		}
	}
}

bool jsonParser::isNewObject(std::string line)
{	
	try {
		std::regex r("(\\{)");
		std::smatch startObjMatch;
		std::regex_search(line, startObjMatch, r);
		std::string startObj = "";
		for(auto x : startObjMatch)
			{
				if(x != ":")
				{
					startObj = x;
				}
			}
		if(startObj == "{")
		{
			return true; 
		}
		else
		{
			return false; 
		}
	}
    catch (const std::regex_error& e) {
        std::cout << "regex_error caught: " << e.what() << '\n';
        if (e.code() == std::regex_constants::error_brack) {
            std::cout << "The code was error_brack\n";
        }
    }
	return false;  
}

bool jsonParser::isEndOfObject(std::string line)
{
	try {
		std::regex r("(})");
		std::smatch endObjMatches;
		std::regex_search(line, endObjMatches, r);
		std::string endObj = "";
		for(auto x : endObjMatches)
			{
				if(x != ":")
				{
					endObj = x;
				}
			}
		if(endObj == "}")
		{
			return true; 
		}
		else
		{	
			return false; 
		}
	}
    catch (const std::regex_error& e) {
        std::cout << "regex_error caught: " << e.what() << '\n';
        if (e.code() == std::regex_constants::error_brack) {
            std::cout << "The code was error_brack\n";
        }
    }
	return false; 
}

bool jsonParser::isEndOfFile(std::string line)
{
	try {
		std::regex r("(}];)");
		std::smatch eofMatches;
		std::regex_search(line, eofMatches, r);
		std::string endObj = "";
		for(auto x : eofMatches)
			{
				if(x != ":")
				{
					endObj = x;
				}
			}
		if(endObj == "}];")
		{
			return true; 
		}
		else
		{
			return false; 
		}
	}
    catch (const std::regex_error& e) {
        std::cout << "regex_error caught: " << e.what() << '\n';
        if (e.code() == std::regex_constants::error_brack) {
            std::cout << "The code was error_brack\n";
        }
    }
	return false; 
}

//parses key
std::string jsonParser::getKey(std::string line)
{
	std::regex r("\"(.*)\": ");
	std::smatch keyMatches;
	std::regex_search(line, keyMatches, r);
	std::string key = "";
	for(auto x : keyMatches)
	{
		if(x != ":")
		{
			key = x;
		}
	}
	return key;
}

//parses value
std::string jsonParser::getValue(std::string line)
{
	std::regex r(": \"(.*)\"");
	std::smatch valueMatches;
	std::regex_search(line, valueMatches, r);
	std::string value = "not found"; 
	for(auto x : valueMatches)
		{
			value = x;				
		}
	return value;
}

//displays all pairs for a given record
void jsonParser::showPairs(std::map<std::string, std::string> keyValuePairs)
{
	for(std::map<std::string,std::string>::const_iterator it = keyValuePairs.begin();
		it != keyValuePairs.end(); ++it)
		{
			std::cout << it->first << " : " << it->second << std::endl;
		}
}

//displays all records
void jsonParser::showRecords()
{
	for (std::vector<std::map<std::string, std::string>>::const_iterator it = _records.begin();
	it != _records.end(); ++it) 
	{
		jsonParser::showPairs(*it);
		std::cout << std::endl << std::endl;
	}
}