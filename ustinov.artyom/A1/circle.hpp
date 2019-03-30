#ifndef Circle_hpp
#define Circle_hpp
#include "Shape.hpp"

class Circle: public Shape
{
public:
  Circle();
  Circle(double xx, double yy, double radius);
  Circle(point_t center, double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t goal) override;
  void move(double dx, double dy) override;
  void show() const;
private:
  point_t center_;
  double radius_;
};

#endif /* Circle_hpp */
