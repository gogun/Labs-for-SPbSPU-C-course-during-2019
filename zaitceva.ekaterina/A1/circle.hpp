#ifndef LAB1_1_CIRCLE_H
#define LAB1_1_CIRCLE_H

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle (point_t centre, double rad);
  double getArea () const override;
  rectangle_t getFrameRect () const override;
  void move (point_t pnt) override;
  void move (double abs, double ord) override;
private:
    point_t pos_;
    double radius_;
};

#endif //LAB1_1_CIRCLE_H
