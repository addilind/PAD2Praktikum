#include "shape.h"

Shape* Shape::last = 0; // initialisiert den staticMember mit dem Nullzeiger

void show_all_shapes(Frame* p) { // gibt alle Shape Objekte auf Frame* aus
    for (Shape* pB = Shape::getLast(); pB != 0; pB = pB->getPrev()) {
        pB->draw(p);
    }
}

bool proof_points(int sx, int sy, int ex, int ey) { //Ueberprueft ob Start und Endpunkte gleich sind
    return((sx == ex) && (sy == ey));    
}
