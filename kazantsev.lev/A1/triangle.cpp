#define _USE_MATH_DEFINES
#include "triangle.h"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC) :
	pos_({ (pointA.x + pointB.x + pointC.x) / 3, (pointA.y + pointB.y + pointC.y) / 3 }),
	point1_(pointA),
	point2_(pointB),
	point3_(pointC)
{
	if ((point1_.x == point2_.x && point1_.y == point2_.y) || (point2_.x == point3_.x && point2_.y == point3_.y) || (point1_.x == point3_.x && point1_.y == point3_.y))	
	{
		throw std::invalid_argument("Two point are matching");
	}
}

double Triangle::getArea() const
{
	return (std::fabs(point1_.x - point3_.x) * (point2_.y - point3_.y) - 
std::fabs(point2_.x - point3_.x) * (point1_.y - point3_.y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
	const double maxX = std::max(std::max(point1_.x, point2_.x), point3_.x);
	const double  minX = std::min(std::min(point1_.x, point2_.x), point3_.x);

	const double maxY = std::max(std::max(point1_.y, point2_.y), point3_.y);
	const double  minY = std::min(std::min(point1_.y, point2_.y), point3_.y);
	const double width = maxX - minX;
	const double height = maxY - minY;
	const point_t position = { minX + width / 2, minY + height / 2 };

	return { position, width, height };
}

void Triangle::move(const point_t &newPos)
{
	const point_t difference = { newPos.x - pos_.x, newPos.y - pos_.y };

	move(difference.x, difference.y);
}

void Triangle::move(const double dx, const double dy)
{
	pos_.x += dx;
	pos_.y += dy;

	point1_.x += dx;
	point1_.y += dy;

	point2_.x += dx;
	point2_.y += dy;

	point3_.x += dx;
	point3_.y += dy;
}

void Triangle::writeParameters() const
{
	rectangle_t rectangle = getFrameRect();
	std::cout << "Triangle point A is (" << point1_.x << ';' << point1_.y << ")";
	std::cout << "\n point B is " << point2_.x << ';' << point2_.y << ")";
	std::cout << "\n point C is " << point3_.x << ';' << point3_.y << ")";
	std::cout << "\n Triangle centre is (" << pos_.x << "," << pos_.y << ")";
	std::cout << "\n Frame rectangle width = " << rectangle.width
			  << ", height = " << rectangle.height
			  << "\n Area = " << getArea() << "\n\n";
}
