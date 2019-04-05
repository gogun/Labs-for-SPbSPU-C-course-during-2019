#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &position, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(const point_t &newPosition) override;
  void move(double dx, double dy) override;

private:
  point_t position_;
  double width_;
  double height_;
};

#endif //RECTANGLE_HPP
