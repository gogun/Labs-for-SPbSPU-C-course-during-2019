#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace utin
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &, const double &);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double &, const double &) override;
    void move(const point_t &) override;
    void printInfo() const override;
    void scale(const double &) override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
