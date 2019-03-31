#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{

  Circle circle(21.77, {9, -4});
  Shape * shape = &circle;
  std::cout << "__Circle info__: " << "\n\n";
  shape -> printShapeInfo();
  std::cout << "Add to OX " << 1 << " and to OY " << 4 << std::endl;
  shape -> move(1, 4);
  shape -> printShapeInfo();
  std::cout << "Move to point (" << 30 << ", " << 11 << ")\n";
  shape -> move({30, 11});
  shape -> printShapeInfo();


  Rectangle rectangle(7,7,{3,5});
  shape = &rectangle;
  std::cout << "__Rectangle info__ " << "\n\n";
  shape -> printShapeInfo();
  std::cout << "Add to ОX " << 5 << " and  to OY " << -1.7 << std::endl;
  shape -> move(5, -1.7);
  shape -> printShapeInfo();
  std::cout << "Move to point (" << 16.5 << ", " << 9 << ")\n";
  shape -> move({16.5, 9});
  shape -> printShapeInfo();
  std::cout << std::endl;
  return 0;
}
