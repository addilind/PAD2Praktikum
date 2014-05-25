#include "telnum.h"
#include <stdexcept>


// ------Telnum-Klasse------

Telnum::Telnum() //Standartkonstruktor
: telnr("0123456789") {
}

Telnum::Telnum(string stelnr, string sfname, string slname, string sstreet, int ihnr, int ipc, string slocation)
: telnr(stelnr), fname(sfname), lname(slname), street(sstreet), hnr(ihnr), pc(ipc), location(slocation) {
    set_telnum(stelnr); //ueberpruefen auf Gueltigkeit der Telefonnumer
    set_pc(ipc); //ueberpruefen auf Gueltigkeit der Plz
}

string Telnum::get_telnum()const {
    return telnr;
}

bool Telnum::proof_digit(char cdigit) {
    switch (cdigit) {
        case ' ':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            false;
    }
}

bool Telnum::first_digit(char cdigit) {
    switch (cdigit) {
        case '+':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            false;
    }
}

void Telnum::set_telnum(string stelnr) {
    if (stelnr.size() == 0) {
        throw std::runtime_error("Keine Telefonnummer!\n");
    }
    if (first_digit(stelnr[0]) == false) {
        throw std::runtime_error("Ungueltige Telefonnummer!\n");
    }
    for (int i = 1; i < stelnr.size(); i++) {
        if (proof_digit(stelnr[i]) == false) {
            throw std::runtime_error("Ungueltige Telefonnummer!\n");
        }
    }
    telnr = stelnr;
}

string Telnum::get_fname() const{
    return fname;
}

string Telnum::get_lname() const{
    return lname;
}

string Telnum::get_street() const{
    return street;
}

int Telnum::get_hnr()const {
    return hnr;
}

int Telnum::get_pc()const {
    return pc;
}

string Telnum::get_location()const {
    return location;
}

void Telnum::set_fname(string sfname) {
    fname = sfname;
}

void Telnum::set_lname(string slname) {
    lname = slname;
}

void Telnum::set_street(string sstreet) {
    street = sstreet;
}

void Telnum::set_hnr(int ihnr) {
    hnr = ihnr;
}

void Telnum::set_pc(int ipc) {
    if (ipc >= 99999) {
        throw std::runtime_error("Ungueltige Postleitzahl");
    }
    pc = ipc;
}

void Telnum::set_location(string slocation) {
    location = slocation;
}