#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

namespace tagiev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &, const double &, const double &);

    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const double &, const double &) override;
    void move(const point_t &) override;
    void scale(double);

  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif
