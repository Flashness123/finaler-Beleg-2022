#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "beleglist.h"
#include "medium.h"
#include "Userinteraction.h"
#include "person.h"

int main(void)
{ 
    char Choice;
    LinkedList <person>* b = new LinkedList <person>; 
    LinkedList <medium>* c= new LinkedList <medium>;
    b->ReadPersonFromFile();
    c->ReadMediumFromFile();
  
    std::cout << "Applications with Person :" << std::endl;
    std::cout << "(1)Add Person " << std::endl;
    std::cout << "(2)Show Person" << std::endl;
    std::cout << "(3)Delete Person" << std::endl;
    std::cout << "Applications with Medium :" << std::endl;
    std::cout << "(4)Add Bluray " << std::endl;
    std::cout << "(5)Add Buch " << std::endl;
    std::cout << "(6)Show all Medium with lend status" << std::endl;
    std::cout << "(7)Lend Medium " << std::endl;
    std::cout << "(8)Return Medium " << std::endl;
    std::cout << "(9)Delete Medium by ID" << std::endl;
    std::cout << "(m)Show Menue again" << std::endl;
    std::cout << "(0)Exit the Program" << std::endl;

    do
    {

        std::cin >> Choice;

            switch(Choice)
            {
                case '1':
                {
                   AddPerson(b);
                   break; 
                }

                case '2':
                {
                    std::cout <<std::setw(9) << "Name" <<std::setw(14) <<"Bibnummer\n";
        
                    ShowPerson(b);
                    break;
                }

                case '3':
                {
                  DeletePerson(b);
                  break;
                }

                case '4':
                {
                  AddBluray(c);
                  break;
                }

                case '5':
                {
                  AddBuch(c);
                  break;
                }

                case '6':
                {
                  std::cout <<std::setw(8) << "Titel" << std::setw(15) << "Medium ID" 
                  << std::setw(13) <<"Lend by\n " << std::endl;
                  ShowAllMediumWithLendStatus(c);
                  break;
                }

                case '7':
                {
                  LendMedium(c,b);
                  break;
                }
                case '8':
                {
                    ReturnMedium(c,b);
                    break;
                }
                case '9':
                {
                  DeleteMedium(c);
                  break;
                }
                case 'm':
                {
                  std::cout << "Applications with Person :" << std::endl;
                  std::cout << "(1)Add Person " << std::endl;
                  std::cout << "(2)Show Person" << std::endl;
                  std::cout << "(3)Delete Person" << std::endl;
                  std::cout << "Applications with Medium :" << std::endl;
                  std::cout << "(4)Add DVD " << std::endl;
                  std::cout << "(5)Add CD " << std::endl;
                  std::cout << "(6)Show all Medium with lend status" << std::endl;
                  std::cout << "(7)Lend Medium " << std::endl;
                  std::cout << "(8)Return Medium " << std::endl;
                  std::cout << "(9)Delete Medium by ID" << std::endl;
                  std::cout << "(m)Show Menue again" << std::endl;
                  std::cout << "(0)Exit the Programm" << std::endl;
                  break;
                }

                case '0':
                {
                  b->PersonInFile();
                  c->MediumInFile();
                    exit (0);
                    break;
                }
          }
          std::cout << "\nHow would you like to continue? Only type in a valid number!" << std::endl;
    }
    while (true);
}
/*
int main(){
    
    LinkedList<medium>* p = new LinkedList<medium>;
    LinkedList<person>* d = new LinkedList<person>;
    Bluray Potter("Harry Potter", 16, 1, 0, 0);
    Bluray Herr("Herr der Ringe", 18, 2, 0, 0);
    Bluray College("College Teens", 12, 3, 0, 0);
    Buch Colege("College Teenswritten", 12, 3, 0, 0);
    person Lukas("Lukas", 16, 1);
    person Kevin("Kevin", 17, 2);
    person Maik("Maik", 13, 3);
    d->PushBack(&Lukas);
    d->PushBack(&Kevin);
    d->PushBack(&Maik);
    d->PersonInFile();
    p->PushBack(&Potter);
    p->PushBack(&Herr);
    p->PushBack(&College);
    p->PushBack(&Colege);
    p->ReadMediumFromFile();
    d->ReadPersonFromFile();
    d->show();
    p->MediumInFile();
    p->show();
return 0;
}*/