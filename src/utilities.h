#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include <string>
#include <algorithm>
#include <locale>
class Utilities
{
    public:
      static std::string & ltrim(std::string & str);
      static std::string & rtrim(std::string & str);
      static std::string & trim(std::string & str);
      static void removeQuotes(std::string &value);
      static void removeComma(std::string &value);
      static void sanitize(std::string &value);
      static void spacesToUnderscores(std::string &value);
      static bool invalidChar (char c);
      static void stripUnicode(std::string & str);
       
};
#endif