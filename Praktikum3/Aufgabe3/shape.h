/* 
 * File:   shape.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 11. Mai 2014, 09:27
 */

#include "frame.h"

#ifndef SHAPE_H
#define	SHAPE_H

//----- Shape-Klasse (Basis) -----

class Shape {
public:

    Shape() : prev(last) {
        last = this;
    } // Definition Standardkonstruktor
    virtual void draw(Frame* ptarget) = 0; // rein virtuelle Methode
    virtual void move(int hor, int ver) = 0; // rein virtuelle Methode

    static Shape* getLast(){
        return last;
    }

    Shape* getPrev() const {
        return prev;
    }

private:
    static Shape* last; // Zeiger auf die zuletzt erzeugte Figur (d.h. Listenanfang)
    Shape* prev; // Zeiger auf die zuvor erzeugte Figur (d.h. die naechste in der Liste) 
};
Shape* Shape::last = 0; // initialisiert den staticMember mit dem Nullzeiger

void show_all_shapes(Frame* p) { // gibt alle Shape Objekte auf Frame* aus
    for (Shape* pB = Shape::getLast(); pB; pB = pB->getPrev()) {
        pB->draw(p);
        cout << endl;
    }
    cout << endl;
}

bool proof_points(int sx, int sy, int ex, int ey) { //Ueberprueft ob Start und Endpunkte gleich sind
    if ((sx == ex) && (sy == ey)) {
        return true;
    } else {
        return false;
    }
}



#endif	/* SHAPE_H */

