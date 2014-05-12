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

//        Line L(1, 10, 5, 10); //test ok
//        L.draw(&test);
//        Rectangle R(0, 4, 7, 3); // test ok
//        R.draw(&test);
//        Triangle T(0, 0, 10, 10, 20, 20); //test ungueltiges dreieck: ok
//        T.draw(&test);
        Triangle T(8, 1, 8, 5, 12, 5); //test ok
        Line L(1,1, 5, 5);
//        T.draw(&test);
//        Rectangle R(0, 1, 2, 3); // test ok
//        R.draw(&test);
        
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

