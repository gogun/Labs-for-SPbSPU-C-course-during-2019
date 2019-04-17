#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &, const point_t &, const point_t &);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move (const point_t &) override;
  void move (double,  double) override;
  void printInfo() const override;

  double getSide(const point_t &, const point_t &);

private:
  point_t center_;
  point_t pointA_, pointB_, pointC_;
  double a_, b_, c_;
};

#endif
