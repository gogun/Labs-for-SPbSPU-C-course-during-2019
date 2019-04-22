#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <cassert>
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

const double accuracy = 0.01;

BOOST_AUTO_TEST_SUITE(testForRectangle)

BOOST_AUTO_TEST_CASE(methodsOfShape)
{
  potapova::Rectangle rectangle({{ 3, 5 }, 3, 10});
  const potapova::rectangle_t rectangleFrameBeforeMove = rectangle.getFrameRect();
  const double areaBefore = rectangle.getArea();

  rectangle.move(1, 4);
  potapova::rectangle_t rectangleFrameAfterMove = rectangle.getFrameRect();
  double areaAfter = rectangle.getArea();

  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.height, rectangleFrameAfterMove.height, accuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.width, rectangleFrameAfterMove.width, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);

  rectangle.move({ 1, 6 });
  rectangleFrameAfterMove = rectangle.getFrameRect();
  areaAfter = rectangle.getArea();

  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.height, rectangleFrameAfterMove.height, accuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.width, rectangleFrameAfterMove.width, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(squareChange)
{
  potapova::Rectangle rectangle({{ 1, 5 }, 4, 3});
  const double areaBeforeScale = rectangle.getArea();
  const double testScale  = 3;
  rectangle.scale(testScale);
  const double areaAfterScale = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScale * testScale * testScale, areaAfterScale, accuracy);
}

BOOST_AUTO_TEST_CASE(availabilityOfProcessingOfInvalidParameters)
{
  BOOST_CHECK_THROW(potapova::Rectangle rectangle({{ 1, 6 }, 5, -3}), std::invalid_argument);
  potapova::Rectangle rectangle({{ 1, 6 }, 3, 5});
  BOOST_CHECK_THROW(rectangle.scale(-3), std::invalid_argument)
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testForCircle)

BOOST_AUTO_TEST_CASE(methodsOfShape)
{
  potapova::Circle circle({ 1, 5 }, 4);
  const potapova::rectangle_t circleFrameBeforeMove = circle.getFrameRect();
  const double areaBefore = circle.getArea();

  circle.move(4, 4);
  potapova::rectangle_t circleFrameAfterMove = circle.getFrameRect();
  double areaAfter = circle.getArea();

  BOOST_CHECK_CLOSE(circleFrameBeforeMove.height, circleFrameAfterMove.height, accuracy);
  BOOST_CHECK_CLOSE(circleFrameBeforeMove.width, circleFrameAfterMove.width, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);

  circle.move({ 3, 5 });
  circleFrameAfterMove = circle.getFrameRect();
  areaAfter = circle.getArea();

  BOOST_CHECK_CLOSE(circleFrameBeforeMove.height, circleFrameAfterMove.height, accuracy);
  BOOST_CHECK_CLOSE(circleFrameBeforeMove.width, circleFrameAfterMove.width, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(squareChange)
{
  potapova::Circle circle({ 4, 5 }, 4);
  const double areaBeforeScale = circle.getArea();
  const double testScale  = 2;
  circle.scale(testScale);
  const double areaAfterScale = circle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScale * testScale * testScale, areaAfterScale, accuracy);
}

BOOST_AUTO_TEST_CASE(availabilityOfProcessingOfInvalidParameters)
{
  BOOST_CHECK_THROW(potapova::Circle circle({ 5, 8 }, -3), std::invalid_argument);
  potapova::Circle circle({ 1, 6 }, 3);
  BOOST_CHECK_THROW(circle.scale(-2), std::invalid_argument)
}

BOOST_AUTO_TEST_SUITE_END()
