#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace krinkina
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &centre, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &centre) override;
    void move(const double dx, const double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    point_t centre_;
    double width_, height_;
  };
}

#endif //RECTANGLE_HPP
