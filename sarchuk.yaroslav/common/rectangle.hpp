#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
namespace sarchuk
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t, double, double);
    Rectangle(rectangle_t);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void writeInfo() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;

  private:
    point_t pos_;
    double width_, height_;
  };
}
#endif
