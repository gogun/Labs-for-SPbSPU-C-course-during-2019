#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace kotov {
  class Rectangle: public Shape
  {
  public:

    Rectangle(const point_t & center, double width, double height);

    const char * getShapeName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & newCenter) override;
    void move(double dX, double dY) override;
    void scale(double scale) override;

  private:
    rectangle_t rect_;
  };
}
#endif // RECTANGLE_HPP
