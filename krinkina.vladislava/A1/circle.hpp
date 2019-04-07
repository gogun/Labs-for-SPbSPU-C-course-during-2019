#pragma once

#include "shape.hpp"

class Circle : public Shape
{
public:
	Circle(const point_t &centre, double radius);

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void printInfo() const override;
	void move(const point_t &centre) override;
	void move(double dx, double dy) override;

private:
	double radius_;
	point_t centre_;
};