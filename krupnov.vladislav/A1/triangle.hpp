#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle:
    public Shape {
public:
  Triangle(const point_t &vertex1, const point_t &vertex2, const point_t &vertex3);
  void printInfo() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newPos) override;
  void move(double dx, double dy) override;
private:
  point_t vertices_[3];
  point_t center_;
};
#endif //TRIANGLE_HPP
