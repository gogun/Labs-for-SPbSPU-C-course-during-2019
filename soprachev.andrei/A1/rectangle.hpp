//
// Created by Andrei Soprachev on 2019-03-19.
//

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &pos, double width, double height);
  Rectangle(const point_t &leftDown, const point_t &rightUp);
  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  double getWidth() const;
  double getHeight() const;

private:
  //in local space
  Vector2 rightUp_;
};


#endif //RECTANGLE_HPP
