#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#define _USE_MATH_DEFINES

#include "shape.hpp"

class Circle : public Shape {
public:
  Circle(const point_t &point, double radius);

  double getArea() const override;
  rectangle_t  getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &point) override;

private:
  point_t centre_;
  double radius_;
};

#endif
