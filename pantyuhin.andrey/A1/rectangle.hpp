#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  
  Rectangle(point_t centre, double width, double height);
  Rectangle(double x, double y, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printParameters() const override;
  void move(double dx, double dy) override;
  void move(point_t centre) override;

private:

  point_t centre_;
  double width_;
  double height_;

};

#endif //RECTANGLE_HPP
