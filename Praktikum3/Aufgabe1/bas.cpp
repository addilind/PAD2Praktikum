#include "bas.h"

Bas* Bas::last = 0; // static Datenmember initialisieren 

Bas::Bas() : name("NoName"), next(last) {
    last = this;
} //standartkonstruktor (erzeugt leere Liste)

Bas::Bas(string sname) : name(sname), next(last) {
    last = this;
}

string Bas::getName() const {
    return name;
}

Bas* Bas::getNext() const {
    return next;
}

Bas* Bas::getLast() const {
    return last;
}

string Bas::setName(string sname) {
    name = sname;
    return name;
}
