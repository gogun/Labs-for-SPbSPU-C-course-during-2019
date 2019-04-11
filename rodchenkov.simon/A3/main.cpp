#include <iostream>
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

int main()
{
  try {
    std::unique_ptr<std::shared_ptr<rodchenkov::Shape>[]> shapes 
        = std::make_unique<std::shared_ptr<rodchenkov::Shape>[]>(2);
    shapes[0] 
        = std::make_shared<rodchenkov::Rectangle>(rodchenkov::point_t{10, 10}, 10, 10);
    shapes[1] 
        = std::make_shared<rodchenkov::Circle>(rodchenkov::point_t{15, 15}, 5);

    rodchenkov::CompositeShape compositeShape{};
    compositeShape.add(shapes[0]);
    compositeShape.add(shapes[1]);
    std::cout << "Original shape : \n";
    compositeShape.printData(std::cout);
    rodchenkov::CompositeShape copyComposite = compositeShape;
    std::cout << "Copy shape : \n";
    copyComposite.printData(std::cout);
    copyComposite.scale(2);
    std::cout << "Original shape after copy scaling : ";
    compositeShape.printData(std::cout);
    std::cout << "Copy shape after scaling : \n";
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
