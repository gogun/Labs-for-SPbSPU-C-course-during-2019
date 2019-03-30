#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &, const double &, const double &);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & position) override;
  void move(const double &, const double &) override;
  void printInfo() const override;

private:
  double width_;
  double height_;
  point_t center_;
};

#endif //RECTANGLE_HPP