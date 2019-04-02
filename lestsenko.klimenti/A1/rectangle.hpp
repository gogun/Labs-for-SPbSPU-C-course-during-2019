#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double, double, const point_t &);
  
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newPos) override;
  void move(double dx, double dy) override;
  point_t getPos() const override;

private:
  double height_;
  double width_;
  point_t center_;
};

#endif // RECTANGLE_HPP
