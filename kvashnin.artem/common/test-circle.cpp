#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "circle.hpp"

const double OFFSET = 0.01;

BOOST_AUTO_TEST_SUITE(testCircle)

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
  const double scaleFactor = 2;
  testingCircle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), testingArea * scaleFactor * scaleFactor, OFFSET);
}

BOOST_AUTO_TEST_CASE(circleTestFrameRectAreaScale)
{
  kvashnin::Circle testingCircle({15, 15}, 10);
  const kvashnin::rectangle_t testingRect = testingCircle.getFrameRect();
  const double scaleFactor = 2;
  testingCircle.scale(scaleFactor);
  const kvashnin::rectangle_t supposedRect = testingCircle.getFrameRect();
  BOOST_CHECK_CLOSE(testingRect.width * scaleFactor, supposedRect.width, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.height * scaleFactor, supposedRect.height, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.x, supposedRect.pos.x, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.y, supposedRect.pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(circleTestThrowingExceptions)
{
  BOOST_CHECK_THROW(kvashnin::Circle({0, 0}, -2), std::invalid_argument);
  kvashnin::Circle testingCircle({15, 15}, 10);
  BOOST_CHECK_THROW(testingCircle.scale(-1), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()
