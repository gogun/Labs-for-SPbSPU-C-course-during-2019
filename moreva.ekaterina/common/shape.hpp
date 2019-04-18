#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace moreva
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double nX, const double nY) = 0;
    virtual void move(const point_t & pos) = 0;
    virtual void scale(double factor) = 0;
    virtual void printInfo() const = 0;
  };
}

#endif //SHAPE_HPP
