#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace frolov
{
  class Rectangle : public frolov::Shape
  {
  public:
    Rectangle(const point_t &center, double height, double width);
    double getArea() const override;
    void move(double dx, double dy) override;
    void move(const point_t &center) override;
    rectangle_t getFrameRect() const override;
    void scale(double factor) override;
    void showPoint() const override;
  private:
    point_t center_;
    double height_;
    double width_;
  };
}

#endif
