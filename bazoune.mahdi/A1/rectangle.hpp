#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.hpp"

class Rectangle : public Shape
{
public: 
  Rectangle(double setWidth, double setHeight, const point_t& setCenter);
  void print() const override;
  double getArea() const override;
  void move(const point_t& move) override;
  void move(const double dx,const double dy) override;
  rectangle_t getFrameRect() const override;
private:
  double width_, height_;
  point_t center_;
};

#endif