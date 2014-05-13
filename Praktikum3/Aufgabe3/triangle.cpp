#include "triangle.h"

Triangle::Triangle() : p1_x(0), p1_y(0), p2_x(0), p2_y(0), p3_x(0), p3_y(0), a(Line()), b(Line()), c(Line()) {
};

//weiterer Konstruktor

Triangle::Triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) : p1_x(p1x), p1_y(p1y), p2_x(p2x), p2_y(p2y), p3_x(p3x), p3_y(p3y), a(Line()), b(Line()), c(Line()) {
    b.set(p1_x, p1_y, p3_x, p3_y);
    c.set(p2_x, p2_y, p3_x, p3_y);
    a.set(p2_x, p2_y, p1_x, p1_y);
    if (proof_triangle(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y) == false) {
        throw std::runtime_error("Die Punkte ergeben kein gueltiges Dreick");
    }
};

Triangle::Triangle(int hor, int ver, int line1, int line2, int line3)
		: p1_x(hor), p1_y(ver), //Gegebener Punkt
		p2_x(hor + get_hypotenuse(line1, line2, line3)), p2_y(ver), //Anderer Endpunkt der Hypotenuse
		p3_x(hor + get_x(line1, line2, line3)), p3_y(ver + get_triangleheight(line1, line2, line3)), //Punkt zwischen Katheten
		a(Line()), b(Line()), c(Line()) {
    b.set(p1_x, p1_y, p3_x, p3_y);
    c.set(p2_x, p2_y, p3_x, p3_y);
    a.set(p2_x, p2_y, p1_x, p1_y);
    if (proof_length(line1, line2, line3) == false) {
        throw std::runtime_error("Die Laengen ergeben kein gueltiges Dreick");
    }
}

void Triangle::draw(Frame* p) {
    if (a.Line_on_Frame(p) == true && b.Line_on_Frame(p) == true && c.Line_on_Frame(p) == true) {
        a.draw(p);
        b.draw(p);
        c.draw(p);
    } else {
        throw std::runtime_error("Linien liegen nicht im Frame, zeichnen nicht moeglich!\n");
    }
}

void Triangle::move(int ver, int hor) {
    p1_x += ver;
    p1_y += hor;
    p2_x += ver;
    p2_y += hor;
    p3_x += ver;
    p3_y += hor;
    b.set(p1_x, p1_y, p3_x, p3_y);
    c.set(p2_x, p2_y, p3_x, p3_y);
    a.set(p2_x, p2_y, p1_x, p1_y);
}

bool proof_triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
    if (proof_points(p1x, p1y, p2x, p2y)) { //prueft ob punkte gleich sind
        return false;
    }
    if (proof_points(p2x, p2y, p3x, p3y)) {
        return false;
    }
    if (proof_points(p3x, p3y, p1x, p1y)) {
        return false;
    }

    //prueft ob Linien senkrecht zu y-Achse
    double a = p1x - p2x;
    double b = p1x - p3x;

    if (a == 0) { //wenn p1, p2 parallel zur y-achse
        if (b == 0) {
            return false; // und andere linie auch senkrecht, dreieck ungueltig
        } else {
            return true; //ansonsten gueltig
        }
    }
    //p1,p2 nicht sparralel
    if (b == 0) { //wenn p1 - p3 parallel zur y-achse
        return true;
    }

    //prueft steigung
    double c = p1y - p2y;
    double d = p1y - p3y;

    if ((c / a) == (d / b)) {
        return false;
    } else {
        return true;
    }
}

bool proof_length(int line1, int line2, int line3) { //prueft laenge der seiten
    if (line1 <= 0)
		return false;
    if (line2 <= 0)
		return false;
    if (line3 <= 0)
		return false;
    std::vector<int> v;
    v.push_back(line1);
    v.push_back(line2);
    v.push_back(line3);
    std::sort(v.begin(), v.end());

    return ( v[2] < (v[0] + v[1]) );
}

int get_triangleheight(int line1, int line2, int line3) { //berechnet hoehe
    std::vector<int> v;
    v.push_back(line1);
    v.push_back(line2);
    v.push_back(line3);
    std::sort(v.begin(), v.end());
    int a = v[0];
    int b = v[1];
    int c = v[2];

    int a2 = std::pow(a, 2);
    int b2 = std::pow(b, 2);
    int c2 = std::pow(c, 2);

    int a4 = std::pow(a, 4);
    int b4 = std::pow(b, 4);
    int c4 = std::pow(c, 4);

    double h1 = std::sqrt(2 * (a2 * b2 + c2 * b2 + c2 * a2)-(a4 + b4 + c4)) / (2 * c);
    int h = static_cast<int> (round(h1));
    return h;
}

int get_x(int line1, int line2, int line3) { //berechnet x wert
    std::vector<int> v;
    v.push_back(line1);
    v.push_back(line2);
    v.push_back(line3);
    std::sort(v.begin(), v.end());
    int b2 = std::pow((v[0]), 2);
    int h2 = std::pow((get_height(line1, line2, line3)), 2);

    double x1 = std::sqrt(b2 - h2);
    int x = static_cast<int> (round(x1));
    return x;
}

int get_hypotenuse(int line1, int line2, int line3) {
    std::vector<int> v;
    v.push_back(line1);
    v.push_back(line2);
    v.push_back(line3);
    std::sort(v.begin(), v.end());
    return v[2];
}


