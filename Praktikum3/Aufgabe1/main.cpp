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
        Pro test1("Peter", false, 34);
//        Pro test12("Peter", false, -34); //Fehler
//        test0.set_age(-13); //Fehler
        Pro test2("Susanne", true, 12);
        Pro test3("Lolita", false, 0);
        Pro test4("Heidi", true, 112);
        
        //-----5 Tesfaelle Roo------
        Roo test5;
        Roo test6("Ball", "Blau", 300); 
        //Roo test7("Baer", "Braun", -1200); //Fehler
        Roo test8("Hochhaus", "Grau", 0);
        Roo test9("Lutscher", "Gruen", 0);
//        test5.set_price(-999); //Fehler    
        Roo test10("Lolita01", "Silbermetallic", 10000000);
        Roo test11("Heidibuch", "Bunt", 1111);
        
        for(Bas* pB = test0.getLast(); pB != 0; pB = pB->getNext()){ //getLast() erste in der Liste an sich das letzte
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

