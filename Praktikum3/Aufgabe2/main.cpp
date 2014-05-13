/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 7. Mai 2014, 20:18
 */

#include "Aufgabe2.h"

/*
 * 
 */
int main() {
    try {
        Frame test;
        
//        Line L1 (0, 0, 10, 10); //test ok
//        L1.draw(&test);
//        Line L2 (10, 0, 10, 20); //test ok
//        L2.draw(&test);
//        Line L3 (20, 0, 10, 20); //test ok
//        L3.draw(&test);
        
        
        test.show();
        test.show_unf();
        
        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

