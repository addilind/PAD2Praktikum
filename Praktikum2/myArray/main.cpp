/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 27. April 2014, 18:53
 */


#include "mySymbol.h"

/*
 * 
 */
int main() {
    try {
        int auswahl = 0;
        string eingabe = "";
        int testindex = 0;
        SymbolTable tabelle;

        while (true) {
            cout << "\nWaehlen Sie eine Option aus: " << endl;
            cout << "1 um Symbole anzulegen.\n2 um Symbole abzufragen.\n"
                    << "3 um vorhandene Symbole zu loeschen.\n0 um zu beenden." << endl;
            cin >> auswahl;
            if (!cin) throw std::runtime_error("Fehlerhafte Eingabe!\n");
            switch (auswahl) {
                case 0:
                    return 0;
                case 1:
                    cout << "Geben Sie ein Symbol ein: "<<endl;
                    //cin >> eingabe;
                    cin.ignore(); //ignoriert auch das letzte enter (liest zeilenumbrueche erst beim naechsten mal mit)
                    std::getline(cin, eingabe); //liest so lange eingabe nach cin, bis enter gedrueckt wird.
                    //throw std::runtime_error("Fehlerhafte Eingabe!\n");
                    
                    if (tabelle.add_symbol(eingabe)) {
                        cout << "Symbol erfolgreich hinzugefuegt!" << endl;
                    } else {
                        cout << "Symbol nicht hinzugefuegt! Bitte neues eingeben!\n" << endl;
                    }
                    break;
                case 2:
                    tabelle.show_symbol();
                    break;
                case 3:
                    cout << "Geben Sie den Index des zu loeschenden Symbols an: ";
                    cin >> testindex;
                    if (!cin) throw std::runtime_error("Fehlerhafte Eingabe!\n");
                    tabelle.del_symbol(testindex);
                    cout << "Symbol geloescht!" << endl;
                    break;
                default:
                    cout << "Fehlerhafte Eingabe!\n";
                    break;
            }
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

