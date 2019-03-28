#ifndef Rectangle_hpp
#define Rectangle_hpp
#include "Shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle();
  Rectangle(rectangle_t in_rect);
  Rectangle(double xx, double yy, double width, double height);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(point_t goal) override;
  virtual void move(double dx, double dy) override;
  void show() const;
private:
  rectangle_t rect_;
};

#endif /* Rectangle_hpp */
