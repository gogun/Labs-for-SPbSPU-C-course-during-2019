#define BOOST_TEST_MODULE A2_TEST

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double diff = 0.001;

BOOST_AUTO_TEST_SUITE(circleTestSuite)

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingCircleRealatively)
{
  kozhin::Circle testCircle({5, -6}, 4);
  const double initialArea = testCircle.getArea();
  const kozhin::rectangle_t initialFrameRect = testCircle.getFrameRect();

  testCircle.move(3, -5);
  const kozhin::rectangle_t newFrameRect = testCircle.getFrameRect();
  BOOST_CHECK_EQUAL(newFrameRect.width, initialFrameRect.width);
  BOOST_CHECK_EQUAL(newFrameRect.height, initialFrameRect.height);
  BOOST_CHECK_EQUAL(testCircle.getArea(), initialArea);
}

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingCircleAbsolutely)
{
  kozhin::Circle testCircle({5, -6}, 4);
  const double initialArea = testCircle.getArea();
  const kozhin::rectangle_t initialFrameRect = testCircle.getFrameRect();

  testCircle.move({-3, 1});
  kozhin::rectangle_t newFrameRect = testCircle.getFrameRect();
  BOOST_CHECK_EQUAL(newFrameRect.width, initialFrameRect.width);
  BOOST_CHECK_EQUAL(newFrameRect.height, initialFrameRect.height);
  BOOST_CHECK_EQUAL(testCircle.getArea(), initialArea);
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

BOOST_AUTO_TEST_SUITE(RectangleTestSuite)

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingRectangleRealatively)
{
  kozhin::Rectangle testRect({-1, 5}, 6, 3);
  const double initialArea = testRect.getArea();
  const kozhin::rectangle_t initialFrameRect = testRect.getFrameRect();

  testRect.move(3, -5);
  const kozhin::rectangle_t newFrameRect = testRect.getFrameRect();
  BOOST_CHECK_EQUAL(newFrameRect.width, initialFrameRect.width);
  BOOST_CHECK_EQUAL(newFrameRect.height, initialFrameRect.height);
  BOOST_CHECK_EQUAL(testRect.getArea(), initialArea);
}

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingRectangleAbsolutely)
{
  kozhin::Rectangle testRect({5, 4}, 3, 8);
  const double initialArea = testRect.getArea();
  const kozhin::rectangle_t initialFrameRect = testRect.getFrameRect();

  testRect.move({-3, 1});
  kozhin::rectangle_t newFrameRect = testRect.getFrameRect();
  BOOST_CHECK_EQUAL(newFrameRect.width, initialFrameRect.width);
  BOOST_CHECK_EQUAL(newFrameRect.height, initialFrameRect.height);
  BOOST_CHECK_EQUAL(testRect.getArea(), initialArea);
}

BOOST_AUTO_TEST_CASE(areaChangeAfterRectangleScaling)
{
  kozhin::Rectangle testRect({7, -5}, 5, 6);
  const double scaleRate = 5.1;
  const double initialArea = testRect.getArea();

  testRect.scale(scaleRate);
  BOOST_CHECK_CLOSE(testRect.getArea(), initialArea * scaleRate * scaleRate, diff);
}

BOOST_AUTO_TEST_CASE(invalidRectangleConstructorParams)
{
  BOOST_CHECK_THROW(kozhin::Rectangle({-1, 3.5}, 1, -3), std::invalid_argument);
  BOOST_CHECK_THROW(kozhin::Rectangle({5, 4}, -5, 6), std::invalid_argument);
  BOOST_CHECK_THROW(kozhin::Rectangle({-6, 5}, -4, -7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidRectangleScaleRate)
{
  kozhin::Rectangle testRect({2, 5}, 4, 3);
  BOOST_CHECK_THROW(testRect.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
