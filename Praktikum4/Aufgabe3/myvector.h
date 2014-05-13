/* 
 * File:   myvector.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 20. Mai 2014, 08:45
 */

#ifndef MYVECTOR_H
#define	MYVECTOR_H

template<class T> class myVector {
public:

    myVector() : sz(0), space(0), elem(0) { //standartkonstruktor
    }

    explicit myVector(int s) : sz(s), space(s), elem(new T[s]) { //explicit verhindert implizite Typumwandlung
    } //weiterer Konstruktor

    myVector(const myVector& source) : sz(source.sz), space(source.sz), elem(new T[source.sz]) {
        for (size_t i(0U); i < sz; i++) {
            elem[i] = source.elem[i];
        }
    } //Copy-Konstruktor

    myVector& operator=(const myVector& a) { //Zuweisungsoperator
        if (this == &a) return *this;
        if (a.sz <= space) {
            for (size_t i(0); i < a.sz; i++) {
                elem[i] = a.elem[i];
            }

            sz = a.sz;
            return *this;
        }
        T* p = new T[a.sz];
        for (size_t i(0); i < a.sz; i++) {
            p[i] = a.elem[i];
        }
        delete[] elem;
        elem = p;
        space = a.sz;
        sz = a.sz;

        return *this;
    }

    virtual ~myVector() { //Destruktor
        delete[] elem;
    }

    int size() const { //Groesse
        return sz;
    }

    int capacity() const { //Kapazitaet
        return space;
    }

    T& operator[](int n) { //Indexoperator mit ueberpruefung
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::operator[](), bad index");
        return elem[n];
    }

    const T& operator[](int n) const { //Indexoperator mit ueberpruefung
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::operator[](), bad index");
        return elem[n];
    }

    T& at(int n) { //Indexoperator mit ueberpruefung
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::at(), bad index");
        return elem[n];
    }

    T get(int n) const {
        return elem[n];
    }// sog. "Getter"

    void set(int n, T v) { //
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::set(), bad index");
        elem[n] = v;
    }// sog. "Setter"

    void reserve(int newspace) { //reserve-Methode
        if (newspace <= space) return;
        T* p = new T[newspace];
        for (size_t i = 0; i < sz; ++i)
            p[i] = elem[i];
        delete[] elem;
        elem = p;
        space = newspace;
    }

    void push_back(const T& val) { //push_back-Methode
        if (space == 0) reserve(8);
        else
            if (sz == space) reserve(space * 2);
        elem[sz] = val;
        ++sz;
    }

    void resize(int newsize, T val = T()) { //resize-Methode
        reserve(newsize);
        for (size_t i = sz; i < newsize; ++i)
            elem[i] = val;
        sz = newsize;
    }

private:
    int sz;
    int space;
    T* elem;
};

template<class U> class myvector {
public:

    myvector() : sz(0), space(0), elem(0) { //standartkonstruktor
    }

    explicit myvector(int s) : sz(s), space(s), elem(new U[s]) { //explicit verhindert implizite Typumwandlung
    } //weiterer Konstruktor

    myvector(const myvector& source) : sz(source.sz), space(source.sz), elem(new U[source.sz]) {
        for (size_t i(0U); i < sz; i++) {
            elem[i] = source.elem[i];
        }
    } //Copy-Konstruktor

    myvector& operator=(const myvector& a) { //Zuweisungsoperator
        if (this == &a) return *this;
        if (a.sz <= space) {
            for (size_t i(0); i < a.sz; i++) {
                elem[i] = a.elem[i];
            }

            sz = a.sz;
            return *this;
        }
        U* p = new U[a.sz];
        for (size_t i(0); i < a.sz; i++) {
            p[i] = a.elem[i];
        }
        delete[] elem;
        elem = p;
        space = a.sz;
        sz = a.sz;

        return *this;
    }

    virtual ~myvector() { //Destruktor
        delete[] elem;
    }

    int size() const { //Groesse
        return sz;
    }

    int capacity() const { //Kapazitaet
        return space;
    }

    U& operator[](int n) { //Indexoperator mit ueberpruefung
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::operator[](), bad index");
        return elem[n];
    }

    const U& operator[](int n) const { //Indexoperator mit ueberpruefung
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::operator[](), bad index");
        return elem[n];
    }

    U& at(int n) { //Indexoperator mit ueberpruefung
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::at(), bad index");
        return elem[n];
    }

    U get(int n) const {
        return elem[n];
    }// sog. "Getter"

    void set(int n, U v) { //
        if (n < 0 || sz <= n)
            throw std::runtime_error("myVector::set(), bad index");
        elem[n] = v;
    }// sog. "Setter"

    void reserve(int newspace) { //reserve-Methode
        if (newspace <= space) return;
        U* p = new U[newspace];
        for (size_t i = 0; i < sz; ++i)
            p[i] = elem[i];
        delete[] elem;
        elem = p;
        space = newspace;
    }

    void push_back(const U& val) { //push_back-Methode
        if (space == 0) reserve(8);
        else
            if (sz == space) reserve(space * 2);
        elem[sz] = val;
        ++sz;
    }

    void resize(int newsize, U val = U()) { //resize-Methode
        reserve(newsize);
        for (size_t i = sz; i < newsize; ++i)
            elem[i] = val;
        sz = newsize;
    }

private:
    int sz;
    int space;
    U* elem;
};

#endif	/* MYVECTOR_H */

