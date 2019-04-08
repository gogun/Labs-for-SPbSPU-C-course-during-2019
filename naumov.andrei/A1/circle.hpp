#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t& Centre, double radius);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t & newCentre);
  void move(double dX, double dY);
  void setRadius(double newRadius);
protected:
  double radius_;
private:
};

#endif // !CIRCLE_HPP
