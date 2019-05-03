#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace alexandrov
{
  class Circle:
      public Shape {
  public:
    Circle(const point_t & center, const double radius);
    void move(const point_t & newPoint) override;
    void move(const double dx, const double dy) override;
    void scale(const double factor) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
  private:
    point_t center_;
    double radius_;
  };
}
#endif // CIRCLE_HPP
