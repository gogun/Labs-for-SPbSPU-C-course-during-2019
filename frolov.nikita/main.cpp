#include "rectangle.cpp"
#include "circle.cpp"
#include <iostream>

int main()
{
  Circle cir(3,{5,2});
  std:: cout << "Area: " << cir.getArea() << "\n";
  cir.move(5,7);
  std::cout << "After change center" << "\n";
  cir.showPoint();
  cir.move({5,12});
  rectangle_t frame = cir.getFrameRect();
  std::cout << "Frame" << "\n";
  std::cout << "Wigth= " << frame.wigth << "\n";
  std::cout << "Height= " << frame.height << "\n";
  std::cout << "Center on x-axis=" << frame.pos.x << "\n";
  std::cout << "Center on y-axis=" << frame.pos.y << "\n";

  Rectangle rect({3,4},4,3);
  std::cout << "Area: " << rect.getArea() << "\n";
  rect.move(5,8);
  std::cout << "After change point";
  rect.showPoint();
  rect.move({10,2});
  std::cout << "After change point";
  rect.showPoint();
  std::cout << "Area after change" << rect.getArea() << "\n";
  rectangle_t frame_ = rect.getFrameRect();
  std::cout << "Frame" << "\n";
  std::cout << "Wigth= " << frame_.wigth << "\n";
  std::cout << "Height= " << frame_.height << "\n";
  std::cout << "Center on x-axis=" << frame_.pos.x << "\n";
  std::cout << "Center on y-axis=" << frame_.pos.y << "\n";

  Rectangle srect({9,4},4,4);
  Shape* shape = &srect;
  rectangle_t sframe_ = shape->getFrameRect();
  std::cout << "Wigth= " << sframe_.wigth << "\n";
  std::cout << "Height= " << sframe_.height << "\n";
  std::cout << "Center on x-axis=" << sframe_.pos.x << "\n";
  std::cout << "Center on y-axis=" << sframe_.pos.y << "\n";
  std::cout << "Area: " << shape->getArea()<< "\n";
  shape->move(18,20);
  std::cout << "After change point";
  shape->showPoint();
  shape->move({2,3});
  std::cout << "After change point";
  shape->showPoint();

  return 0;
}
