#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base_types.hpp"

class Shape
{
  public:
  virtual ~Shape() = default;
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  void move(const point_t newPoint)
  {
    this->centre = newPoint;
  };
  void move(const double dx, const double dy)
  {
    double newX = this->centre.x + dx;
    double newY = this->centre.y + dy;

    this->centre = { newX, newY };
  };

  protected:
  point_t centre;
};

#endif
