#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace uzhegov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &center, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printParams() const override;
    void move(double dx, double dy) override;
    void move(const point_t &point) override;
    void scale(double coefficient) override;

  private:
    point_t center_;
    double width_, height_;
  };
}
#endif
