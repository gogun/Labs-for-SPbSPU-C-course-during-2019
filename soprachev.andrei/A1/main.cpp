#include <iostream>
#include <cassert> //need for assetr
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

std::string rectToString(rectangle_t rectangle)
{
  return "pos: " + rectangle.pos.toString() + "\nwidth = " + std::to_string(rectangle.width) +
         "\nheight = " + std::to_string(rectangle.height);
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

  Shape * shapes[5] = {&rectangleByPosWH, &rectangleByLeftDownRightUp, &circle, &triangleByPosAndLocalVert,
                       &triangleByWorldVert};

  for (Shape * shape : shapes)
  {
    std::cout << shapeToString(shape) << "\n\n";
  }

  shapes[0]->move(1, 2); //перемещение на вектор
  shapes[1]->move(point_t{1, 1}); //перемещение в точку
  shapes[2]->move(-1, -3); //перемещение на вектор
  shapes[3]->move(1, 2); //перемещение на вектор
  shapes[4]->move(point_t{1, 1}); //перемещение в точку

  std::cout <<  "after move: \n\n";

  for (Shape * shape : shapes)
  {
    std::cout << shapeToString(shape) << "\n\n";
  }

  return 0;
}
