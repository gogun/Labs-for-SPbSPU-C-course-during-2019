#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double Epsilon = 0.1;

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(permanencyOfMeasurements)
{
  troshev::Rectangle rectangle({ 10, 10 }, 10, 10);
  const troshev::rectangle_t rectangleFrameBeforeMoving = rectangle.getFrameRect();
  const double areaBeforeMoving = rectangle.getArea();
  rectangle.move(3, 3);
  troshev::rectangle_t rectangleFrameAfterMoving = rectangle.getFrameRect();
  double areaAfterMoving = rectangle.getArea();
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.width, rectangleFrameAfterMoving.width, Epsilon);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.height, rectangleFrameAfterMoving.height, Epsilon);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, Epsilon);

  rectangle.move({ 2, 2 });
  rectangleFrameAfterMoving = rectangle.getFrameRect();
  areaAfterMoving = rectangle.getArea();
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.width, rectangleFrameAfterMoving.width, Epsilon);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.height, rectangleFrameAfterMoving.height, Epsilon);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, Epsilon);
}

BOOST_AUTO_TEST_CASE(areaChanging)
{
  troshev::Rectangle rectangle({ 5, 5 }, 2, 2);
  const double areaBeforeScaling = rectangle.getArea();
  rectangle.scale(2);
  const double areaAfterScaling = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * areaBeforeScaling, areaAfterScaling, Epsilon);
}

BOOST_AUTO_TEST_CASE(presenceAndProcessingOfIncorrectParameters)
{
  BOOST_CHECK_THROW(troshev::Rectangle rectangle({ 5, 5 }, -3, 3), std::invalid_argument);
  troshev::Rectangle rectangle({ 3, 3 }, 5, 7);
  BOOST_CHECK_THROW(rectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(permanencyOfMeasurements)
{
  troshev::Circle circle({ 15, 15 }, 5);
  const troshev::rectangle_t circleFrameBeforeMoving = circle.getFrameRect();
  const double areaBeforeMoving = circle.getArea();
  circle.move(4, 4);
  troshev::rectangle_t circleFrameAfterMoving = circle.getFrameRect();
  double areaAfterMoving = circle.getArea();
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.height, circleFrameAfterMoving.height, Epsilon);
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.width, circleFrameAfterMoving.width, Epsilon);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, Epsilon);

  circle.move({ 6, 6 });
  circleFrameAfterMoving = circle.getFrameRect();
  areaAfterMoving = circle.getArea();
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.height, circleFrameAfterMoving.height, Epsilon);
  BOOST_CHECK_CLOSE(circleFrameBeforeMoving.width, circleFrameAfterMoving.width, Epsilon);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, Epsilon);
}

BOOST_AUTO_TEST_CASE(areaChanging)
{
  troshev::Circle circle({ 10, 15 }, 1);
  const double areaBeforeScaling = circle.getArea();
  circle.scale(1.772);
  double areaAfterScaling = circle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * areaBeforeScaling, areaAfterScaling, Epsilon);
}

BOOST_AUTO_TEST_CASE(presenceAndProcessingOfIncorrectParameters)
{
  BOOST_CHECK_THROW(troshev::Circle circle({ 10, 3 }, -3), std::invalid_argument);
  troshev::Circle circle({ 3, 3 }, 7);
  BOOST_CHECK_THROW(circle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
