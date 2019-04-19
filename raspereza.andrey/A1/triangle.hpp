#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t &vertexA, const point_t &vertexB, const point_t &vertexC);

  double getArea() const override;
  void printInfo() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newPoint) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  point_t vertexA_;
  point_t vertexB_;
  point_t vertexC_;
};

#endif //TRIANGLE_HPP
