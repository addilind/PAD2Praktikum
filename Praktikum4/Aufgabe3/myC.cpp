
#include "myC.h"
#include <sstream>

// Standardkonstrukor

myC::myC() : wert("unbekannt") {
}

// Konstruktor

myC::myC(string val) : wert(val) {
}

string myC::get_wert()const{
    return wert;
}


myC myC::operator*(const int& times) const{
    std::stringstream ss; //wie ein ausgabestrom
    for(int i = 0; i < times; i++)
        ss << wert;
    return myC(ss.str()); //gibt einen String in einem myC verpackt zurück
}
myC myC::operator+(const myC& other) const{
    std::stringstream ss;
    ss << wert << other.wert; //verkettet beide Werte
    return myC(ss.str()); //gibt einen String in einem myC verpackt zurück
}