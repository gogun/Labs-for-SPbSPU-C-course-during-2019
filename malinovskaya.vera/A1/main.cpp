#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
	Circle oCircle({ 4.0, 2.0 }, 3.0);
	Shape *pointer = &oCircle;
	std::cout << "Circle:" << std::endl;
	std::cout << std::endl;
	std::cout << "Area: " << pointer->getArea() << std::endl;
	std::cout << "Frame (width): " << pointer->getFrameRect().width << std::endl;
	std::cout << "Frame (height): " << pointer->getFrameRect().height << std::endl;
	pointer->print();
	std::cout << std::endl;
	std::cout << "Shift: dx = " << -2 << ", dy = " << 4 << std::endl;
	pointer->move(-2.0, 4.0);
	pointer->print();
	std::cout << std::endl;
	std::cout << "Move to (" << 0 << ", " << -6 << ")" << std::endl;
	pointer->move({0.0, -6.0});
	pointer->print();

	std::cout << std::endl;
	std::cout << std::endl;

	Rectangle oRectangle({ 3.0, 4.0, { 5.0, 8.0 } });
	pointer = &oRectangle;
	std::cout << "Rectangle:" << std::endl;
	std::cout << std::endl;
	std::cout << "Area: " << pointer->getArea() << std::endl;
	std::cout << "Frame (width): " << pointer->getFrameRect().width << std::endl;
	std::cout << "Frame (height): " << pointer->getFrameRect().height << std::endl;
	pointer->print();
	std::cout << std::endl;
	std::cout << "Shift: dx = " << 8 << ", dy = " << 2 << std::endl;
	pointer->move(8.0, 2.0);
	pointer->print();
	std::cout << std::endl;
	std::cout << "Move to (" << -5 << ", " << -10 << ")" << std::endl;
	pointer->move({ -5.0, -10.0 });
	pointer->print();

	return 0;
}