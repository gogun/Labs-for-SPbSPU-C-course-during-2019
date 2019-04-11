#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &, const point_t &, const point_t &);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getCentre() const override;
  void move(double dx, double dy) override;
  void move(const point_t &point) override;
  double getLength(const point_t & p1, const point_t & p2) const;

private:
  point_t p1_, p2_, p3_;
  double const length12_, length23_, length13_;
};


#endif
