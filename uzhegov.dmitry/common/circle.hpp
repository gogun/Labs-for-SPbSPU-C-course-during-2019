#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace uzhegov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printParams() const override;
    void move(double dx, double dy) override;
    void move(const point_t &point) override;
    void scale(double coefficient) override;

  private:
    point_t center_;
    double radius_;
  };
}
#endif
