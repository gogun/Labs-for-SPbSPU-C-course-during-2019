#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace krinkina
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double dx, const double dy) = 0;
    virtual void move(const point_t &centre) = 0;
    virtual void scale(double coefficient) = 0;
    virtual void printInfo() const = 0;
  };
}

#endif // SHAPE_HPP
