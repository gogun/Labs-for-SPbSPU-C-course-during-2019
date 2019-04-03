#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &pos, const double &width, const double &height);
  
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printInfo() const override;

  void move(const double &dx, const double &dy) override;
  void move(const point_t &pos) override;

private: 
  double width_, height_;
  point_t pos_;
};

#endif
