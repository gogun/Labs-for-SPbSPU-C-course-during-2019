#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"


void showRectangle_t(lebedev::rectangle_t data)
{
  std::cout<<"Width = "<<data.width<<"\n";
  std::cout<<"Height = "<<data.height<<"\n";
  std::cout<<"(X = "<<data.pos.x<<";";
  std::cout<<"Y = "<<data.pos.y<<")"<<"\n";
}

void showAll(const lebedev::Shape * shape)
{
  assert(shape != nullptr);
  std::cout<<"Area = "<<shape->getArea()<<"\n";
  showRectangle_t(shape->getFrameRect());
}

int main()
{
  lebedev::Rectangle r1(3.00, 4.00, { 5.00, 4.00 });
  std::cout<<"Rectangle."<<"\n";
  showAll(&r1);
  std::cout<<"After scale"<<"\n";
  r1.scale(3.0);
  showAll(&r1);
  r1.move({ .x = 7.00, .y = 8.00 });
  std::cout<<"After move"<<"\n";
  showAll(&r1);
  lebedev::Circle c1(3.00, { 1.00, 3.00 });
  std::cout<<"Circle."<<"\n";
  showAll(&c1);
  std::cout<<"After scale"<<"\n";
  c1.scale(4.00);
  showAll(&c1);
  c1.move(3.00, -1.5);
  std::cout<<"After move"<<"\n";
  showAll(&c1);
  
  return 0;
}
