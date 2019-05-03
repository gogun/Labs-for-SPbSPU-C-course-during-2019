#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace golikov
{
  class Rectangle :
          public golikov::Shape
  {
  public:
    Rectangle(const rectangle_t &figure);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void showParams() const override;

  private:
    rectangle_t m_figure;
  };
}

#endif
