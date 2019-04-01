#include <iostream>
#include <cassert>
#include "Rectangle.hpp"

Rectangle::Rectangle(const point_t &pos, const double &width, const double &height) :
	Shape(pos),
	width_(width),
	height_(height)
{
	assert((width_ >= 0.0) && (height >= 0.0));
}

double Rectangle::getArea() const
{
	return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
	return { pos_, width_, height_ };
}

void Rectangle::printFeatures() const
{
	std::cout << "Rectangle information:\n" << "Width: " << width_ << "\n"
	<< "Height: " << height_ << "\n";
}
