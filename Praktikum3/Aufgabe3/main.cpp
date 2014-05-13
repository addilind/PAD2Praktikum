/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 9. Mai 2014, 16:15
 */

#include "frame.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"

/*
 * 
 */
int main() {
    try {
        Frame test;

//        Line L(1, 10, 5, 10); //startpunkt(1,10) - endpunkt(2,10) test ok
//        L.draw(&test);
//        Rectangle R(0, 4, 5, 7); //startpunkt(0,4) - endpunkt(4,7) test ok
//        R.draw(&test);
//        Triangle T(0, 0, 10, 10, 20, 20); //test ungueltiges dreieck: ok
//        T.draw(&test);
//        Triangle T1(8, 1, 8, 5, 12, 5); //test ok
//        T1.draw(&test);
//        Line L1(10,10, 0, 0);
//        L1.draw(&test);
//        Rectangle R1(0, 1, 2, 3); // test ok
//        R.draw(&test);
//        Circle C(5, 5, 2);
//        C.draw(&test);
//        Circle C4(34, 34, 10); //Fehler
//        Triangle T2(0, 0, 5, 10, 18); //Fehler test ok
//        Triangle T2(0, 0, 5, 5, 5); //test ok
//        Triangle T2(10, 10, 15, 14, 5); //test ok
//        T2.draw(&test);
//        Triangle T3(10,10,30,10,15,15);
        
        
//        Triangle T5(8,3,9,3,10,3);
//        cout << get_hypotenuse(12, 9, 5) << endl;
//        cout << proof_Triangle(0,0, 8,3, 10,14) << endl;
//        cout << proof_Triangle(0,0, 0,0, 10,14) << endl;
//        cout << proof_length(12,12,12);
//        cout << proof_length(-12,-12,-12);
//        cout << proof_length(12,2,2);
//        cout << get_height(5, 9, 12) << endl;
//        cout << get_x(5, 9, 12) << endl;
        
        Circle C1(15, 15, 10);
        Circle C2(11, 11, 2);
        Circle C3(19,11,2);
//        
//        Line L1(8, 18, 12, 20);
//        Line L2(22, 18, 18, 20);
//        Line L3(12, 20, 18, 20);
//        
//        Triangle T1(5, 15, 1, 11, 1, 19);
//        Triangle T2(25, 15, 29, 11, 29, 19);
//        
        
//        Line L(0,0, 20,0);
//        Line L2(0,0, 0, 20);
//        Line L3(0,0,20,20);
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

