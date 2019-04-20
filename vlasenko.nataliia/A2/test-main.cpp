#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "circle.hpp"
#include "rectangle.hpp"


BOOST_AUTO_TEST_SUITE(circleMethodsTesting)

const double FAULT = 0.01;

BOOST_AUTO_TEST_CASE(circleAfterTransferingTest)
{
	vlasenko::Circle circleTest({ 4.5, 7.3 }, 4.0);
	const double circleAreaBeforeMoving = circleTest.getArea();
	const vlasenko::rectangle_t frameRectBeforeMoving = circleTest.getFrameRect();
	//moving circle to point (7.2,2.3)
	circleTest.move(2.2, -5.8);

	//area and frame rectangle security check
	BOOST_CHECK_CLOSE(circleTest.getArea(), circleAreaBeforeMoving, FAULT);
	vlasenko::rectangle_t frameRectAfterMoving = circleTest.getFrameRect();
	BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, FAULT);
	BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(circleAfterMovingTest)
{
	vlasenko::Circle circleTest({ 4.5, 7.3 }, 4.0);
	const double circleAreaBeforeMoving = circleTest.getArea();
	const vlasenko::rectangle_t frameRectBeforeMoving = circleTest.getFrameRect();

	//moving cicle to point (-3.5, 1.2)
	circleTest.move({ -3.5, 1.2 });

	//area and frame rectangle security check
	BOOST_CHECK_CLOSE(circleTest.getArea(), circleAreaBeforeMoving, FAULT);
	vlasenko::rectangle_t frameRectAfterMoving = circleTest.getFrameRect();
	BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, FAULT);
	BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(circleScaleTesting)
{
	vlasenko::Circle circleTest({ 2.5, 2.5 }, 3.0);
	const double circleAreaBeforeScale = circleTest.getArea();
	const double testScale = 2.5;

	//scale in 2,5 times
	circleTest.scale(testScale);
	//check that area scale in 6.25 times
	BOOST_CHECK_CLOSE(circleTest.getArea(), circleAreaBeforeScale * testScale * testScale, FAULT);
}

BOOST_AUTO_TEST_CASE(circleExceptionAfterScaleTesting)
{
	vlasenko::Circle circleTest({ 1.4, 5.2 }, 3.0);
        BOOST_CHECK_THROW(circleTest.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleExceptionTesting)
{
	BOOST_CHECK_THROW(vlasenko::Circle({ 1.4,3.2 }, -2.0), std::invalid_argument);
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangleMethodsTesting)

BOOST_AUTO_TEST_CASE(rectangleAfterTransferingTesting)
{
	vlasenko::Rectangle rectangleTest({ 2.5, 7.5 }, 5.0, 2.0);
	const double rectangleAreaBeforeMoving = rectangleTest.getArea();
	const vlasenko::rectangle_t frameRectBeforeMoving = rectangleTest.getFrameRect();
	rectangleTest.move(7.2, 2.3);

	BOOST_CHECK_CLOSE(rectangleTest.getArea(), rectangleAreaBeforeMoving, FAULT);
	vlasenko::rectangle_t frameRectAfterMoving = rectangleTest.getFrameRect();
	BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, FAULT);
	BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(rectangleAfterMovingTesting)
{
	vlasenko::Rectangle rectangleTest({ 2.5, 7.5 }, 5.0, 2.0);
	const double rectangleAreaBeforeMoving = rectangleTest.getArea();
	const vlasenko::rectangle_t frameRectBeforeMoving = rectangleTest.getFrameRect();
	rectangleTest.move({ 2.5,-8.1 });

	BOOST_CHECK_CLOSE(rectangleTest.getArea(), rectangleAreaBeforeMoving, FAULT);
	vlasenko::rectangle_t frameRectAfterMoving = rectangleTest.getFrameRect();
	BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, FAULT);
	BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(rectangleScaleTesting)
{
	vlasenko::Rectangle rectangleTest({ 2.5, 2.5 }, 3.0, 5.0);
	const double rectangleAreaBeforeScale = rectangleTest.getArea();
	const vlasenko::rectangle_t frameRectBeforeScale = rectangleTest.getFrameRect();
        const double scaleTesting = 2.5;

        rectangleTest.scale(scaleTesting);
	BOOST_CHECK_CLOSE(rectangleTest.getArea(), rectangleAreaBeforeScale * testScale * testScale, FAULT);
	const vlasenko::rectangle_t frameRectAfterScale = rectangleTest.getFrameRect();
	BOOST_CHECK_CLOSE(frameRectAfterScale.height, frameRectBeforeScale.height * testScale, FAULT);
	BOOST_CHECK_CLOSE(frameRectAfterScale.width, frameRectBeforeScale.width * testScale, FAULT);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionAfterScaleTesting)
{
	vlasenko::Rectangle rectangleTest({ 2.1, 5.3 }, 5.5, 3.2);
	BOOST_CHECK_THROW(rectangleTest.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleWidthExceptionTesting)
{
	BOOST_CHECK_THROW(vlasenko::Rectangle({ 5.1,4.2 }, -2.2, -5.8), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleHeightExceptionTesting)
{
	BOOST_CHECK_THROW(vlasenko::Rectangle({ 5.1,4.2 }, 3.0, -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
