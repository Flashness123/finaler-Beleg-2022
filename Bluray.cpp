#include <cstring>
#include "medium.h"
using namespace std;

Bluray::Bluray(){
    name=new char[16];
    name[0]='\0';
    mediumnr=0;
    usage=false;
    usgnr=0;
    FSK=0;
}

Bluray::Bluray(const char* name,int FSK, int mediumnr,bool usage, int usgnr){
    this->usage=usage;
    this->usgnr=usgnr;
    this->mediumnr=mediumnr;
    this->name=new char[strlen(name+1)];
    strcpy(this->name,name);
    this->FSK=FSK;
}

bool Bluray::operator==(Bluray other){
    return strcmp(this->name,other.name) == 0;
    }

ostream& Bluray::OUT(std::ostream& COUT){
    COUT<<name<<'\n';
    COUT<<FSK<<'\n';
    COUT<<mediumnr<<'\n';
    COUT<<usage<<'\n';
    COUT<<usgnr<<'\n';
    return COUT;}

void Bluray::display()const{
    cout<<"Name:"<<name<<'\n';
    cout<<"FSK:"<<FSK<<'\n';
    cout<<"Mediumnumber:"<<mediumnr<<'\n';
    cout<<"In use:"<<usage<<'\n';
    cout<<"User Number:"<<usgnr<<'\n';

}

void Bluray::changeusage(){
    if (usage==false)
    {
        this->usage=true;
    }else{
        this->usage=false;
    }
    
}
