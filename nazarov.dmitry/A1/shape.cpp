#include <iostream>
#include "Shape.hpp"

Shape::Shape(const point_t &pos) :
	pos_(pos)
{}

void Shape::printData() const
{
	this->printFeatures();

	std::cout << "Center : { " << "x: " << this->pos_.x  << ", y:"
		<< this->pos_.y << " }\n"
		<< "Area: " << this->getArea() << "\n\n";

	rectangle_t frameRect = this->getFrameRect();

	std::cout << "Framing rectangle information:\n"
		<< "  Width: " << frameRect.width << "\n"
		<< "  Height: " << frameRect.height << "\n"
		"  Center : {" << "x: " << frameRect.pos.x << ", y:"
		<< frameRect.pos.y << " }\n\n";
}

void Shape::move(const double &dx, const double &dy)
{
	pos_.x += dx;
	pos_.y += dy; 
}

void Shape::move(const point_t &pos)
{
	pos_ = pos;
}
