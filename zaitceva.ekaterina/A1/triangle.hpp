#ifndef UNTITLED1_TRIANGLE_H
#define UNTITLED1_TRIANGLE_H

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &point1, const point_t &point2, const point_t &point3);
  point_t getCentre() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(double dx, double dy) override;
  void printTriang() const;

private:
  point_t point1_;
  point_t point2_;
  point_t point3_;
  point_t centre_;
  double side1_;
  double side2_;
  double side3_;
};

#endif
