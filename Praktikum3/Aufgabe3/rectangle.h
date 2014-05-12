/* 
 * File:   rectangle.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 11. Mai 2014, 09:28
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include "shape.h"
#include "line.h"

// ----- Rectangle-Klasse (abgeleitet von Shape) -----

bool proof_Rectangle(int, int, int, int);

class Rectangle : public Shape {
public:
    Rectangle(); // Standardkonstruktor
    Rectangle(int swx, int swy, int nex, int ney); // ein Konstruktor
    void draw(Frame*); // rein virtuelles shape::draw() ueberschreiben
    void move(int h, int v); // rein virtuelles shape::move() ueberschreiben 
private:
    int sw_x;
    int sw_y;
    int ne_x;
    int ne_y;
    Line n;
    Line e;
    Line s;
    Line w;
    void update_lines();
};


#endif	/* RECTANGLE_H */

