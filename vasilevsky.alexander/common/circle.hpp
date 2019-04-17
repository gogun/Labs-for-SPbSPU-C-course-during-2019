#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace vasilevsky
{
  class Circle: public Shape
  {
  public:
    Circle(const double &, const point_t &);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(const double &, const double &) override;
    void printInfo() const override;
    void scale(const double &) override;

  private:
    double radius_;
    point_t center_;
  };
}

#endif
