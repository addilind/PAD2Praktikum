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


void show_all_shapes(Frame* p);
bool proof_points(int sx, int sy, int ex, int ey);



#endif	/* SHAPE_H */

