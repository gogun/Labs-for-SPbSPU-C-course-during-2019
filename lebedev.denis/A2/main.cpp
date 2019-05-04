#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"
#include "polygon.hpp"

void showRectangle_t(lebedev::rectangle_t data)
{
  std::cout<<"Width = "<<data.width<<'\n';
  std::cout<<"Height = "<<data.height<<'\n';
  std::cout<<"(X = "<<data.pos.x<<";";
  std::cout<<"Y = "<<data.pos.y<<")"<<'\n';
}

void showAll(const lebedev::Shape *shape)
{
  if (shape != nullptr)
  {
    std::cout<<"Area = "<<shape->getArea()<<'\n';
    showRectangle_t(shape->getFrameRect());
  }
  else
  {
    throw std::invalid_argument("Shape's pointer is null!!!");
  }
}

void PrintDataPolygon(const lebedev::Polygon *polygon)
{
  if (polygon != nullptr)
  {
    bool unconvex = polygon->checkBump();
    if (unconvex != true)
    {
      double ZeroArea = polygon->getArea();
      if (ZeroArea > 0)
      {
        polygon->printData();
        std::cout<<"Area = "<<polygon->getArea()<<'\n';
        showRectangle_t(polygon->getFrameRect());
      }
      else
      {
        throw std::invalid_argument("Area must be more then 0");
      }
    }
    else
    {
      throw std::invalid_argument("Polygon must be convex!!!");
    }
  }
  else
  {
    throw std::invalid_argument("Shape's pointer is null!!!");
  }
}

int main()
{
  lebedev::Rectangle rectangle1(3.00, 4.00, { 5.00, 4.00 });
  std::cout<<"Rectangle."<<'\n';
  showAll(&rectangle1);
  std::cout<<"After scale"<<'\n';
  rectangle1.scale(3.0);
  showAll(&rectangle1);
  rectangle1.move({.x = 7.00, .y = 8.00 });
  std::cout<<"After move"<<'\n';
  showAll(&rectangle1);
  lebedev::Circle circle1(3.00, { 1.00, 3.00 });
  std::cout<<"Circle."<<'\n';
  showAll(&circle1);
  std::cout<<"After scale"<<'\n';
  circle1.scale(4.00);
  showAll(&circle1);
  circle1.move(3.00, -1.5);
  std::cout<<"After move"<<'\n';
  showAll(&circle1);
  lebedev::point_t shape[] = {{3.0, 2.0}, {9.0, 2.0}, {9.0, 5.0}, {3.0, 5.0}};
  size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
  lebedev::Polygon polygon1(qtyVertex, shape);
  std::cout <<"Polygon."<<'\n';
  PrintDataPolygon(&polygon1);
  std::cout<<"After scale"<<'\n';
  polygon1.scale(2.0);
  PrintDataPolygon(&polygon1);
  std::cout<<"After move(3.0, -1.0)"<<'\n';
  polygon1.move(3.00, -1.0);
  PrintDataPolygon(&polygon1);
  std::cout<<"After move(1.00, 2.0)"<<'\n';
  polygon1.move({.x = 1.00, .y = 2.0});
  PrintDataPolygon(&polygon1);

  std::cout<<"~ Copy constructor ~"<<'\n';
  lebedev::Polygon polygonCopyConstructor(polygon1);
  polygonCopyConstructor.printData();

  std::cout<<"~ Copy assignment ~"<<'\n';
  lebedev::Polygon polygonCopyAssignment;
  polygonCopyAssignment = polygon1;
  polygonCopyAssignment.printData();

  std::cout <<"~ Move constructor of polygon ~"<<'\n';
  lebedev::Polygon polygonMoveConstructor(std::move(polygonCopyAssignment));
  polygonMoveConstructor.printData();

  std::cout <<"~ Move assignment of polygon ~"<<'\n';
  lebedev::Polygon polygonMoveAssignment;
  polygonMoveAssignment = (std::move(polygon1));
  polygonMoveAssignment.printData();

  return 0;
}
