#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double DIFF = 0.0001;

BOOST_AUTO_TEST_SUITE(rectangleMethodsTest)

BOOST_AUTO_TEST_CASE(permanenceParamsOfRectangleAfterOffsetMoving)
{
  uzhegov::Rectangle testRectangle({1.0, 2.0}, 3.0, 4.0);
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const uzhegov::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move(5.0, 4.0);
  uzhegov::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();

  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeMoving, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, DIFF);
}

BOOST_AUTO_TEST_CASE(permanenceParamsOfRectangleAfterMovingToPoint)
{
  uzhegov::Rectangle testRectangle({0.0, 0.0}, 3.0, 4.0);
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const uzhegov::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move({0.0, 0.0});
  uzhegov::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();

  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeMoving, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, DIFF);
}

BOOST_AUTO_TEST_CASE(increaseRectangleAreaAfterScaling)
{
  uzhegov::Rectangle testRectangle({0.1, 3.0}, 6.0, 3.0);
  const double areaBefore = testRectangle.getArea();
  const double coefficient = 2.0;
  testRectangle.scale(coefficient);

  BOOST_CHECK_CLOSE(testRectangle.getArea(), coefficient * coefficient * areaBefore, DIFF);
}

BOOST_AUTO_TEST_CASE(catchingExceptionInRectagleParams)
{
  BOOST_CHECK_THROW(uzhegov::Rectangle({3.0, 2.0}, -1, 4), std::invalid_argument);
  BOOST_CHECK_THROW(uzhegov::Rectangle({2.0, 1.1}, 4, -4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(catchingExceptionAfterScale)
{
  uzhegov::Rectangle testRectangle({0.1, 2.0}, 1, 2);
  BOOST_CHECK_THROW(testRectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleMethodsTest)

BOOST_AUTO_TEST_CASE(permanenceParamsOfCircleAfterOffsetMoving)
{
  uzhegov::Circle testCircle({1.6, 7.0}, 3.0);
  const double circleAreaBeforeMoving = testCircle.getArea();
  const uzhegov::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();
  testCircle.move(5.6, 3.0);
  uzhegov::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();

  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMoving, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, DIFF);
}

BOOST_AUTO_TEST_CASE(permanenceParamsOfCircleAfterMovingToPoint)
{
  uzhegov::Circle testCircle({1.0, 0.2}, 4.0);
  const double circleAreaBeforeMoving = testCircle.getArea();
  const uzhegov::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();
  testCircle.move({0.0, 0.0});
  uzhegov::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();

  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMoving, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, DIFF);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, DIFF);
}

BOOST_AUTO_TEST_CASE(increaseCircleAreaAfterScaling)
{
  uzhegov::Circle testCircle({0.1, 3.0}, 5.0);
  const double areaBefore = testCircle.getArea();
  const double coefficient = 2.0;
  testCircle.scale(coefficient);

  BOOST_CHECK_CLOSE(testCircle.getArea(), coefficient * coefficient * areaBefore, DIFF);
}

BOOST_AUTO_TEST_CASE(catchingExceptionInCircleParams)
{
  BOOST_CHECK_THROW(uzhegov::Circle({3.1, 4.0}, -1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(catchingExceptionAfterScale)
{
  uzhegov::Circle testCircle({0.1, 2.5}, 1);
  BOOST_CHECK_THROW(testCircle.scale(-4), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
