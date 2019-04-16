#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &point, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getCentre() const override;
  void move(double dx, double dy) override;
  void move(const point_t &) override;

private:
  point_t centre_;
  double radius_;
};

#endif
