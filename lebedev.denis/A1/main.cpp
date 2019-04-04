#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"


int main() {
  Rectangle r1({ 4.2, 6.2 },4.0, 5.5);
  Circle c1({ 3.2, 7.2 }, 4.0);
  Shape * shapePtrRec = &r1;
  std::cout<<"Rectangle\n";
  std::cout<<"Area = "<<shapePtrRec->getArea()<<'\n';
  rectangle_t position_r = shapePtrRec->getFrameRect();
  std::cout<<"Height = "<<position_r.height<<'\n';
  std::cout<<"Width = "<<position_r.width <<'\n';
  std::cout <<"Position = "<<"(X = "<<position_r.pos.x << ";";
  std::cout <<"Y = "<<position_r.pos.y<<")";
  shapePtrRec->move(3.0, -1.5);
  rectangle_t data_r = shapePtrRec->getFrameRect();
  std::cout<<"New Position = "<<data_r.pos.x<<";"<<data_r.pos.y<<'\n';
  Shape * shapePtrCir = &c1;
  std::cout<<"Circle\n";
  std::cout<<"Area = "<<shapePtrCir->getArea()<<'\n';
  rectangle_t position_c = shapePtrCir->getFrameRect();
  std::cout<<"Height = "<<position_c.height<<'\n';
  std::cout<<"Width = "<<position_c.width<<'\n';
  std::cout<<"Position = "<<"(X = "<<position_c.pos.x<<";";
  std::cout<<"Y = "<<position_c.pos.y<<")";
  shapePtrCir->move(4.0, 1.5);
  rectangle_t data_c = shapePtrCir->getFrameRect();
  std::cout<<"New Position = "<<"(X = "<<data_c.pos.x<<";";
  std::cout<<"Y="<<data_c.pos.y<<")";
  return 0;
}
