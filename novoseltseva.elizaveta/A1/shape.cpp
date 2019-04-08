#include <iostream>
#include "shape.hpp"

void Shape::move(float dx, float dy)
{
  object.pos.x = dx;
  object.pos.y = dy;
  std::cout << "Centr in: " << "X = " << object.pos.x << " Y = " << object.pos.y << std::endl;
}

void Shape::move(const point_t& point)
{
  rectangle_t temp;
  temp.pos = object.pos;
  object.pos.x += point.x;
  object.pos.y += point.y;
  std::cout << "Centr was been in X = " << temp.pos.x << " and Y = " << temp.pos.y << " move to X = " << point.x
      << " and Y = " << point.y << ", and now that is in point:\nX = "
      << object.pos.x << " Y = " << object.pos.y << std::endl;
}

rectangle_t Shape::getFrameRect()
{
  rectangle_t t_rectangle;
  t_rectangle.pos.x = object.pos.x;
  t_rectangle.pos.y = object.pos.y;
  t_rectangle.width = object.width;
  t_rectangle.height = object.height;
  std::cout << "Space param: " << std::endl << "width = " << t_rectangle.width << ", height = " << t_rectangle.height << std::endl;
  return t_rectangle;
}
