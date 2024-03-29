#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double MISTAKE = 0.001;

BOOST_AUTO_TEST_SUITE(circleTesting)

BOOST_AUTO_TEST_CASE(circleTestMoving)
{
  utin::Circle testCircle({2.1, 3.9}, 4.5);
  const double areaBeforeMoving = testCircle.getArea();
  const utin::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();
  testCircle.move(-1.1, 2.1);
  BOOST_CHECK_CLOSE(testCircle.getArea(), areaBeforeMoving, MISTAKE);
  const utin::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, MISTAKE);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, MISTAKE);
}

BOOST_AUTO_TEST_CASE(circleTestMovingTo)
{
  utin::Circle testCircle({2.1, 3.9}, 4.5);
  const double areaBeforeMoving = testCircle.getArea();
  const utin::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();
  testCircle.move({-1.0, 2.0});
  BOOST_CHECK_CLOSE(testCircle.getArea(), areaBeforeMoving, MISTAKE);
  const utin::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, MISTAKE);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, MISTAKE);
}

BOOST_AUTO_TEST_CASE(circleTestScale)
{
  utin::Circle testCircle({2.1, 3.9}, 4.5);
  const double areaBeforeScale = testCircle.getArea();
  const double multiplier = 1.5;
  testCircle.scale(multiplier);
  BOOST_CHECK_CLOSE(testCircle.getArea(), areaBeforeScale * multiplier * multiplier, MISTAKE);
}

BOOST_AUTO_TEST_CASE(circleTestTrowException)
{
  BOOST_CHECK_THROW(utin::Circle testCircle({1.1, 1.2}, -1.1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleTestTrowExceptionScale)
{
  utin::Circle testCircle({2.1, 3.9}, 4.5);
  BOOST_CHECK_THROW(testCircle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangleTesting)

BOOST_AUTO_TEST_CASE(rectangleTestMoving)
{
  utin::Rectangle testRectangle({2.1, 3.9}, 4.5, 5.5);
  const double areaBeforeMoving = testRectangle.getArea();
  const utin::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move(-1.1, 2.1);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), areaBeforeMoving, MISTAKE);
  const utin::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, MISTAKE);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, MISTAKE);
}

BOOST_AUTO_TEST_CASE(rectangleTestMovingTo)
{
  utin::Rectangle testRectangle({2.1, 3.9}, 4.5, 5.5);
  const double areaBeforeMoving = testRectangle.getArea();
  const utin::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move({-1.0, 2.0});
  BOOST_CHECK_CLOSE(testRectangle.getArea(), areaBeforeMoving, MISTAKE);
  const utin::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, MISTAKE);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, MISTAKE);
}

BOOST_AUTO_TEST_CASE(rectangleTestScale)
{
  utin::Rectangle testRectangle({2.1, 3.9}, 4.5, 5.5);
  const double areaBeforeScale = testRectangle.getArea();
  const double multiplier = 1.5;
  testRectangle.scale(multiplier);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), areaBeforeScale * multiplier * multiplier, MISTAKE);
}

BOOST_AUTO_TEST_CASE(rectangleTestWidthTrowException)
{
  BOOST_CHECK_THROW(utin::Rectangle({1.1, 1.2}, -1.1, 1.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleTestHeigthTrowException)
{
  BOOST_CHECK_THROW(utin::Rectangle({1.1, 1.2}, 1.1, -1.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleTestTrowExceptionScale)
{
  utin::Rectangle testRectangle({2.1, 3.9}, 4.5, 5.5);
  BOOST_CHECK_THROW(testRectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
