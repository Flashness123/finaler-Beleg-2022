#include "person.h"
#include "beleglist.h"

void AddPerson(LinkedList <person>*b);
// TODO : Keine doppelten ID's, sowie eine Spanne von 1-100
void ShowPerson(LinkedList <person>*b); // Show Funktion viel aestetischer machen
void DeletePerson(LinkedList<person>*b); //Prüfen, ob diese Person existiert
void AddBluray(LinkedList<medium>*c);
void AddBuch (LinkedList<medium>*c);
void ShowAllMediumWithLendStatus(LinkedList<medium>*c);//ähnlich wie bei Show
void LendMedium(LinkedList<medium>*c, LinkedList <person>*b);
//TODO Nutzer muss angeben welches Medium er ausleihen möchte (ID angeben) sowie welche Bibnr dieser hat
void ReturnMedium(LinkedList<medium>*c,LinkedList<person>*b);//Eingabe welches Medium er/sie/es return möchte und mittels SetPerson auf Null setzen
void DeleteMedium(LinkedList<medium>*c);
//Geschafft: alles. Nur noch schöner gestalten