#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, const double radius);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const double dx, const double dy);
  void move(const point_t &point);
  point_t getCenter() const;
  double getRadius() const;
  void show() const;

private:
  point_t center_;
  double radius_;
};

#endif
