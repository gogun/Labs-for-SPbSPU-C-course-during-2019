#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(double side1, double side2, double side3, const point_t &center);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &pos) override;
  void move(double dx, double dy) override;
  void printInfo() const override;

private:
  double side1_;
  double side2_;
  double side3_;
  point_t pos_;
};

#endif //TRIANGLE_HPP
