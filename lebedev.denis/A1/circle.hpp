#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle: public Shape 
{
public:	
  Circle(point_t pos, double radius);
  
  double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  void move(double x, double y) override;
  void move(point_t poit) override;
  
private:
  double  m_radius;
  point_t m_position;
};
#endif
