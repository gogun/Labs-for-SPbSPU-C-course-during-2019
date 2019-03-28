#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

int main()
{
  Circle cir({12, 12}, 12);
  cir.printInf();
  // Move to point{23,45}
  cir.move({23, 45});
  std::cout << "Parameters of circle after move: " << std::endl;
  cir.printInf();

  // Move to x = 45, y = 12
  cir.move(45, 12);
  std::cout << "Parameters of circle after move: " << std::endl;
  cir.printInf();

  Rectangle rect(12, 34, 23 , 56);
  rect.printInf();
  // Move to point{67,78}
  rect.move({67, 78});
  std::cout << "Parameters of rectangle after move: " << std::endl;
  rect.printInf();

  // Move to x = 17, y = 34
  rect.move(17, 34);
  std::cout << "Parameters of rectangle after move: " << std::endl;
  rect.printInf();

  // Square around circle
  rectangle_t rec = cir.getFrameRect();
  Rectangle rect2({rec.pos.x, rec.pos.y}, rec.width, rec.height );
  rect2.printInf();
    
  return 0;
}


