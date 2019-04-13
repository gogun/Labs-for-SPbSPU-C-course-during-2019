#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void viewInfo(const afanasiev::Shape &figure)
{
  afanasiev::rectangle_t frameRect = figure.getFrameRect();
  std::cout << "Coordinates of position: (";
  std::cout << frameRect.pos.x << ", ";
  std::cout << frameRect.pos.y << ")" << std::endl;
  std::cout << "Frame Width: " << frameRect.width << std::endl;
  std::cout << "Frame Height: " << frameRect.height << std::endl;
}

void viewArea(const afanasiev::Shape &figure)
{
  std::cout << "Area is " << figure.getArea() << std::endl;
}

int main()
{
  afanasiev::point_t point = {15, 20};

  afanasiev::Rectangle rectangle(point, 50, 60);
  afanasiev::Circle circle(point, 10);

  std::cout << "--RECTANGLE--" << std::endl;
  viewInfo(rectangle);
  viewArea(rectangle);
  std::cout << "--CIRCLE--" << std::endl;
  viewInfo(circle);
  viewArea(circle);

  std::cout << "Moving on increment..." << std::endl;

  rectangle.move(15, 20);
  circle.move(15, 20);

  std::cout << "--RECTANGLE--" << std::endl;
  viewInfo(rectangle);
  viewArea(rectangle);
  std::cout << "--CIRCLE--" << std::endl;
  viewInfo(circle);
  viewArea(circle);

  std::cout << "Moving to a new point..." << std::endl;

  afanasiev::point_t newPoint = {40, 50};

  std::cout << "--RECTANGLE--" << std::endl;
  rectangle.move(newPoint);
  viewInfo(rectangle);
  viewArea(rectangle);
  std::cout << "--CIRCLE--" << std::endl;
  circle.move(newPoint);
  viewInfo(circle);
  viewArea(circle);

  std::cout << "Scaling..." << std::endl;

  rectangle.scale(1.5);
  circle.scale(2);

  std::cout << "--RECTANGLE--" << std::endl;
  viewInfo(rectangle);
  viewArea(rectangle);
  std::cout << "--CIRCLE--" << std::endl;
  viewInfo(circle);
  viewArea(circle);

  return 0;
}
