#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual const float getArea() = 0;
  virtual const rectangle_t getFrameRect() = 0;
  virtual void move(point_t & newCentre) = 0;
  virtual void move(float newX, float newY) = 0;

  const point_t & getCentre() { return centre_; }
protected:
  point_t centre_;
private:
};

#endif // !SHAPE_HPP