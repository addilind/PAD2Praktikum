/* 
 * File:   myC.cpp
 * 
 * v1.0 150514 - TW & RJ
 * 
 * Klasse fuer myC
 */

#include "myC.h"

// Standardkonstrukor
myC::myC() : name("unbekannt"), wert(0.0) {
}

// Konstruktor
myC::myC(string nam, double val) : name(nam), wert(val) {
}

// * Operator
double myC::operator *(double m) const {
    double k = 0.0;
    k = wert*m;
    return k;
}