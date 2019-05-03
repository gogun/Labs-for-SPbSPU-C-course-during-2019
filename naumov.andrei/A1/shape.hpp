#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  Shape(const point_t& centre) :
    centre_(centre)
  {}
  virtual ~Shape() = default;
  virtual double getArea() const  = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t & newCentre) = 0;
  virtual void move(double dX, double dY) = 0;
  const point_t & getCentre() const
  { 
    return centre_;
  }
protected:
  point_t centre_;
private:
};

#endif // !SHAPE_HPP
