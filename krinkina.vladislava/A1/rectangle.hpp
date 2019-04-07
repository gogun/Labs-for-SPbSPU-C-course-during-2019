#pragma once
#include "shape.hpp"
class Rectangle: public Shape
{
public:
	Rectangle(const point_t &centre, double width, double height);

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t &centre) override;
	void move(const double dx, const double dy) override;
	void printInfo() const override;
private:
	double width_, height_;
	point_t centre_;
};