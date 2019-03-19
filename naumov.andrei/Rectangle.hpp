#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle: public Shape
{
public:
  const float getArea();
  const rectangle_t getFrameRect();
  void move(point_t & newCentre);
  void move(float newX, float newY);

  void setWidth(float newWidth);
  void setHeight(float newHeight);
protected:
  float width_;
  float height_;
private:
};

#endif // !RECTANGLE_HPP

