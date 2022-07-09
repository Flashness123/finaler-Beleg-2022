#include "Userinteraction.h"

void ShowPerson(LinkedList <person>*b)
{
    b->show();        
}

void ShowAllMediumWithLendStatus(LinkedList <medium>*c)
{
   c->borrowed();
}

void AddPerson(LinkedList <person>*b)
{   
    char* buf=new char[20];
    char* Buf=new char[20];
    char* puf=new char[20];
    int age = atoi(Buf);
    int usernum = atoi(puf);
    std::cout << "Enter your name " << std::endl;
    std::cin >>buf;
    std::cout << "Enter your age " << std::endl;
    std::cin >>Buf;
    std::cout << "Enter your user-number " << std::endl;
    std::cin >>puf;
    b->PushBack(new person(buf,age,usernum));
    std::cout << "Person got added" << std::endl;
    
}

void AddBluray(LinkedList <medium>*c)
{
    char* buf=new char[20];
    char* Buf=new char[20];
    char* puf=new char[20];
    char* muf=new char[20];
    char* luf=new char[20];
    int FSK = atoi(Buf);
    int Mediumnum = atoi(puf);
    bool use = atoi(muf);
    int Usernum = atoi(luf);
    std::cout << "Enter your name " << std::endl;
    std::cin >>buf;
    std::cout << "Enter your FSK " << std::endl;
    std::cin >>Buf;
    std::cout << "Enter your Mediumnum " << std::endl;
    std::cin >>puf;
    std::cout << "Enter if used 0 or 1 " << std::endl;
    std::cin >>muf;
    std::cout << "Enter if used by which user-number " << std::endl;
    std::cin >>luf;
    c->PushBack(new Bluray(buf,FSK,Mediumnum,use,Usernum));
    std::cout << "Bluray got added" << std::endl;
    
}

void AddBuch(LinkedList < medium>*c)
{
    char* buf=new char[20];
    char* Buf=new char[20];
    char* puf=new char[20];
    char* muf=new char[20];
    char* luf=new char[20];
    int FSK = atoi(Buf);
    int Mediumnum = atoi(puf);
    bool use = atoi(muf);
    int Usernum = atoi(luf);
    std::cout << "Enter your name " << std::endl;
    std::cin >>buf;
    std::cout << "Enter your FSK " << std::endl;
    std::cin >>Buf;
    std::cout << "Enter your Mediumnum " << std::endl;
    std::cin >>puf;
    std::cout << "Enter if used 0 or 1 " << std::endl;
    std::cin >>muf;
    std::cout << "Enter if used by which user-number " << std::endl;
    std::cin >>luf;
    c->PushBack(new Buch(buf,FSK,Mediumnum,use,Usernum));
    std::cout << "Buch got added" << std::endl;
    
}

void DeletePerson(LinkedList <person>*b)
{
    if(b->Front()==nullptr)
    std::cout << "List is Empty. Not possible to delete" << std::endl;

    else
    {   
        char* buf=new char[4];
        std::cout << "Please enter the usgnr: " << std::endl;
        std::cin >>buf;
        b->DeletePersonID(atoi(buf));
    }
}

void DeleteMedium(LinkedList<medium>*c)
{
        if(c->Front()==nullptr)
    std::cout << "List is Empty. Not possible to delete" << std::endl;

    else
    {
        char* Bufmedium=new char[4];
        std::cout << "Please enter a medium number" << std::endl;
        std::cin >>Bufmedium;
        if(c->GetMediumID(atoi(Bufmedium))!= nullptr)
        {
            c->DeleteMediumID(atoi(Bufmedium));
        }  
        else
            std::cout << "Medium does not exist" << std::endl;
    }
}

void LendMedium(LinkedList<medium>*c,LinkedList<person>*b)
{

    if(c->Front()==nullptr)
    {
        std::cout << "ListIsEmpty. You can not lend anything" << std::endl;
    }

    else
    {
        char* bufmedium=new char[4];
        char* bufperson=new char[4];
        std::cout << "Please enter the medium number: " << std::endl;
        std::cin>>bufmedium;
        if(c->GetMediumID(atoi(bufmedium))!= nullptr)
        {
            if(c->GetMediumID(atoi(bufmedium))->getusgnr()==0) //uberpruft verfugbarkeit
            {
                std::cout << "Please enter your usgnrnumber" << std::endl;
                std::cin >> bufperson;
                if(bufperson != nullptr)
                {
                    c->GetMediumID(atoi(bufmedium))->setusgnr((atoi(bufperson)));
                    std::cout << "Medium lended to the Person" << std::endl;
                }

                else
                    std::cout << "libnummer does not exist" << std::endl;
            }

            else
            {
                std::cout << "Medium already lended" << std::endl;
            }
        }
        else
            std::cout << "Medium does not exist" << std::endl;
    }        
}

void ReturnMedium(LinkedList<medium>*c,LinkedList<person>*b)
{

    if(c->Front()==nullptr)
    {
        std::cout << "ListIsEmpty. You can not lend anything" << std::endl;
    }

    else
    {
        char* bufmedium=new char[4];
        char* bufperson=new char[4];
        std::cout << "Please enter the medium number: " << std::endl;
        std::cin>>bufmedium;
        if(c->GetMediumID(atoi(bufmedium))!= nullptr)
        {
            if(c->GetMediumID(atoi(bufmedium))->getusgnr()!= 0) 
            {
                std::cout << "Please enter your usgnrnumber" << std::endl;
                std::cin >> bufperson;
                if(bufperson != nullptr)
                {
                    c->GetMediumID(atoi(bufmedium))->setusgnr(0);
                    std::cout << "Medium lended to the Person" << std::endl;
                }

                else
                    std::cout << "libnummer does not exist" << std::endl;
            }

            else
            {
                std::cout << "Medium already lended" << std::endl;
            }
        }
        else
            std::cout << "Medium does not exist" << std::endl;
    }        
}