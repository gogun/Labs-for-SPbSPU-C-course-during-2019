#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace lutsenko
{
  class Circle :public Shape
  {
  public:
    Circle(double radius, const point_t & pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t & point) override;
    void scale(double coefficient) override;
  private:
    double radius_;
    point_t pos_;
  };
}

#endif
