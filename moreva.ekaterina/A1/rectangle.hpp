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
  void move(const double newX, const double newY) override;
  void printInfo() const override;

 private:
  double width_, height_;
  point_t center_;
};

#endif //RECTANGLE_HPP
