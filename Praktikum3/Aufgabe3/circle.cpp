
#include "circle.h"
#include <cmath>

Circle::Circle() : x(0), y(0), r(0) {
}

Circle::Circle(int mx, int my, int ir) : Shape(), x(mx), y(my), r(ir) {
}
void Circle::draw(Frame* target){ // rein virtuelles shape::draw() ueberschreiben
    for(int dx = -r; dx <=r; dx++)
    {
        int dy = static_cast<int>(std::round(std::sqrt( static_cast<double>(r*r - dx*dx))));
        target->put_point(x + dx, y + dy);
        target->put_point(x + dx, y - dy);
    }
    for(int dy = -r; dy <=r; dy++)
    {
        int dx = static_cast<int>(std::round(std::sqrt( static_cast<double>(r*r - dy*dy))));
        target->put_point(x + dx, y + dy);
        target->put_point(x - dx, y + dy);
    }
}
void Circle::move(int h, int v){ // rein virtuelles shape::move() ueberschreiben v
    x+= h;
    y+= v;
}
