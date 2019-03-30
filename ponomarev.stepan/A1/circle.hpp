#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(point_t dot, double rad);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t point) override;

private:
  point_t center_;
  double radius_;
};
#endif //A1_CIRCLE_HPP
