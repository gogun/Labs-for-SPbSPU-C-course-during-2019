#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"

#define COMPARE_TOLERANCE 0.001

BOOST_AUTO_TEST_SUITE(rectangle) // rectangle

BOOST_AUTO_TEST_SUITE(move) // rectangle/move

BOOST_AUTO_TEST_CASE(widthNotChanged)
{
  fedorov::Rectangle rectangle({ 0, 0 }, 3.5, 4.5);
  double width = rectangle.getWidth();

  rectangle.move(1.5, 2.5);
  BOOST_CHECK_EQUAL(rectangle.getWidth(), width);

  rectangle.move({ 4.1, 2.6 });
  BOOST_CHECK_EQUAL(rectangle.getWidth(), width);
}

BOOST_AUTO_TEST_CASE(heightNotChanged)
{
  fedorov::Rectangle rectangle({ 0, 0 }, 3.5, 4.5);
  double height = rectangle.getHeight();

  rectangle.move(1.5, 2.5);
  BOOST_CHECK_EQUAL(rectangle.getHeight(), height);

  rectangle.move({ 4.1, 2.6 });
  BOOST_CHECK_EQUAL(rectangle.getHeight(), height);
}

BOOST_AUTO_TEST_CASE(areaNotChanged)
{
  fedorov::Rectangle rectangle({ 0, 0 }, 3.5, 4.5);
  double area = rectangle.getArea();

  rectangle.move(1.5, 2.5);
  BOOST_CHECK_EQUAL(rectangle.getArea(), area);

  rectangle.move({ 4.1, 2.6 });
  BOOST_CHECK_EQUAL(rectangle.getArea(), area);
}

BOOST_AUTO_TEST_SUITE_END() // rectangle/move

BOOST_AUTO_TEST_SUITE(scale) // rectangle/scale

BOOST_AUTO_TEST_CASE(areaScaledCorrectly)
{
  fedorov::Rectangle rectangle({ 0, 0 }, 3.5, 4.5);
  double area = rectangle.getArea();

  double scale = 2.5;
  double areaScaled = area * scale * scale;

  rectangle.scale(scale);
  
  BOOST_CHECK_CLOSE(rectangle.getArea(), areaScaled, COMPARE_TOLERANCE);

  BOOST_CHECK_CLOSE(rectangle.getArea() / area, scale * scale, COMPARE_TOLERANCE);
}

BOOST_AUTO_TEST_SUITE_END() // rectangle/scale

BOOST_AUTO_TEST_SUITE(parametersCheck) // rectangle/parametersCheck

BOOST_AUTO_TEST_CASE(wrongWidth)
{
  BOOST_CHECK_THROW(fedorov::Rectangle({ 2, 4 }, -3, 5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(wrongHeight)
{
  BOOST_CHECK_THROW(fedorov::Rectangle({ 2, 4 }, 3, -5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(wrongScaleCoefficient)
{
  fedorov::Rectangle rectangle({ 2, 4 }, 3, 5);
  BOOST_CHECK_THROW(rectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END() // rectangle/parametersCheck

BOOST_AUTO_TEST_SUITE_END() // rectangle


BOOST_AUTO_TEST_SUITE(circle) // circle

BOOST_AUTO_TEST_SUITE(move) // circle/move

BOOST_AUTO_TEST_CASE(radiusNotChanged)
{
  fedorov::Circle circle({ 0, 0 }, 3.5);
  double radius = circle.getRadius();

  circle.move(1.5, 2.5);
  BOOST_CHECK_EQUAL(circle.getRadius(), radius);

  circle.move({ 4.1, 2.6 });
  BOOST_CHECK_EQUAL(circle.getRadius(), radius);
}

BOOST_AUTO_TEST_CASE(areaNotChanged)
{
  fedorov::Circle circle({ 0, 0 }, 3.5);
  double area = circle.getArea();

  circle.move(1.5, 2.5);
  BOOST_CHECK_EQUAL(circle.getArea(), area);

  circle.move({ 4.1, 2.6 });
  BOOST_CHECK_EQUAL(circle.getArea(), area);
}

BOOST_AUTO_TEST_SUITE_END() // circle/move

BOOST_AUTO_TEST_SUITE(scale) // circle/scale

BOOST_AUTO_TEST_CASE(areaScaledCorrectly)
{
  fedorov::Circle circle({ 0, 0 }, 3.5);
  double area = circle.getArea();

  double scale = 2.5;
  double areaScaled = area * scale * scale;

  circle.scale(scale);

  BOOST_CHECK_CLOSE(circle.getArea(), areaScaled, COMPARE_TOLERANCE);

  BOOST_CHECK_CLOSE(circle.getArea() / area, scale * scale, COMPARE_TOLERANCE);
}

BOOST_AUTO_TEST_SUITE_END() // circle/scale

BOOST_AUTO_TEST_SUITE(parametersCheck) // circle/parametersCheck

BOOST_AUTO_TEST_CASE(wrongRadius)
{
  BOOST_CHECK_THROW(fedorov::Circle circle({ 0, 0 }, -3); , std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(wrongScaleCoefficient)
{
  fedorov::Circle circle({ 0, 0 }, 3);
  BOOST_CHECK_THROW(circle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END() // circle/parametersCheck

BOOST_AUTO_TEST_SUITE_END() // circle