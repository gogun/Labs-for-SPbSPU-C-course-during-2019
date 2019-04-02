//
// Created by Andrei Soprachev on 2019-03-31.
//

#ifndef LAB1_CIRCLE_HPP
#define LAB1_CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, double radius);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

private:
  double radius;
};


#endif //LAB1_CIRCLE_HPP
