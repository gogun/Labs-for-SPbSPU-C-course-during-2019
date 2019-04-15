#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.hpp"



class Triangle : public Shape
{
public:
  Triangle(const point_t & point1, const point_t & point2, const point_t & point3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  virtual void move(const point_t & pos) override;
  void move(const double &x, const double &y) override;
  void printInfo() const;
  void getCenterInfo() const override;

private:
  point_t p1_;
  point_t p2_;
  point_t p3_;
  point_t center_;
};
#endif
