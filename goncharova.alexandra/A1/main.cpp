#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
	point_t dot = { 3, 4 };
	Circle circle1(dot, 15);
	Rectangle rectangle1(dot, 10, 10);

	Shape* shape1 = &circle1;
	std::cout << "Area of circle1: ";
	std::cout << shape1.getArea() << "\n";
	std::cout << "Height of frame rectangle: ";
	std::cout << shape1.getFrameRect().height << "\n";
	std::cout << "Width of frame rectangle: ";
	std::cout << shape1.getFrameRect().width << "\n";

	point_t movePoint = { 5,6 };
	shape1.move(movePoint);
	std::cout << "Circle moved to: x:" << shape1.center_.x;
	std::cout << ", y:" << shape1.center_.y << "\n";

	shape1.move(7.0, 8.0);
	std::cout << "Circle moved to: x:" << shape1.center_.x;
	std::cout << ", y:" << shape1.center_.y << "\n";

	std::cout << "-----" << "\n";

	shape1 = &rectangle1;
	std::cout << "Area of rectangle1: ";
	std::cout << shape1.getArea() << "\n";
	std::cout << "Height of frame rectangle: ";
	std::cout << shape1.getFrameRect().height << "\n";
	std::cout << "Width of frame rectangle: ";
	std::cout << shape1.getFrameRect().width << "\n";

	shape1.move(movePoint);
	std::cout << "Rectangle moved to: x:" << shape1.center_.x;
	std::cout << ", y:" << shape1.center_.y << "\n";

	shape1.move(7.0, 8.0);
	std::cout << "Rectangle moved to: x:" << shape1.center_.x;
	std::cout << ", y:" << shape1.center_.y << "\n";

	return 0;
}
