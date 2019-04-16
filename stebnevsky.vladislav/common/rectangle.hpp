#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace stebnevsky
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const rectangle_t & rect_init);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;

  private:
    rectangle_t m_rect;
  };
}

#endif // RECTANGLE_HPP
