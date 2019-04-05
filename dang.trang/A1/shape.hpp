#ifndef shape_hpp
#define shape_hpp
#include "base-types.hpp"
class Shape
{
  public:
  virtual ~Shape(){};
  virtual double getArea()const = 0;
  virtual rectangle_t getFrameRect()const = 0;
  virtual void move(const double mX,const double mY) = 0;
  virtual void move(const point_t point) = 0;
  virtual void dataoutput() const =0;
};
#endif
