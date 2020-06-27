# JSONtoSQLBuilder
Creates a .sql file from a .json file (one level deep) or a csv file.
Parses all keys and assumes they are the names of the columns. If a column name is not compatible with SQL naming conventions (ie has spaces), then the spaces between words will be replaced with underscores and all trailing spaces will be removed. <br />
<br />
The values are stored as records that can be inserted into the name of the table specified either with the -table flag or through the program when prompted. The resulting SQL file will be formatted in a way to work with the specified database that can be specified with the -s flag or through the program when prompted. The SQL file is also coded in a way to check if the table exists and if not will create a table with a primary key of ID, and all column names are set to the varchar type. <br />
<br />

# Usage
Navigate to directory with the binary (If compiled from source, it will be in stored in either windows/SqlBuilder.exe or linux/SqlBuilder)<br />
<br/>
## Windows
**SqlBuilder.exe** *fileToParse* [OPTION]...<br />

## Linux 
**./SqlBuilder** *fileToParse* [OPTION]...<br />

### OPTIONS
<pre>
<b>-s</b> [DATABASE]        serverType
                     specify which database the output sql file will be compatible with
                     Supported Databases:
                            <em>mysql</em>   - MySQL Server <br />
                            <em>mssql</em>   - MS SQL Server <br />
                            <em>sqlite</em>  - SQLite<br />
                            <em>pgsql</em>   - PostGres SQL<br />
                     if option is not specified, program will prompt for this


<b>-o</b> [FILENAME]        outputFile
                     specifies the filename for the output sqlfile.
                     If .sql is not included as an extension, 
                     it will be appended to the file name. If this 
                     option is not specified, the program will
                      prompt for this.


<b>-table</b> [TABLENAME]   table
                     specifies the name of the table to insert the records into. 
                     If option is not specified, program will prompt for this.


<b>-v</b>  {<em>on</em> | <em>off</em>}       verbose
                     takes an option of <em>on</em> or <em>off</em>.
                     If set to on, it will output the parsed records to the console. 
</pre>

# Installation:
## Windows
<a href="https://github.com/reaperofchaos/JSONtoSQLBuilder/blob/master/windows/SqlBuilder.exe">Windows Binary</a><br/>
<br/>
### Compile from Source
Requires GCC and MAKE to compile <br />
Download <a href="https://sourceforge.net/projects/gnuwin32/">GNUWin</a> to run MAKE in windows.<br />
From a command prompt navigate to windows build folder and run make <br />
Navigate to project directory in console <br />
<pre>
cd windows
make clean
make
</pre>

## Linux
<a href='https://github.com/reaperofchaos/JSONtoSQLBuilder/blob/master/linux/SqlBuilder'>Linux Binary</a>

### Compile from Source
Requires GCC and Make to compile <br />
From a command prompt navigate to linux build folder and run make <br />
Navigate to project directory in console <br />
<pre>
cd linux
make clean
make
</pre>