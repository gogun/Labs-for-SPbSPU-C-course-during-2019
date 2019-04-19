#define BOOST_TEST_MODULE unittest

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"


//окружность

BOOST_AUTO_TEST_SUITE(testsForCircle)

const double EPSILON = 0.1;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  gusarov::Circle testingCircle({2.0, 3.0}, 5.0);
  const double radius = testingCircle.getRadius();
  const double area = testingCircle.getArea();

  testingCircle.move(1.0, 2.0);
  BOOST_CHECK_CLOSE(testingCircle.getRadius(), radius, EPSILON);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), area, EPSILON);

  testingCircle.move({3.0, 5.0});
  BOOST_CHECK_CLOSE(testingCircle.getRadius(), radius, EPSILON);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), area, EPSILON);
}

BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  gusarov::Circle testingCircle({2.0, 3.0}, 5.0);

  const double area = testingCircle.getArea();
  const double scale = 3.0;

  testingCircle.scale(scale);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), area * scale * scale, EPSILON);
}

BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(gusarov::Circle testingCircle({-1.0, -1.0}, -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

//прямоугольник

BOOST_AUTO_TEST_SUITE(testsForRectangle)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  gusarov::Rectangle testingRect({1.0, 2.0}, 3.0, 4.0);

  const double width = testingRect.getWidth();
  const double height = testingRect.getHeight();
  const double area = testingRect.getArea();

  testingRect.move(5.0, 5.5);
  BOOST_CHECK_CLOSE(testingRect.getWidth(), width, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getHeight(), height, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getArea(), area, EPSILON);

  testingRect.move({10.0, 12.0});
  BOOST_CHECK_CLOSE(testingRect.getWidth(), width, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getHeight(), height, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getArea(), area, EPSILON);
}
BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  gusarov::Rectangle testingRect({1.0, 2.0}, 3.0, 4.0);

  const double area = testingRect.getArea();
  const double scale = 3.0;
  testingRect.scale(scale);
  BOOST_CHECK_CLOSE(testingRect.getArea(), area * scale * scale, EPSILON);
}
BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(gusarov::Rectangle testingRect({0.0, -1.0}, -1.0, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
