#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace shestakova
{
  class Circle : public Shape
  {
  public:
    Circle(point_t pos, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;

  private:
    point_t pos_;
    double radius_;
  };
}
#endif
