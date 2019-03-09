#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
private:
  point_t center;
  float radius;
  float area;
  reactangle_t frameRect;

public:
  Circle(point_t center, float radius);
  float getArea();
  reactangle_t getFrameRect();
  void move(float x, float y);
  void moveTo(float x, float y);
};

#endif // CIRCLE_HPP
