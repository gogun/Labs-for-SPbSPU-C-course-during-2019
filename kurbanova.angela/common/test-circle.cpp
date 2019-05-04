#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "circle.hpp"
#define INACCURACY 0.001

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(invariabilityRadAfterMoveInPoint)
{
  kurbanova::Circle test_circle({ 12, -17 }, 4);
  const double rad = test_circle.getRad();
  test_circle.move({ 6, 20 });
  BOOST_CHECK_CLOSE(test_circle.getRad(), rad, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityRadAfterMoveDxDy)
{
  kurbanova::Circle test_circle({ 12, -17 }, 4);
  const double rad = test_circle.getRad();
  test_circle.move(5, 5);
  BOOST_CHECK_CLOSE(test_circle.getRad(), rad, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreaAfterMoveInPoint)
{
  kurbanova::Circle test_circle({ 12, -17 }, 4);
  const double area = test_circle.getArea();
  test_circle.move({ 6, 20 });
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreaAfterMoveDxDy)
{
  kurbanova::Circle test_circle({ 12, -17 }, 4);
  const double area = test_circle.getArea();
  test_circle.move(5, 5);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreaAfterScaleAnIncrease)
{
  kurbanova::Circle test_circle({ 10, 10 }, 4);
  const double area = test_circle.getArea();
  const double numeric_one = 2;
  test_circle.scale(numeric_one);
  BOOST_CHECK_CLOSE(test_circle.getArea(), numeric_one * numeric_one * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreaAfterScaleAnDecrease)
{
  kurbanova::Circle test_circle({ 10, 10 }, 4);
  const double area = test_circle.getArea();
  const double numeric_two = 0.5;
  test_circle.scale(numeric_two);
  BOOST_CHECK_CLOSE(test_circle.getArea(), numeric_two * numeric_two * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(throwExceptionRad)
{
  BOOST_CHECK_THROW(kurbanova::Circle test_circle({ 10, 10 }, -4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(throwExceptionAfterScale)
{
  kurbanova::Circle test_circle({ 10, 10 }, 4);
  BOOST_CHECK_THROW(test_circle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
