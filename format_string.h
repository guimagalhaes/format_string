#ifndef _FORMAT_STRINGH
#define _FORMAT_STRINGH

#include <string>
#include <list>

class format_string
{
    public: 
        //pass string to uppsercase
        static std::string uppercase(const std::string);
                //pass string to lowercase
        static std::string lowercase(const std::string);
        
        //convert other type to string
        static std::string to_string(const long long int);
        static std::string to_string(const int);
        static std::string to_string(const bool);
        static std::string to_string(const double);
        static std::string to_string(const std::string);
        static std::string to_string(const char*);
        
        //convert string to respective type
        static void from_string(const std::string &, int&);
        static void from_string(const std::string &, bool&);
        static void from_string(const std::string &, long long int&);
        static void from_string(const std::string &, double&);
        static void from_string(const std::string &, std::string&);
            
        //cut off the string "t" on the edges of the source string
        static std::string trim_right(const std::string &source, const std::string &t=" ");
        static std::string trim_left(const std::string &source, const std::string &t=" ");
        static std::string trim(const std::string &source, const std::string &t=" ");
                
                //split the strings using sep as separator and return the list in the str_list
                void split(const std::string &source, const std::string &sep, std::list<std::string> &str_list);
                
                //return true if source has any of the characteres in chars
                bool has_char(const std::string &source, const std::string &chars);
        
        //return true if source string ends with sufix string
        static bool ends_with(const std::string &source, const std::string &sufix);
        
        //return true if source string starts with prefix string
        static bool starts_with(const std::string &source, const std::string &prefix);
};

#endif

