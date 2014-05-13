#include "telnum.h"
#include <stdexcept>

Telnum::Telnum() //Standartkonstruktor
: digit('0') {
}

Telnum::Telnum(char cdigit) //weiterer Konstruktor
: digit(cdigit) {
}

char Telnum::get_digit() {
    return digit;
}

std::string Telnum::build_telnum(char cdigit) {
    std::string telnum = "leer";
    if (proof_digit(cdigit) == false) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }
    for(int i(0); i<50; ++i){
        if(i == 0){
            telnum += first_digit(cdigit);
        }
        telnum += cdigit;
    }
    return telnum;    
}

bool Telnum::proof_digit(char cdigit) {
    switch (cdigit) {
        case '+':
            return true;
        case ' ':
            return true;
        case '0':
            return true;
        case '1':
            return true;
        case '2':
            return true;
        case '3':
            return true;
        case '4':
            return true;
        case '5':
            return true;
        case '6':
            return true;
        case '7':
            return true;
        case '8':
            return true;
        case '9':
            return true;
        default:
            false;
    }
}

char Telnum::first_digit(char cdigit) {
    if (proof_digit(cdigit) == false) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }
    if(cdigit != '+' && cdigit != '0'){
        throw std::runtime_error("Ungueltige Telefonnummer!\n");
    }
    return cdigit;
}
