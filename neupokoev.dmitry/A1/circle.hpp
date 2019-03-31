#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
	Circle(double radius, point_t dot);
	void move(const point_t &dot) override;
	void move(double moveX, double moveY) override;
	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void writeParameters() const override;
	
private:
	point_t centre_;
	double radius_;
};

#endif
