#define BOOST_TEST_MODULE A2_TEST_MODULE

#include "boost/test/included/unit_test.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

const double INACCURACY = 1e-6;

BOOST_AUTO_TEST_SUITE(a2_circle_test_suite)

BOOST_AUTO_TEST_CASE(circle_absolute_moving_t)
{
  rodchenkov::Circle testCircle{{0, 0}, 1};
  const double       radiusBeforeMoving = testCircle.getRadius();
  const double       areaBeforeMoving   = testCircle.getArea();
  testCircle.move({1, 1});
  BOOST_CHECK_CLOSE(radiusBeforeMoving, testCircle.getRadius(), INACCURACY);
  BOOST_CHECK_CLOSE(areaBeforeMoving, testCircle.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(circle_relative_moving_t)
{
  rodchenkov::Circle testCircle{{0, 0}, 1};
  const double       radiusBeforeMoving = testCircle.getRadius();
  const double       areaBeforeMoving   = testCircle.getArea();
  testCircle.move(1, 1);
  BOOST_CHECK_CLOSE(radiusBeforeMoving, testCircle.getRadius(), INACCURACY);
  BOOST_CHECK_CLOSE(areaBeforeMoving, testCircle.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(circle_upscaling_t)
{
  const double       scalingRatio = 2;
  rodchenkov::Circle testCircle{{0, 0}, 1};
  const double       radiusBeforeScaling = testCircle.getRadius();
  const double       areaBeforeScaling = testCircle.getArea();
  testCircle.scale(scalingRatio);
  BOOST_CHECK_CLOSE(testCircle.getRadius(), radiusBeforeScaling * scalingRatio, INACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getArea(), areaBeforeScaling * pow(scalingRatio, 2), INACCURACY);
}

BOOST_AUTO_TEST_CASE(circle_downscaling_t)
{
    const double       scalingRatio = 0.5;
    rodchenkov::Circle testCircle{ {0, 0}, 1 };
    const double       radiusBeforeScaling = testCircle.getRadius();
    const double       areaBeforeScaling = testCircle.getArea();
    testCircle.scale(scalingRatio);
    BOOST_CHECK_CLOSE(testCircle.getRadius(), radiusBeforeScaling * scalingRatio, INACCURACY);
    BOOST_CHECK_CLOSE(testCircle.getArea(), areaBeforeScaling * pow(scalingRatio, 2), INACCURACY);
}

BOOST_AUTO_TEST_CASE(circle_constructor_exception_t)
{
  BOOST_CHECK_THROW(rodchenkov::Circle testCircle({ 0, 0 }, -1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circle_scalig_exception_t)
{
  rodchenkov::Circle testCircle{{0, 0}, 1};
  BOOST_CHECK_THROW(testCircle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

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
