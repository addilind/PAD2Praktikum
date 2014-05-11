/* 
 * File:   main.cpp
 * Author: Doro
 *
 * Created on 14. Januar 2014, 13:34
 */

#include "ws13.h"

int main() {
    try {
        string Liwanze1("noName");
        string Liwanze2("noName");
        list<Liwanze> Lvz;
        populate(Lvz);
        print_LvzMembers(Lvz);
        init_connections(Lvz);
        int eingabe(0);


        while (eingabe != 3) {
            cout << "Geben Sie 1 ein, wenn Sie einen Namen zum Netzwerk hinzufuegen wollen!" << endl;
            cout << "Geben Sie 2 ein, wenn Sie zwei Namen im Netzwerk mit einander verbinden wollen!" << endl;
            cout << "Geben Sie 3 ein, wenn Sie das Programm beenden wollen!" << endl;
            cin >> eingabe;
            if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");

            switch (eingabe) {
                case 3:
                    if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");
                    return 0;
                    break;

                case 2:
                    while (Liwanze1 != "q" && Liwanze2 != "q") { //Solange beide Eingaben ungleich "q" sind
                        cout << "Geben Sie zwei Namen ein, die Sie mit einander verbinden wollen: ";
                        cin >> Liwanze1;
                        if (!cin) {
                            throw std::runtime_error("Inkorrekte Eingabe!");
                        }
                        if (Liwanze1 != "q") {
                            cin >> Liwanze2;
                            if (!cin) {
                                throw std::runtime_error("Inkorrekte Eingabe!");
                            }
                            if (Liwanze2 != "q") {
                                bool name_doppelt(false);
                                if (Liwanze1 == Liwanze2) {
                                    cout << "Bitte zwei verschiedene Namen eingeben!" << endl;
                                    name_doppelt = true;
                                    break;
                                }
                                if (name_doppelt == false) {
                                    zweinamen_eingeben(Lvz, Liwanze1, Liwanze2);
                                }
                            }
                            for (list<Liwanze>::iterator i = Lvz.begin(); i != Lvz.end(); i++) {
                                cout << i->get_name() << endl;
                                i->print_tierone();
                            }
                        }
                    }
                    break;
                case 1:
                    namen_eingeben(Lvz);
                    break;
                default:
                    cout << "Bitte geben Sie eine Zahl zwischen 1 und 3 ein!" << endl;
                    break;
            }
        }

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what();
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: ";
        return -1;
    }


}