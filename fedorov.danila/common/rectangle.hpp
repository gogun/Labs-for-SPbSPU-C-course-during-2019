#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace fedorov
{
	class Rectangle :
		  public Shape
	{
	public:
		Rectangle(const point_t &position, const double width, const double height);

		rectangle_t getFrameRect() const override;
		double getArea() const override;
		double getWidth() const;
		double getHeight() const;

		void printInfo() const override;
		void scale(double scale) override;

	private:
		double width_, height_;
	};
}

#endif //RECTANGLE_HPP
