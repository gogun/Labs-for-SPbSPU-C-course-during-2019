#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle :
    public Shape {
public:
  
  Circle(double radius, const point_t pos);

  void info() const;
  double getArea() const override;
  rectangle_t getFrameRate() const override;
  void move(const pos_t &new_pos) override;
  void move(const doble dx, const double dy) override;

private:
  double radius_;
  point_t pos_;
};
#endif //CIRCLE_HPP
