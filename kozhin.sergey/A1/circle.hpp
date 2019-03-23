#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &, double);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double x, double y);
  void move(const point_t &);

private:
  point_t center_;
  double radius_;
  double area_;
  rectangle_t frameRect_;
};

#endif // CIRCLE_HPP
