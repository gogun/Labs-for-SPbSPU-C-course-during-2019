#include <iostream>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

void workWithFigure(fedorov::Shape* figure);

int main()
{
  try
  {
    std::cout << "rectangle:" << std::endl;
    fedorov::Rectangle rectangle({ 1.5, 2.5 }, 5.5, 4.5);
    workWithFigure(&rectangle);

    std::cout << "circle:" << std::endl;
    fedorov::Circle circle({ 3.4, 5.3 }, 2.0);
    workWithFigure(&circle);
  }
  catch (std::invalid_argument error)
  {
    std::cout << error.what() << std::endl;
    return 1;
  }

  return 0;
}

void workWithFigure(fedorov::Shape* figure)
{
  if (figure == nullptr)
  {
    throw std::invalid_argument("Empty pointer");
  }

  figure->printInfo();

  figure->move(2.1, -1.2);
  std::cout << "\tmoved figure for  +2.1, -1.2" << std::endl;
  figure->printInfo();

  figure->scale(2.5);
  std::cout << "\tscaled figure with coefficient 2.5" << std::endl;
  figure->printInfo();

  figure->move({1.0, 2.0});
  std::cout << "\tmoved figure to   (1;2)" << std::endl;
  figure->printInfo();

  figure->scale(0.5);
  std::cout << "\tscaled figure with coefficient 0.5" << std::endl;
  figure->printInfo();
}
