#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t center, const double radius);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const point_t point);
  virtual void move(const double x, const double y);
  virtual void getInfo() const;
private:
  point_t center_;
  double radius_;
};

#endif // !CIRCLE_HPP
