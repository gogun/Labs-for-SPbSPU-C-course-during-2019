#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <iostream>
#include <stdexcept>

class Shape
{
public:
  virtual ~Shape() = default;
  virtual void printInfo() const = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &newPos) = 0;
  virtual void move(double dx, double dy) = 0;
};
#endif //SHAPE_HPP
