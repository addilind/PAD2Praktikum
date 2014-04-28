/* 
 * File:   myArray.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 27. April 2014, 18:54
 */

#ifndef MYARRAY_H
#define	MYARRAY_H

#include <stdexcept>

template< class T, int N > class myArray {
public:

    myArray() { //Standartkonstruktor
        for (size_t i(0U); i < N; ++i) {
            elem[i] = T();
        }
    }

    myArray(T t) { //weiterer konstruktor
        for (size_t i(0U); i < N; ++i) {
            elem[i] = t;
        }
    };

    myArray(const myArray& r) { //copy-konstruktor
        *this = r;
    };

    myArray<T, N>& operator =(const myArray<T, N>& r) {
        for (size_t i(0U); i < N; ++i) {
            elem[i] = r.elem[i];
        }
        return *this;
    };

    explicit myArray(const T& t) {
        for (size_t i = 0U; i < N; ++i) {
            elem = t;
        }
    };
    
    T& operator[](int n) { //Indexoperator (ohne ueberpruefung)
//        if (n < 0 || N <= n){
//            throw std::runtime_error("myArray::operator[](), bad index");
//        }
        return elem[n];
    }
    const T& operator[](int n) const { //Indexoperator
//        if (n < 0 || N <= n){
//            throw std::runtime_error("myArray::operator[](), bad index");
//        }
        return elem[n];
    }
    
    T& at(size_t n){ //Indexzugriff (mit ueberpruefung)
        if (n < 0 || N <= n){
            throw std::runtime_error("myArray::operator[](), bad index");
        }
        return elem[n];
    }
    
    T* dataPtr (int n){ //datapointer gibt pointer auf element zurück statt element selbst
        if (n < 0 || N <= n){
            throw std::runtime_error("myArray::operator[](), bad index");
        }
        return &elem[n];
    }
    
    const T* dataPtr (int n) const{
        if (n < 0 || N <= n){
            throw std::runtime_error("myArray::operator[](), bad index");
        }
        return &elem[n];
    }

    int size() const { //groesse
        return N;
    }

private:
    T elem[N];
};





#endif	/* MYARRAY_H */

