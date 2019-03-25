#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Circle: public Shape
{
public:
  Circle(double radius, point_t dot);
  void move(double deltax, double deltay) override;
  void move(const point_t &dot) override;
  double getArea() const override;
  void writeChanges() const;
  rectangle_t getFrameRect() const override;
private:
  point_t centre_;
  double r_;
};

#endif
