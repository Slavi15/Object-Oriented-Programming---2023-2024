#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shapes(3)
{
	setPoint(x1, y1, 0);
	setPoint(x2, y2, 1);
	setPoint(x3, y3, 2);
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Shapes(3)
{
	setPoint(p1, 0);
	setPoint(p2, 1);
	setPoint(p3, 2);
}

double Triangle::getArea() const
{
	// Hero's Formula
	/*double halfPerimeter = getPerimeter() / 2;

	double sideA = getPointAtIndex(0).getDistance(getPointAtIndex(1));
	double sideB = getPointAtIndex(1).getDistance(getPointAtIndex(2));
	double sideC = getPointAtIndex(0).getDistance(getPointAtIndex(2));

	return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));*/
	// Hero's Formula

	// Determinant
	const Shapes::Point& p1 = getPointAtIndex(0);
	const Shapes::Point& p2 = getPointAtIndex(1);
	const Shapes::Point& p3 = getPointAtIndex(2);

	return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2;
	// Determinant
}

bool Triangle::isPointInside(int x, int y) const
{
	Shapes::Point p(x, y);

	Triangle t1(getPointAtIndex(0), getPointAtIndex(1), p);
	Triangle t2(getPointAtIndex(0), getPointAtIndex(2), p);
	Triangle t3(getPointAtIndex(1), getPointAtIndex(2), p);

	return abs(t1.getArea() + t2.getArea() + t3.getArea() - getArea()) <= std::numeric_limits<double>::epsilon(); // 0.0001
}
