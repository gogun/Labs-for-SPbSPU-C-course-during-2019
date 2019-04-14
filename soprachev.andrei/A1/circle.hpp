//
// Created by Andrei Soprachev on 2019-03-31.
//

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, double radius);
  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;

private:
  double radius_;
};


#endif //CIRCLE_HPP
