#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

namespace tagiev
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &, const double &);

    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const double &, const double &) override;
    void move(const point_t &) override;
    void scale(double);

  private:
    point_t center_;
    double radius_;
  };
}

#endif
