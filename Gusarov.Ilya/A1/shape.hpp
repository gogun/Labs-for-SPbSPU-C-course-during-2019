#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.hpp"
//#define _USE_MATH_DEFINES
//#include <cmath>

class Shape{
public:
  rectangle_t data_of_rectangle;
  double radius;
  point_t centre;
  point_t left_bottom;
  point_t left_upper;
  point_t right_bottom;
  point_t right_upper;

  virtual double getArea()
  {
    return data_of_rectangle.width * data_of_rectangle.height;
  }
  virtual rectangle_t getFrameArea()
  {
    rectangle_t framed;
    framed.width = 2*radius;
    framed.height = 2*radius;
    framed.pos = centre;
    return framed;
  }
  void move(point_t &lastPoint, point_t newPoint)
  {
    lastPoint.x = newPoint.x;
    lastPoint.y = newPoint.y;
  }
  void move(point_t &lastPoint, double shiftX, double shiftY)
  {
    lastPoint.x += shiftX;
    lastPoint.y += shiftY;
  }
};

#endif
