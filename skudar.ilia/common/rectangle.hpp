#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace skudar
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &, double, double);
    Rectangle(double, double, double, double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif
