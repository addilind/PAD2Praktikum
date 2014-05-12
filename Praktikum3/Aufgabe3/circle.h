/* 
 * File:   circle.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 12. Mai 2014, 12:44
 */

#ifndef CIRCLE_H
#define	CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    Circle();
    Circle(int mx, int my, int ir);
    void draw(Frame*); // rein virtuelles shape::draw() ueberschreiben
    void move(int h, int v); // rein virtuelles shape::move() ueberschreiben 

private:
    int x;
    int y;
    int r;
};


#endif	/* CIRCLE_H */

