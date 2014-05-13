#include "derived.h"

Pro::Pro() : gender(true), age(0) {
}

Pro::Pro(string sname, bool bgender, int iage) : Bas(sname), gender(bgender), age(iage) {
    if (age < 0) {
        throw std::runtime_error("ungueltiges Alter!\n");
    }
}

bool Pro::get_gen() const {
    return gender;
}

int Pro::get_age() const {
    return age;
}

void Pro::set_age(int iage){
    if (iage < 0) {
        throw std::runtime_error("ungueltiges Alter!\n");
    }
    age=iage;
}

void Pro::print() const {
    if (age < 0) {
        throw std::runtime_error("ungueltiges Alter!\n");
    }
    if (gender == false) {
        cout << "Name: " << getName() << " Geschlecht: maennlich Alter: " << age << endl;
    } else {
        cout << "Name: " << getName() << " Geschlecht: weiblich Alter: " << age  << endl;
    }
     
}

Roo::Roo() : color("default"), price(0){
}

void Roo::set_price(int iprice){
    if (iprice < 0) {
        throw std::runtime_error("ungueltiges Alter!\n");
    }
    price=iprice;
}

Roo::Roo(string sname, string scolor, int iprice) : Bas(sname), color(scolor), price(iprice) {
    if(price < 0){
        throw std::runtime_error("ungueltiger Preis!\n");
    }
}

void Roo::print() const {
    if(price < 0){
        throw std::runtime_error("ungueltiger Preis!\n");
    }
    cout << "Name: " << getName() << " Farbe: " << color << " Preis: " << price << endl;
    
}