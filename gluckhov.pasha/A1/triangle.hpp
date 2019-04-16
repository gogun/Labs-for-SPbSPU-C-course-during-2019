#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle: public Shape
{
  public:
    Triangle(const point_t &vertexA, const point_t &vertexB, const point_t &vertexC);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printData() const override;
    void move(double dx, double dy) override;
    void move(const point_t &newPos) override;
  private:
    point_t pos_;
    point_t vertexA_;
    point_t vertexB_;
    point_t vertexC;
};
#endif
