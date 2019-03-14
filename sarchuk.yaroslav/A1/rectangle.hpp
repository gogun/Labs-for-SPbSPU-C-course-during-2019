#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle final : public Shape {
public:
  Rectangle(const point_t &position, const double width, const double height);
  Rectangle(const rectangle_t &info);
  Rectangle();


  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void writeInfo() const override;
  void move(const point_t &pos) override;
  void move(const double dx, const double dy) override;

private:
  point_t pos_;
  double width_, height_;
};

#endif
