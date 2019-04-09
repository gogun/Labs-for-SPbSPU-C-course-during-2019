#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

namespace kornilov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t& centre, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const point_t& point) override;
    void scale(const double coefficient) override;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif
