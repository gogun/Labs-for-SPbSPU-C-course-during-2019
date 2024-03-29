#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace ivleva
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, const point_t & center);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & point) override;
    void move(double dx, double dy) override;
    void print() const override;
    void scale(double coefficient) override;
 
  private:
    double radius_;
    point_t center_;
  };
}
#endif
