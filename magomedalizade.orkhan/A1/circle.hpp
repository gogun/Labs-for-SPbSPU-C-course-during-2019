#ifndef Circle_hpp
#define Circle_hpp

#include "base-types.hpp"
#include "Shape.hpp"

class Circle:
  public Shape {
public:
  Circle(const point_t &place, const double radius);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void getInfo() const;
  void scale(const double scoping);
  point_t getPlace() const;
  double getRadius() const;
private:  
  double radius_; 
};
#endif
