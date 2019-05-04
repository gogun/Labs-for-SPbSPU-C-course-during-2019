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

void printData(lebedev::Polygon *polygon) const
{
  if (polygon = nullptr)
  {
    throw std::invalid_argument("Polygon pointer is null");
  }
  else
  {
    for (std::size_t index = 0; index < m_qtyVertex ; index++)
    {
      std::cout<<"Polygon's vertex №"<<index<< ".Position of vertex (X="<<m_vertex[index].x<<";";
      std::cout<<"Y="<<m_vertex[index].y <<")"<<'\n';
    }
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
        printData(&polygon);
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
  lebedev::Rectangle r1(3.00, 4.00, { 5.00, 4.00 });
  std::cout<<"Rectangle."<<'\n';
  showAll(&r1);
  std::cout<<"After scale"<<'\n';
  r1.scale(3.0);
  showAll(&r1);
  r1.move({.x = 7.00, .y = 8.00 });
  std::cout<<"After move"<<'\n';
  showAll(&r1);
  lebedev::Circle c1(3.00, { 1.00, 3.00 });
  std::cout<<"Circle."<<'\n';
  showAll(&c1);
  std::cout<<"After scale"<<'\n';
  c1.scale(4.00);
  showAll(&c1);
  c1.move(3.00, -1.5);
  std::cout<<"After move"<<'\n';
  showAll(&c1);
  lebedev::point_t shape[] = {{3.0, 2.0}, {9.0, 2.0}, {4.0, 3.0}, {4.0, 6.0}};
  size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
  lebedev::Polygon poly(qtyVertex, shape);
  std::cout <<"Polygon."<<'\n';
  PrintDataPolygon(&poly);
  std::cout<<"After scale"<<'\n';
  poly.scale(2.0);
  PrintDataPolygon(&poly);
  std::cout<<"After move(3.0, -1.0)"<<'\n';
  poly.move(3.00, -1.0);
  PrintDataPolygon(&poly);
  std::cout<<"After move(1.00, 2.0)"<<'\n';
  poly.move({.x = 1.00, .y = 2.0});
  PrintDataPolygon(&poly);

  std::cout<<"Demo copy constructor of polygon"<<'\n';
  lebedev::Polygon polygonCopyConstructor(polygon);
  PrintDataPolygon(&polygonCopyConstructor);

  std::cout<<"Demo copy assignment of polygon"<<'\n';
  lebedev::Polygon polygonCopyAssignment;
  polygonCopyAssignment = poly;
  PrintDataPolygon(&polygonCopyAssignment);
  std::cout << "Is source polygon alive ?" << std::endl;
  PrintDataPolygon(&poly);

  std::cout << "Demo move constructor of polygon" << std::endl;
  lebedev::Polygon polygonMoveConstructor(std::move(polygonCopyAssignment));
  PrintDataPolygon(&polygonMoveConstructor);

  std::cout << "Demo move assignment of polygon" << std::endl;
  lebedev::Polygon polygonMoveAssignment;
  polygonMoveAssignment = (std::move(poly));
  polygonMoveAssignment.printInfo();
  std::cout << "Is moved polygon alive ?" << std::endl;
  PrintDataPolygon(&poly);

  return 0;
}
