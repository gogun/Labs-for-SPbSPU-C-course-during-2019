#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace zakharova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double height, point_t pos);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t newpos) override;
    void scale(double factor) override;

    void getInfo() const override;

  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif // RECTANGLE_HPP
