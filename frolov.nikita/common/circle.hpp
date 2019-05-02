#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace frolov
{
  class Circle : public frolov::Shape
  {
  public:
    Circle(const point_t &center, double radius);
    double getArea() const override;
    void move(double dx, double dy) override;
    void move(const point_t &center) override;
    rectangle_t getFrameRect() const override;
    void scale(double factor) override;
    void showPoint() const override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
