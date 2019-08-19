#include <iostream>
#include <format_string.h>

using namespace std;

int main()
{
    format_string fstring;
    string test_str;
    list<string> str_list;
        list<string>::iterator str_iter;
            
    //long long int lli = 10000000000;
    int i = 10;
    bool b = true;
    double d = 1.0;
    string str = "tEsTe";
    const char *s = "teste";
    
    if (format_string::ends_with("teste","te"))
        cout << "teste ends with te" << endl;
    if (format_string::ends_with("teste",""))
        cout << "teste ends with empty" << endl;
    if (format_string::ends_with("teste","t"))
        cout << "teste ends with t" << endl;
    if (format_string::ends_with("teste","e"))
        cout << "teste ends with e" << endl;
    if (format_string::starts_with("teste","te"))
        cout << "teste starts with te" << endl;
    if (format_string::starts_with("teste",""))
        cout << "teste starts with empty" << endl;
    if (format_string::starts_with("teste","e"))
        cout << "teste starts with e" << endl;
    cout << endl;
        
    cout << fstring.uppercase(str) << endl;
        cout << fstring.lowercase(str) << endl << endl;
    
    //test_str = fstring.to_string(lli);
    //cout << test_str << endl;
    test_str = fstring.to_string(i);
    cout << test_str << endl;
    test_str = fstring.to_string(b);
    cout << test_str << endl;
    test_str = fstring.to_string(d);
    cout << test_str << endl;
    test_str = fstring.to_string(str);
    cout << test_str << endl;
    test_str = fstring.to_string(s);
    cout << test_str << endl << endl;
        
    
    fstring.from_string("10", i);
    cout << i << endl;
    fstring.from_string("true", b);
    if (b)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    //fstring.from_string("10000000000", lli);
    //cout << lli << endl;
    fstring.from_string("1.0", d);
    cout << d << endl;
    fstring.from_string("teste", str);
    cout << str << endl << endl;
    
    cout << "|" << fstring.trim_right(" teste ") << "|" << endl;
    cout << "|" << fstring.trim_left(" teste ") << "|" << endl;
    cout << "|" << fstring.trim(" teste ") << "|" << endl;
    
        cout << endl;
        
        fstring.split(" teste  1 2 3  "," ",str_list);        
        cout << "string list:" << endl;
        for(str_iter = str_list.begin(); str_iter != str_list.end(); ++str_iter) {
            cout << (*str_iter) << endl;
        }
        
        cout << endl;
        
        if (fstring.has_char("teste","#$%\t "))
            cout << "has char 1" << endl;
        else
            cout << "does not has char 1" << endl;
        if (fstring.has_char("teste ","#$%\t "))
            cout << "has char 2" << endl;
        else
            cout << "does not has char 2" << endl;
        if (fstring.has_char("teste\t","#$%\t "))
            cout << "has char 3" << endl;
        else
            cout << "does not has char 3" << endl;
        if (fstring.has_char("teste#","#$%\t "))
            cout << "has char 4" << endl;
        else
            cout << "does not has char 4" << endl;
        if (fstring.has_char("teste!","#$%\t "))
            cout << "has char 5" << endl;
        else
            cout << "does not has char 5" << endl;
        
    return 0;
}
