/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 12. Mai 2014, 14:31
 */

#include <iostream>
#include <string>
#include <map>

using std::endl;
using std::cerr;
using std::cin;
using std::cout;
using std::string;
using std::map;
/*
 * 
 */

string operator++(string& str) {
    return str += "x";
}

int main() {
    try {
        map<string, string> words; // Worte und ihre Haeufigkeit, Deklaration/Definition 
        string s;
        while (cin >> s && s != "quit"){
            ++words[s];
            // der Schluessel von words ist vom Typ string
            // die int Werte von words werden mit 0 initialisiert
            // wenn s schon enthalten ist, erhoeht map dessen Wert mit ++ um 1
            // wenn s noch nicht enthalten ist, wird ein (s,0)-Paar
            // eingefuegt und mit dem int-Operator ++ auf den Wert 1 erhöht
            // words[s] liefert int& als Anzahl des Worts s
        }
        typedef map<string, string>::const_iterator Iter;
        for (Iter p = words.begin();p != words.end(); ++p){
            cout << p->first << ':' << p->second << '\n';
        }
        
        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

