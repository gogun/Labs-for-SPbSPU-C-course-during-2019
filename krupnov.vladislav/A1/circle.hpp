#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &p, const double &R);
  double getArea() const override;
  double getRadius() const;
  rectangle_t getFrameRect() const override;
  void setRadius(const double &R);
  void move(const point_t &p) override;
  void move(const double &x, const double &y) override;
  void printInfo() const;
  void getCenterInfo() const override;
private:
  double r_;
  point_t center_;
};
#endif
