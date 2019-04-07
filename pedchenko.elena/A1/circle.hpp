#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t & center, double radius);
  
  void move(const point_t & newCenter) override;
  void move(double dx, double dy) override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void writeInfo() const override;

private:
  double radius_;
  point_t center_;
};

#endif 
