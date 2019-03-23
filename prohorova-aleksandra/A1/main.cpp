#include <iostream>
#ifndef AP_A1_RECTANGLE
#include "rectangle.hpp"
#define AP_A1_RECTANGLE
#endif
#ifndef AP_A1_CIRCLE
#include "circle.hpp"
#define AP_A1_CIRCLE
#endif

int main()
{
  Shape* correctFigures[] = {new Circle(point_t{1,2},4), new Rectangle(point_t{3,4},2,3),
                             new Circle(-2.1234, 3.4567, 1), new Rectangle(1.2,-2.3,1,1)};
  int size = sizeof(correctFigures)/sizeof(Shape*);
  std::cout << "Starting values: \n";
  for(int i = 0;i < size;i++)
  {
    correctFigures[i]->show();
  }
  std::cout << "\nMoving all figures for dx = 10, dy = 20:\n";
  for(int i = 0;i<size;i++)
  {
    correctFigures[i]->move(10,20);
    correctFigures[i]->show();
  }
  std::cout << "\nMoving all figures to the point (0,0):\n";
  for(int i = 0;i<size;i++)
  {
    correctFigures[i]->move(point_t{0,0});
    correctFigures[i]->show();
  }
  for(int i = 0;i<size;i++)
  {
    delete correctFigures[i];
  }
  std::cout << "\nTrying to create figures with incorrect parameters:\n";
  Shape* incorrectFigures[] = {new Rectangle(2,2,-1,-1),new Circle(3,4,0),
                               new Rectangle(-10.5,-20.4, 0,2), new Circle(1,1,-5)};
  size = sizeof(incorrectFigures)/sizeof(Shape*);
  for(int i = 0;i < size;i++)
  {
    delete incorrectFigures[i];
  }
  return 0;
}
