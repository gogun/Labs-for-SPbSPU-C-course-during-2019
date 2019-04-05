#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
  public:
    virtual ~Shape() = default;

    virtual void displayData() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;

    virtual void move (double dx, double dy) = 0;
    virtual void move (const point_t &dot) = 0;
};
#endif
