#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t &newPoint, double radius);

  double getArea() const override;
  void printInfo() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newPoint) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  double radius_;
};

#endif // CIRCLE_HPP
