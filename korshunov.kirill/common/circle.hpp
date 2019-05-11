#ifndef A2_CIRCLE_HPP_
#define A2_CIRCLE_HPP_

#include "shape.hpp"

namespace korshunov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &center) override;
    void move(double dx, double dy) override;
    void scale(double) override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif
