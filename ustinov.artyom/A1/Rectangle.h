#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(rectangle_t in_rect);
	Rectangle(double xx, double yy, double width, double height);
	~Rectangle();
	virtual double getArea() const override;
	virtual rectangle_t getFrameRect() const override;
	virtual void move(point_t goal) override;
	virtual void move(double dx, double dy) override;
	void show() const;
private:
	rectangle_t rect_;
};
#endif