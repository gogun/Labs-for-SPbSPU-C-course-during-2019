#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const rectangle_t &rect);
  Rectangle(double width, double height, const point_t &pos);
  Rectangle(double width, double height, double posx, double posy);

  double getWidth() const;
  double getHeight() const;
  point_t getPos() const;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double x, double y) override;
  void move(const point_t &point) override;

private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
