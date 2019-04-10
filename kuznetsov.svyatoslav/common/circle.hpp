#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace kuznetsov
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &, double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &position) override;
    void move(double, double) override;
    void printInfo() const override;
    void scale(double) override;

  private:
    double radius_;
    point_t center_;
  };
}

#endif //CIRCLE_HPP
