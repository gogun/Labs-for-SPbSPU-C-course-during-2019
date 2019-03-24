#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape{
public:
  virtual rectangle_t getFrameArea()
  {
    rectangle_t framed;
    framed.width = right_upper.x - left_bottom.x;
    framed.height = left_upper.y - right_bottom.y;
    framed.pos.x = (left_bottom.x + right_upper.x)/2;
    framed.pos.y = (left_bottom.y + right_upper.y)/2;
    return framed;
  }
};

#endif
