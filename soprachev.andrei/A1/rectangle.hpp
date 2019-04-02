//
// Created by Andrei Soprachev on 2019-03-19.
//

#ifndef LAB1_RECTANGLE_HPP
#define LAB1_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &pos, double width, double height);

  Rectangle(const point_t &leftDown, const point_t &rightUp);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  double getWidth() const;

  double getHeight() const;

private:
  //in local space (O(0,0) = pos)
  //храня локальные координаты получаем возможность не менять их при передвижение, масштабиповороте и повороте фигуры
  point_t rightUp;
  point_t leftDown;
};


#endif //LAB1_RECTANGLE_HPP
