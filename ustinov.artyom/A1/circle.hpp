#ifndef circle_hpp
#define circle_hpp
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(point_t center, double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t goal) override;
  void move(double dx, double dy) override;
  void show() const override;
private:
  point_t center_;
  double radius_;
};

#endif /* Circle_hpp */
