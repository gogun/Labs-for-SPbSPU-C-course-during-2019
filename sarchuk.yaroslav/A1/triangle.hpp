#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle final : public Shape {
public:
  Triangle(const point_t &first, const point_t &second, const point_t &third);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void writeInfo() const override;
  void move(const point_t &pos) override;
  void move(const double dx, const double dy) override;

private:
  point_t pos_;
  point_t first_, second_, third_;
  double a_, b_, c_;
};

#endif
