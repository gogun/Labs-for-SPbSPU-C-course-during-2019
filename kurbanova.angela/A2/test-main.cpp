#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#define INACCURACY 0.001

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(invariabilityWidthAfterMoveInPoint)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double width = test_rec.getFrameRect().width; 
  test_rec.move({6, 10});
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityWidthAfterMoveDxDy)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double width = test_rec.getFrameRect().width;
  test_rec.move(6, 10);
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityHeightAfterMoveInPoint)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double heigt = test_rec.getFrameRect().height;
  test_rec.move({6, 10});
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().height, heigt, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityHeightAfterMoveDxDy)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double height = test_rec.getFrameRect().height;
  test_rec.move(6, 10);
  BOOST_CHECK_CLOSE(test_rec.getFrameRect().height, height, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreAfterMoveInPoint)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double area = test_rec.getArea();
  test_rec.move({6, 10});
  BOOST_CHECK_CLOSE(test_rec.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreAfterMoveDxDy)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double area = test_rec.getArea();
  test_rec.move(6, 10);
  BOOST_CHECK_CLOSE(test_rec.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreAfterScaleAnIncrease)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double area = test_rec.getArea();
  const double number_one = 2;
  test_rec.scale(number_one);
  BOOST_CHECK_CLOSE(test_rec.getArea(), number_one * number_one * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreAfterScaleAnDecrease)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  const double area = test_rec.getArea();
  const double number_two = 0.5;
  test_rec.scale(number_two);
  BOOST_CHECK_CLOSE(test_rec.getArea(), number_two * number_two * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(scaleTest)
{
  kurbanova::Rectangle test_rec({5, 5}, 8, 2);
  BOOST_CHECK_THROW(test_rec.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(throwExceptionWidth)
{
  BOOST_CHECK_THROW(kurbanova::Rectangle test_rec({5, 5}, 8, 2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(throwExceptionHeight)
{
  BOOST_CHECK_THROW(kurbanova::Rectangle test_rec({5, 5}, 8, 2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(invariabilityRadAfterMoveInPoint)
{
  kurbanova::Circle test_circle({12, -17}, 4);
  const double rad = test_circle.getRad();
  test_circle.move({6, 20});
  BOOST_CHECK_CLOSE(test_circle.getRad(), rad, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityRadAfterMoveDxDy)
{
  kurbanova::Circle test_circle({12, -17}, 4);
  const double rad = test_circle.getRad();
  test_circle.move(5, 5);
  BOOST_CHECK_CLOSE(test_circle.getRad(), rad, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreaAfterMoveInPoint)
{
  kurbanova::Circle test_circle({12, -17}, 4);
  const double area = test_circle.getArea();
  test_circle.move({6, 20});
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invariabilityAreaAfterMoveDxDy)
{
  kurbanova::Circle test_circle({12, -17}, 4);
  const double area = test_circle.getArea();
  test_circle.move(5, 5);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreaAfterScaleAnIncrease)
{
  kurbanova::Circle test_circle({10, 10}, 4);
  const double area = test_circle.getArea();
  const double numeric_one = 2;
  test_circle.scale(numeric_one);
  BOOST_CHECK_CLOSE(test_circle.getArea(), numeric_one * numeric_one * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(changingAreaAfterScaleAnDecrease)
{
  kurbanova::Circle test_circle({10, 10}, 4);
  const double area = test_circle.getArea();
  const double numeric_two = 0.5;
  test_circle.scale(numeric_two);
  BOOST_CHECK_CLOSE(test_circle.getArea(), numeric_two * numeric_two * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(throwExceptionRad)
{
  BOOST_CHECK_THROW(kurbanova::Circle test_circle({10, 10}, -4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(throwExceptionAfterScale)
{
  kurbanova::Circle test_circle({10, 10}, 4);
  BOOST_CHECK_THROW(test_circle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
