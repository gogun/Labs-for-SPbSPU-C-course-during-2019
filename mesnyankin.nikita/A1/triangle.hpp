#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t &a, const point_t &b, const point_t &c);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double x, double y) override;
  void move(const point_t &point) override;

  void showCoordinates() const;

  point_t getA() const;
  point_t getB() const;
  point_t getC() const;
  double getAB() const;
  double getBC() const;
  double getCA() const;
  point_t getPos() const;

private:
  point_t a_;
  point_t b_;
  point_t c_;
  point_t pos_;
};

#endif
