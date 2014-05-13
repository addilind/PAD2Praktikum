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

    Frame() {
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                frame[i][j] = black;
            }
        }
    };

    void put_point(size_t x, size_t y) { // Punkt im Frame speichern
        if (on_frame(x, y)) {
            frame[x][y] = white;
        }
        throw std::runtime_error("Punkt liegt nicht im Frame");
    }

    void reset() { // Frame leeren
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                frame[i][j] = black;
            }
        }
    }

    void show(std::ostream& target = std::cout) const { // Frame auf die Konsole ausgeben (formatiert))
        clock_t start(0);
        clock_t end(0);
        start = clock();
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                target << frame[i][j]; //Jedes einzelne Zeichen ausgeben
            }
            target << endl;
        }
        end = clock();
        if (start != -1 && end != -1) {
            start = end - start;
            target << "\t\t[ " << start << "] ticks" << endl;
        } else
            throw std::runtime_error("clock() fehlgeschlagen");
    }

    void show_unf() const { // Frame auf die Konsole ausgeben (unformatiert)
        clock_t start(0);
        clock_t end(0);
        start = clock();
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                cout.put(frame[i][j]); //Jedes einzelne Zeichen ausgeben
            }
            cout.put('\n');
        }
        end = clock();
        if (start != -1 && end != -1) {
            start = end - start;
            cout << "\t\t[ " << start << "] ticks" << endl;
        } else
            throw std::runtime_error("clock() fehlgeschlagen");
    }

    bool on_frame(int x, int y) const {
        if (x > xMax || y > yMax) {
            return false;
        }
        if (x < 0 || y < 0) {
            return false;
        }
        return true;
    }

    std::ostream& operator<<(std::ostream& target) {
        show(target);
        return target;
    }
private:
    char frame[xMax][yMax];
};
#endif	/* FRAME_H */

