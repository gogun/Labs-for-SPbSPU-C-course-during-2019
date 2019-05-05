#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t &, const point_t &, const point_t &);

  double getArea() const override;
  void printInfo() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &) override;
  void move(double dx, double dy) override;

private:
  point_t vertexA_;
  point_t vertexB_;
  point_t vertexC_;
  point_t center_;
};

#endif //TRIANGLE_HPP
