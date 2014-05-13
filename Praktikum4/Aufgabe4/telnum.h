/* 
 * File:   telnum.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 22. Mai 2014, 15:34
 */

#ifndef TELNUM_H
#define	TELNUM_H

#include <string>

class Telnum {
public:
    Telnum(); //Standartkonstruktor
    Telnum(char cdigit); //weiterer Konstruktor
    
    char get_digit();
    
    std::string build_telnum(char cdigit);
    bool proof_digit(char cdigit);
    char first_digit(char cdigit);
    void get_telnum();
    
private:
    char digit; //Anzahl der Möglichkeiten für eine Telefonnummer
};

#endif	/* TELNUM_H */

