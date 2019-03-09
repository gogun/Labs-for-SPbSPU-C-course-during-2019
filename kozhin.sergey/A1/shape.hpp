#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual float getArea() = 0;
  virtual reactangle_t getFrameRect() = 0;
  virtual void move(float x, float y) = 0;
  virtual void moveTo(float x, float y) = 0;
  virtual ~Shape(){};
};

#endif // SHAPE_HPP
