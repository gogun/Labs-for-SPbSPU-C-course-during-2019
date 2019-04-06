#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle:
    public Shape
{
public:
  Circle(const point_t &position, const double radius);

  rectangle_t getFrameRect() const override;
  double getArea() const override;

  void printInfo() const override;

private:
  double radius_;
};

#endif //CIRCLE_HPP
