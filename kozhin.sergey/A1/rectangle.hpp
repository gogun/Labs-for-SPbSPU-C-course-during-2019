#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
private:
  point_t center;
  float width;
  float height;
  float area;
  reactangle_t frameRect;

public:
  Rectangle(point_t center, float width, float height);
  float getArea();
  reactangle_t getFrameRect();
  void move(float x, float y);
  void moveTo(float x, float y);
};

#endif // RECTANGLE_HPP
