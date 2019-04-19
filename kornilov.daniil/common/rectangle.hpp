#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

namespace kornilov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const rectangle_t& parameters);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const point_t& point) override;
    void scale(const double coefficient) override;

  private:
    rectangle_t rectangle_;
  };
}

#endif
