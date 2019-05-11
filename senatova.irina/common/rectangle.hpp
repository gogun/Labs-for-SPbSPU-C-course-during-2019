#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace senatova
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t pos, double height, double width);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void print() const override;
    void scale(double multiplier) override;

  private:
    point_t pos_;
    double height_;
    double width_;
  };
}

#endif //RECTANGLE_HPP
