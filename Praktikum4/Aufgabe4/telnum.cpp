#include "telnum.h"
#include <stdexcept>
#include <sstream>


// ------Telnum-Klasse------

Telnum::Telnum() //Standartkonstruktor
: telnr("0123456789") {
}

Telnum::Telnum(string stelnr, string sfname, string slname, string sstreet, int ihnr, int ipc, string slocation)
: telnr(stelnr), fname(sfname), lname(slname), street(sstreet), hnr(ihnr), pc(ipc), location(slocation) {
    set_telnum(stelnr); //ueberpruefen auf Gueltigkeit der Telefonnumer
    set_pc(ipc); //ueberpruefen auf Gueltigkeit der Plz
}

string read_string(std::ifstream& source){
    std::stringstream buf;
    char c = 0;
    source >> c;
    while(c != '\0')
    {
        buf << c;
        source >> c;
    }
    return buf.str();
}

void Telnum::save_to(std::ofstream& target){
    target << telnr << '\0';
    target << fname << '\0';
    target << lname << '\0';
    target << street << '\0';
    target << hnr << '\0';
    target << pc << '\0';
    target << location << '\0';
}

Telnum Telnum::read_from(std::ifstream& source){
    Telnum result;
    result.telnr = read_string(source);
    result.fname = read_string(source);
    result.lname = read_string(source);
    result.street = read_string(source);
    source >> result.hnr;
    source.get(); //0-Trennbyte
    source >> result.pc;
    source.get(); //0-Trennbyte
    result.location = read_string(source);
    return result;
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
    }
    return false;
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
    }
    return false;
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