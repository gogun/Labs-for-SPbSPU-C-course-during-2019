#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle: public Shape {
public:
  Triangle(const point_t &, const double *);
  Triangle(const point_t &, const double); //equilateral triangle

  double getArea(const double *) const;
  double getArea() const override;
  double getSide(const int) const;
  rectangle_t getFrameRect() const override;
  void move(const double, const double) override;
  void move(const point_t &) override;
  void printSpec() const override;

private:
  const int nTops_ = 3;
  point_t center_;
  point_t coordinates_[3]; //array of tops' coordinates
  void setCoordinates(const double *sides);
};

#endif
