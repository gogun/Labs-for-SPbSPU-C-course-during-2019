#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t& pA, const point_t& pB, const point_t& pC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(const double dx, const double dy) override;
  std::string getName() const override;

private:
  point_t centre_;
  point_t pointA_;
  point_t pointB_;
  point_t pointC_;
};

#endif
