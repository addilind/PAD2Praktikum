/* 
 * File:   line.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 12. Mai 2014, 10:48
 */

#ifndef LINE_H
#define	LINE_H


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
    if (!test->on_frame(start_x, start_y) || !test->on_frame(end_x, end_y)) {
        throw std::runtime_error("Die Punkte liegen nicht im Frame!\n");
    } else {
        int dx = (end_x - start_x); //durchschnitt
        int dy = (end_y - start_y);
        int xstep = 1; //Schritte
        int ystep = 1;
        int f; //fehler

        if (dx < 0) { //wenn dx kleiner 0 ist
            dx = -dx; //kehre die Variablen um
            xstep = -1;
        }
        if (dy < 0) { //wenn dx kleiner 0 ist
            dy = -dy; //kehre die Variablen um
            ystep = -1;
        }

        int a = dx * 2; //Berechnen der Richtung um Fehler zu aktualisieren/regenerieren
        int b = dy * 2;

        if (dy <= dx) { //Fallunterscheidung der "Schnellen Richtung"
            f = -dx; //Zuweisen des Fehlers
            while (start_x < end_x || start_x > end_x) { //Solange startpunkt kleiner oder groeßer als endpunkt ist
                test->put_point(start_x, start_y); //plotten(setzen des Punktes)
                f = f + b; //aktualisieren des fehlers
                if (f > b) { //Fallunterscheidung: wenn der Fehler kleiner als b
                    start_y = start_y + ystep; //wird ein Schritt in die y Richtung gelaufen
                    f = f - a; //der Fehler mit a aktualisiert/regeneriert, weil in y Richtung gelaufen wurde
                }
                start_x = start_x + xstep; //ansonsten wird in x Richtung gelaufen
            }
        } else {
            f = -dy; //Zuweisen des Fehlers
            while (start_y < end_y || start_y > end_y) {//Solange startpunkt kleiner oder groeßer als endpunkt ist
                test->put_point(start_x, start_y); //plotten(setzen des Punktes)
                f = f + a; //aktualisieren des fehlers
                if (f > a) { //Fallunterscheidung: wenn der Fehler kleiner als a
                    start_x = start_x + xstep; //wird in x richtung gelaufen
                    f = f - b; //Der Fehler wird mit a aktualisiert/regeneriert weil in x Richtung gelaufen wurde
                }
                start_y = start_y + ystep; //ansonsten wird in y Richtung gelaufen
            }
            test->put_point(start_x, start_y); //Plotten (Setzen des Punktes)
        }
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



#endif	/* LINE_H */

