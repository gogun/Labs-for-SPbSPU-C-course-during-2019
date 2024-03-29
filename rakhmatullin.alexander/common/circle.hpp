#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace rakhmatullin
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &, double);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &) override;
    void move(double, double) override;
    void scale(double) override;
  private:
    point_t center_;
    double radius_;
  };
}
#endif //CIRCLE_HPP
