#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace sysoeva
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t vertex1, point_t vertex2, point_t vertex3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void showCoord();
    void printCenter();
  private:
    point_t vertex_1;
    point_t vertex_2;
    point_t vertex_3;
    point_t center_;
    point_t getCenter() const;
  };
}

#endif
