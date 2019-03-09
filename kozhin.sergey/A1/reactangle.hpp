#ifndef REACTANGLE_HPP
#define REACTANGLE_HPP
#include "shape.hpp"

class Reactangle : public Shape
{
private:
  point_t center;
  float width;
  float height;
  float area;
  reactangle_t frameRect;

public:
  Reactangle(point_t center, float width, float height);
  float getArea();
  reactangle_t getFrameRect();
  void move(float x, float y);
  void moveTo(float x, float y);
};

#endif // REACTANGLE_HPP
