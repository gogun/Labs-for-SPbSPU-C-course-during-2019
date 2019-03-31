#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  
  Rectangle(point_t centre, double widh, double height);
  Rectangle(double x, double y, double widh, double height);

  point_t getPos() const;
  double getWidh() const;
  double getHeight() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t centre) override;

private:

  point_t centre_;
  double widh_;
  double height_;

};

#endif //RECTANGLE_HPP
