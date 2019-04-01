#include <cassert>
#include <iostream>
#include "Circle.hpp"

const double PI = 3.14159265;

Circle::Circle(const point_t &pos, const double &radius) :
	Shape(pos),
	radius_(radius)
{
	assert(radius >= 0.0);
}

double Circle::getArea() const
{
	return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
	return { pos_, 2 * radius_, 2 * radius_ };
}

void Circle::printFeatures() const
{
	std::cout << "Circle information:\n" << "radius: " << radius_ << "\n";
}
