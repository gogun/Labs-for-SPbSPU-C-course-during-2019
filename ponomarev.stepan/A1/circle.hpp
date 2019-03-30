#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape {
public:

  Circle(const point_t pos, const double radius);

  double getArea() const override;
  rectangle_t getFrameRate() const override;
  void getInfo() const override;
  void move(const point_t &new_pos) override;
  void move(const double dx, const double dy) override;

private:
  point_t pos_;
  double radius_;
};
#endif //CIRCLE_HPP
