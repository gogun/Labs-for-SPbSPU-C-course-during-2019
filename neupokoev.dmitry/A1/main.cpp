#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"


int main()
{
	Circle myCircle(6.0, {5.0, 4.0});
	Shape* pointer = &myCircle;
	pointer->writeParameters();
	pointer->move(5.0, 6.0);
	pointer->writeParameters();
	pointer->move({7.0, -7.0});
	pointer->writeParameters();

	Rectangle myRectangle({{9.0, 10.0}, 5.0, 4.0});
	pointer = &myRectangle;
	pointer->writeParameters();
	pointer->move(5.0, 6.0);
	pointer->writeParameters();
	pointer->move({7.0, -7.0});
	pointer->writeParameters();

	return 0;
}
