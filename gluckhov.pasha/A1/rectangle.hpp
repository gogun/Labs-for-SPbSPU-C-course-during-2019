#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
  public:
    Rectangle(double width, double height, const point_t &position);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printData() const override;
    void move(double dx, double dy) override;
    void move(const point_t & newPos) override;
  private:
    point_t pos_;
    double width_;
    double height_;
};
#endif
