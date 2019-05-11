#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "rectangle.hpp"

const double OFFSET = 0.01;

BOOST_AUTO_TEST_SUITE(testRectagle)

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
  const double scaleFactor = 2;
  testingRectangle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testingRectangle.getArea(), testingArea * scaleFactor * scaleFactor, OFFSET);
}

BOOST_AUTO_TEST_CASE(rectangleTestFrameRectAfterScale)
{
  kvashnin::Rectangle testingRectangle({4, 4}, 16, 20);
  const kvashnin::rectangle_t testingRect = testingRectangle.getFrameRect();
  const double scaleFactor = 2;
  testingRectangle.scale(scaleFactor);
  const kvashnin::rectangle_t supposedRect = testingRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(testingRect.width * scaleFactor, supposedRect.width, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.height * scaleFactor, supposedRect.height, OFFSET);
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
