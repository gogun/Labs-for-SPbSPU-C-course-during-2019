#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace shahbazly
{
  class Rectangle:
      public Shape
  {
  public:
    Rectangle(const point_t & pos, const double & width, const double & height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & pos) override;
    void move(double dx, double dy) override;
    void scale(double scaleFactor) override;
    void showParameters() const override;
  private:
    double m_height;
    double m_width;
    point_t m_center;
  };
}
#endif
