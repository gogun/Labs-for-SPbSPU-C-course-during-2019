#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED
#include "base-types.hpp"

class Shape
{
public:
	Shape(const point_t &pos);
	virtual ~Shape() = default;

	virtual double getArea() const = 0;
	virtual rectangle_t getFrameRect() const = 0;
	virtual void printFeatures() const = 0;

	void printData() const;

	virtual void move(const double &dx, const double &dy);
	virtual void move(const point_t &pos);

protected:
	point_t pos_;
};

#endif
