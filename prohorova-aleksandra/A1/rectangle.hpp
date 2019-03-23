#ifndef AP_A1_SHAPE
#include "shape.hpp"
#define AP_A1_SHAPE
#endif
class Rectangle:public Shape
{
public:
  Rectangle(double,double,double,double);
  Rectangle(const point_t&,double,double);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t&) override;
  void move(double,double) override;
  void show() const override;

  double getWidth() const;
  double getHeight() const;
  point_t getPos() const;

private:
  rectangle_t rect_;
  void check() const override;
};
