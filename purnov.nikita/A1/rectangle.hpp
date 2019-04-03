#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const double width, const double height, const point_t & pos);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const point_t & pos);
  virtual void move(double x, double y);
  
private:
  rectangle_t rect_;
};

#endif
