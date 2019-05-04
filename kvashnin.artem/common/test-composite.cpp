#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "composite-shape.hpp"
#include "circle.hpp"

const double OFFSET = 0.01;

BOOST_AUTO_TEST_SUITE(testComposite)

BOOST_AUTO_TEST_CASE(compositeShapeTestAreaAndSizeAfterOffset)
{
  kvashnin::Circle testingCircle({0, 0}, 2);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const double testingArea = comShp.getArea();
  const kvashnin::rectangle_t testingFrameBefore = comShp.getFrameRect();
  comShp.move(100, 100);
  const kvashnin::rectangle_t testingFrameAfter = comShp.getFrameRect();
  BOOST_CHECK_CLOSE(comShp.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestAreaAndSizeAfterMoveToPoint)
{
  kvashnin::Circle testingCircle({0, 0}, 2);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const double testingArea = comShp.getArea();
  const kvashnin::rectangle_t testingFrameBefore = comShp.getFrameRect();
  comShp.move({150, 150});
  const kvashnin::rectangle_t testingFrameAfter = comShp.getFrameRect();
  BOOST_CHECK_CLOSE(comShp.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestAfterScale)
{
  kvashnin::Circle testingCircle({15, 15}, 10);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const double testingArea = comShp.getArea();
  const double scaleFactor = 2;
  comShp.scale(scaleFactor);
  BOOST_CHECK_CLOSE(comShp.getArea(), testingArea * scaleFactor * scaleFactor, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestFrameRectAreaScale)
{
  kvashnin::Circle testingCircle({0, 0}, 10);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const kvashnin::rectangle_t testingRect = comShp.getFrameRect();
  const double scaleFactor = 2;
  comShp.scale(scaleFactor);
  const kvashnin::rectangle_t supposedRect = comShp.getFrameRect();
  BOOST_CHECK_CLOSE(testingRect.width * scaleFactor, supposedRect.width, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.height * scaleFactor, supposedRect.height, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.x, supposedRect.pos.x, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.y, supposedRect.pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestThrowingExceptions)
{
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  BOOST_CHECK_THROW(comShp.getFrameRect(), std::invalid_argument);
  BOOST_CHECK_THROW(comShp.scale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(comShp.add(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(comShp.remove(-2), std::out_of_range);
  BOOST_CHECK_THROW(comShp[-2], std::out_of_range);
  BOOST_CHECK_THROW(kvashnin::CompositeShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
