/* 
 * File:   bas.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 5. Mai 2014, 20:29
 */

#ifndef BAS_H
#define	BAS_H

#include <stdexcept>
#include <string>
#include <iostream>

using std::endl;
using std::cerr;
using std::cout;
using std::string;

class Bas {
public:

    Bas() : name("NoName"), next(last) {
        last = this;
    } //standartkonstruktor (erzeugt leere Liste)

    explicit Bas(string sname) : name(sname), next(last) {
        last = this;
    }

    //----- Getter -----

    string getName() const {
        return name;
    }

    Bas* getNext() const {
        return next;
    }

    Bas* getLast() const {
        return last;
    }

    //----- Setter -----

    string setName(string sname) {
        name = sname;
    }

    virtual void print() const = 0; //rein virtuelle Methode, also abstrakte Klasse, da mit '=0' inititalisiert
    //virtual void print() const { cout << name; } // virtuelle Methode, dann polymorphe Klasse 
    //void print() const { cout << name; }

private:
    string name;
    Bas* next;
    static Bas* last;
};
Bas* Bas::last = 0; // static Datenmember initialisieren 

class Pro : public Bas {
public:

    Pro() : gender(true) {
    }

    Pro(string sname, bool bgender) : Bas(sname), gender(bgender) {
    }
    void print() const;
private:
    bool gender;

};

void Pro::print() const {
    if (gender == false) {
        cout << "Name: " << getName() << " Geschlecht: maennlich" << endl;
    }
    cout << "Name: " << getName() << " Geschlecht: weiblich" << endl;
}

class Roo : public Bas {
public:
    
    Roo() : age(0){}
    Roo(string sname, int iage): Bas(sname), age(iage) {}
    
    void print() const;
    
private:
   int age;

};

void Roo::print() const {
    if(age > 0){
    cout << "Name: " << getName() << " Alter: " << age << endl;
    }
    throw std::runtime_error("ungueltiges Alter!\n");
}

#endif	/* BAS_H */

