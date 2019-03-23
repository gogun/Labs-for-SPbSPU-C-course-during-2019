#ifndef AP_A1_SHAPE
#include "shape.hpp"
#define AP_A1_SHAPE
#endif

class Circle:public Shape
{
public:
  Circle(double,double,double);
  Circle(const point_t&,double);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t&) override;
  void move(double,double) override;
  void show() const override;

  const point_t& getPos() const;
  double getRadius() const;
  
private:
  point_t pos_;
  double radius_;

  void check() const override;
};