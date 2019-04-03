#include <iostream>
#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(const rectangle_t &rectangle) :
	rectangle_(rectangle)
{
	assert((rectangle_.width > 0.0) && (rectangle_.height > 0.0));
}

double Rectangle::getArea() const
{
	return (rectangle_.width * rectangle_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
	return rectangle_;
}

void Rectangle::move(double dx, double dy)
{
	rectangle_.pos.x += dx;
	rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &point)
{
	rectangle_.pos = point;
}

void Rectangle::print() const
{
	std::cout << "Center: (" << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << std::endl;
}