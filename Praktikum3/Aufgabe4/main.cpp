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

void tf(const myVec& rcmv, myVec& rmv) {
    //rcmv[1] = 4.2;      // Fehler, wie es auch sein soll
    double d1 = rcmv[1]; // die const-Version []
    rmv[1] = 0.7; // die nicht-const-Version []
    double d2 = rmv[1]; // die nicht-const-Version []
}

int main() {
    try {

        // ----- Positiv-Tests -----
        myVec vv1(1, 10); // Index von 1 bis 10 // vv(-3,6) geht z.B. auch
        for (int i = 1; i <= 10; ++i) { // probieren Sie einige Werte aus
            vv1[i] = static_cast<double> (i);
            std::cout << vv1.at(i) << '\n';
        }
        std::cout << "----------Ende Test1\n";
        myVec vv2(-3, 6); // Index von -3 bis 6
        for (int i = -3; i <= 6; ++i) {
            vv2[i] = static_cast<double> (i);
            std::cout << vv2[i] << '\n';
        }
        std::cout << "----------Ende Test2\n";
        myVec vv3(10, 30); //index von 10 bis 20
        for (int i = 10; i <= 30; ++i) {
            vv3[i] = static_cast<double> (i);
            std::cout << vv3[i] << '\n';
        }
        std::cout << "----------Ende Test3\n";
        myVec vv4(5, 10); //index von 5 bis 10
        for (int i = 5; i <= 10; ++i) {
            vv4[i] = static_cast<double> (i);
            std::cout << vv4[i] << '\n';
        }
        std::cout << "----------Ende Test4\n";
        myVec vv5(1, 5); // Aufruf Konstruktor

        myVec copy(vv1); //Aufruf Copy-Konstruktor
        for (int i = 1; i <= 10; ++i) {
            std::cout << copy[i] << '\n';
        }
        std::cout << "----------Ende Test5\n";
        copy = vv2;
        for (int i = -3; i <= 6; ++i) {
            std::cout << copy[i] << '\n';
        }
        std::cout << "----------Ende Test6\n";
        myVec vv9(-15, -10); //wird ausgefuehrt
        for (int i = -15; i <= -10; ++i) {
            vv9[i] = static_cast<double> (i);
            std::cout << vv9[i] << '\n';
        }
        std::cout << "----------Ende Test7\n";
        // ----- negativ-Tests -----
        myVec vv6(2, 1); //Fehler1
//        myVec vv7(1, 10); //kein Fehler aber nur die haelfte der ausgabe
//        for (int i = 5; i <= 10; ++i) {
//            vv7[i] = static_cast<double> (i);
//            std::cout << vv7[i] << '\n';
//      }
//        myVec vv8(1, 10);//wirft keinen Fehler aber läuft nur bis zur haelfte
//        for (int i = 1; i <= 5; ++i) {
//            vv8[i] = static_cast<double> (i);
//            std::cout << vv8[i] << '\n';
//        }
//        myVec vv10(1, 5);//Fehler
//        for (int i = 1; i <= 10; ++i) {
//            vv10[i] = static_cast<double> (i);
//            std::cout << vv10[i] << '\n';
//        }
//        myVec vv11(-5, -1); //Fehler
//        myVec vv12(10, -1); //Fehler
//        myVec vv11(1, -1); //Fehler


        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

