/* 
 * File:   Aufgabe2.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 12. Mai 2014, 10:53
 */

#ifndef AUFGABE2_H
#define	AUFGABE2_H

#include "frame.h"

void Bresenham(Frame* target, int x1, int y1, int x2, int y2);

class Line {
public:
    Line(); // Standardkonstruktor
    Line(int sx, int sy, int ex, int ey); // ein weiterer Konstruktor

    void set(int sx, int sy, int ex, int ey);
    
    void set_point(Frame* target, int x, int y, bool fliphor, bool flipbisec);

    void draw(Frame*); // rein virtuelles shape::draw() ueberschreiben

    void move(int h, int v); // rein virtuelles shape::move() ueberschreiben

private:
    int start_x;
    int start_y;
    int end_x;
    int end_y;
};

#endif	/* AUFGABE2_H */

