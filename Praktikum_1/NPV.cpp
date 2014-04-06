/* 
 * File:   NPV.cpp
 * Author: Dorothee Müller-Ahlheim
 * 
 * Created on 17. März 2014, 09:14
 * Cppfile: Definitionen
 */

#include "NPV.h"
#include <ctime>
#include <cstdlib>


//Standartkonstruktor

NPV::NPV()
: inv(),
irate(0.10) {
}

//Weiterer Konstruktor

NPV::NPV(vector<long double> vinv, const double dirate)
: inv(vinv),
irate(dirate) {
}


NPV::NPV(size_t number) {
    irate = (rand() % 5000) / 10000.0;
    cout << "Zinzsatz: " << irate << endl;
    long double value = 0.0;
    for (size_t i = 0; i < number; i++) {
        value = ((rand() % 10000) - 5000);
        cout << "Wert: " << static_cast<double> (value) << endl;
        inv.push_back(value);
    }
}

const double NPV::get_irate() const { //getter für irate
    return irate;
}

const vector<long double>& NPV::get_inv() const { //getter für den Vektor
    return inv;
}
/* Klasse hat jetzt alles was sie zur berechnung braucht, da sie eine Methode und keine supportfunktion mehr ist
 * Die Werte kommen jetzt aus den Membervariablen und müssen nicht mehr als PArameter übergeben werden.
 */
long double NPV::reckoning() { //Berechnung des Kapitalwertes npv = C0
    long double npv(0.0);
    for (size_t i(0); i < inv.size(); i++) {
        //std::cout << static_cast<double>(inv.at(i)) << "/" <<(pow((1 + irate), i)) << std::endl;
        npv += inv.at(i) / (pow((1 + irate), i));
    }
    return npv;
}

void NPV::add_inv(long double value) {
    inv.push_back(value);
}