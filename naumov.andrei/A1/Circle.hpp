#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include"Shape.hpp"

class Circle: public Shape
{
public:
  float getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t & newCentre);
  void move(float newX, float newY);
  
  void setRadius(float newRadius);
protected:
  float radius_;
private:
};

#endif // !CIRCLE_HPP
