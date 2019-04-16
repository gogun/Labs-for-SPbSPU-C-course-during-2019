#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle: public Shape {
public:
  Triangle(const point_t &, const double, const double, const double);
  Triangle(const point_t &, const double, const double); //isosceles triangle
  Triangle(const point_t &, const double); //equilateral triangle
  Triangle(const point_t &, const point_t &, const point_t &); //by coordinates

  double getArea() const override;
  point_t getCenter() const;
  double getSide(const int) const;
  rectangle_t getFrameRect() const override;
  void move(const double, const double) override;
  void move(const point_t &) override;
  void printSpec() const override;

private:
  const int nTops_ = 3;
  point_t center_;
  point_t coordinates_[3]; //array of tops' coordinates
  void setCoordinates(const double &, const double &, const double &);
  double getArea(const double &, const double &, const double &) const;
};

#endif
