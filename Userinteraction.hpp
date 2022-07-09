#include "person.h"
#include "beleglist.h"

void AddPerson(LinkedList <Person>*b);
// TODO : Keine doppelten ID's, sowie eine Spanne von 1-100
void ShowPerson(LinkedList <Person>*b); // Show Funktion viel aestetischer machen
void DeletePerson(LinkedList<Person>*b); //Prüfen, ob diese Person existiert
void AddDVD(LinkedList<Medium>*c);
void AddCD (LinkedList<Medium>*c);
void ShowAllMediumWithLendStatus(LinkedList<Medium>*c);//ähnlich wie bei Show
void LendMedium(LinkedList<Medium>*c, LinkedList <Person>*b);
//TODO Nutzer muss angeben welches Medium er ausleihen möchte (ID angeben) sowie welche Bibnr dieser hat
void ReturnMedium(LinkedList<Medium>*c,LinkedList<Person>*b);//Eingabe welches Medium er/sie/es return möchte und mittels SetPerson auf Null setzen
void DeleteMedium(LinkedList<Medium>*c);
//Geschafft: alles. Nur noch schöner gestalten