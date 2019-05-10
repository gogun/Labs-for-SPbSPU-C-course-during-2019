#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "circle.hpp"

const double diff = 0.001;

BOOST_AUTO_TEST_SUITE(circleTestSuite)

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingCircleRealatively)
{
  kozhin::Circle testCircle({5, -6}, 4);
  const double initialArea = testCircle.getArea();
  const kozhin::rectangle_t initialFrameRect = testCircle.getFrameRect();

  testCircle.move(3, -5);
  const kozhin::rectangle_t newFrameRect = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(newFrameRect.width, initialFrameRect.width, diff);
  BOOST_CHECK_CLOSE(newFrameRect.height, initialFrameRect.height, diff);
  BOOST_CHECK_CLOSE(testCircle.getArea(), initialArea, diff);
}

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingCircleAbsolutely)
{
  kozhin::Circle testCircle({5, -6}, 4);
  const double initialArea = testCircle.getArea();
  const kozhin::rectangle_t initialFrameRect = testCircle.getFrameRect();

  testCircle.move({-3, 1});
  kozhin::rectangle_t newFrameRect = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(newFrameRect.width, initialFrameRect.width, diff);
  BOOST_CHECK_CLOSE(newFrameRect.height, initialFrameRect.height, diff);
  BOOST_CHECK_CLOSE(testCircle.getArea(), initialArea, diff);
}

BOOST_AUTO_TEST_CASE(areaChangeAfterCircleScaling)
{
  kozhin::Circle testCircle({-1, -3}, 5);
  const double scaleRate = 6.3;
  const double initialArea = testCircle.getArea();

  testCircle.scale(scaleRate);
  BOOST_CHECK_CLOSE(testCircle.getArea(), initialArea * scaleRate * scaleRate, diff);
}

BOOST_AUTO_TEST_CASE(invalidCircleConstructorParams)
{
  BOOST_CHECK_THROW(kozhin::Circle({-1, 3.5}, -6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidCircleScaleRate)
{
  kozhin::Circle testCircle({2, 5}, 4);
  BOOST_CHECK_THROW(testCircle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
