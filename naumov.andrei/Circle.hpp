#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include"Shape.hpp"

class Circle: public Shape
{
public:
  const float getArea();
  const rectangle_t getFrameRect();
  void move(point_t & newCentre);
  void move(float newX, float newY);
  
  void setRadius(float newRadius);
protected:
  float radius_;
private:
};

#endif // !CIRCLE_HPP

