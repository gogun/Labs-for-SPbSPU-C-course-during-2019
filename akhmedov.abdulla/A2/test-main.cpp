#define BOOST_TEST_MODULE testRectangle

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double accuracy = 0.0001;

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(consistencyOfWidthHeightArea)
{
  akhmedov::Rectangle exampleRect({ 0, 0 }, 3.18, 9.6875);
  const double widthB = exampleRect.getWidth();
  const double heightB = exampleRect.getHeight();
  const double areaB = exampleRect.getArea();

  exampleRect.move(4, 5);
  BOOST_CHECK_CLOSE(widthB, exampleRect.getWidth(), accuracy);
  BOOST_CHECK_CLOSE(heightB, exampleRect.getHeight(), accuracy);
  BOOST_CHECK_CLOSE(areaB, exampleRect.getArea(), accuracy);

  exampleRect.move({ 6, 8.29 });
  BOOST_CHECK_CLOSE(widthB, exampleRect.getWidth(), accuracy);
  BOOST_CHECK_CLOSE(heightB, exampleRect.getHeight(), accuracy);
  BOOST_CHECK_CLOSE(areaB, exampleRect.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(correctScaling)
{
  akhmedov::Rectangle exampleRect({ 0, 0 }, 3.18, 9.6875);
  const double multiplyCoefficient = 7.836;
  const double areaB = exampleRect.getArea();

  exampleRect.scale(multiplyCoefficient);
  BOOST_CHECK_CLOSE(areaB * multiplyCoefficient * multiplyCoefficient, exampleRect.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(argumentsExceptionsTest)
{
  BOOST_CHECK_THROW(akhmedov::Rectangle({ 0, 0 }, -3, 4), std::invalid_argument);
  BOOST_CHECK_THROW(akhmedov::Rectangle({ 0, 0 }, 3, -4), std::invalid_argument);
  BOOST_CHECK_THROW(akhmedov::Rectangle({ 0, 0 }, -3, -4), std::invalid_argument);

  akhmedov::Rectangle exampleRectangle({ 0, 0 }, 3, 4);
  BOOST_CHECK_THROW(exampleRectangle.scale(-5), std::invalid_argument);
  BOOST_CHECK_THROW(exampleRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(consistencyOfWidthHeightArea)
{
  akhmedov::Circle exampleCircle({ 0, 0 }, 8.9756);
  akhmedov::rectangle_t circumscribedRectangle = exampleCircle.getFrameRect();
  const double widthB = circumscribedRectangle.width;
  const double heightB = circumscribedRectangle.height;
  const double areaB = exampleCircle.getArea();
  const double radiusB = exampleCircle.getRadius();

  exampleCircle.move({ 25, 3.569 });
  circumscribedRectangle = exampleCircle.getFrameRect();
  BOOST_CHECK_CLOSE(widthB, circumscribedRectangle.width, accuracy);
  BOOST_CHECK_CLOSE(heightB, circumscribedRectangle.height, accuracy);
  BOOST_CHECK_CLOSE(areaB, exampleCircle.getArea(), accuracy);
  BOOST_CHECK_CLOSE(radiusB, exampleCircle.getRadius(), accuracy);

  exampleCircle.move(5.678, 8);
  circumscribedRectangle = exampleCircle.getFrameRect();
  BOOST_CHECK_CLOSE(widthB, circumscribedRectangle.width, accuracy);
  BOOST_CHECK_CLOSE(heightB, circumscribedRectangle.height, accuracy);
  BOOST_CHECK_CLOSE(areaB, exampleCircle.getArea(), accuracy);
  BOOST_CHECK_CLOSE(radiusB, exampleCircle.getRadius(), accuracy);
}

BOOST_AUTO_TEST_CASE(correctScaling)
{
  akhmedov::Circle exampleCircle({ 0, 0 }, 7);
  const double multiplyCoefficient = 6.576;
  const double areaB = exampleCircle.getArea();

  exampleCircle.scale(multiplyCoefficient);
  BOOST_CHECK_CLOSE(areaB * multiplyCoefficient * multiplyCoefficient, exampleCircle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(argumentsExceptionsTest)
{
  BOOST_CHECK_THROW(akhmedov::Circle({ 0, 0 }, -4), std::invalid_argument);
  BOOST_CHECK_THROW(akhmedov::Circle({ 0, 0 }, 0), std::invalid_argument);

  akhmedov::Circle exampleCircle({ 0, 0 }, 3);
  BOOST_CHECK_THROW(exampleCircle.scale(-5), std::invalid_argument);
  BOOST_CHECK_THROW(exampleCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
