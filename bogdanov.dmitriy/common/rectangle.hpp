#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace bogdanov
{
  class Rectangle: public Shape {
  public:
    Rectangle(const point_t &center, double width, double height);

    void move(const point_t &newCenter) override;
    void move(double dx, double dy) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void writeInfo() const override;
    void scale(double scalingFactor) override;

  private:
    rectangle_t rectangle_;
  };
}  //namespace bogdanov

#endif
