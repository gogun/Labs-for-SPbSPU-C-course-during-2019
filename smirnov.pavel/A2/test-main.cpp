#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testsOfLabTwo)

const double ERROR_CHANCE = 0.01;

BOOST_AUTO_TEST_CASE(testOfRectangleMoving)
{
  smirnov::Rectangle rect(15, 10, {0, 0});
  const double areaBeforeMoving = rect.getArea();
  const smirnov::rectangle_t rectBeforeMoving = rect.getFrameRect();
  rect.move({-4, 7});
  BOOST_CHECK_CLOSE(rect.getFrameRect().width, rectBeforeMoving.width, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(rect.getFrameRect().height, rectBeforeMoving.height, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(areaBeforeMoving, rect.getArea(), ERROR_CHANCE);
  rect.move(15, -3);
  BOOST_CHECK_CLOSE(rect.getFrameRect().width, rectBeforeMoving.width, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(rect.getFrameRect().height, rectBeforeMoving.height, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(areaBeforeMoving, rect.getArea(), ERROR_CHANCE);
}

BOOST_AUTO_TEST_CASE(testOfCircleMoving)
{
  smirnov::Circle circ(5, {0, 0});
  const double areaBeforeMoving = circ.getArea();
  const smirnov::rectangle_t circBeforeMoving = circ.getFrameRect();
  circ.move({-4, 7});
  BOOST_CHECK_CLOSE(circ.getFrameRect().width, circBeforeMoving.width, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(circ.getFrameRect().height, circBeforeMoving.height, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(areaBeforeMoving, circ.getArea(), ERROR_CHANCE);
  circ.move(15, -3);
  BOOST_CHECK_CLOSE(circ.getFrameRect().width, circBeforeMoving.width, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(circ.getFrameRect().height, circBeforeMoving.height, ERROR_CHANCE);
  BOOST_CHECK_CLOSE(areaBeforeMoving, circ.getArea(), ERROR_CHANCE);
}

BOOST_AUTO_TEST_CASE(testOfRectangleScaling)
{
  smirnov::Rectangle rect(4, 6, {0, 0});
  const double areaBeforeMoving = rect.getArea();
  const double scalingCoef = 3;
  rect.scale(scalingCoef);
  BOOST_CHECK_CLOSE(areaBeforeMoving * scalingCoef * scalingCoef, rect.getArea(), ERROR_CHANCE);
}

BOOST_AUTO_TEST_CASE(testOfCircleScaling)
{
  smirnov::Circle circ(7, {0, 0});
  const double areaBeforeMoving = circ.getArea();
  const double scalingCoef = 0.5;
  circ.scale(scalingCoef);
  BOOST_CHECK_CLOSE(areaBeforeMoving * scalingCoef * scalingCoef, circ.getArea(), ERROR_CHANCE);
}

BOOST_AUTO_TEST_CASE(testOfInvalidScalingCoefInRectangle)
{
  smirnov::Rectangle rect(10, 5, {0, 0});
  BOOST_CHECK_THROW(rect.scale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(rect.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testOfInvalidScalingCoefInCircle)
{
smirnov::Circle circ(3, {0, 0});
BOOST_CHECK_THROW(circ.scale(-2), std::invalid_argument);
BOOST_CHECK_THROW(circ.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testOfInvalidParametersOfRectangle)
{
  BOOST_CHECK_THROW(smirnov::Rectangle rect(-5, 3, {0, 0}), std::invalid_argument);
  BOOST_CHECK_THROW(smirnov::Rectangle rect(5, -3, {0, 0}), std::invalid_argument);
  BOOST_CHECK_THROW(smirnov::Rectangle rect(-5, -3, {0, 0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testOfInvalidParametersOfCircle)
{
  BOOST_CHECK_THROW(smirnov::Circle circ(-5, {0, 0}), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
