//#include <iostream>
//#include "circle.hpp"
//#include "rectangle.hpp"
//
//int main()
//{
//  krinkina::Circle circle{{6, 5}, 13 };
//  krinkina::Shape * shape = &circle;
//
//  std::cout << "THE PARAMETERS OF THE CIRCLE\n";
//  shape->printInfo();
//
//  shape->move(0, 1);
//  std::cout << "the parameters of the circle after move dx = 0, dy = 1 :\n";
//  shape->printInfo();
//
//  shape->move({ -3, -2 });
//  std::cout << "the parameters of the circle after move centre to the point (-3,-2) :\n";
//  shape->printInfo();
//
//  std::cout << "the parameters of the scale circle with coefficient = 3 :\n";
//  shape->scale(3);
//  shape->printInfo();
//
//  std::cout << '\n';
//
//  krinkina::Rectangle rect{{1, 5}, 15, 10 };
//  shape = &rect;
//
//  std::cout << "THE PARAMETERS OF THE RACTANGLE \n";
//  shape->printInfo();
//
//  shape->move(-1, -5);
//  std::cout << "the parameters of the rectangle after move dx = -1, dy = -5:\n";
//  shape->printInfo();
//
//  shape->move({ 3, 1 });
//  std::cout << "the parameters of the rectangle after move centre to the point (3,1) :\n";
//  shape->printInfo();
//
//  std::cout << "the parameters of the scale rectangle with coefficient = 5 :\n";
//  shape->scale(5);
//  shape->printInfo();
//
//  system("pause");
//
//  return 0;
//}
