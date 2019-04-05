#ifndef Circle_hpp

#define Circle_hpp



#include "Shape.hpp"



class Circle: public Shape

{

public:

  double radius_;

  point_t center_;

  Circle(const point_t &center, double radius);

  double getArea() const;

  rectangle_t getFrameRect() const;

  void move(const point_t &newPoint);

  void move(double dx, double dy);

};



#endif