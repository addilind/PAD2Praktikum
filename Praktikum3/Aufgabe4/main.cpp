/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 4. Mai 2014, 15:42
 */

#include <iostream>
#include "myvector.h"

using std::endl;
using std::cerr;

/*
 * 
 */

//void tf(const myVec&, myVec&);

int main() {
    try {


        myVec vv(1, 10); // Index von 1 bis 10 // vv(-3,6) geht z.B. auch
        for (int i = 1; i <= 10; ++i) { // probieren Sie einige Werte au
            vv[i] = static_cast<double> (i);
            std::cout << vv[i] << '\n';
        }
        myVec vv1(1, 5); // Index von 1 bis 10 // vv(-3,6) geht z.B. auch
        for (int i = 1; i <= 10; ++i) { // probieren Sie einige Werte au
            vv1[i] = static_cast<double> (i);
            std::cout << vv1[i] << '\n';
        }

        myVecstd vv2(-3, 6); // Index von 1 bis 10 // vv(-3,6) geht z.B. auch
        for (int i = -3; i <= 6; ++i) { // probieren Sie einige Werte au
            vv2[i] = static_cast<double> (i);
            std::cout << vv2[i] << '\n';
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

//void tf(const myVec& rcmv, myVec& rmv) {
//    //rcmv[1] = 4.2;      // Fehler, wie es auch sein soll
//    double d1 = rcmv[1]; // die const-Version []
//    rmv[1] = 0.7; // die nicht-const-Version []
//    double d2 = rmv[1]; // die nicht-const-Version []
//}