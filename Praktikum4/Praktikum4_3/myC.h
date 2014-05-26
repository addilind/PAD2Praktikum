/* 
 * File:   myC.h
 * 
 * v1.0 150514 - TW & RJ
 * 
 * Header fuer die Klasse myC
 */

#ifndef MYC_H
#define	MYC_H

#include <string>

using std::string;

class myC {
public:
    myC(); // Standardkonstruktor
    myC(string,double); // Konstruktor
    // Methode
    double operator*(double)const;
private:
    // Membervariablen
    string name;
    double wert;

};

#endif	/* MYC_H */

