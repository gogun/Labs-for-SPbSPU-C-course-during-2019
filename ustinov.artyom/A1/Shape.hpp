#ifndef Shape_hpp
#define Shape_hpp
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t goal) = 0;
  virtual void move(double dx, double dy) = 0;
};

#endif /* Shape_hpp */
