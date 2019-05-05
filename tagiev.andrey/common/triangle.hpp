#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.hpp"

namespace tagiev
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t &, const point_t &, const point_t &);

    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const point_t &) override;
    void move(const double &, const double &) override;
    void scale(double);

  private:
    point_t pointA_;
    point_t pointB_;
    point_t pointC_;
    point_t center_;
  };
}

#endif
