#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
  public:
    Circle(double radius, point_t pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;

  private:
    double radius_;
};

#endif
