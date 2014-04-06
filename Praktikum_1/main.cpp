/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matnr.: 736476
 *
 * Created on 17. März 2014, 09:04
 * 
 * Ein Programm zur Berechnung des Kapitalwerts, gerundet auf drei Stellen hinter dem Komma,
 * mit einem Festen Zinssatz(1.05% p.a.) auf die vierte Stelle hinter dem Komma genau gerundet.
 * 
 */

#include "NPV.h"
#include <ctime>
#include <cstdlib>

/*
 * 
 */



int main() {
    try {
        long double value(0.0);
        bool again = true;
        int choice = 3;
        int more = 0;
        int number = 0;
        double irate = 0.0;
        cout.precision(3);//3 Nachkommastellen
        cout << "1 Werte eingeben, zuf\x93llige Werte erzeugen mit 2, 0 beenden" << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                return 0;
            case 1:
            {
                vector<long double> vinv;
                while (again) {
                    cout << "Geben Sie einen Wert ein ";
                    cin >> value;

                    vinv.push_back(value);
                    cout << "Weitere Werte eingeben? Ja= 0 Nein = 1" << endl;
                    cin >> more;
                    if (more == 1) again = false;
                }
                cout << "Geben Sie einen Zinzsatz ein.";
                cin >> irate;
                NPV instanz = NPV(vinv, irate);
                cout << "Der Kapitalwert betraegt: " <<
                        static_cast<double> (instanz.reckoning()) << endl;
                break;
            }
            case 2:
            {
                cout << "Geben Sie eine Anzahl an ";
                cin >> number;
                NPV instanz = NPV(number);
                cout << "Der Kapitalwert betraegt: " <<
                        static_cast<double> (instanz.reckoning()) << endl;
                break;
            }
            default: return 0;
        }

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}


