/* 
 * File:   frame.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 7. Mai 2014, 20:20
 */

#ifndef FRAME_H
#define	FRAME_H

#include <stdexcept>
#include <iostream>
#include <ctime>

using std::endl;
using std::cerr;
using std::cout;

const int xMax = 55; // Zeichen pro Frame-Zeile
const int yMax = 34; // Zeilen pro Frame

//----- Frame-Klasse -----

class Frame {
public:

    enum color {
        black = ' ', white = '*'
    };

    Frame();

    void put_point(int x, int y);

    void reset();

    void show(std::ostream& target = std::cout) const;

    void show_unf() const;

    bool on_frame(int x, int y) const;
    
private:
    char frame[xMax][yMax];
};



#endif	/* FRAME_H */

