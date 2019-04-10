#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(rectangleTest)

const double Epsilon = 0.01;

BOOST_AUTO_TEST_CASE(widthPermanenceAfterMovingToPoint)
{
  skudar::Rectangle rectangle(4, 2, 3, 5);
  rectangle.move({0, 0});
  BOOST_CHECK_EQUAL(3, rectangle.getFrameRect().width);
}

BOOST_AUTO_TEST_CASE(widthPermanenceAfterMovingToCoordinates)
{
  skudar::Rectangle rectangle(4, 2, 3, 5);
  rectangle.move(1, 3);
  BOOST_CHECK_EQUAL(3, rectangle.getFrameRect().width);
}

BOOST_AUTO_TEST_CASE(heightPermanenceAfterMovingToPoint)
{
  skudar::Rectangle rectangle(4, 2, 3, 5);
  rectangle.move({0, 0});
  BOOST_CHECK_EQUAL(5, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(heightPermanenceAfterMovingToCoordinates)
{
  skudar::Rectangle rectangle(4, 2, 3, 5);
  rectangle.move(1, 3);
  BOOST_CHECK_EQUAL(5, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(areaPermanenceAfterMovingToPoint)
{
  skudar::Rectangle rectangle(4, 2, 3, 5);
  const double rectangleArea = rectangle.getArea();
  rectangle.move({0, 0});
  BOOST_CHECK_CLOSE(rectangle.getArea(), rectangleArea, Epsilon);
}
BOOST_AUTO_TEST_CASE(areaPermanenceAfterMovingToCoordinates)
{
  skudar::Rectangle rectangle(4, 2, 3, 5);
  const double rectangleArea = rectangle.getArea();
  rectangle.move(1, 3);
  BOOST_CHECK_CLOSE(rectangle.getArea(), rectangleArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(squareChangeOfAreaAfterScaling)
{
  skudar::Rectangle rectangle(4, 2, 3, 5);
  const double rectangleArea = rectangle.getArea();
  rectangle.scale(2.5);
  BOOST_CHECK_CLOSE(2.5 * 2.5, rectangle.getArea() / rectangleArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(incorrectWidth)
{
  BOOST_CHECK_THROW(skudar::Rectangle rectangle(4, 5, -10, 4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(incorrectHeight)
{
  BOOST_CHECK_THROW(skudar::Rectangle rectangle(4, 5, 4, -5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(incorrectCoefficientOfScaling)
{
  skudar::Rectangle rectangle({0, 0}, 3, 6);
  BOOST_CHECK_THROW(rectangle.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()




BOOST_AUTO_TEST_SUITE(circleTest)

const double Epsilon = 0.01;

BOOST_AUTO_TEST_CASE(radiusPermanenceAfterMovingToPoint)
{
  skudar::Circle circle(2, 2, 9);
  circle.move({0, 0});
  BOOST_CHECK_EQUAL(9, circle.getFrameRect().width / 2);
}

BOOST_AUTO_TEST_CASE(radiusPermanenceAfterMovingToCoordinates)
{
  skudar::Circle circle(2, 2, 9);
  circle.move(3, 6);
  BOOST_CHECK_EQUAL(9, circle.getFrameRect().width / 2);
}

BOOST_AUTO_TEST_CASE(areaPermanenceAfterMovingToPoint)
{
  skudar::Circle circle(2, 2, 9);
  const double circleArea = circle.getArea();
  circle.move({0, 0});
  BOOST_CHECK_CLOSE(circle.getArea(), circleArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(areaPermanenceAfterMovingToCoordinates)
{
  skudar::Circle circle(2, 2, 9);
  const double circleArea = circle.getArea();
  circle.move(3, 8);
  BOOST_CHECK_CLOSE(circle.getArea(), circleArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(squareChangeOfAreaAfterScaling)
{
  skudar::Circle circle(2, 2, 9);
  const double circleArea = circle.getArea();
  circle.scale(3.3);
  BOOST_CHECK_CLOSE(3.3 * 3.3, circle.getArea() / circleArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(incorrectRadius)
{
  BOOST_CHECK_THROW(skudar::Circle circle(2, 2, -6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(incorrectCoefficientOfScaling)
{
  skudar::Circle circle(2, 2, 6);
  BOOST_CHECK_THROW(circle.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
