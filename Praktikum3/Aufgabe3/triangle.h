/* 
 * File:   triangle.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 11. Mai 2014, 09:28
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "shape.h"
#include "line.h"
#include <vector>
#include <algorithm>
#include "math.h"
#include <cmath>

bool proof_triangle(int, int, int, int, int, int);
bool proof_length(int, int, int);
int get_triangleheight(int, int, int);
int get_x(int, int, int);
int get_hypotenuse(int, int, int);

// --- Triangle-Klasse -----

class Triangle : public Shape {
public:

    //Standartkonstruktor

    Triangle();

    //weiterer Konstruktor

    Triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y);

    Triangle(int hor, int ver, int line1, int line2, int line3);

    void draw(Frame* p);

    void move(int ver, int hor);
private:
    int p1_x;
    int p1_y;
    int p2_x;
    int p2_y;
    int p3_x;
    int p3_y;
    Line a;
    Line b;
    Line c;
};


#endif	/* TRIANGLE_H */

