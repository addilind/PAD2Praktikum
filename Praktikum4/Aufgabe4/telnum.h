/* 
 * File:   telnum.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 22. Mai 2014, 15:34
 */

#ifndef TELNUM_H
#define	TELNUM_H

#include <string>
using std::string;

class Telnum {
public:
    Telnum(); //Standardkonstruktor
    Telnum(string stelnr, string sfname = "Unbekannter", string slname = "Verehrer", string sstreet = "", int ihnr = 0, int ipc = 0, string slocation = ""); //weiterer Konstruktor 

    string get_telnum()const; //getter
    void set_telnum(string stelnr); //setter
    
    string get_fname()const; //getter
    string get_lname()const;
    string get_street()const;
    int get_hnr()const;
    int get_pc()const;
    string get_location()const;

    void set_fname(string sfname); //setter
    void set_lname(string slname);
    void set_street(string sstreet);
    void set_hnr(int ihnr);
    void set_pc(int ipc);
    void set_location(string location);

private:
    string telnr; //Anzahl der Möglichkeiten für eine Telefonnummer
    bool proof_digit(char cdigit);
    bool first_digit(char cdigit);
    string fname;
    string lname;
    string street;
    int hnr;
    int pc;
    string location;
};

#endif	/* TELNUM_H */

