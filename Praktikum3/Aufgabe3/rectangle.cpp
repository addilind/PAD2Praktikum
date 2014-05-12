#include "rectangle.h"

Rectangle::Rectangle() : sw_x(0), sw_y(0), ne_x(0), ne_y(0), n(Line()), e(Line()), s(Line()), w(Line()) {
}

Rectangle::Rectangle(int swx, int swy, int nex, int ney) : sw_x(swx), sw_y(swy), ne_x(nex), ne_y(ney), n(Line()), e(Line()), s(Line()), w(Line()) {
    n.set(sw_x, ne_y, ne_x, ne_y);
    e.set(ne_x, sw_y, ne_x, ne_y);
    s.set(sw_x, sw_y, ne_x, sw_y);
    w.set(sw_x, sw_y, sw_x, ne_y);
    //prüfen, ob ein gültiges Rechteck vorliegt
    if (proof_Rectangle(sw_x, sw_y, ne_x, ne_y) == false)
        throw std::runtime_error("Start und Endpunkte sind gleich, es kann kein Rechteck gezeichnet werden!\n");
}

void Rectangle::draw(Frame* p){
    if (n.Line_on_Frame(p) == true && e.Line_on_Frame(p) == true && s.Line_on_Frame(p) == true && w.Line_on_Frame(p) == true) {
        n.draw(p);
        e.draw(p);
        s.draw(p);
        w.draw(p);
    }
}

void Rectangle::move(int hor, int ver){
    sw_x += ver;
    sw_y += hor;
    ne_x += ver;
    ne_y += hor;
    n.set(sw_x, ne_y, ne_x, ne_y);
    e.set(ne_x, sw_y, ne_x, ne_y);
    s.set(sw_x, sw_y, ne_x, sw_y);
    w.set(sw_x, sw_y, sw_x, ne_y);
}

bool proof_Rectangle(int sx, int sy, int ex, int ey) { //Ueberprueft ob Start und Endpunkte gleich sind
    if ((sx == ex) || (sy == ey)) {
        return false;
    } else {
        return true;
    }
}

