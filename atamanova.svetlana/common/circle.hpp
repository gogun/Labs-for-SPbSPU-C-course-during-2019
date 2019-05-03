#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace atamanova
{
  class Circle : public Shape
  {
  public:
    Circle(point_t center, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t point) override;
    void scale(double scale) override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif // CIRCLE_HPP
