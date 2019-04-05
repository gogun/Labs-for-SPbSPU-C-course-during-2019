#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void showRectangle_t(rectangle_t data)
{
  std::cout<<"Width = "<<data.width<<"\n";
  std::cout<<"Height = "<<data.height<<"\n";
  std::cout<<"(X = "<<data.pos.x<<";";
  std::cout<<"Y = "<<data.pos.y<<")"<<"\n";
}

void showAll(const Shape & shape)
{
  std::cout<<"Area = "<<shape.getArea()<<"\n";
  showRectangle_t(shape.getFrameRect());
}

int main()
{
  Rectangle r1({ 5.00, 10.00 }, 3.00, 4.00);
  std::cout<<"Rectangle."<<"\n";
	
  showAll(r1);
  r1.move({ .x = 7.00, .y = 8.00 });
  
  std::cout<<"After move"<<"\n";
  showAll(r1);
 
  Circle c1({ 1.00, 3.00 }, 3.00);
  std::cout<<"Circle."<<"\n";
  
  showAll(c1);
  c1.move(3.00, -1.5);
  
  std::cout<<"After move"<<"\n";
  showAll(c1);
  return 0;
}
