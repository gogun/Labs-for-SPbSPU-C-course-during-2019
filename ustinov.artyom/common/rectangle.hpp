#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace ustinov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t &center, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &goal) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void show() const override;

  private:
    rectangle_t rect_;
  };
};
#endif /* Rectangle_hpp */
