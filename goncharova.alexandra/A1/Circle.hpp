#ifndef Circle_hpp

#define Circle_hpp


#include "Shape.hpp"



class Circle: public Shape

{

public:

  point_t center_;

  double radius_;

  Circle(const point_t &center, double radius);

  double getArea() const;

  rectangle_t getFrameRect() const;

  void move(const point_t &newPoint);

  void move(double dx, double dy);

};


#endif
