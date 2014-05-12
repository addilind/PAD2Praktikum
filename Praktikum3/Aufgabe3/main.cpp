/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 9. Mai 2014, 16:15
 */

#include "frame.h"
#include "triangle.h"
#include "circle.h"

/*
 * 
 */
int main() {
    try {
        Frame test;

//        Line L(1, 10, 5, 10); //test ok
//        L.draw(&test);
//        Rectangle R(0, 4, 7, 3); // test ok
//        R.draw(&test);
//        Triangle T(0, 0, 10, 10, 20, 20); //test ungueltiges dreieck: ok
//        T.draw(&test);
//        Triangle T(8, 1, 8, 5, 12, 5); //test ok
//        Line L(1,1, 5, 5);
//        T.draw(&test);
//        Rectangle R(0, 1, 2, 3); // test ok
//        R.draw(&test);
        
        Circle C1(15, 15, 10);
        Circle C2(11, 11, 2);
        Circle C3(19,11,2);
        
        Line L1(8, 18, 12, 20);
        Line L2(22, 18, 18, 20);
        Line L3(12, 20, 18, 20);
        
        Triangle T1(5, 15, 1, 11, 1, 19);
        Triangle T2(25, 15, 29, 11, 29, 19);
        
        show_all_shapes(&test); // test ok

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

