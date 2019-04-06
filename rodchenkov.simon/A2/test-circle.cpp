#define BOOST_TEST_MODULE 

#include "boost/test/included/unit_test.hpp"
#include "circle.hpp"

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
