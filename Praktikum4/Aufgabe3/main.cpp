/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:41
 */

#include <iostream>
#include <stdexcept>
#include "myvector.h"

using std::endl;
using std::cerr;

/*
 * 
 */

void tempfunc(myVector<T> vt, myvector<U> vu);


int main() {
    try {

        void tempfunc(myVector<T> vt, myvector<U> vu) {
            
        }

        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

