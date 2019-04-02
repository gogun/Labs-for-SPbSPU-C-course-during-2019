#include <iostream>
#include <cassert> //need for assetr
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "shape.hpp"


std::string rectToString(rectangle_t rectangle)
{
  return "pos = (" + std::to_string(rectangle.pos.x) + "; " + std::to_string(rectangle.pos.y) + ")\nwidth = " +
         std::to_string(rectangle.width) + "\nheight = " + std::to_string(rectangle.height);
}

std::string shapeToString(Shape *shape)
{
  assert(shape != nullptr);
  return rectToString(shape->getFrameRect()) + "\narea = " + std::to_string(shape->getArea());
}


int main()
{
  //прямоугольник по центру, высоте и ширине
  Rectangle rectangleByPosWH = Rectangle(point_t{1, 5}, 4, 2);

  //прямоугольник по двум вершинам
  Rectangle rectangleByLeftDownRightUp = Rectangle(point_t{4, 4}, point_t{5, 5});

  //круг по центру и радиусу
  Circle circle = Circle(point_t{3, 4}, 2);

  //треугольниу по центру масс и координатам относительно центра масс
  Triangle triangleByPosAndLocalVert = Triangle(point_t{2, 5}, point_t{-2, -2}, point_t{4, -2}, point_t{-2, 4});

  //треугольник по трём точкам
  Triangle triangleByWorldVert = Triangle(point_t{4, 5}, point_t{-1, 9}, point_t{0, 3});

  Shape *shape[6];
  shape[0] = &rectangleByPosWH;
  shape[1] = &rectangleByLeftDownRightUp;
  shape[2] = &circle;
  shape[3] = &triangleByPosAndLocalVert;
  shape[4] = &triangleByWorldVert;


  for (int i = 0; shape[i] != nullptr; i++)
  {
    std::cout << shapeToString(shape[i]) << "\n\n";
  }

  shape[0]->move(1, 2); //перемещение на вектор
  shape[1]->move(point_t{1, 1}); //перемещение в точку
  shape[2]->move(-1, -3); //перемещение на вектор
  shape[3]->move(1, 2); //перемещение на вектор
  shape[4]->move(point_t{1, 1}); //перемещение в точку

  std::cout <<  "after move: \n\n";

  for (int i = 0; shape[i] != nullptr; i++)
  {
    std::cout << shapeToString(shape[i]) << "\n\n";
  }

  return 0;
}
