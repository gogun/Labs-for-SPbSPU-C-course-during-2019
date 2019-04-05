#ifndef circle_hpp

#define circle_hpp



#include "shape.hpp"



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
