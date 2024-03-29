#include <boost/test/auto_unit_test.hpp>
#include <cmath>
#include "rectangle.hpp"

const double INACCURACY = 1e-6;

BOOST_AUTO_TEST_SUITE(a2_rectangle_test_suite)

BOOST_AUTO_TEST_CASE(rectangle_absolute_moving_t)
{
  rodchenkov::Rectangle testRectangle{{0, 0}, 1, 1};
  const double          widthBeforeMoving  = testRectangle.getWidth();
  const double          heightBeforeMoving = testRectangle.getHeight();
  const double          areaBeforeMoving   = testRectangle.getArea();
  testRectangle.move({1, 1});
  BOOST_CHECK_CLOSE(widthBeforeMoving, testRectangle.getWidth(), INACCURACY);
  BOOST_CHECK_CLOSE(heightBeforeMoving, testRectangle.getHeight(), INACCURACY);
  BOOST_CHECK_CLOSE(areaBeforeMoving, testRectangle.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangle_relative_moving_t)
{
  rodchenkov::Rectangle testRectangle{{0, 0}, 1, 1};
  const double          widthBeforeMoving  = testRectangle.getWidth();
  const double          heightBeforeMoving = testRectangle.getHeight();
  const double          areaBeforeMoving   = testRectangle.getArea();
  testRectangle.move(1, 1);
  BOOST_CHECK_CLOSE(widthBeforeMoving, testRectangle.getWidth(), INACCURACY);
  BOOST_CHECK_CLOSE(heightBeforeMoving, testRectangle.getHeight(), INACCURACY);
  BOOST_CHECK_CLOSE(areaBeforeMoving, testRectangle.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangle_upscaling_t)
{
  const double          scalingRatio = 2;
  rodchenkov::Rectangle testRectangle{{0, 0}, 1, 1};
  const double          areaBeforeScaling   = testRectangle.getArea();
  const double          heightBeforeScaling = testRectangle.getHeight();
  const double          widthBeforeScaling  = testRectangle.getWidth();
  testRectangle.scale(scalingRatio);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), areaBeforeScaling * pow(scalingRatio, 2), INACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getHeight(), heightBeforeScaling * scalingRatio, INACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getWidth(), widthBeforeScaling * scalingRatio, INACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangle_downscaling_t)
{
  const double          scalingRatio = 0.5;
  rodchenkov::Rectangle testRectangle{{0, 0}, 1, 1};
  const double          areaBeforeScaling = testRectangle.getArea();
  testRectangle.scale(scalingRatio);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), areaBeforeScaling * pow(scalingRatio, 2), INACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangle_constructor_exception_t)
{
  BOOST_CHECK_THROW(rodchenkov::Rectangle testRectangle({ 0, 0 }, -1, 1), std::invalid_argument);
  BOOST_CHECK_THROW(rodchenkov::Rectangle testRectangle({ 0, 0 }, 1, -1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangle_scalig_exception_t)
{
  rodchenkov::Rectangle testRectangle{{0, 0}, 1, 1};
  BOOST_CHECK_THROW(testRectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
