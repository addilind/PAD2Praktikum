/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 7. Mai 2014, 20:18
 */

#include "frame.h"

/*
 * 
 */
int main() {
    try {
        Frame test;
        Line linientest;
        //Linie (gerade)
        int sx = 34;
        int sy = 1;
        int ex = 34;
        int ey = 20;
        
        int sx3 = 35;
        int sy3 = 20;
        int ex3 = 35;
        int ey3 = 1;
        
        //Linie (diagonal)
        int sx1 = 34;
        int sy1 = 1;
        int ex1 = 20;
        int ey1 = 20;
        
        int sx2 = 20;
        int sy2 = 1;
        int ex2 = 34;
        int ey2 = 20;
        
        int sx4 = 0;
        int sy4 = 0;
        int ex4 = 55;
        int ey4 = 55;
        
        
        test.put_point(36, 1);
        test.put_point(36, 2);
        test.put_point(36, 3);
        test.put_point(36, 4);
        test.put_point(36, 5);
        test.put_point(36, 6);
        
        linientest.draw(sx, sy, ex, ey, test); //gerade Linie (von links nach rechts)
        linientest.draw(sx3, sy3, ex3, ey3, test); //gerade Linie (von rechts nach links)
        linientest.draw(sx1, sy1, ex1, ey1, test); //Diagonal (von links nach rechts) sich ueberschneidend mit test3
        linientest.draw(sx2, sy2, ex2, ey2, test); //Diagonal (von rechts nach links), test3
      //  bresenham(sx, sy, ex, ey, test); //Punkt, der nicht auf dem Frame liegt
        linientest.draw(sx4, sy4, ex4, ey4, test);
        
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

