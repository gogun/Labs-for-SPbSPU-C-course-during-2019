#include <iostream>
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

int main()
{
  try {
    rodchenkov::CompositeShape compositeShape{};
    compositeShape.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{ 10, 10 }, 10, 10));
    compositeShape.add(std::make_unique<rodchenkov::Circle>(rodchenkov::point_t{ 15, 15 }, 5));
    std::cout << "-- Original shape : \n";
    compositeShape.printData(std::cout);
    rodchenkov::CompositeShape copyComposite = compositeShape;
    std::cout << "-- Copy shape : \n";
    copyComposite.printData(std::cout);
    copyComposite.scale(2);
    std::cout << "-- Original shape after copy scaling : \n";
    compositeShape.printData(std::cout);
    std::cout << "-- Copy shape after scaling : \n";
    copyComposite.printData(std::cout);
  } catch (const std::invalid_argument& exc) {
    std::cerr << "error: invalid parameter \"" << exc.what() << "\"" << std::endl;
    return 1;
  } catch (const std::exception& exc) {
    std::cerr << "error: " << exc.what() << std::endl;
    return 2;
  }
  return 0;
}
