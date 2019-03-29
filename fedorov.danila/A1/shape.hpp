#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  Shape();
  Shape(const point_t &position);
  virtual ~Shape() = default;

  virtual rectangle_t getFrameRect() const = 0;
  virtual double getArea() const = 0;

  virtual void printInfo() const;
  void move(const point_t &point);
  void move(double dx, double dy);

protected:
  point_t position_;
};

#endif //SHAPE_HPP
