/* 
 * File:   myC.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 26. Mai 2014, 09:59
 */

#ifndef MYC_H
#define	MYC_H

#include <string>

using std::string;

class myC {
public:
    myC(); // Standardkonstruktor
    myC(string); // Konstruktor
    
    string get_wert () const;
    
    myC operator*(const int& times) const;
    myC operator+(const myC& other) const;
    
private:
    // Membervariablen
    string wert;

};


#endif	/* MYC_H */

