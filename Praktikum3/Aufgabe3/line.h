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
};

Line::Line()// Definition des Standardkonstruktors
: start_x(0), start_y(0), end_x(0), end_y(0) {
}

Line::Line(int sx, int sy, int ex, int ey)// Def. des weiteren Konstuktors
: start_x(sx), start_y(sy), end_x(ex), end_y(ey) {
}

void Line::set(int sx, int sy, int ex, int ey) {
    start_x = sx;
    start_y = sy;
    end_x = ex;
    end_y = ey;
}

void Line::draw(Frame* test) {
    if (!test->on_frame(start_x, start_y) || !test->on_frame(end_x, end_y)) {
        throw std::runtime_error("Die Punkte liegen nicht im Frame!\n");
    } else {
        int dx = (end_x - start_x); //durchschnitt
        int dy = (end_y - start_y);
        int xstep = 1;
        int ystep = 1;
        int f;

        if (dx < 0) { //wenn dx kleiner 0 ist
            dx = -dx; //kehre die Variablen um
            xstep = -1;
        }
        if (dy < 0) {
            dy = -dy;
            ystep = -1;
        }

        int a = dx * 2;
        int b = dy * 2;

        if (dy <= dx) {
            f = -dx;
            while (start_x < end_x || start_x > end_x) {
                test->put_point(start_x, start_y);
                f = f + b;
                if (f > b) {
                    start_y = start_y + ystep;
                    f = f - a;
                }
                start_x = start_x + xstep;
            }
        } else {
            f = -dy;
            while (start_y < end_y || start_y > end_y) {
                test->put_point(start_x, start_y);
                f = f + a;
                if (f > a) {
                    start_x = start_x + xstep;
                    f = f - b;
                }
                start_y = start_y + ystep;
            }
            test->put_point(start_x, start_y);
        }
    }
}

void Line::move(int h, int v) {// Def. der line::move() Methode
    start_x += h;
    start_y += v;
    end_x += h;
    end_y += v;
}

bool Line::Line_on_Frame(Frame* p) {
    if (p->on_frame(start_x, start_y) && p->on_frame(end_x, end_y))
        return true;
    else return false;
}


#endif	/* LINE_H */

