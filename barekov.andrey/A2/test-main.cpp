#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

const double ErrorValue = 0.01;

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingCircle)
{
  barekov::Circle testCircle({4, 4}, 8.7);
  const barekov::rectangle_t InitialFrameRect = testCircle.getFrameRect();
  const double InitialArea = testCircle.getArea();

  testCircle.move({1.9, 1.9});
  barekov::rectangle_t movedFrameRect = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testCircle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testCircle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(InitialArea, testCircle.getArea(), ErrorValue);

  testCircle.move(5, -7);
  movedFrameRect = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testCircle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testCircle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(InitialArea, testCircle.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingRectangle)
{
  barekov::Rectangle testRectangle({6, 6}, 1.3, 2.4);
  const barekov::rectangle_t InitialFrameRect = testRectangle.getFrameRect();
  const double InitialArea = testRectangle.getArea();

  testRectangle.move({1.9, 1.9});
  barekov::rectangle_t movedFrameRect = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testRectangle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testRectangle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(InitialArea, testRectangle.getArea(), ErrorValue);

  testRectangle.move(5, -7);
  movedFrameRect = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testRectangle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testRectangle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(InitialArea, testRectangle.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterScalingCircle)
{
  barekov::Circle testCircle({4, 4}, 3);
  const double InitialArea = testCircle.getArea();
  const int scaleFactor = 2.75;
  testCircle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testCircle.getArea(), scaleFactor * scaleFactor * InitialArea, ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterScalingRectangle)
{
  barekov::Rectangle testRectangle({4, 4}, 3, 8);
  const double InitialArea = testRectangle.getArea();
  const int scaleFactor = 2.75;
  testRectangle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), scaleFactor * scaleFactor * InitialArea, ErrorValue);
}

BOOST_AUTO_TEST_CASE(invalidArgumentsCircle)
{
  BOOST_CHECK_THROW(barekov::Circle({1, 2}, -3), std::invalid_argument);

  barekov::Circle testCircle({1, 2}, 3);
  BOOST_CHECK_THROW(testCircle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidArgumentsRectangle)
{
  BOOST_CHECK_THROW(barekov::Rectangle({1, 2}, -3, 4), std::invalid_argument);
  BOOST_CHECK_THROW(barekov::Rectangle({1, 2}, 3, -4), std::invalid_argument);

  barekov::Rectangle testRectangle({1, 2}, 3, 4);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
