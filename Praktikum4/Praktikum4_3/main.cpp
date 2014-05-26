/* 
 * File:   main.cpp
 * 
 * v1.0 150514 - TW & RJ
 * 
 * Treiber zur Klasse myC. Bildet das innere Produkt und addiert die Werte.
 */

// Einbinden von...
#include "myC.h"
#include <vector>
#include <iostream>

// Benutzen von...
using std::vector;
using std::cout;
using std::endl;
using std::cerr;

/**
 * Bildet das innere Produkt
 * @param first Start des ersten Iterators
 * @param last Ende des ersten Iterators
 * @param first2 Start vom 2ten Iterator
 * @param init Startwert
 * @return  Der Zusammengerechnete Wert
 */
template<class IterIn, class IterIn2, class T>T inner_product(IterIn first,
        IterIn last, IterIn2 first2, T init) {
    // Multiplikation von zwei Sequenzen (zu einem Wert)
    while (first != last) {
        // Multiplikation von Elementpaaren, und Summierung
        init = init + (*first2)* (*first);
        ++first;
        ++first2;
    }
    return init;
}

/**
 * 
 * @param vT Erster Vektor
 * @param vU Zweiter Vektor
 * @return gibt die Summe aus
 */
template<class T, class U>T sum(vector<T> vT, vector<U> vU) {
    T sum = inner_product(vT.begin(), vT.end(), vU.begin(), T());
    return sum;
}

void test();

/*
 * 
 */
int main() try{
    return 0;
}
catch(...){
    cerr<<"Sonstiger Fehler"<<endl;
    return -1;
}

void test() {
    vector<int> test;
    vector<int> test2;
    test.push_back(1);
    test.push_back(8);
    test.push_back(9);

    test2.push_back(4);
    test2.push_back(3);
    test2.push_back(5);

    cout << sum(test, test2) << "\n";

    vector<myC> test_C;
    test_C.push_back(myC("a", 4.0));
    test_C.push_back(myC("b", 3.0));
    test_C.push_back(myC("c", 5.0));

    cout << sum(test, test_C) << "\n";
}