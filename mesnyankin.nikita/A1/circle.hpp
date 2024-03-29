#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(double radius, const point_t &pos);
  Circle(double radius, double posX, double posY);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double x, double y) override;
  void move(const point_t &point) override;

  double getRadius() const;
  point_t getPos() const;

private:
  double radius_;
  point_t pos_;
};

#endif
