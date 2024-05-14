#include "Circle.h"

Circle::Circle(int x, int y, double radius) : Shapes(1), radius(radius)
{
	setPoint(x, y, 0);
}

Circle::Circle(const Point& p, double radius) : Shapes(1), radius(radius)
{
	setPoint(p, 0);
}

const double Circle::getRadius() const
{
	return this->radius;
}

double Circle::getArea() const
{
	return M_PI * getRadius() * getRadius();
}

double Circle::getPerimeter() const
{
	return 2 * M_PI * getRadius();
}

bool Circle::isPointInside(int x, int y) const
{
	Shapes::Point p(x, y);
	return getPointAtIndex(0).getDistance(p) < getRadius();
}
