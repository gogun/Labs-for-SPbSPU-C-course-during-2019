#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace besedin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, const point_t &center);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double dx, double dy) noexcept override;
    void move(const point_t &newPos) noexcept override;
    void scale(double scale) override;

  private:
    double width_;
    double height_;
    point_t center_;
  };
}

#endif
