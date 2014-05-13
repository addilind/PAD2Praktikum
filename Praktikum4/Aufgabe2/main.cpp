/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:41
 */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <map>

using std::string;
using std::endl;
using std::cerr;
using std::cout;
using std::ifstream;
using std::ofstream;

/*
 * 
 */
int main() {
    try {
        string dateiname = "Ruebezahl"; //Einen String mit dem Namen dateiname deklarieren und mit dem dateinamen initialisieren
        string dateinameout = "p5a2";
        ifstream input(dateiname.c_str(), std::ios::binary);
        if (!input) {
            throw std::runtime_error("Fehler!\n");
        }
std:
        std::map<string, int> ms;
        string word = "";
        
        char cinput = ' ';
        while (input.read(&cinput, sizeof (char))) {
            //solange chars im vector speichern bis leerzeichen kommt
            if (cinput != ' ') {
                word += cinput; //chars in word summieren
                ++ms[word]; //Alle Chars in Map ablegen
                ofstream outfile(dateinameout.c_str(), std::ios::app);
                if (!outfile) throw std::runtime_error("Kein Schreibzugriff auf die Datei!");
            } else { //ansonsten weiter einzelne zeichen
                input.read(&cinput, sizeof (char));
            }
        }
//        typedef std::map<string, int>::const_iterator Iter; //Ausgabe der Map
//        for (Iter p = ms.begin(); p != ms.end(); ++p) {
//            cout << p->first << ':' << p->second << '\n';
//        }
        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

