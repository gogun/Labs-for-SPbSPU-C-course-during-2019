#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t & pos, double width, double height);
  Rectangle(double posX, double posY, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & pos) override;
  void move(const double dX, const double dY) override;
  void printInfo() const override;

private:
  point_t center_;
  double width_, height_;
 };

#endif //RECTANGLE_HPP
