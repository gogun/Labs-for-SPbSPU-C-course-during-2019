#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle: public Shape
{
  public:
    Triangle(double base, double height, const point_t &position);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printData() const override;
    void move(double dx, double dy) override;
    void move(const point_t & newPos) override;
  private:
    double height_;
    double base_;
    point_t pos_;
};
#endif
