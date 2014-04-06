/* 
 * File:   NPV.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 17. März 2014, 09:14
 * Headerfile: Deklarationen
 */

#include <vector>
#include <iostream>
#include <stdexcept>
#include "math.h"
#include <string>
#include <ctime>
#include <cstdlib>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;


#ifndef NPV_H
#define	NPV_H

class NPV {
public:
    NPV(); //Standartkonstruktor
    NPV(vector<long double>, const double); //weiterer Konstruktor
    NPV(size_t);
    const double get_irate() const;
    const vector<long double>& get_inv() const;
        
    long double reckoning();
    void add_inv(long double);

private:
    vector<long double> inv;
    double irate;

};
#endif	/* NPV_H */

