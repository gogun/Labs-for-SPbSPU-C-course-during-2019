#ifndef Rectangle_hpp

#define Rectangle_hpp


#include "Shape.hpp"


class Rectangle : public Shape

{

public:

  point_t center_;

  double width_;
  double height_;

  Rectangle(const point_t &center, double width, double height);

  double getArea() const;

  rectangle_t getFrameRect() const;

  void move(const point_t &newPoint);

  void move(double dx, double dy);

};


#endif
