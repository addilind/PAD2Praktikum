#include "frame.h"

Frame::Frame() {
    for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
        for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
            frame[i][j] = black;
        }
    }
};

void Frame::put_point(size_t x, size_t y) { // Punkt im Frame speichern
    if (!on_frame(x, y)) {
        throw std::runtime_error("Punkt liegt nicht im Frame");
    }
    frame[x][y] = white;
}

void Frame::reset() { // Frame leeren
    for (size_t i(0U); i < xMax; i++) { //Jede Zeile durchgehen
        for (size_t j(0U); j < yMax; j++) { //Jedes Zeichen durchgehen
            frame[i][j] = black;
        }
    }
}

void Frame::show(std::ostream& target) const { // Frame auf die Konsole ausgeben (formatiert))
    clock_t start(0);
    clock_t end(0);
    double s(0.0);
    start = clock();
    for (size_t i(0U); i < yMax; i++) { //Jede Zeile durchgehen
        for (size_t j(0U); j < xMax; j++) { //Jedes Zeichen durchgehen
            target << frame[j][i]; //Jedes einzelne Zeichen ausgeben
        }
        target << endl;
    }
    end = clock();
    if (start != -1 && end != -1) {
        start = end - start;
        s = start / CLOCKS_PER_SEC;
        target << "\t\t[ " << start << "clicks == " << s << "s ]" << endl;
    } else
        throw std::runtime_error("clock() fehlgeschlagen");
}

void Frame::show_unf() const { // Frame auf die Konsole ausgeben (unformatiert)
    clock_t start(0);
    clock_t end(0);
    double s(0.0);
    start = clock();
    for (size_t i(0U); i < yMax; i++) { //Jede Zeile durchgehen
        for (size_t j(0U); j < xMax; j++) { //Jedes Zeichen durchgehen
            cout.put(frame[j][i]); //Jedes einzelne Zeichen ausgeben
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

bool Frame::on_frame(int x, int y) const {
    if (x > xMax || y > yMax) {
        return false;
    }
    if (x < 0 || y < 0) {
        return false;
    }
    return true;
}