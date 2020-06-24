#ifndef SQLBUILDER_INCLUDED
#define SQLBUILDER_INCLUDED
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <iterator>
#include <vector>
#include <cstddef>


class SQLBuilder
{
	private:
		std::ofstream _out;
		std::string _tableName;
		std::string _title;
		std::set<std::string> _columns;
		int _columnTotal;
		std::vector<std::map<std::string, std::string>> _records;
		std::string _server;
	public:
		SQLBuilder();
		SQLBuilder(std::string fileName, std::string table, std::vector<std::map<std::string, std::string>> records, std::string server);
		~SQLBuilder();
		
		//getter
		std::set<std::string> getColumns()
		{
			return _columns; 
			
		}
		
		std::string getTitle()
		{
			return _title; 
		}
		std::string getTable()
		{
			return _tableName; 
		}
		//setter
		void setOutputFile(std::string fileName)
		{ 
		
			_title = fileName; 
			_out.open(fileName, std::ofstream::out | std::ios::app );
			if(!_out.is_open())
			{
				std::cerr << std::endl << "Unable to open file. "
				<< std::endl;
			}
		}
		
		void setColumns();
		void createMYSQLFile();
		void createMSSQLFile();
		void createSQLiteFile();
		void createSQLFile();
		void outputRecord(std::map<std::string, std::string> record);
		void outputRecords();
		void displayColumns();
		



};

#endif