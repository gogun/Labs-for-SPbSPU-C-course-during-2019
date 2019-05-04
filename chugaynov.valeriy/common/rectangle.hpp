#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.hpp"

namespace chugaynov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &, double width, double height);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
  private:
    point_t pos_;
    double width_;
    double height_;
  };
}
#endif
