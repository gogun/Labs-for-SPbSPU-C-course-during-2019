#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double radius, const point_t & pos);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const point_t & pos);
  virtual void move(double x, double y);
  
private:
  double radius_;
  point_t pos_;
};

#endif
