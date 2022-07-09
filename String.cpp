#include "String.hpp"
#include <cstring>

Cppstring::Cppstring()
{
    buf = NULL;
    len = 0;    
}

Cppstring::Cppstring(const char* other)
{
    len = strlen(other);
    buf = new char[len+1];
    strncpy(buf, other,len+1);

}

Cppstring::Cppstring(const Cppstring& other)
{
    this->len = other.len;
    this->buf = new char[len+1];
    strncpy(this->buf, other.buf,len+1);
}

Cppstring:: ~Cppstring()
{   
    clean();
}

int Cppstring:: getlen()
{
    return len;
}

char* Cppstring:: getBuf()
{
    return buf;
}

Cppstring& Cppstring:: operator=(Cppstring& other)
{
    clean();
    if (&other!=this)
    {
        len = other.getlen();
        buf = new char[len+1];
        strncpy(buf,other.getBuf(), len+1);
    }
    return *this;
    
}

int Cppstring :: operator==(Cppstring& other)
{
    if (strcmp(buf,other.getBuf())==0)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

int Cppstring :: operator==(const char* other)
{
    if (strcmp(buf,other)==0)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

void Cppstring :: clean()
{
    if(buf != nullptr)
    {
        delete []buf;
    }
    len = 0;
}

std::ostream& operator<<(std::ostream& COUT, Cppstring& other)
{
    COUT << other.getBuf();
    return COUT;
}
std::istream& operator>>(std::istream& stream,  Cppstring& other)
{
    stream >> other.buf;
    return stream;
}
