#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"


class Rectangle: public Shape
{
public:
  Rectangle(const point_t & center, double width, double height);
  
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & centerPoint) override;
  void move(double dx, double dy) override;
  void writeInfo() const override;

private:
  rectangle_t rectangle_;
};

#endif 
