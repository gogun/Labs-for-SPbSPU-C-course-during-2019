#ifndef rectangle_hpp
#define rectangle_hpp
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle();
  Rectangle(rectangle_t in_rect);
  Rectangle(double xx, double yy, double width, double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t goal) override;
  void move(double dx, double dy) override;
  void show() const;
private:
  rectangle_t rect_;
};

#endif /* Rectangle_hpp */
