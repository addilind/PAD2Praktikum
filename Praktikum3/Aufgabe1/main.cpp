/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 5. Mai 2014, 20:28
 */

#include "bas.h"

/*
 * 
 */
int main() {
    try {

        Pro test1(string("Peter"), false);
        Pro test2;
        Roo test3;
        Roo test4(string("Susanne"), 34);
        Roo test5(string("Heinz"), -12);
        
        for(Bas* pB = test1.getLast(); pB; pB = pB->getNext()){
            pB->print();
            cout << endl;
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

