#include "utilities.h"

std::string & Utilities::ltrim(std::string & str)
{
  auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( str.begin() , it2);
  return str;   
}

std::string & Utilities::rtrim(std::string & str)
{
  auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( it1.base() , str.end() );
  return str;   
}

std::string & Utilities::trim(std::string & str)
{
   return Utilities::ltrim(Utilities::rtrim(str));
}


void Utilities::removeQuotes(std::string &value)
{
    // Remove all double-quote characters
  value.erase(
    remove( value.begin(), value.end(), '\"' ),
    value.end());
}
void Utilities::removeComma(std::string &value)
{
  // Remove all double-quote characters
  value.erase(
    remove( value.begin(), value.end(), ',' ),
    value.end());
}
void Utilities::spacesToUnderscores(std::string &value)
{
  std::replace(value.begin(), value.end(), ' ', '_');  
}
void Utilities::sanitize(std::string &value)
{
    Utilities::stripUnicode(value);
    Utilities::removeQuotes(value);
    Utilities::trim(value);
}

bool Utilities::invalidChar (char c) 
{  
    return !(c>=0 && c <128);   
} 

void Utilities::stripUnicode(std::string & str) 
{ 
    str.erase(remove_if(str.begin(),str.end(), Utilities::invalidChar), str.end());  
}