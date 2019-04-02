#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-type.hpp"

class Shape {
public:
  virtual ~Shape() = default; //distructor
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void printSpec() const = 0;
  void move(double, double);
  void move(const point_t &); //move figure to new center
protected:
  point_t center_;
  Shape(const point_t &); //constructor
};

#endif
