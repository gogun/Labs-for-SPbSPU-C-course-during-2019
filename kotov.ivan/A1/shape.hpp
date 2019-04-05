#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "base-types.hpp"

class Shape
{

public:

  virtual ~Shape() = default;

  virtual std::string getShapeName() const = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t & newPos) = 0;
  virtual void move(double dX, double dY) = 0;
};

#endif // SHAPE_HPP
