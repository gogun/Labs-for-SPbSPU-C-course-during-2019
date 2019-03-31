#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
	virtual void move(double moveX, double moveY) = 0;
	virtual void move(const point_t &point) = 0;
	virtual double getArea() const = 0;
	virtual rectangle_t getFrameRect() const = 0;
	virtual void writeParameters() const = 0;
	virtual ~Shape() = default;
};

#endif
