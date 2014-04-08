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
#include <stdlib.h>

using std::vector;


#ifndef NPV_H
#define	NPV_H

class NPV {
public:
    /**********************  Konstruktoren  **********************/
    NPV(); //Standardkonstruktor
    explicit NPV(const double interestRate); //explicit verbietet dem Compiler implizite Typumwandlung, weiterer Konstruktor, uebernimmt Zinzsatz
    NPV(vector<long double> investments, const double interestRate); //weiterer Konstruktor, uebernimmt gegebene Daten
    explicit NPV(size_t randomCount);	//explicit verbietet dem Compiler implizite Typumwandlung, weiterer Konstruktor, generiert Anzahl zufaelliger Daten
    
    /********************** Getter / Setter **********************/
    const double& get_irate() const; //Referenz, weil Wert nicht kopiert werden muss; const -> kann und darf nicht geändert werden.
    void set_irate(const double& interestRate); //Übergabe einer Referenz

    const vector<long double>& get_inv() const; //const hinter Parameterliste garantiert, dass Methode das Objekt nicht verändert. Wird einmal vom Konstruktor initialisiert danach nicht mehr sondern konstant.
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
