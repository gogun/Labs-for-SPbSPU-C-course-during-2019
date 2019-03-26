#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape {
public:
  Circle(point_t centre, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  point_t centre_;
  double radius_;
};

#endif
