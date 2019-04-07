#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &to_position) = 0;
  virtual void move(const double &dx, const double &dy) = 0;
  virtual void printShapeInfo() const = 0;
  point_t getCentre() const;
protected:
  point_t pos_;
  Shape(const point_t &centre);
};
#endif
