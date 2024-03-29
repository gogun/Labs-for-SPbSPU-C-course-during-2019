#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace ivleva
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const rectangle_t & rect);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & point) override;
    void move(double dx, double dy) override;
    void print() const override;
    void scale(double coefficient) override;
  
  private:
    rectangle_t rect_;
  };
}

#endif
