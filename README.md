# JSONtoSQLBuilder
Creates a .sql file from a .json file (one level deep)
Parses all json keys and assumes they are the names of the columns. 
Stores the values as records that will be inserted into the name of a table specified or creates a table if it does not exist.

# Installation:
## Windows
Requires GCC to compile
Download GNUWIN <a href="https://sourceforge.net/projects/gnuwin32/" to run MAKE in windows.
from a command prompt navigate to windows build folder and run make.

Run SQLBuilder.exe <name of JSON file to read>
Type in the name of the desired SQL File
Type in the name of the table. 

Creates a SQL file that can be imported in MYSQL using the keys for the JSON file to create columns. 
If a table does not exist, the SQL file will attempt to create a file with a primary key of id and all other colums will be VARCHAR(80) NULL

# Linux
Requires GCC and Make to compile
From a command prompt navigate to linux build folder and run make

./SqlBuilder <name of JSON file to read>
Type in the name of the desired SQL File
Type in the name of the table. 

Creates a SQL file that can be imported in MYSQL using the keys for the JSON file to create columns. 
If a table does not exist, the SQL file will attempt to create a file with a primary key of id and all other colums will be VARCHAR(80) NULL
