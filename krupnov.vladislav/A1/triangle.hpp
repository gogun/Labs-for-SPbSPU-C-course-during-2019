#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle:
    public Shape {
public:
  Triangle(const point_t &top1, const point_t &top2, const point_t &top3);
  void printInfo() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newPos) override;
  void move(double dx, double dy) override;
private:
  point_t tops_[3];
  point_t center_;
};
#endif //TRIANGLE_HPP
