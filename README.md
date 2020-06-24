# JSONtoSQLBuilder
Creates a .sql file from a .json file (one level deep)
Parses all json keys and assumes they are the names of the columns. 
Stores the values as records that will be inserted into the name of a table specified or creates a table if it does not exist.
If a CSV is selected, program will attempt to correct csv files with commas inside of quotations (common problem with csv files exported from Microsoft Excel) and replace spaces in column names with underscores to allow for valid sql column names

# Usage
navigate to directory with binary (windows/SqlBuilder.exe) or (linux/SqlBuilder)

## Windows
SqlBuilder.exe *file to parse* -s *server type*

## Linux
./SqlBuilder *file to parse* -s *server type*

### Flags
flags: **-s** specifies SQL syntax to be used in output file  <br />
       Options: **mysql**   - MySQL Server <br />
                **mssql**   - MS SQL Server <br />
                **sqlite**  - SQLite<br />
                **sqlite3** - SQLite<br />
       if no option is specified mysql syntax will be used in output sql file <br />
Files that can be parsed: CSV, JSON(must be a flat file with one level) <br />
Database Servers that will handled outputted SQL files MySQL mysql and MS SQL Server mssql  <br />

  
# Installation:
## Windows
<a href="https://github.com/reaperofchaos/JSONtoSQLBuilder/blob/master/windows/SqlBuilder.exe">Windows Binary</a>

### Compile from Source
Requires GCC to compile
Download GNUWIN <a href="https://sourceforge.net/projects/gnuwin32/">GNUWin</a> to run MAKE in windows.
From a command prompt navigate to windows build folder and run make.

Run SQLBuilder.exe <name of JSON file to read>
Type in the name of the desired SQL File
Type in the name of the table. 

Creates a SQL file that can be imported in MYSQL using the keys for the JSON file to create columns. 
If a table does not exist, the SQL file will attempt to create a file with a primary key of id and all other colums will be VARCHAR(80) NULL

## Linux
<a href='https://github.com/reaperofchaos/JSONtoSQLBuilder/blob/master/linux/SqlBuilder'>Linux Binary</a>

### Compile from Source
Requires GCC and Make to compile
From a command prompt navigate to linux build folder and run make

./SqlBuilder <name of JSON file to read>
Type in the name of the desired SQL File
Type in the name of the table. 

Creates a SQL file that can be imported in MYSQL using the keys for the JSON file to create columns. 
If a table does not exist, the SQL file will attempt to create a file with a primary key of id and all other colums will be VARCHAR(80) NULL
