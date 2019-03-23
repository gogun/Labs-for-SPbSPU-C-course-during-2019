#ifndef AP_A1_SHAPE
#define AP_A1_SHAPE
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t  getFrameRect() const = 0;
  virtual void move(const point_t&) = 0;
  virtual void move(double,double) = 0;
  virtual void show() const = 0;
  
protected:
  virtual void check() const = 0;
};
#endif // AP_A1_SHAPE