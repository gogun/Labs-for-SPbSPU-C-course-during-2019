#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace skudar
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &, double);
    Circle(double, double, double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
