/* 
 * File:   main.cpp
 * Author: Doro
 *
 * Created on 1. April 2014, 14:42
 */

#include "myvector.h"
#include <iostream>
#include <string>

using std::string;

/*
 * 
 */

template<class T> void testfunction(myVector<T>& test, const T& val, const T& halla);

int main() {

    try {

        myVector<string> testS;
        myVector<char> testC;
        myVector<int> testI;
        myVector<double> testD;
        

        testfunction<string> (testS, "abc", "def");
        testfunction<char> (testC, 'a', 'b');
        testfunction<int> (testI, 1, -2);
        testfunction<double> (testD, 1.3, -2.5);

        //        myVec vv(1, 10); // Index von 1 bis 10 // vv(-3,6) geht z.B. auch
        //        for (int i = 1; i <=10; ++i) { // probieren Sie einige Werte au
        //            vv[i] = static_cast<double> (i);
        //            std::cout << vv[i] << '\n';
        //        }
        //        
        //        myVecstd vv2(-3, 6); // Index von 1 bis 10 // vv(-3,6) geht z.B. auch
        //        for (int i = -3; i <=6; ++i) { // probieren Sie einige Werte au
        //            vv2[i] = static_cast<double> (i);
        //            std::cout << vv2[i] << '\n';
        //        }


        return 0;
    } catch (std::exception& e) {
        std::cerr << "Ausnahme: " << e.what() << std::endl;
        return -2;
    } catch (...) {
        std::cerr << "Unbekannte Ausnahme: " << std::endl;
        return -1;
    }

}

template<class T> void testfunction(myVector<T>& test, const T& val, const T& halla) {
    
    test.push_back(val);
    test.push_back(halla);
    test.push_back(halla);
    
    myVector<T> testcopy;
    testcopy = myVector<T>(test); //Test Zuweisungsoperator und Copykonstruktor
    
    for(size_t i(0U); i<test.size(); i++){
        std::cout << "Vektorinhalt: '" << test[i] << "'; ";
        std::cout << "Kopierter Vektorinhalt: '" << testcopy[i] << "'" << std::endl;
    }
        
    std::cout << "Wert am Index 2: " << test.get(2) << std::endl;
    test.set(2, val);
    std::cout << "Wert am Index 2 nach set(): " << test.get(2) << std::endl;
    std::cout << "Wert am Index 1: " << test[1] << std::endl;
    std::cout << "Wert am Index 0: " << test.get(0) << std::endl;
    std::cout << "Wert am Index 1 mit at(): " << test.at(1) << std::endl;
    std::cout << "Vektorgroesse: " << test.size() << std::endl;
    std::cout << "Vektorkapazitaet: " << test.capacity() << std::endl;
    test.resize(15);
    std::cout << "Vektorgroesse nach resize(): " << test.size() << std::endl;
    std::cout << "Vektorkapazitaet nach resize(): " << test.capacity() << std::endl;
    test.reserve(20);
    std::cout << "Vektorkapazitaet nach reverse(): " << test.capacity() << std::endl;
    
}