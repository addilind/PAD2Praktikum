/* 
 * File:   ws13.h
 * Author: Doro
 *
 * Created on 14. Januar 2014, 13:35
 * 
 * Beinhaltet die Deklarationen
 */

#ifndef WS13_H
#define	WS13_H

#include <stdexcept> //include dateien für error
#include <string> //include dateien für string
#include <vector> //include dateien für vector
#include <iostream> //include dateien für ein und ausgabeströme
#include <list>



using std::string;
using std::list;
using std::cerr;
using std::cout;
using std::endl;
using std::cin;

class Liwanze{
public:
    enum Region {ndef, amer, apac, emea}; //Enumeration muss ganz oben stehen zwecks vorwärtsdeklaration
    
    Liwanze(); //Standartkonstruktor
    Liwanze(string, Region); //weiterer Konstruktor
    
    string get_name()const; // Methode zum auslesen des Namens Rückgabetyp ist string getter
    Region get_loc() const; //Methode zum auslesen der Region Rückgabetyp ist enumerator(Region) getter
    
    void print(); //Methode zur ausgabe, kein Rückgabetyp
    
    bool connects(Liwanze*); //Pointer(Zeiger) vom Datentyp Liwanze
    bool connected(Liwanze*); //Pointer(Zeiger) vom Datentyp Liwanze
    void print_tierone(); //tier one
    void add_connTo(Liwanze*);
    void add_connFrom (Liwanze*);
    
private:
    string name;
    Region loc;
    list<string> connectsTo;
    list<string> connectedFrom;
    
};

//support-funktionen
void populate(list<Liwanze>&); 
void print_LvzMembers(list<Liwanze>&);
void add_Liwanze(string, list<Liwanze>&);
void init_connections(list<Liwanze>&);
void make_connection(list<Liwanze>&, string, string);
void namen_eingeben(list<Liwanze>&);
void zweinamen_eingeben(list<Liwanze>&, string, string);

#endif	/* WS13_H */

 