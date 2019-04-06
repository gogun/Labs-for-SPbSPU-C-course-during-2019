#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Rectangle rectangle({ 5, 7, { 5, 4 } });
  Shape &figure1 = rectangle;
  std::cout << "\nRECTANGLE:\n";
  figure1.draw();
  std::cout << "Moving rectangle Ox -3 and Oy 5\n";
  figure1.move(-3, 5);
  figure1.draw();
  std::cout << "Moving rectangle to the point (9, 4)\n";
  figure1.move({9, 4});
  figure1.draw();
  std::cout << "\n";
  
  Circle circle(7, { 1, 5 });
  Shape &figure2 = circle;
  std::cout << "CIRCLE:\n";
  figure2.draw();
  std::cout << "Moving circle Ox +4 and Oy +3\n";
  figure2.move(4, 3);
  figure2.draw();
  std::cout << "Moving circle to the point (-10, 7)\n";
  figure2.move({ -10, 7 });
  figure2.draw();
  std::cout << "\n";
  
  return 0;
}
