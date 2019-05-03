#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace besedin
{
  class Circle: public Shape
  {
  public:
    Circle(double radius, const point_t &center);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double dx, double dy) noexcept override;
    void move(const point_t &newPos) noexcept override;
    void scale(double scale) override;

  private:
    double radius_;
    point_t center_;
  };
}

#endif
