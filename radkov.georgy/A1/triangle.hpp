#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle:
  public Shape
{
public:
  Triangle(const point_t &pos_a, const point_t &pos_b, const point_t &pos_c);
  point_t getPos() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &pos) override;
  void move(const double dx, const double dy) override;
  void printInformation() const override;

private:
  point_t corners_[3];
};

#endif
