#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t & Centre, double width, double height);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t & newCentre);
  void move(double dX, double dY);
  void setWidth(double newWidth);
  void setHeight(double newHeight);
protected:
  double width_;
  double height_;
private:
};

#endif // !RECTANGLE_HPP
