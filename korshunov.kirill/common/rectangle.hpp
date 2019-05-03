#ifndef A2_RECTANGLE_HPP_
#define A2_RECTANGLE_HPP_

#include "shape.hpp"

namespace korshunov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &center, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &center) override;
    void move(double dx, double dy) override;
    void scale(double) override;

  private:
    rectangle_t rectangle_;
  };
}

#endif
