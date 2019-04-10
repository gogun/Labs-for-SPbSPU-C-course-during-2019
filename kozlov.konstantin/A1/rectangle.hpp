#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const rectangle_t &rect);
  virtual void printData() const override;
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t & pos) override;
  virtual void move(const double x, const double y) override;

private:
  rectangle_t rect_;
};

#endif
