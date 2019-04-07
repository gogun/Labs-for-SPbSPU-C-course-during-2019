#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle:public Shape {
public:
  Rectangle(const point_t, double, double); //constructor: center of rectangle, width and height
  Rectangle(double, double, double, double); //constructor: coordinates x, y, width and height

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t) override;
  void move(double, double) override;

  void print() const override;
  point_t getPosition() const;
  double getHeight() const;
  double getWidth() const;

private:
  rectangle_t rectCl_;
};
#endif //A1_RECTANGLE_HPP
