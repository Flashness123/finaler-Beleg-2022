#ifndef __beleglist_h__
#define __beleglist_h__
#include <iostream>
//#include "BelegBluray.h"
#include "medium.h"
#include "person.h"
#include <cstring>
#include <fstream>

template <class T>
class LinkedListNode{
    public:
    LinkedListNode( T* Item,
                    LinkedListNode* Previous = nullptr,
                    LinkedListNode* Next = nullptr);
    T* Item;
    LinkedListNode* Previous;
    LinkedListNode* Next;
    
    
};
template <class T>
LinkedListNode<T>::LinkedListNode(T* item, LinkedListNode* previous,LinkedListNode* next)
                    :Item(item),Previous(previous),Next(next){}



template <class T>
class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    void Clear();

    void PushBack(T* Item);
    void PopBack();
    void show();
    T* Front();
    T* Back();
    bool Empty();
    bool Search(T* Item);
    void remove(T* Item);
    void lend(T* Item, person);
    void returning(T* Item, person);
    void borrowed();
    void MediumInFile();
    void ReadMediumFromFile();
    void PersonInFile();
    void ReadPersonFromFile();
    void DeletePersonID(int n);
    void DeleteMediumID(int n);
    T* GetMediumID (int n);
    //int fileoutput();
    LinkedListNode<T>* getHead();
private:
 // zu public geandert weil sonst error: Head’ is private within this context
    LinkedListNode<T>* Head;
};


template <class T>
LinkedList<T>::LinkedList():Head(nullptr){}

template <class T>
LinkedList<T>::~LinkedList(){
    Clear();
}

template <class T>
LinkedListNode<T>* LinkedList<T>::getHead(){
    return Head;}

template <class T>
void LinkedList<T>::Clear(){
    LinkedListNode<T>* Current=Head;
    while (Current != nullptr)
    {
        LinkedListNode<T>* Temp = Current->Next;
        delete Current;
        Current = Temp;
    }
    Head=nullptr;
    
}

template <class T>
void LinkedList<T>::MediumInFile()
{
    std::ofstream out;
    out.open("Mymedium.txt");
    LinkedListNode<T>* Current = Head;
        while (Current != nullptr)
        {   
            out<<*(Current->Item);

            if(dynamic_cast<Bluray*>(Current->Item)==NULL)
            {
                out<< "Buch" << std::endl;    
            }

            else
            {
                out<<"Bluray" << std::endl;
            }

            Current = Current->Next;
        }
        out.close();
}

template <class T>
void LinkedList<T>::PersonInFile()
{
    std::ofstream out;
    out.open("Myperson.txt");
    LinkedListNode<T>* Current = Head;
        while (Current != nullptr)
        {   
            out<<*(Current->Item);
            out<<"Bluray" << std::endl;
            Current = Current->Next;
        }
        out.close();
}

template <class T>
void LinkedList<T>::ReadPersonFromFile()
{
    char *buf=new char[127];
    int age;
    int usgnr;
    char* puf=new char[127];
    std::ifstream in("Myperson.txt");
    if(in.is_open())
    {
        while(!in.eof())
        {   
            in.getline(puf,127);
            in.getline(buf,127);
            age=atoi(buf);
            in.getline(buf,127);
            usgnr=atoi(buf);
            if(puf[0]<2)
            cout<<"break"<<endl;
                break;
            PushBack(new person(puf,age,usgnr));
        }
    }else{cout<<"Dateiname nicht korrekt<<endl;";}
    in.close();
}


template <class T>
void LinkedList<T>::ReadMediumFromFile()
{
    char *buf=new char[127];
    int FSK;
    int mediumnr;
    bool usage;
    int usgnr;
    char* BUF=new char[127];
    char* puf=new char[127];
    std::ifstream in("Mymedium.txt");
    if(in.is_open())
    {
        while(!in.eof())
        {   
            in.getline(puf,127);
            in.getline(buf,127);
            FSK=atoi(buf);
            in.getline(buf,127);
            mediumnr=atoi(buf);
            in.getline(buf,127);
            usage=atoi(buf);
            in.getline(buf,127);
            usgnr=atoi(buf);
            in.getline(BUF,127);
            if(puf[0]<2)
            cout<<"break"<<endl;
                break;
            if(BUF == "Bluray")
                PushBack(new Bluray(puf,FSK,mediumnr,usage,usgnr));
            else
                PushBack(new Buch(puf,FSK,mediumnr,usage,usgnr));
        }
    }else{cout<<"Dateiname nicht korrekt<<endl;";}
    in.close();
}

template <class T>
void LinkedList<T>::PushBack(T* Item){//konnte tamplate problematisc werden
    if (Head == nullptr)//case if the List is empty
    {
        Head = new LinkedListNode<T>(Item);
    }
    else//case if the List is not empty
    {
        LinkedListNode<T> * Current = Head;
        while(Current->Next != nullptr){
            Current=Current->Next;
        }
        LinkedListNode<T> * Temp = new LinkedListNode<T>(Item,Current);
        Current->Next=Temp;
    }
}

template<class T>
void LinkedList<T>::show(){ 
    LinkedListNode<T> * Current = Head;
        while(Current != nullptr){
            cout<<*(Current->Item)<<endl;
            Current=Current->Next;
        }
}

template <class T>
std::ostream& operator <<(std::ostream& COUT, LinkedList<T>& other){
    //std::cout<< "X";
    LinkedListNode<T> * Current = other.getHead();
    while (Current != nullptr){
        COUT<<(Current->Item)<<" "; //vielleict fehlerhaft
        Current=Current-> Next;
    }
    //std::cout<< "X";
    return COUT;
}

template <class T>
T* LinkedList<T>::Front(){
    if(Head==nullptr){
        throw std::out_of_range("Tried to call Front() empty linked list");
    }
    return Head->Item;
}

template <class T>
T* LinkedList<T>::Back(){
    if(Head==nullptr){
        throw std::out_of_range("Tried to call Back() empty linked list");
    }
    LinkedListNode<T>* Current = Head;
    while (Current->Next != nullptr){
        Current=Current-> Next;
    }
    return Current->Item;
}

template <class T>
void LinkedList<T>::PopBack(){
    if(Head==nullptr){//empty list
        throw std::out_of_range("Tried to pop empty linked list");
    }

    if(Head->Next==nullptr){
        delete Head;// one node
        Head=nullptr;
    }
    else{//when two or more nodes exist in the list
        LinkedListNode<T>* Current = Head;
        while (Current->Next != nullptr){
            Current=Current-> Next;
        }
        Current->Previous->Next=nullptr;
        delete Current;
    }
}

template <class T>
bool LinkedList<T>::Empty(){
    return Head == nullptr;
}

template<class T>
bool LinkedList<T>::Search(T* Item){ //funktioniert, eventuell noch umarbeiten fur T werte
    LinkedListNode<T> * Current = Head;
        while(Current != nullptr){
            if(Current->Item==Item){
                cout<<"Item enthalten"<<endl;
                return true;
                break;
                }
            else{Current=Current->Next;
                }
            }
            cout<<"Item nicht enthalten"<<endl;
            return false;
}

template<class T>
void LinkedList<T>::remove(T* Item){
    LinkedListNode<T> * Current = Head;
        while(Current != nullptr){
            if(Current->Item==Item){
            if(Head==nullptr){//empty list
                throw std::out_of_range("Tried to pop empty linked list");
            }

            if(Head->Next==nullptr){
                delete Head;// one node
                Head=nullptr;
            }
            else{//when two or more nodes exist in the list
                Current->Previous->Next=Current->Next;
                Current->Next->Previous=Current->Previous;
                delete Current;
            }
                break;
                }
            else{Current=Current->Next;
                }
            }

}
template<class T>
void LinkedList<T>::DeletePersonID(int n)
    {
        bool found=false;
        LinkedListNode<T>* Current = Head;
        while (Current != nullptr)
        {
            person* p;
            p=Current->Item;
            if (p->getusgnr()== n)
            {
                if (Current == Head)
                {
                    Head = Current->Next;
                    delete Current;
                }

                else if (Current->Next == nullptr)
                {
                    Current->Previous->Next = nullptr;
                    delete Current;
                }
                else
                {
                    Current->Previous->Next = Current->Next;
                    Current->Next->Previous = Current->Previous;
                    delete Current;
                }
                found=true;
                break;
            }

            else
            found=false;

            Current = Current->Next;
        }
        if(found==true)
        {
            std::cout << "Person got deleted" << std::endl;
        }
        else
            std::cout << "Person does not exist" << std::endl;
    }
template<class T>
T* LinkedList<T>::GetMediumID (int n)
    {
            LinkedListNode<T>* Current = Head;
            while (Current != nullptr)
            {   
                medium* p;
                p =(Current->Item);
                if(p==nullptr)
                {
                    std::cout << "p ist nullptr" << std::endl;
                    break;
                }

                if(p->getmediumnr()== n)
                {
                    return Current->Item;
                }
                Current = Current->Next;
            }
        return nullptr;
    }


template<class T>
void LinkedList<T>::lend(T* Item, person p){
LinkedListNode<T> * Current = Head;
    while(Current != nullptr){
        if(Current->Item==Item){
            cout<<"Item wird verliehen"<<endl;
            Item->changeusage();
            int a=p.getusgnr();
            Item->setusgnr(a);
            break;
            }
        else{Current=Current->Next;
            }
        }
}

template<class T>
void LinkedList<T>::returning(T* Item, person p){
if(Item->getusage()){
    LinkedListNode<T>* Current = Head;
    while(Current != nullptr){
        if(Current->Item==Item){
            cout<<"Item wird zuruckgegeben"<<endl;
            Item->changeusage();
            Item->setusgnr(0);
            break;
        }
        else {Current=Current->Next;}
    }
}
else{cout<<"Item nicht verliehen"<<endl;}
}

template<class T>
void LinkedList<T>::DeleteMediumID(int n)
    {
        bool found=false;
        LinkedListNode<T>* Current = Head;
        while (Current != nullptr)
        {
            medium* p;
            p=Current->Item;
            if (p->getmediumnr()== n)
            {
                if (Current == Head)
                {
                    Head = Current->Next;
                    delete Current;
                }

                else if (Current->Next == nullptr)
                {
                    Current->Previous->Next = nullptr;
                    delete Current;
                }
                else
                {
                    Current->Previous->Next = Current->Next;
                    Current->Next->Previous = Current->Previous;
                    delete Current;
                }
                found=true;
                break;
            }
            else
            found=false;

        Current = Current->Next;
        }

        if(found==true)
        {
            std::cout << "Medium deleted" << std::endl;
        }
        else
            std::cout << "Medium doesnt exist" << std::endl;
    }

template<class T>
void LinkedList<T>::borrowed(){
    LinkedListNode<T>* Current = Head;
   
        while(Current != nullptr){
            if(Current->Item->getusage()){
                cout<<*(Current->Item)<<endl;
            }
          
            Current=Current->Next;
            
        }
}

#endif