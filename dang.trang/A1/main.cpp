#include <iostream>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
using namespace std;

int main()
{
  Rectangle rectangle1({{25,25},8,20});
  Circle circle1({50,50},12);
  Triangle triangle1({5,5},{0,10},{10,10});

  rectangle1.print();
  circle1.print();
  triangle1.print();

  cout<<"\n";
  cout<<" New shapes: \n";

  rectangle1.move(20,20);
  rectangle1.move({40,70});
  cout<<"Move rectangle to: \n";
  rectangle1.print();

  cout<<"\n";

  circle1.move({40,40});
  circle1.move(10,10);
  cout<<"Move circle to: \n";
  circle1.print();

  cout<<"\n";

  triangle1.move(10,5);
  triangle1.move({30,20});
  cout<<"Move triangle to: \n";
  triangle1.print();

  return 0;
}
