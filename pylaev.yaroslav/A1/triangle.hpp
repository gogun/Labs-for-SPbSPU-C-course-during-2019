#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#define nTops 3

#include "shape.hpp"

class Triangle: public Shape {
public:
  Triangle(const point_t &, const double *);
  Triangle(const point_t &, const double); //equilateral triangle

  double getArea() const override;
  double getAreaByCoordinates() const;
  double getSide(const int) const;
  rectangle_t getFrameRect() const override;
  void move(const double, const double) override;
  void move(const point_t &) override;
  void printSpec() const override;
private:
  const int nTops_ = nTops;
  point_t center_;
  double sides_[nTops]; // array of lengths
  point_t coordinates_[nTops]; //array of tops' coordinates
  void setCoordinates();
  };

#endif
