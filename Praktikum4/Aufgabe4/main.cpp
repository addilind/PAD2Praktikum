/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:42
 */

#include <iostream>
#include "telnum.h"

using std::endl;
using std::cerr;
using std::cout;
using std::cin;

/*
 * 
 */
int main() {
    try {
        Telnum telnum;
        char number;
        cout << "Geben Sie eine Nummer ein: Eingabe mit ; beenden. " << endl;
        cin >> number;
        
        while(number != ';'){
            telnum.build_telnum(number);
            cin.putback(number);
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

