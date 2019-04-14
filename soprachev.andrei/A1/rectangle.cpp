//
// Created by Andrei Soprachev on 2019-03-19.
//

#include "rectangle.hpp"
#include <cassert> //need for assert

//Прямоугольник по центру, ширине и высоте
Rectangle::Rectangle(const point_t &pos, double width, double height) :
  Shape(pos),
  rightUp_(Vector2(width, height) / 2)
{
  assert(width > 0);
  assert(height > 0);
}

//прямоугольник по левой нижней и правой верхней вершине
Rectangle::Rectangle(const point_t &leftDown, const point_t &rightUp) :
  Shape(Vector2(leftDown) + (Vector2(rightUp) - Vector2(leftDown)) / 2),
  rightUp_(Vector2(rightUp) - pos_)
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
  result.pos = this->pos_.getPoint();
  result.width = getWidth();
  result.height = getHeight();
  return result;
}

double Rectangle::getHeight() const
{
  return (rightUp_.y_ * 2);
}

double Rectangle::getWidth() const
{
  return (rightUp_.x_ * 2);
}

std::string Rectangle::getName() const
{
  return "Rectangle";
}



