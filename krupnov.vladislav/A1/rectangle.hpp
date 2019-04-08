#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &p, const double &w, const double &h);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void setWidth(const double &w);
  void setHeight(const double &h);
  void move(const point_t &p) override;
  void move(const double &x, const double &y) override;
  void printInfo() const;
  void getCenterInfo() const;
private:
  double width_;
  double height_;
  point_t center;
};
#endif
