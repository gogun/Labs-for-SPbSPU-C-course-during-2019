#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t pos, const double width, const double height);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const point_t point);
  virtual void move(const double x, const double y);
  virtual void getInfo() const;
private:
  double width_;
  double height_;
  point_t center_;
};

#endif // !RECTANGLE_HPP