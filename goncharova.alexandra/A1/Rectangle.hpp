#ifndef Rectangle_hpp

#define Rectangle_hpp

#include "Shape.hpp"

class Rectangle : public Shape

{

public:

  double height_;

  double width_;

  point_t center_;

  Rectangle(const point_t &center, double width, double height);

  double getArea() const;

  rectangle_t getFrameRect() const;

  void move(const point_t &newPoint);

  void move(double dx, double dy);

};

#endif