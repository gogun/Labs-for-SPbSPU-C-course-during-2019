#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &position, double radius);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(double dx, double dy) override;

  void move(const point_t &position) override;

private:
  point_t center_;
  double radius_;
};

#endif
