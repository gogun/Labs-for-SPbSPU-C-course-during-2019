#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double Wid, double Hei, double xrect, double yrect); 
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double mX, double mY);
  void move(const point_t &point);
  void dataoutput() const;
private: 
  rectangle_t rrect_;
};

#endif


