#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  float getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t & newCentre);
  void move(float newX, float newY);

  void setWidth(float newWidth);
  void setHeight(float newHeight);
protected:
  float width_;
  float height_;
private:
};

#endif // !RECTANGLE_HPP
