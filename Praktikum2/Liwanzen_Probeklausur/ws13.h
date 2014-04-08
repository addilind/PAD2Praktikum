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



using std::string;
using std::vector;
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
    vector<string> connectsTo;
    vector<string> connectedFrom;
    
};

//support-funktionen
void populate(vector<Liwanze>&); //Funktion die Werte in einen Vector schreibt, bekommt leeren Vektor übergeben
void print_LvzMembers(vector<Liwanze>&); // Funktion die den Inhalt den Vektors ausgibt, bekommt einen vektor übergeben
void add_Liwanze(string, vector<Liwanze>&);
void init_connections(vector<Liwanze>&); //Supportfunktion zum vernetzen der 6 ursprünglichen Mitglieder
void make_connection(vector<Liwanze>&, string, string);
void namen_eingeben(vector<Liwanze>&);
void zweinamen_eingeben(vector<Liwanze>&, string, string);

#endif	/* WS13_H */

 