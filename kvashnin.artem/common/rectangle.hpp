#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace kvashnin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t &position, const double width, const double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(const double dx, const double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    rectangle_t rect_;
  };
}
#endif
