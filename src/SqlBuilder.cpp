#include "SqlBuilder.h"

		SQLBuilder::SQLBuilder()
		{
		}
		
		void SQLBuilder::displayColumns()
		{
			std::cout << "Table Colums: " << std::endl; 
			for(std::set<std::string>::const_iterator it = _columns.begin();
				it != _columns.end(); it++)
				{
					if(it != _columns.begin())
					{
						std::cout << ", ";
					}
					std::cout << *it; 
				}
				std::cout << std::endl;
				_columnTotal = _columns.size();
		}
		
		SQLBuilder::SQLBuilder(std::string fileName, std::string table, std::vector<std::map<std::string, std::string>> records, std::string server)
		{	
			SQLBuilder::setOutputFile(fileName);
			_tableName = table; 
			_records = records; 
			_server = server;
		}
		
		SQLBuilder::~SQLBuilder()
		{
		}

		
		void SQLBuilder::setColumns()
		{
			std::map<std::string, std::string> record = _records.front(); 
			for(std::map<std::string,std::string>::const_iterator it = record.begin();
			it != record.end(); ++it)
			{
				_columns.insert(it->first);
			}
			_columnTotal = _columns.size();
		}
		
		void SQLBuilder::outputRecord(std::map<std::string, std::string> record)
		{
			
			for(std::map<std::string, std::string>::const_iterator it = record.begin();
			it != record.end(); ++it)
			{
				if(it != record.begin())
				{
					_out << ", "; 
				}
				_out << "'" << it->second << "'"; 
			}
		}
		
		void SQLBuilder::outputRecords()
		{
			for(std::vector<std::map<std::string, std::string>>::const_iterator it = _records.begin();
			it != _records.end(); ++it)
			{
				if(it != _records.begin())
				{
					_out << "),\r\n\t(";

				}
				else
				{
					_out << "\t(";
				}
				SQLBuilder::outputRecord(*it);
			}
		}
		void SQLBuilder::createSQLFile()
		{ 
			SQLBuilder::setColumns();
			if(_server == "mysql")
			{
				SQLBuilder::createMYSQLFile();
			}
			if(_server == "mssql")
			{
				SQLBuilder::createMSSQLFile();
			}
			if(_server == "sqlite" || _server == "sqlite3")
			{
				SQLBuilder::createSQLiteFile();
			}
			if(_server == "pgsql")
			{
				SQLBuilder::createPostgresFile();
			}
			std::cout << "FileName " << SQLBuilder::getTitle() 
					  << " has been created." << std::endl;
			std::cout << "Table Name: " << SQLBuilder::getTable() << std::endl;
			SQLBuilder::displayColumns();
			std::cout << "Number of records inserted: " << _records.size() << std::endl;
		}

		void SQLBuilder::createSQLiteFile()
		{
			//check if table exists and create if not
			_out << "CREATE TABLE IF NOT EXISTS `" << _tableName <<"` (\r\n";
			_out << "id INTEGER PRIMARY KEY ASC,\r\n";
			std::set<std::string>::iterator it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ",\r\n";
				}
				_out << (*it) << " VARCHAR NULL"; 
				it++; 
			}
			_out << ");\r\n\r\n";
        
			//write to output file;
			_out << "INSERT INTO " << _tableName << "(";
			it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ", ";
				}
				_out << (*it); 
				it++;
			}
			_out << ") \r\n"; 
			_out << "VALUES \r\n"; 
			//type records
			SQLBuilder::outputRecords();
			_out << ");"; 
			_out.close();
		}
		void SQLBuilder::createPostgresFile()
		{
			//check if table exists and create if not
			_out << "CREATE TABLE IF NOT EXISTS " << _tableName <<" (\r\n";
			_out << "id SERIAL PRIMARY KEY,\r\n";
			std::set<std::string>::iterator it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ",\r\n";
				}
				_out << (*it) << " VARCHAR(255) NULL"; 
				it++; 
			}
			_out << ");\r\n\r\n";
        
			//write to output file;
			_out << "INSERT INTO " << _tableName << "(";
			it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ", ";
				}
				_out << (*it); 
				it++;
			}
			_out << ") \r\n"; 
			_out << "VALUES \r\n"; 
			//type records
			SQLBuilder::outputRecords();
			_out << ");"; 
			_out.close();
		}
		void SQLBuilder::createMYSQLFile()
		{
			//check if table exists and create if not
			_out << "CREATE TABLE IF NOT EXISTS `" << _tableName <<"` (\r\n";
			_out << "id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,\r\n";
			std::set<std::string>::iterator it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ",\r\n";
				}
				_out << (*it) << " VARCHAR(255) NULL"; 
				it++; 
			}
			_out << ");\r\n\r\n";
        
			//write to output file;
			_out << "INSERT INTO " << _tableName << "(";
			it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ", ";
				}
				_out << (*it); 
				it++;
			}
			_out << ") \r\n"; 
			_out << "VALUES \r\n"; 
			//type records
			SQLBuilder::outputRecords();
			_out << ");"; 
			_out.close();
		}
	void SQLBuilder::createMSSQLFile()
		{
			//check if table exists and create if not
			_out << "if not exists (select * from sysobjects where name='" << _tableName <<"' and xtype='U')\r\n";
			_out << "create table " << _tableName << " ( \r\n";
			_out << "\tid INT IDENTITY(1, 1) PRIMARY KEY,\r\n";
			std::set<std::string>::iterator it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ",\r\n";
				}
				_out << "\t" << (*it) << " VARCHAR(255) NULL"; 
				it++; 
			}
			_out << "\r\n);\r\n\r\n";
        
			//write to output file;
			_out << "INSERT INTO " << _tableName << "(";
			it = _columns.begin();
			//print columns
			while(it != _columns.end())
			{
				if(it != _columns.begin())
				{
					_out << ", ";
				}
				_out << (*it); 
				it++;
			}
			_out << ") \r\n"; 
			_out << "VALUES \r\n"; 
			//type records
			SQLBuilder::outputRecords();
			_out << ");"; 
			_out.close();
		}