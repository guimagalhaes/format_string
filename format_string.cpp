#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "format_string.h"

using namespace std;

string format_string::uppercase(const string x)
{
    string p = x;

    for (unsigned int q=0; q<p.length(); q++)
        p[q] = toupper(p[q]);
        
    return p;
}

string format_string::lowercase(const string x)
{
    string p = x;

    for (unsigned int q=0; q<p.length(); q++)
        p[q] = tolower(p[q]);
        
    return p;
}


string format_string::to_string(const long long int x) 
{
   char buf[256];
   sprintf(buf, "%llu", x);
   return string(buf);
}

string format_string::to_string(const int x) 
{
   char buf[256];
   sprintf(buf, "%i", x);
   return string(buf);
}

string format_string::to_string(const bool x) 
{
   return (x) ? "true" : "false";
}

string format_string::to_string(const double x) 
{
   char buf[256];    
    //string s;
    
   sprintf(buf, "%f", x);
    /*s = string(buf);
    
    int i = s.find(".",1);
    s[i] = ',';*/
        
   return string(buf);
}

string format_string::to_string(const string x) 
{
   return x;
}

string format_string::to_string(const char* x) 
{
   return string(x);
}

void format_string::from_string(const string &y, int& x) 
{
   x = atoi(y.c_str());
}

void format_string::from_string(const string &y, bool& x) 
{
   x = (y == "true");
}

void format_string::from_string(const string &y, long long int& x) 
{
   x = atoll(y.c_str());
}

void format_string::from_string(const string &y, double& x) 
{
   x = strtod(y.c_str(), NULL);
}

void format_string::from_string(const string &y, string& x) 
{
   x = y;
}

string format_string::trim_right(const string &source, const string &t) 
{
       string str = source;

       return str.erase(str.find_last_not_of(t) + 1);
}

string format_string::trim_left(const string &source, const string &t) 
{
       string str = source;

       return str.erase(0, source.find_first_not_of(t));
}

string format_string::trim(const string &source, const string &t) 
{
       string str = source;

       return trim_left(trim_right(str, t), t);
}

void format_string::split(const string &source, const string &sep,list<string> &str_list) 
{
    string::size_type start_pos = 0, end_pos = 0;
        string token,str;
        
        str = trim(source,sep);
        
        while (end_pos != string::npos) {
            end_pos = str.find(sep,start_pos);
                if (end_pos != string::npos) {
                    token = str.substr(start_pos,end_pos - start_pos);
                    start_pos = end_pos + sep.size();
                }
                else {
                    if (start_pos < str.size())
                            token = str.substr(start_pos,str.size() - start_pos);
                }
                
                token = trim(token,sep);
                if (token.size())
                    str_list.push_back(token);
        }
}

bool format_string::has_char(const string &source, const string &chars) 
{
    string::size_type pos;
        
    for (size_t i = 0; i < chars.size(); ++i) {
            pos = source.find(chars[i],0);
                if (pos != string::npos)
                    return true;
        }
        
        return false;
}

bool format_string::ends_with(const std::string &source, const std::string &sufix)
{
    if (sufix == "" && source == "")
        return true;

    if (sufix != "") {
        string::size_type pos = source.rfind(sufix);
        if (pos != string::npos && pos == (source.size()-sufix.size()))
            return true;
    }
    
    return false;
}
        
bool format_string::starts_with(const std::string &source, const std::string &prefix)
{
    if (prefix == "" && source == "")
        return true;
    
    if (prefix != "") {    
        if (source.find(prefix) == 0)
            return true;
    }
    
    return false;
}

