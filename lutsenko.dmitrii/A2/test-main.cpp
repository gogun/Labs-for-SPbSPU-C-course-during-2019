#define BOOST_TEST_MODULE testA2
#include <stdexcept>
#include <boost\test\included\unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testShape)

BOOST_AUTO_TEST_CASE(unalteredRectangleAfterMove1)
{
  lutsenko::Rectangle rect({10.0, 15.0, 20.0, 25.0});
	lutsenko::rectangle_t rect_before = rect.getFrameRect();
	double area_before = rect.getArea();
	rect.move({100.0, 200.0});
	BOOST_CHECK_CLOSE_FRACTION(area_before, rect.getArea(), 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.height, rect.getFrameRect().height, 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.width, rect.getFrameRect().width, 0.001);
}

BOOST_AUTO_TEST_CASE(unalteredRectangleAfterMove2)
{
	lutsenko::Rectangle rect({10.0, 15.0, 20.0, 25.0});
	lutsenko::rectangle_t rect_before = rect.getFrameRect();
	double area_before = rect.getArea();
	rect.move(10.0, 20.0);
	BOOST_CHECK_CLOSE_FRACTION(area_before, rect.getArea(), 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.height, rect.getFrameRect().height, 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.width, rect.getFrameRect().width, 0.001);
}

BOOST_AUTO_TEST_CASE(unalteredCircleAfterMove1)
{
	lutsenko::Circle circle(10.0, {1.0, 2.0});
	lutsenko::rectangle_t rect_before = circle.getFrameRect();
	double area_before = circle.getArea();
	circle.move({5.0, 7.0});
	BOOST_CHECK_CLOSE_FRACTION(area_before, circle.getArea(), 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.height, circle.getFrameRect().height, 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.width, circle.getFrameRect().width, 0.001);
}

BOOST_AUTO_TEST_CASE(unalteredCircleAfterMove2)
{
	lutsenko::Circle circle(10.0, {1.0, 2.0});
	lutsenko::rectangle_t rect_before = circle.getFrameRect();
	double area_before = circle.getArea();
	circle.move({10.0, 10.0});
	BOOST_CHECK_CLOSE_FRACTION(area_before, circle.getArea(), 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.height, circle.getFrameRect().height, 0.001);
	BOOST_CHECK_CLOSE_FRACTION(rect_before.width, circle.getFrameRect().width, 0.001);
}

BOOST_AUTO_TEST_CASE(quadraticChangeRectangleArea)
{
	lutsenko::Rectangle rect({10.0, 15.0, 20.0, 25.0});
	double area_before = rect.getArea();
	double coefficient = 3;
	rect.scale(coefficient);
	BOOST_CHECK_CLOSE_FRACTION(area_before * coefficient * coefficient, rect.getArea(), 0.001);
}

BOOST_AUTO_TEST_CASE(quadraticChangeCircleArea)
{
	lutsenko::Circle circle(10.0, {1.0, 2.0});
	double area_before = circle.getArea();
	double coefficient = 3;
	circle.scale(coefficient);
	BOOST_CHECK_CLOSE_FRACTION(area_before * coefficient * coefficient, circle.getArea(), 0.001);
}

BOOST_AUTO_TEST_CASE(corectRectParametrs)
{
	BOOST_CHECK_THROW(lutsenko::Rectangle({-10.0, 15.0, 20.0, 25.0}), std::invalid_argument);
	BOOST_CHECK_THROW(lutsenko::Rectangle({10.0, -15.0, 20.0, 25.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(corectCircleParametrs)
{
	BOOST_CHECK_THROW(lutsenko::Circle(-10.0, {1.0, 2.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(corectRectangleScaling)
{
	lutsenko::Rectangle rect({10.0, 15.0, 20.0, 25.0});
	BOOST_CHECK_THROW(rect.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(corectCircleScaling)
{
	lutsenko::Circle circle(10.0, {1.0, 2.0});
	BOOST_CHECK_THROW(circle.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
