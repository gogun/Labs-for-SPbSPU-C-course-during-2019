#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace pylaev {
  class Triangle: public Shape {
  public:
    Triangle(const point_t &, const point_t &, const point_t &); //by coordinates

    double getArea() const override;
    double getSide(const int) const;
    rectangle_t getFrameRect() const override;
    void move(const double, const double) override;
    void move(const point_t &) override;
    void scale(const double) override;
    void printSpec() const override;

  private:
    const int nTops_ = 3;
    point_t coordinates_[3]; //array of tops' coordinates
    point_t getCenter() const;
  };
}

#endif
