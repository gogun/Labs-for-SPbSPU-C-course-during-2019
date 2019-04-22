#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace lutsenko
{
  class Rectangle :public Shape
  {
  public:
    Rectangle(const rectangle_t & rect);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy) override;
    void move(const point_t & point) override;
    void scale(double coefficient) override;
  private:
    rectangle_t rect_;
  };
}

#endif
