#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "rectangle.hpp"
#define INACCURACY 0.001

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(invariabilityWidthAfterMoveInPoint)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double width = test_rec.getFrameRect().width;
  test_rec.move({ 6, 10 });
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityWidthAfterMoveDxDy)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double width = test_rec.getFrameRect().width;
  test_rec.move(6, 10);
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityHeightAfterMoveInPoint)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double heigt = test_rec.getFrameRect().height;
  test_rec.move({ 6, 10 });
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().height, heigt, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityHeightAfterMoveDxDy)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double height = test_rec.getFrameRect().height;
  test_rec.move(6, 10);
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().height, height, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreAfterMoveInPoint)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double area = test_rec.getArea();
  test_rec.move({ 6, 10 });
  BOOST_CHECK_CLOSE(test_rec.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreAfterMoveDxDy)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double area = test_rec.getArea();
  test_rec.move(6, 10);
  BOOST_CHECK_CLOSE(test_rec.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreAfterScaleAnIncrease)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double area = test_rec.getArea();
  const double number_one = 2;
  test_rec.scale(number_one);
  BOOST_CHECK_CLOSE(test_rec.getArea(), number_one * number_one * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreAfterScaleAnDecrease)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  const double area = test_rec.getArea();
  const double number_two = 0.5;
  test_rec.scale(number_two);
  BOOST_CHECK_CLOSE(test_rec.getArea(), number_two * number_two * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(scaleTest)
{
  kurbanova::Rectangle test_rec({ 5, 5 }, 8, 2);
  BOOST_CHECK_THROW(test_rec.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(throwExceptionWidth)
{
  BOOST_CHECK_THROW(kurbanova::Rectangle test_rec({ 5, 5 }, -8, 2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(throwExceptionHeight)
{
  BOOST_CHECK_THROW(kurbanova::Rectangle test_rec({ 5, 5 }, 8, -2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
