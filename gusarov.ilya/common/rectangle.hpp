#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.hpp"

namespace gusarov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t &, const double, const double);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const double, const double) override;
    void move(const point_t &) override;
    void printInfo() const override;
    void scale(const double) override;
    double getHeight() const;
    double getWidth() const;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif
