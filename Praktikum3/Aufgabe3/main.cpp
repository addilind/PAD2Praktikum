/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 9. Mai 2014, 16:15
 */

#include "frame.h"
#include "square.h"
#include "triangle.h"

/*
 * 
 */
int main() {
    try {
        Frame test;

//        Line L(20, 20, 34, 34); //test ok
//        L.draw(&test);
//        Rectangle R(0, 10, 10, 20); // test ok
//        R.draw(&test);
//        Triangle T(0, 0, 10, 10, 20, 20); //test ungueltiges dreieck: ok
//        T.draw(&test);
//        Triangle T(34, 20, 10, 20, 0, 0); //test ok
//        T.draw(&test);


        test.show();

        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

