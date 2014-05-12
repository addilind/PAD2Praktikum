#include "line.h"

Line::Line()// Definition des Standardkonstruktors
: start_x(0), start_y(0), end_x(0), end_y(0) {
}

Line::Line(int sx, int sy, int ex, int ey)// Def. des weiteren Konstuktors
: start_x(sx), start_y(sy), end_x(ex), end_y(ey) {
}

void Line::set(int sx, int sy, int ex, int ey) {
    start_x = sx;
    start_y = sy;
    end_x = ex;
    end_y = ey;
}

void Line::draw(Frame* test) {
    if (!test->on_frame(start_x, start_y) || !test->on_frame(end_x, end_y)) {
        throw std::runtime_error("Die Punkte liegen nicht im Frame!\n");
    }
    if(end_x < start_x){ //wenn endpunkt links von startpunkt ist, punkte umdrehen
        int tmpx = start_x;
        int tmpy = start_y;
        start_x = end_x;
        start_y = end_y;
        end_x = tmpx;
        end_y = tmpy;
    }
    int sx = start_x;
    int sy = start_y;
    int ex = end_x;
    int ey = end_y;
    
    bool fliphor = false; //spiegeln
    bool flipbisec = false; //spiegeln
    
    if(ey < sy){ //wenn endpunkt ueber startpunkt liegt, horizontal spiegeln
        ey *= -1;
        sy *= -1;
        fliphor = true;
    }
    if((ex-sx)<(ey-sy)){ //wenn Steigung groeßer als 45° spiegeln an der Winkelhalbierenden
        int tmp = sx;
        sx = sy;
        sy = tmp;
        tmp = ex;
        ex = ey;
        ey = tmp;
        flipbisec = true;
    }
    set_point(sx, sy, fliphor, flipbisec, test); //plotten des startpunktes
    
    while(sx < ex){
        ++sx;
        if((ey-sy)*2 > (ex-sx)){//wenn auch nach y gelaufen wird
            ++sy;  
        }
        set_point(sx, sy, fliphor, flipbisec, test);        
    }
}

void Line::set_point(int x, int y, bool fliphor, bool flipbisec, Frame* target){
    if(flipbisec){ //wenn Steigung groeßer als 45° spiegeln an der Winkelhalbierenden
        int tmp = x;
        x = y;
        y = tmp;
    }
    if(fliphor){ //wenn endpunkt ueber startpunkt liegt, horizontal spiegeln
        y *= -1;
    }
    target->put_point(x,y);
}

void Line::move(int h, int v) {// Def. der line::move() Methode
    start_x += h;
    start_y += v;
    end_x += h;
    end_y += v;
}

bool Line::Line_on_Frame(Frame* p) {
    if (p->on_frame(start_x, start_y) && p->on_frame(end_x, end_y))
        return true;
    else return false;
}

