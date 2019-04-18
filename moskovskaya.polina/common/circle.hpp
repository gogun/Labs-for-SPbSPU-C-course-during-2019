#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace moskovskaya
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &newCenter, double radius);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(double dx, double dy) override;

    void move(const point_t &newCenter) override;

    void scale(double factor) override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif // CIRCLE_HPP
