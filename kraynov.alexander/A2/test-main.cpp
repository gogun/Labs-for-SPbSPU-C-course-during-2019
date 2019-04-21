#define BOOST_TEST_MODULE A2;

#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

const double accuracy = 0.00001;

BOOST_AUTO_TEST_SUITE(testRectangle)

	BOOST_AUTO_TEST_CASE(consistancyInMovement)
	{
		kraynov::Rectangle rect({1, 2}, 3, 4);
		const double initHeight = rect.getFrameRect().height;
		const double initWidth = rect.getFrameRect().width;
		const double initArea = rect.getArea();
		rect.move({0, 0});
		BOOST_CHECK_EQUAL(initWidth, rect.getFrameRect().width);
		BOOST_CHECK_EQUAL(initHeight, rect.getFrameRect().height);
		BOOST_CHECK_CLOSE(initArea, rect.getArea(), accuracy);
		rect.move(1, 1);
		BOOST_CHECK_EQUAL(initWidth, rect.getFrameRect().width);
		BOOST_CHECK_EQUAL(initHeight, rect.getFrameRect().height);
		BOOST_CHECK_CLOSE(initArea, rect.getArea(), accuracy);

	}

	BOOST_AUTO_TEST_CASE(consistancyInScaling)
	{
		kraynov::Rectangle rect({1, 2}, 3, 4);
		const double mult = 1.5;
		const double resultArea = rect.getArea() * mult * mult;
		rect.scale(mult);
		BOOST_CHECK_CLOSE(rect.getArea(), resultArea, accuracy);
	}

	BOOST_AUTO_TEST_CASE(IncorrectArgumets)
	{
		BOOST_CHECK_THROW(kraynov::Rectangle({0, 0}, -1, 0), std::invalid_argument);
		BOOST_CHECK_THROW(kraynov::Rectangle({0, 0}, 0, -1), std::invalid_argument);

		kraynov::Rectangle rect({0, 0}, 1.5, 1.5);
		const double mult = -1.5;

		BOOST_CHECK_THROW(rect.scale(mult), std::invalid_argument);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

	BOOST_AUTO_TEST_CASE(consistancyInMovement)
	{
		kraynov::Circle circ({1, 2}, 3);
		const double initHeight = circ.getFrameRect().height;
		const double initWidth = circ.getFrameRect().width;
		const double initArea = circ.getArea();
		circ.move({0, 0});
		BOOST_CHECK_EQUAL(initWidth, circ.getFrameRect().width);
		BOOST_CHECK_EQUAL(initHeight, circ.getFrameRect().height);
		BOOST_CHECK_CLOSE(initArea, circ.getArea(), accuracy);
		circ.move(1, 1);
		BOOST_CHECK_EQUAL(initWidth, circ.getFrameRect().width);
		BOOST_CHECK_EQUAL(initHeight, circ.getFrameRect().height);
		BOOST_CHECK_CLOSE(initArea, circ.getArea(), accuracy);

	}

	BOOST_AUTO_TEST_CASE(consistancyInScaling)
	{
		kraynov::Circle circ({1, 2}, 3);
		const double mult = 1.5;
		const double resultArea = circ.getArea() * mult * mult;
		circ.scale(mult);
		BOOST_CHECK_CLOSE(circ.getArea(), resultArea, accuracy);
	}

	BOOST_AUTO_TEST_CASE(IncorrectArgumets)
	{
		BOOST_CHECK_THROW(kraynov::Circle({0, 0}, -1), std::invalid_argument);
		kraynov::Circle circ({0, 0}, 1.5);
		const double mult = -1.5;

		BOOST_CHECK_THROW(circ.scale(mult), std::invalid_argument);
	}

BOOST_AUTO_TEST_SUITE_END()
