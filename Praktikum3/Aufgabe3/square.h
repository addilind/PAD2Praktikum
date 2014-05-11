/* 
 * File:   square.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 11. Mai 2014, 09:28
 */

#ifndef SQUARE_H
#define	SQUARE_H

#include "rectangle.h"

// ----- Square-Klasse (abgeleitet von Rectangle) -----

class Square : public Rectangle {
    public:
    Square():Rectangle(){};
    Square(int swx, int swy, int i): Rectangle(swx, swy, (swx+i), (swy+i)) {};
    void draw(Frame* p){
        Rectangle::draw(p);
    }
    void move(int h, int v){
        Rectangle::move(h, v);
    }
};


#endif	/* SQUARE_H */

