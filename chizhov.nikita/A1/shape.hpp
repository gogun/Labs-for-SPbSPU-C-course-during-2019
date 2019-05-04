#ifndef CN_A1_SHAPE
#define CN_A1_SHAPE
#include "base-types.hpp"

class Shape {
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void move(point_t point) = 0;
};
#endif
