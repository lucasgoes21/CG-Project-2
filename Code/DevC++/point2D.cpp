#include "point2D.h"

Point2D::Point2D(double xx , double yy, Color c):Primitive("Point2D"), x(xx), y(yy), color(c) {
}

Point2D::Point2D(const Point2D &p):Primitive("Point2D") {
	x = p.x;
	y = p.y;
	color = p.color;
}

void Point2D::draw(Screen &screen) const{
	screen.setPixel(x, y, color);
}