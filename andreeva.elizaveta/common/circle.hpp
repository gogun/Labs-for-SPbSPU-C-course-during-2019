#ifndef A2_CIRCLE_HPP
#define A2_CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace andreeva
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &point, double rad);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t &point) override;
    void scale(double factor) override;

  private:
    point_t center_;
    double radius_;
  };
}
#endif
