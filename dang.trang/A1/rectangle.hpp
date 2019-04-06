#ifndef rectangle_hpp
#define rectangle_hpp
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double Wid, double Hei, double xrect, double yrect); 

  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const double mX,const double mY);
  void move(const point_t point);
  void dataoutput() const;
private: rectangle_t rrect;
};
#endif
