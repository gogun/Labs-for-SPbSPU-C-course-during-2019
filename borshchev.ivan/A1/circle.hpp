#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t, const double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double newX, double newY) override;
  void move(const point_t & point) override;
  void dataOutput() const override;

private:
  double radius_;
  point_t center_;
};

#endif
