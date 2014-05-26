/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:41
 */
#include <vector>
#include <stdexcept>
#include <iostream>
#include "myC.h"

using std::cerr;
using std::endl;

template<class T, class U>
std::vector<T> multiply(std::vector<T> vt, std::vector<U> vu) {
    if (vu.size() != vt.size()) {
        throw std::runtime_error("Ungueltige Vektoren!");
    }
    std::vector<T> result;
    typename std::vector<U>::iterator right = vu.begin();
    for (typename std::vector<T>::iterator left = vt.begin();
            left != vt.end();
            ++left) {
        result.push_back((*left) * (*right));
        ++right;
    }
    return result;
}

template<class T, class U>
T sumprod(std::vector<T> vt, std::vector<U> vu, T init = T()) {
    T sum = init;
    std::vector<T> products = multiply(vt, vu);
    for (typename std::vector<T>::iterator iter = products.begin(); iter != products.end(); ++iter) {
        sum = (sum + *iter);
    }
    return sum;
}

int main() {
    try {

        std::vector<myC> vi0;
        std::vector<int> vi1;

        vi0.push_back(myC("hallo"));
        vi0.push_back(myC("welt"));
        vi0.push_back(myC("!"));
        vi1.push_back(2);
        vi1.push_back(3);
        vi1.push_back(1);

        std::cout << sumprod(vi0, vi1, myC("")).get_wert() << endl;
        

        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

