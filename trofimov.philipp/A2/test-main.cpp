#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double accuracy = 0.01;

BOOST_AUTO_TEST_SUITE(testsSuiteRectangle)

BOOST_AUTO_TEST_CASE(immutabilityOfMeasurements)
{
  trofimov::Rectangle rectangle({ 5, 10 }, 10, 5);
  const trofimov::rectangle_t rectangleFrameBeforeMoving = rectangle.getFrameRect();
  const double areaBeforeMoving = rectangle.getArea();
  rectangle.move(5, 6);
  trofimov::rectangle_t rectangleFrameAfterMoving = rectangle.getFrameRect();
  double areaAfterMoving = rectangle.getArea();
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.width, rectangleFrameAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.height, rectangleFrameAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);

  rectangle.move({ 2, 5 });
  rectangleFrameAfterMoving = rectangle.getFrameRect();
  areaAfterMoving = rectangle.getArea();
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.width, rectangleFrameAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.height, rectangleFrameAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);
}

BOOST_AUTO_TEST_CASE(squareChangeOfArea)
{
  trofimov::Rectangle rectangle({ 5, 10 }, 2, 3);
  const double areaBeforeScaling = rectangle.getArea();
  rectangle.scale(1.5);
  const double areaAfterScaling = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * areaBeforeScaling, areaAfterScaling, accuracy);
}

BOOST_AUTO_TEST_CASE(availabilityAndProcessingOfIncorrectParameters)
{
  BOOST_CHECK_THROW(trofimov::Rectangle rectangle({ 5, 10 }, -3, 3), std::invalid_argument);
  trofimov::Rectangle rectangle({ 2, 3 }, 5, 7);
  BOOST_CHECK_THROW(rectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testsSuiteCircle)

BOOST_AUTO_TEST_CASE(immutabilityOfMeasurements)
{
  trofimov::Circle circle({ 13, 15 }, 5);
  const trofimov::rectangle_t circleFrameBeforeMoving = circle.getFrameRect();
  const double areaBeforeMoving = circle.getArea();
  circle.move(2, 4);
  trofimov::rectangle_t circleFrameAfterMoving = circle.getFrameRect();
  double areaAfterMoving = circle.getArea();
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.height, circleFrameAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.width, circleFrameAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);

  circle.move({ 3, 5 });
  circleFrameAfterMoving = circle.getFrameRect();
  areaAfterMoving = circle.getArea();
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.height, circleFrameAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.width, circleFrameAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);
}

BOOST_AUTO_TEST_CASE(squareChangeOfArea)
{
  trofimov::Circle circle({ 13, 15 }, 6);
  const double areaBeforeScaling = circle.getArea();
  circle.scale(1.3);
  double areaAfterScaling = circle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * areaBeforeScaling, areaAfterScaling, accuracy);
}

BOOST_AUTO_TEST_CASE(availabilityAndProcessingOfIncorrectParameters)
{
  BOOST_CHECK_THROW(trofimov::Circle circle({ 11, 3 }, 4), std::invalid_argument);
  trofimov::Circle circle({ 2, 3 }, 7);
  BOOST_CHECK_THROW(circle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
