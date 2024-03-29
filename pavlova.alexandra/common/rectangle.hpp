#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace pavlova
{
  class Rectangle : public Shape {
  public:
    Rectangle(double height, double width, const point_t &center);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coeff) override;

  private:
    double height_;
    double width_;
    point_t center_;
  };
}
#endif
