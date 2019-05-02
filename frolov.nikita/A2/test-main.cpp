#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

const double Inaccuracy = 0.01;

BOOST_AUTO_TEST_SUITE(testOfRectangle)

BOOST_AUTO_TEST_CASE(checkChangesAfterMovingOfRectangle)
{
  frolov::Rectangle rectangle({3, 5}, 3, 10);
  const frolov::rectangle_t rectangleFrameBeforeMove = rectangle.getFrameRect();
  const double areaBeforeMove = rectangle.getArea();

  rectangle.move(1, 4);
  frolov::rectangle_t rectangleFrameAfterMove = rectangle.getFrameRect();

  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.height, rectangleFrameAfterMove.height, Inaccuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.width, rectangleFrameAfterMove.width, Inaccuracy);
  BOOST_CHECK_CLOSE(areaBeforeMove, rectangle.getArea(), Inaccuracy);

  rectangle.move({1, 6});
  rectangleFrameAfterMove = rectangle.getFrameRect();

  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.height, rectangleFrameAfterMove.height, Inaccuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMove.width, rectangleFrameAfterMove.width, Inaccuracy);
  BOOST_CHECK_CLOSE(areaBeforeMove, rectangle.getArea(), Inaccuracy);
 }

BOOST_AUTO_TEST_CASE(areaCheckAfterScalingOfRectangle)
{
  frolov::Rectangle rectangle({1, 5}, 4, 3);
  const double areaBeforeScale = rectangle.getArea();
  const double testScale = 5;
  rectangle.scale(testScale);
  BOOST_CHECK_CLOSE(areaBeforeScale * testScale * testScale, rectangle.getArea(), Inaccuracy);
 }

BOOST_AUTO_TEST_CASE(invalidArgumentsInRectangle)
{
  BOOST_CHECK_THROW(frolov::Rectangle rectangle({1, 6}, 5, -9), std::invalid_argument);
  BOOST_CHECK_THROW(frolov::Rectangle rectangle({1, 6}, -9, 6), std::invalid_argument);
  frolov::Rectangle rectangle({3, 4}, 3, 4);
  BOOST_CHECK_THROW(rectangle.scale(-4), std::invalid_argument);
 }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testForCircle)

BOOST_AUTO_TEST_CASE(checkChangesAfterMovingOfRectangle)
{
  frolov::Circle circle({5, 3}, 10);
  const frolov::rectangle_t circleFrameBeforeMove = circle.getFrameRect();
  const double areaBeforeMove = circle.getArea();

  circle.move(1, 4);
  frolov::rectangle_t circleFrameAfterMove = circle.getFrameRect();

  BOOST_CHECK_CLOSE(circleFrameBeforeMove.height, circleFrameAfterMove.height, Inaccuracy);
  BOOST_CHECK_CLOSE(circleFrameBeforeMove.width, circleFrameAfterMove.width, Inaccuracy);
  BOOST_CHECK_CLOSE(areaBeforeMove, circle.getArea(), Inaccuracy);

  circle.move({1, 6});
  circleFrameAfterMove = circle.getFrameRect();

  BOOST_CHECK_CLOSE(circleFrameBeforeMove.height, circleFrameAfterMove.height, Inaccuracy);
  BOOST_CHECK_CLOSE(circleFrameBeforeMove.width, circleFrameAfterMove.width, Inaccuracy);
  BOOST_CHECK_CLOSE(areaBeforeMove, circle.getArea(), Inaccuracy);
 }

BOOST_AUTO_TEST_CASE(areaCheckAfterScalingOfCircle)
{
  frolov::Circle circle({5, 4}, 3);
  const double areaBeforeScale = circle.getArea();
  const double testScale = 5;
  circle.scale(testScale);
  BOOST_CHECK_CLOSE(areaBeforeScale * testScale * testScale, circle.getArea(), Inaccuracy);
 }

BOOST_AUTO_TEST_CASE(invalidArgumentsInCircle)
{
  BOOST_CHECK_THROW(frolov::Circle circle({6, 5}, -9), std::invalid_argument);
  frolov::Circle circle({4, 3}, 4);
  BOOST_CHECK_THROW(circle.scale(-4), std::invalid_argument);
 }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testForTriangle)

BOOST_AUTO_TEST_CASE(checkChangesAfterMovingOfTriangle)
{
  frolov::Triangle triangle({3, 4}, {4, 5}, {6, 4});
  const frolov::rectangle_t triangleFrameBeforMove = triangle.getFrameRect();
  const double areaBeforMove = triangle.getArea();

  triangle.move(4, 5);
  frolov::rectangle_t triangleFrameAfterMove = triangle.getFrameRect();

  BOOST_CHECK_CLOSE(triangleFrameAfterMove.height, triangleFrameBeforMove.height, Inaccuracy);
  BOOST_CHECK_CLOSE(triangleFrameAfterMove.width, triangleFrameBeforMove.width, Inaccuracy);
  BOOST_CHECK_CLOSE(areaBeforMove, triangle.getArea(), Inaccuracy);

  triangle.move({4, 5});
  triangleFrameAfterMove = triangle.getFrameRect();

  BOOST_CHECK_CLOSE(triangleFrameAfterMove.height, triangleFrameBeforMove.height, Inaccuracy);
  BOOST_CHECK_CLOSE(triangleFrameAfterMove.width, triangleFrameBeforMove.width, Inaccuracy);
  BOOST_CHECK_CLOSE(areaBeforMove, triangle.getArea(), Inaccuracy);
 }

BOOST_AUTO_TEST_CASE(areaCheckAfterScalingOfTriangle)
{
  frolov::Triangle triangle({3, 4}, {6, 7}, {1, 5});
  const double areaBeforScaling = triangle.getArea();
  const double testScale = 4;
  triangle.scale(testScale);
  BOOST_CHECK_CLOSE(areaBeforScaling * testScale * testScale, triangle.getArea(), Inaccuracy);
 }

BOOST_AUTO_TEST_CASE(invalidArgumentsInTriangle)
{
  BOOST_CHECK_THROW(frolov::Triangle triangle({4, 5}, {4, 6}, {4, 7}), std::invalid_argument);
  BOOST_CHECK_THROW(frolov::Triangle triangle({5, 6}, {1, 6}, {4, 6}), std::invalid_argument);
  frolov::Triangle triangle({4, 5}, {1, 4}, {6, 7});
  BOOST_CHECK_THROW(triangle.scale(-4), std::invalid_argument);
 }

BOOST_AUTO_TEST_SUITE_END()
