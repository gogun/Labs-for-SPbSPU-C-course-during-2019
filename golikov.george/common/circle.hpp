#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace golikov
{
  class Circle :
          public golikov::Shape
  {
  public:
    Circle(double radius, const point_t &center);
    Circle(double radius, double center_x, double center_y);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void showParams() const override;

  private:
    double m_radius;
    point_t m_center;
  };
}

#endif
