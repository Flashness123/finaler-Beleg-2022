#ifndef _STRINGCLASS_HPP_
#define _STRINGCLASS_HPP_

#include <iostream>
class Cppstring{
public:
    Cppstring();
    Cppstring(const char* PBuf);
    Cppstring(const Cppstring& other);
    ~Cppstring();
    int getlen();
    char* getBuf();
    Cppstring& operator=(Cppstring& other);
    int operator==(Cppstring& other);
    int operator==(const char* other);
    void clean();
    friend std::ostream& operator<<(std::ostream& COUT, Cppstring& other);
    friend std::istream& operator>>(std::istream& stream,  Cppstring& other);
private:
    char* buf;
    int len;

};

#endif