#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &p1, const point_t &p2, const point_t &p3);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &pos) override;
  void move(double dx, double dy) override;
  void printInfo() const override;

private:
  point_t A_;
  point_t B_;
  point_t C_;
  point_t findCenter() const;
  static double getDistance(const point_t &p1, const point_t &p2);
};

#endif //TRIANGLE_HPP
