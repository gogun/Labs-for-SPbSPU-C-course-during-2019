#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace zybkin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &, double, double);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void printInfo() const;
    void move(const point_t &);
    void move(double, double);
    void scale(double);

  private:
    double height_;
    double width_;
    point_t center_;
  };
}

#endif /* RECTANGLE_HPP */
