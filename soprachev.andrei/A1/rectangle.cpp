//
// Created by Andrei Soprachev on 2019-03-19.
//

#include "rectangle.hpp"
#include <cassert> //need for assetr

//Прямоугольник по центру, ширине и высоте
Rectangle::Rectangle(const point_t &pos, double width, double height) :
  Shape(pos),

  leftDown
    (
      point_t
        {
          -width / 2,
          -height / 2
        }
    ),

  rightUp
    (
      point_t
        {
          width / 2,
          height / 2
        }
    )
{
  assert(width > 0);
  assert(height > 0);

}

//прямоугольник по левому нижнему и правому верхнему углам
Rectangle::Rectangle(const point_t &leftDown, const point_t &rightUp) :
  Shape
    (
      point_t
        {
          leftDown.x + (rightUp.x - leftDown.x) / 2,
          leftDown.y + (rightUp.y - leftDown.y) / 2
        }
    ),
  leftDown(leftDown - pos),
  rightUp(rightUp - pos)
{
  assert(rightUp.x > leftDown.x);
  assert(rightUp.y > leftDown.y);
}


double Rectangle::getArea() const
{
  return getWidth() * getHeight();
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t result;
  result.width = getWidth();
  result.height = getHeight();
  result.pos = this->pos;
  return result;
}

double Rectangle::getHeight() const
{
  return (rightUp.y - leftDown.y);
}


double Rectangle::getWidth() const
{
  return (rightUp.x - leftDown.x);
}



