#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace potapova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &center, double height, double width);
    double getArea() const override;
    void move(double dx, double dy) override;
    void move(const point_t &center) override;
    void scale(double coefficient) override;
    rectangle_t getFrameRect() const override;
  private:
    rectangle_t rectangle_;
  };
}

#endif // RECTANGLE_HPP
