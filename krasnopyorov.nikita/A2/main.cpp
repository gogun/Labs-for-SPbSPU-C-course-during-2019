#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void writeFrameRect(const krasnopyorov::rectangle_t &frameRect)
{
  std::cout << "Frame Rectangle: " << "\n";
  std::cout << "Coordinates of centre: (" << frameRect.pos.x << "," << frameRect.pos.y << ")" << "\n";
  std::cout << "Size of frame rectagle: " << "\n";
  std::cout << "Height: " << frameRect.height << "\n";
  std::cout << "Width: " << frameRect.width << "\n";
}

void demonstrateScaling(krasnopyorov::Shape *pointerShape, double k)
{
  if (pointerShape == nullptr)
  {
    throw std::invalid_argument("Pointer to object can't be nullptr");
  }

  std::cout << "Area before scaling: " << pointerShape->getArea() << "\n";
  pointerShape->scale(k);
  std::cout << "Area after scaling: " << pointerShape->getArea() << "\n";
}

int main()
{
  krasnopyorov::Circle objCirc(1.0, {0, 0});
  krasnopyorov::Shape *pointerShape = &objCirc;

  std::cout << "Square of circle: " << pointerShape->getArea() << "\n";
  krasnopyorov::rectangle_t frameRect = objCirc.getFrameRect();
  writeFrameRect(frameRect);

  const double dx = 2.1;
  const double dy = 3.3;
  pointerShape->move(dx, dy);
  objCirc.writeChanges();

  krasnopyorov::point_t dot = {0, 0};
  pointerShape->move(dot);
  objCirc.writeChanges();

  const double k = 2;
  demonstrateScaling(&objCirc, k);

  std::cout << "\n\n";

  krasnopyorov::Rectangle objRect({2.5, 1.0, {0, 0}});
  pointerShape = &objRect;

  std::cout << "Square of rectangle: " << pointerShape->getArea() << "\n";

  frameRect = pointerShape->getFrameRect();
  writeFrameRect(frameRect);

  pointerShape->move(dx, dy);
  objRect.writeChanges();

  pointerShape->move(dot);
  objRect.writeChanges();

  demonstrateScaling(&objRect, k);

  std::cout << "\n";

  return 0;
}
