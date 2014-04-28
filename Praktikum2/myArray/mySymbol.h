/* 
 * File:   mySymbol.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 27. April 2014, 21:13
 */

#ifndef MYSYMBOL_H
#define	MYSYMBOL_H

#include "myArray.h"
#include <iostream>
#include <ctype.h>
#include <string>

using std::endl;
using std::cerr;
using std::cout;
using std::cin;

using std::string;

class mySymbol {
public:

    mySymbol() : letter(), length(0) {
    }

    mySymbol(const string& source) : letter(), length(source.size()) { //Bekommt einen string uebergeben
        if (length < 1 || length > 32) //ueberprüfe ob string kleiner als 1 Zeichen oder groeßer als 32 Zeichen
            throw std::runtime_error("bad source");
        for (int i = 0; i < length; i++) { //kopiert jedes einzele Zeichen vom String in das Array
            if (!isalpha(source[i]) || source[i] == ' ') { //ueberprueft korrekte zeichen
                throw std::runtime_error("unerlaubte Zeichen!\n"); //wirft einen fehler bei inkorrekten Zeichen
            }
            letter[i] = source[i]; //ist das Zeichen korrekt wird es hinzugefuegt
        }
    }

    bool operator ==(const mySymbol& other) { //Bekommt ein Symbol uebergeben
        if (other.length != length) { //Ueberprüft ob Smybole ungleich lang sind.
            return false; //Wenn Symbole ungleichlang wird abgebrochen
        }
        for (size_t i = 0; i < length; i++) { //vergleich jeden einzelnen Buchstaben auf ungleichheit
            if (other.letter[i] != letter[i])
                return false; //Wenn Buchstaben ungleich sind wird abgegbrochen
        }
        return true;
    }

    bool operator !=(const mySymbol& other) {
        return !(*this == other); //Aufruf des vergleich operators 
    }

    myArray<char, 32> letter; //Symbol ist eine Menge von Zeichen und die max Anzahl
    int length;
};

class SymbolTable {
public:

    SymbolTable() : table() {
    }

    bool add_symbol(const mySymbol& symbol) {
        int ffindex = 1024;
        //ueberprüfen, ob eingegebenes Symbol korrekt ist (keine leerzeichen, nur groß-/kleinbuchstaben)
        for (size_t i(0U); i < 1024U; i++) {
            if (ffindex == 1024 && table[i].length == 0) {//Ueberprueft ob es noch eine leere Zeile braucht(oder ob schon eine gefunden wurde) und ob die ZEile in der er gereade ist eine leere Zeile ist
                ffindex = i; //schreibt den Index der gefundenen ersten leeren Zeile in die Variable
            } else {
                if (table[i] == symbol) //ueberpruefe ob gleiches Symbol drin steht
                    return false; //weil doppelt ist
            }
        }
        if (ffindex == 1024) {
            throw std::runtime_error("Speicher voll!\n");
        }
        table[ffindex] = symbol; //schreibt das symbol an den ersten freien index
    }

    void show_symbol() {
        for (size_t i(0U); i < 1024U; i++) { //Alle Zeilen(Symbole) in der Tabelle durchgehen
            if (table[i].length != 0) { //table[i] zeigt ein Symbol an der Stelle i
                cout << "Stelle: " << i << "\tSymbol: ";
                for (size_t j(0U); j < table[i].length; ++j) { //table[i].length gibt die laenge des symbols an, dass aus mehreren letter(zeichen) besteht
                    cout << table[i].letter[j]; //Jeder einzelner Buchstabe aus letter(Array mit Zeichen) des Symbols an der Stelle table[i]
                }
                cout << endl;
            }
        }
    }

    void del_symbol(int symindex) {
        if (symindex < 0 || symindex > 1023){
            throw std::runtime_error("Index nicht vorhanden!\n");
        }
        table[symindex] = mySymbol();
    }

    myArray<mySymbol, 1024> table;
};

#endif	/* MYSYMBOL_H */

