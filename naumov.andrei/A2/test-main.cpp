#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"


BOOST_AUTO_TEST_SUITE(rectangleTest);
BOOST_AUTO_TEST_CASE(widthImmutabilityAfterMovingToPoint)
{
  naumov::Rectangle rectangle({-1,1},3,4);
  rectangle.move({ 0.7,20 });
  BOOST_CHECK_EQUAL(3,rectangle.getFrameRect().width);
}

BOOST_AUTO_TEST_CASE(widthImmutabilityAfterMovingWithDisplacement)
{
  naumov::Rectangle rectangle({ -1,1 }, 3, 4);
  rectangle.move(0.7, 20);
  BOOST_CHECK_EQUAL(3, rectangle.getFrameRect().width);
}

BOOST_AUTO_TEST_CASE(heightImmutabilityAfterMovingToPoint)
{
  naumov::Rectangle rectangle({ 0,0 }, 15, 20);
  rectangle.move({ -3.3, 7 });
  BOOST_CHECK_EQUAL(20, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(heightImmutabilityAfterMovingWithDisplacement)
{
  naumov::Rectangle rectangle({ 0,0 }, 15, 20);
  rectangle.move(-3.3, 7);
  BOOST_CHECK_EQUAL(20, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(areaImmutabilityAfterMovingToPoint)
{
  naumov::Rectangle rectangle({ -2,-3 }, 2.5, 13);
  double rectangleArea = rectangle.getArea();
  rectangle.move({ -8, 0.3 });
  BOOST_CHECK_EQUAL(rectangleArea, rectangle.getArea());
}

BOOST_AUTO_TEST_CASE(areaImmutabilityAfterMovingWithDisplacement)
{
  naumov::Rectangle rectangle({ -2,-3 }, 2.5, 13);
  double rectangleArea = rectangle.getArea();
  rectangle.move(-8, 0.3);
  BOOST_CHECK_EQUAL(rectangleArea, rectangle.getArea());
}

BOOST_AUTO_TEST_CASE(scuareChangeOfAreaAfterScaling)
{
  naumov::Rectangle rectangle({ 2,222.2 }, 3, 6);
  double rectangleArea = rectangle.getArea();
  rectangle.scale(1.1);
  BOOST_CHECK_EQUAL(1.1 * 1.1, rectangle.getArea() / rectangleArea);
}

BOOST_AUTO_TEST_CASE(inncorrectWidth)
{
  BOOST_CHECK_THROW(naumov::Rectangle rectangle({ 0.11,0.11 }, -3.4, 6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectHeight)
{
  BOOST_CHECK_THROW(naumov::Rectangle rectangle({ 0.11,0.11 }, 3.4, -6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficient)
{
  naumov::Rectangle rectangle({ 0.11,0.11 }, 3.4, 6);
  BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END(rectangleTest);



BOOST_AUTO_TEST_SUITE(circleTest);
BOOST_AUTO_TEST_CASE(radiusImmutabilityAfterMovingToPoint)
{
  naumov::Circle circle({ -1,1 }, 3);
  circle.move({ 0.7,20 });
  BOOST_CHECK_EQUAL(3, circle.getFrameRect().width / 2);
}

BOOST_AUTO_TEST_CASE(radiusImmutabilityAfterMovingWithDisplacement)
{
  naumov::Circle circle({ -1,1 }, 3);
  circle.move(0.7, 20);
  BOOST_CHECK_EQUAL(3, circle.getFrameRect().width / 2);
}

BOOST_AUTO_TEST_CASE(areaImmutabilityAfterMovingToPoint)
{
  naumov::Circle circle({ -2,-3 }, 2.5);
  double circleArea = circle.getArea();
  circle.move({ -8, 0.3 });
  BOOST_CHECK_EQUAL(circleArea, circle.getArea());
}

BOOST_AUTO_TEST_CASE(areaImmutabilityAfterMovingWithDisplacement)
{
  naumov::Circle circle({ -2,-3 }, 2.5);
  double circleArea = circle.getArea();
  circle.move(-8, 0.3);
  BOOST_CHECK_EQUAL(circleArea, circle.getArea());
}

BOOST_AUTO_TEST_CASE(scuareChangeOfAreaAfterScaling)
{
  naumov::Circle circle({ 2,222.2 }, 3);
  double circleArea = circle.getArea();
  circle.scale(1.1);
  BOOST_CHECK_EQUAL(1.1 * 1.1, circle.getArea() / circleArea);
}

BOOST_AUTO_TEST_CASE(inncorrectRadius)
{
  BOOST_CHECK_THROW(naumov::Circle circle({ 0.11,0.11 }, -3.4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficient)
{
  naumov::Circle circle({ 0.11,0.11 }, 3.4);
  BOOST_CHECK_THROW(circle.scale(0), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END(cirleTest);
