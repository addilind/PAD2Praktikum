/* 
 * File:   frame.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 7. Mai 2014, 20:20
 */

#ifndef FRAME_H
#define	FRAME_H

#include <array>
#include <iostream>


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

    Frame() {
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                frame[i][j] = black;
            }
        }
    };

    void put_point(size_t x, size_t y) { // Punkt im Frame speichern
        if (on_frame(x, y)== true) {
            frame[x][y] = white;
        }
        else{
        throw std::runtime_error("Punkt liegt nicht im Frame");
        }
    }

    void reset() { // Frame leeren
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                frame[i][j] = black;
            }
        }
    }

    void show() const { // Frame auf die Konsole ausgeben (formatiert)
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                cout << frame[i][j]; //Jedes einzelne Zeichen ausgeben
            }
            cout << endl;
        }
    }

    bool on_frame(int x, int y) const;
private:
    char frame[xMax][yMax];
};

bool Frame::on_frame(int x, int y) const {
    if (x > xMax || y > yMax) {
        return false;
    }
    if (x < 0 || y < 0) {
        return false;
    } else {
        return true;
    }
}
#endif	/* FRAME_H */

