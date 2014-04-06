/* 
 * File:   NPV.cpp
 * Author: Dorothee Mueller-Ahlheim
 * 
 * Created on 17. Maerz 2014, 09:14
 * Cppfile: Definitionen
 */

#include "NPV.h"

/********************** Konstruktoren **********************/
//Standardkonstruktor
NPV::NPV()
  : inv(),        //Investments-vektor leer initialisieren
    irate(0.10)    //Zinzsatz mit 10% defaultwert initialisieren
{ }

//Weiterer Konstruktor: uebernimmt Zinzsatz
NPV::NPV(const double dirate)
  : inv(),        //Investments-vektor leer initialisieren
    irate(dirate)
{
    if (dirate < 0)
        throw std::invalid_argument("Interest rate cannot be negative");
}

//Weiterer Konstruktor: uebernimmt bereits vorgegebene Daten
NPV::NPV(vector<long double> vinv, const double dirate)
  : inv(vinv),
    irate(dirate)
{
    if (dirate < 0)
        throw std::invalid_argument("Interest rate cannot be negative");
}

//Weiterer Konstruktor: generiert eine Anzahl zufaelliger Daten
NPV::NPV(size_t number) {
    srand(static_cast<size_t>(time(0))); //Zufalls-seed auf Rechnerzeit setzen

    irate = (rand() % 5000) / 10000.0;
    long double value = 0.0;
    for (size_t i = 0; i < number; i++) {
        value = ((rand() % 10000) - 5000);
        inv.push_back(value);
    }
}

/********************** Getter / Setter **********************/
const double& NPV::get_irate() const { //getter fuer irate(Zinzsatz)
    return irate;
}

void NPV::set_irate(const double& dirate) { //setter fuer irate(Zinzsatz)
    if (dirate < 0)
        throw std::invalid_argument("Interest rate cannot be negative");
    irate = dirate;
}

const vector<long double>& NPV::get_inv() const { //getter fuer den Investments-Vektor
    return inv;
}

void NPV::add_inv(long double value) { //Investment hinzufuegen
    inv.push_back(value);
}

/* Eine Instanz hat alles was sie zur Berechnung braucht,
 * da die Methode direkt auf Membervariablen zugreifen kann
 * muessen die Werte nicht als Parameter uebergeben werden
 */
const long double NPV::reckoning() const { //Berechnung des Kapitalwertes npv = C0
    long double npv(0.0);
    for (size_t i(0); i < inv.size(); i++) {
        npv += inv.at(i) / powl( (1 + irate), i );
    }
    return npv;
}

const long double NPV::reckoning(const size_t& roundPrecision) const {
    long double value = reckoning(); //Berechnung durchfuehren
    long double shift = powl(10, roundPrecision);
    //Zur Rundung auf x nachkommastellen, das Komma um x Stellen nach rechts verschieben,
    //runden und anschließend wieder zurueckverschieben
    return roundl(value * shift)/shift;
}
