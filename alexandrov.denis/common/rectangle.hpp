#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace alexandrov
{
  class Rectangle:
      public Shape {
  public:
    Rectangle(const rectangle_t & rect);
    void move(const point_t & newPoint) override;
    void move(const double dx, const double dy) override;
    void scale(const double factor) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
  private:
    rectangle_t rect_;
  };
}
#endif // RECTANGLE_HPP
