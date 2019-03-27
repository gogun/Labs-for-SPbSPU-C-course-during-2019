#ifndef A1_SHAPE
#define A1_SHAPE

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual point_t getPos() const = 0;
  virtual void move(const point_t& centre) = 0;
  virtual void move(double mx, double my) = 0;
};

#endif
