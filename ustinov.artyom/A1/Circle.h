#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape
{
public:
	Circle();
	Circle(double xx, double yy, double radius);
	Circle(point_t center, double radius);
	~Circle();
	virtual double getArea() const override;
	virtual rectangle_t getFrameRect() const override;
	virtual void move(point_t goal) override;
	virtual void move(double dx, double dy) override;
	void show() const;
private:
	point_t center_;
	double radius_;
};
#endif