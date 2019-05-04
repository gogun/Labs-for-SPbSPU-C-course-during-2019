#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle:
    public Shape
{
public:
  Triangle(const point_t& A, const point_t& B, const point_t& C);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & pos) override;
  void move(double dx, double dy) override;
  void showParams() const override;
private:
  point_t pos_;
  point_t point1_;
  point_t point2_;
  point_t point3_;
};

#endif
