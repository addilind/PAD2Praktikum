/* 
 * File:   frame.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 7. Mai 2014, 20:20
 */

#ifndef FRAME_H
#define	FRAME_H

#include <array>
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
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                frame[x][y] = white;
            }
        }
        //        if (on_frame(x, y)){
        //            frame[x][y] = white;
        //        }
        //        throw std::runtime_error("Punkt liegt nicht im Frame");
    }

    void reset() { // Frame leeren
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                frame[i][j] = black;
            }
        }
    }

    void show() const { // Frame auf die Konsole ausgeben (formatiert))
        clock_t start(0);
        clock_t end(0);
        double s(0.0);
        start = clock();
        for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
            for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
                cout << frame[i][j]; //Jedes einzelne Zeichen ausgeben
            }
            cout << endl;
        }
        end = clock();
        if (start != -1 && end != -1) {
            start = end - start;
            s = start / CLOCKS_PER_SEC;
            cout << "\t\t[ " << start << "clicks == " << s << "s ]" << endl;
        } else
            throw std::runtime_error("clock() fehlgeschlagen");
    }

    void show_unf() const { // Frame auf die Konsole ausgeben (unformatiert)
        clock_t start(0);
        clock_t end(0);
        double s(0.0);
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
            s = start / CLOCKS_PER_SEC;
            cout << "\t\t[ " << start << "clicks == " << s << "s ]" << endl;
        } else
            throw std::runtime_error("clock() fehlgeschlagen");
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
    }
    return true;
}


//----- Line-Klasse (abgeleitet von Frame) -----

class Line : public Frame {
public:
    Line(); // Standardkonstruktor
    Line(int sx, int sy, int ex, int ey); // ein Konstruktor

    void set(int sx, int sy, int ex, int ey) {
    }

    void draw(Frame*); // rein virtuelles shape::draw() ueberschreiben

    void move(int h, int v); // rein virtuelles shape::move() ueberschreiben

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

void Line::move(int h, int v) {// Def. der line::move() Methode
    start_x += h;
    start_y += v;
    end_x += h;
    end_y += v;
}
// ----- Bresenham-Algorithmus -----

void Line::draw(Frame* test) {
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
//schnelle-richtung herrausfinden ueber if-abfrage; Bei dx = 7 und dy = 4 ist x die schnelle richtung
//fehler(f) initital berechnen und zwar indem schnelle richtung durch 2 geteilt (halbiert wird)
//wenn x die schnelle richtung ist, wird x immer hoch gelaufen, y nicht. ist es anders rum muss man die werte umdrehen
//Anschließen Fehler - dy(also langsame richtung) und schauen ob ergebnis kleiner oder groeßer ist als 0
//wenn ergebnis kleiner als 0 dann darf mit der langsamen richtung (also y) einen schritt nach oben gegangen werden
//ist dies nicht der fall wird y nicht erhöht sondern nur x.
//wenn dy verändert wurde(wenn ergebnis kleiner 0 war), muss der fehler wieder korrigiert werden und zwar, in dem dx wieder dazu addiert wird
//wurde dy nicht verändert, bleibt f wie es war.

//// ----- Rectangle-Klasse (abgeleitet von Shape) -----
//
//class Rectangle : public Shape {
//public:
//    Rectangle(); // Standardkonstruktor
//    Rectangle(int swx, int swy, int nex, int ney); // ein Konstruktor
//    void draw(Frame*); // rein virtuelles shape::draw() ueberschreiben
//    void move(int h, int v); // rein virtuelles shape::move() ueberschreiben 
//private:
//    int sw_x, sw_y, ne_x, ne_y;
//    Line n, e, s, w;
//    void update_lines();
//};
//
//// ----- Square-Klasse (abgeleitet von Rectangle) -----
//
//class Square : public Rectangle {
//};
//



#endif	/* FRAME_H */

