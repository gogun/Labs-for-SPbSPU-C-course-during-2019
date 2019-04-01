#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED
#include "Shape.hpp"

class Rectangle :
	public Shape
{
public:
	Rectangle(const point_t &pos, const double &width, const double &height);

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void printFeatures() const override;

private:
	double width_, height_;
};

#endif
