#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace bessonov
{

	class Rectangle : public Shape
	{
	public:
		Rectangle(const point_t &center, double width, double height);

		double getArea() const override;

		rectangle_t getFrameRect() const override;

		void move(double dx, double dy) override;

		void move(const point_t &newCenter) override;

    void scale(double factor) override;

	private:
		point_t center_;
		double width_;
		double height_;
	};
}

#endif
