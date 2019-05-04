#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace atamanova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t center, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t point) override;
    void scale(double scale) override;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif // RECTANGLE_HPP
