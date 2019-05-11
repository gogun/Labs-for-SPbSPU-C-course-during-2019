#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace potapova
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double radius);
    double getArea() const override;
    void move(double dx, double dy) override;
    void move(const point_t &center) override;
    void scale(double coefficient) override;
    rectangle_t getFrameRect() const override;
  private:
    point_t center_;
    double radius_;
  };
}


#endif // CIRCLE_HPP
