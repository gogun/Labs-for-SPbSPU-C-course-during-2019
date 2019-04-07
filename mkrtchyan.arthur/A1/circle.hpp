#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape {
public:
  Circle(double radius, point_t pos);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  double radius_;
  point_t pos_;
};

#endif
