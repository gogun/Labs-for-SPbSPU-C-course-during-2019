#ifndef Circle_hpp
#define Circle_hpp
#include "Shape.hpp"

class Circle: public Shape
{
public:
  Circle();
  Circle(double xx, double yy, double radius);
  Circle(point_t center, double radius);
  //~Circle();
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(point_t goal) override;
  virtual void move(double dx, double dy) override;
  void show() const;
private:
  point_t center_;
  double radius_;
};

#endif /* Circle_hpp */
