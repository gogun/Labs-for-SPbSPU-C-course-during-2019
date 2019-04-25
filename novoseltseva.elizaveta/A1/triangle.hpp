#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle :
	public Shape
{
public:
	Triangle(const point_t a, const point_t b, const point_t c);
	point_t getCenter() const;
	double getArea() const  override;
	rectangle_t getFrameRect() const  override;
	void move(const double dx, const double dy)  override;
	void move(const point_t& pos)  override;
	void showParams() const override;
private:
	point_t a_, b_, c_;
};

#endif
