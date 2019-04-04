#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
using namespace std;
void moveBothToPos(Shape* first, Shape * second,const point_t &pos)
{
  first->move(pos);
  second->move(pos);
}
bool hasGreaterArea(const Shape* first, const Shape * second)
{
  return first->getArea()>second->getArea();
}
void printFrameRect(const Shape* ref)
{
  rectangle_t frameRect = ref->getFrameRect();
  cout << "Object's frame Width is " << frameRect.width << endl;
  cout << "Object's frame Height is: " << frameRect.height << endl;
  cout << "Object's frame Center is positioned at " << frameRect.pos.x << " , " << frameRect.pos.y << endl;
}

int main()
{
  Circle a({1,1},2);
  Rectangle b({2,2},1,1);
  cout << "Shape a position is " << a.getCenter().x << " , " << a.getCenter().y << endl;
  cout << "Shape b position is " << b.getPos().x << " , " << b.getPos().y << endl;
  moveBothToPos(&a, &b,{9,9});
  
  cout << "Shape a position is " << a.getCenter().x<<" , " << a.getCenter().y << endl;
  cout << "Shape b position is " << b.getPos().x << " , " << b.getPos().y<<endl;
  if(hasGreaterArea(&a, &b))
  {
    cout << "a has area greater then b" << endl;
  }
  else
  {
    cout << "a has area not greater then shape b" << endl;
  }
  cout << "Printing Frame for object a" << endl;
  printFrameRect(&a);
  cout << "Printing Frame for object b" << endl;
  printFrameRect(&b);
  
  return 0;
}
