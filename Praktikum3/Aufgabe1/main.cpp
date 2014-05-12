/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 5. Mai 2014, 20:28
 */

#include "bas.h"
#include "derived.h"

/*
 * 
 */
int main() {
    try {
        
        //-----5 Testfaelle Pro-----
        Pro test0;
        Pro test1(string("Peter"), false, 34);
//        Pro test12(string("Peter"), false, -34); //Fehler
//        Pro test0.set_age(-13); //Fehler
        Pro test2(string("Susanne"), true, 12);
        Pro test3(string("Lolita"), false, 0);
        Pro test4(string("Heidi"), true, 112);
        
        //-----5 Tesfaelle Roo------
        Roo test5;
        Roo test6(string("Ball"), "Blau", 300); //explicit und einmal impliziter aufruf von string
        //Roo test7(string("Baer"), "Braun", -1200); //Fehler
        Roo test8(string("Hochhaus"), "Grau", 0);
        //Roo test9(string("Lutscher"), "Gruen", b); //Fehler       
        Roo test10(string("Lolita01"), "Silbermetallic", 10000000);
        Roo test11(string("Heidibuch"), "Bunt", 1111);
        
        for(Bas* pB = test1.getLast(); pB != 0; pB = pB->getNext()){ //getLast() erste in der Liste an sich das letzte
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

