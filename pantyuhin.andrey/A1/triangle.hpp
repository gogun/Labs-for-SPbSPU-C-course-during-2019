#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t vertex1, point_t vertex2, point_t vertex3);
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

  point_t getCentre() const;
  double getPerimeter() const;
  void printParameters() const;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t newCentre) override;

private:

  point_t vertex_[3];
  double getSide(int vertex1, int vertex2) const;
};

#endif //A_TRIANGLE_HPP
