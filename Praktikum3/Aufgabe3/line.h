/* 
 * File:   line.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 11. Mai 2014, 09:27
 */

#include "shape.h"

#ifndef LINE_H
#define	LINE_H

//----- Line-Klasse (abgeleitet von Shape) -----

class Line : public Shape {
public:
    Line(); // Standardkonstruktor
    Line(int sx, int sy, int ex, int ey); // ein Konstruktor

    void set(int sx, int sy, int ex, int ey);

    void draw(Frame*); // rein virtuelles shape::draw() ueberschreiben

    void move(int h, int v); // rein virtuelles shape::move() ueberschreiben

    bool Line_on_Frame(Frame* t);

private:
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    void set_point(int x, int y, bool fliphor, bool flipbisec, Frame* target);
};

#endif	/* LINE_H */