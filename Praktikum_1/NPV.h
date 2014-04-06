/* 
 * File:   NPV.h
 * Author: Dorothee Mueller-Ahlheim
 *
 * Created on 17. Maerz 2014, 09:14
 * Headerfile: Deklarationen
 */

#include <vector>
#include <stdexcept>
#include <math.h>
#include <ctime>

using std::vector;


#ifndef NPV_H
#define	NPV_H

class NPV {
public:
    /**********************  Konstruktoren  **********************/
    NPV();																//Standardkonstruktor
    explicit NPV(const double interestRate);							//weiterer Konstruktor, uebernimmt Zinzsatz
    NPV(vector<long double> investments, const double interestRate);	//weiterer Konstruktor, uebrnimmt gegebene Daten
    explicit NPV(size_t randomCount);									//weiterer Konstruktor, generiert Anzahl zufaelliger Daten
    
    /********************** Getter / Setter **********************/
	const double& get_irate() const;
    void set_irate(const double& interestRate);

    const vector<long double>& get_inv() const;
    void add_inv(long double investment);
    
    /**********************    Methoden     **********************/
    const long double reckoning() const; //Berechnet Kapitalwert
	const long double reckoning(const size_t& roundPrecision) const; //Gibt gerundeten Kapitalwert zurueck

private:
	/********************** Membervariablen **********************/
    vector<long double> inv;
    double irate;
};
#endif	/* NPV_H */
