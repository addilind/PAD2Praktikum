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
    Bas();
    explicit Bas(string sname);

    //----- Getter -----

    string getName() const;
    Bas* getNext() const;
    Bas* getLast() const;

    //----- Setter -----

    string setName(string sname);

    virtual void print() const = 0; //rein virtuelle Methode, also abstrakte Klasse, da mit '=0' inititalisiert

private:
    string name;
    Bas* next;
    static Bas* last;
};



#endif	/* BAS_H */

