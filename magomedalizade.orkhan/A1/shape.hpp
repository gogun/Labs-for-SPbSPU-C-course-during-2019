#ifndef shape_hpp
#define shape_hpp
#include "base-types.hpp"

class Shape
{
public:
  Shape(const point_t &place);
  virtual double getArea() const =0;
  virtual rectangle_t getFrameRect() const =0;
  virtual void move(const double dx, const double dy);
  virtual void move(point_t &a);
  virtual void getInfo() const =0;
  virtual point_t getPlace() const =0;
  virtual void scale(const double scoping)=0;
protected:
  point_t place_;
};

#endif

