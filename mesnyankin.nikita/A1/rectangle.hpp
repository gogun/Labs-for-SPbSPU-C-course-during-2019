#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle: public Shape {

public:
  Rectangle(const rectangle_t &rect);
  Rectangle(const double &width, const double &height, const point_t &pos);
  Rectangle(const double &width, const double &height, const double &posx, const double &posy);

  double getWidth();
  double getHeight();
  point_t getPos();

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double &x, const double &y) override;
  void move(const point_t &point) override;

private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
