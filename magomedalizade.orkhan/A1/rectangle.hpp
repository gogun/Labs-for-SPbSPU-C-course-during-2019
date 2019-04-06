#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "base-types.hpp"
#include "Shape.hpp"

class Rectangle: 
  public Shape {
public:
  Rectangle(const point_t &place, const double width, const double height);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void getInfo() const;
  point_t getPlace() const;
  double getWidth() const;
  double getHeight() const;
  void scale(const double scoping);
private:
  double width_, height_;	
};

#endif
