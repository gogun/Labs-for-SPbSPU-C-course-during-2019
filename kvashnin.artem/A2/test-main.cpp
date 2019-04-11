#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

const double OFFSET = 0.01;

BOOST_AUTO_TEST_SUITE(testSuiteKvashninArtem)

BOOST_AUTO_TEST_CASE(circleTestAreaAndSizeAfterOffset)
{
  kvashnin::Circle testingCircle({0, 0}, 2);
  const double testingArea = testingCircle.getArea();
  const kvashnin::rectangle_t testingFrameBefore = testingCircle.getFrameRect();
  testingCircle.move(100, 100);
  const kvashnin::rectangle_t testingFrameAfter = testingCircle.getFrameRect();
  BOOST_CHECK_CLOSE(testingCircle.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(circleTestAreaAndSizeAfterMoveToPoint)
{
  kvashnin::Circle testingCircle({10, 10}, 7);
  const double testingArea = testingCircle.getArea();
  const kvashnin::rectangle_t testingFrameBefore = testingCircle.getFrameRect();
  testingCircle.move({150, 150});
  const kvashnin::rectangle_t testingFrameAfter = testingCircle.getFrameRect();
  BOOST_CHECK_CLOSE(testingCircle.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(circleTestAfterScale)
{
  kvashnin::Circle testingCircle({15, 15}, 10);
  const double testingArea = testingCircle.getArea();
  testingCircle.scale(2);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), testingArea * 4, OFFSET);
}

BOOST_AUTO_TEST_CASE(circleTestFrameRectAreaScale)
{
  kvashnin::Circle testingCircle({15, 15}, 10);
  const kvashnin::rectangle_t testingRect = testingCircle.getFrameRect();
  testingCircle.scale(2);
  const kvashnin::rectangle_t supposedRect = testingCircle.getFrameRect();
  BOOST_CHECK_CLOSE(testingRect.width * 2, supposedRect.width, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.height * 2, supposedRect.height, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.x, supposedRect.pos.x, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.y, supposedRect.pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(circleTestThrowingExceptions)
{
  BOOST_CHECK_THROW(kvashnin::Circle({0, 0}, -2), std::invalid_argument);
  kvashnin::Circle testingCircle({15, 15}, 10);
  BOOST_CHECK_THROW(testingCircle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleTestAreaAndSizeAfterOffset)
{
  kvashnin::Rectangle testingRectangle({0, 0}, 2, 4);
  const double testingArea = testingRectangle.getArea();
  const kvashnin::rectangle_t testingFrameBefore = testingRectangle.getFrameRect();
  testingRectangle.move(100, 100);
  const kvashnin::rectangle_t testingFrameAfter = testingRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(testingRectangle.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(rectangleTestAreaAndSizeAfterMoveToPoint)
{
  kvashnin::Rectangle testingRectangle({2, 2}, 8, 10);
  const double testingArea = testingRectangle.getArea();
  const kvashnin::rectangle_t testingFrameBefore = testingRectangle.getFrameRect();
  testingRectangle.move({150, 150});
  const kvashnin::rectangle_t testingFrameAfter = testingRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(testingRectangle.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(rectangleTestAreaScale)
{
  kvashnin::Rectangle testingRectangle({4, 4}, 16, 20);
  const double testingArea = testingRectangle.getArea();
  testingRectangle.scale(2);
  BOOST_CHECK_CLOSE(testingRectangle.getArea(), testingArea * 4, OFFSET);
}

BOOST_AUTO_TEST_CASE(rectangleTestFrameRectAfterScale)
{
  kvashnin::Rectangle testingRectangle({4, 4}, 16, 20);
  const kvashnin::rectangle_t testingRect = testingRectangle.getFrameRect();
  testingRectangle.scale(2);
  const kvashnin::rectangle_t supposedRect = testingRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(testingRect.width * 2, supposedRect.width, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.height * 2, supposedRect.height, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.x, supposedRect.pos.x, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.y, supposedRect.pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(rectangleTestThrowingExceptions)
{
  BOOST_CHECK_THROW(kvashnin::Rectangle({0, 0}, -1, 2), std::invalid_argument);
  kvashnin::Rectangle testingRectangle({4, 4}, 16, 20);
  BOOST_CHECK_THROW(testingRectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
