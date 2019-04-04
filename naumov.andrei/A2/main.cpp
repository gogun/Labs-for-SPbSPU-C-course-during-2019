#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  try
  {
    naumov::Rectangle testRectangle({ 40,20 }, 11.5, 10);
    testRectangle.getInformation();

    testRectangle.setHeight(2);
    testRectangle.setWidth(2);
    testRectangle.move(100, 100);

    naumov::Shape* pShape = &testRectangle;
    pShape->getInformation();

    testRectangle.scale(0);

    testRectangle.getInformation();



    naumov::Circle testCircle({ 20,40 }, 12);
    testCircle.getInformation();

    testCircle.setRadius(1);
    testCircle.move({ 35,44 });

    pShape = &testCircle;
    pShape->getInformation();

    testCircle.scale(4.1);

    testCircle.getInformation();
  }
  catch (char* error)
  {
    std::cerr << error;
    return 1;
  }
  return 0;
}
