#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace zakharova
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, point_t pos);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t newpos) override;
    void scale(double factor) override;

    void getInfo() const override;

  private:
    double radius_;
    point_t pos_;
  };
}

#endif // CIRCLE_HPP
