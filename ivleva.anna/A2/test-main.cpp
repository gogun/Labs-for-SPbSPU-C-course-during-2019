#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

double accuracy = 0.01;

BOOST_AUTO_TEST_SUITE(testingOfCircle)

BOOST_AUTO_TEST_CASE(constancyOfSettings)
{
  ivleva::Circle circle(6, { 2, 3 });
  ivleva::rectangle_t circleFrameBefore = circle.getFrameRect();
  double areaBefore = circle.getArea();
  circle.move(3, 6);
  ivleva::rectangle_t circleFrameAfter = circle.getFrameRect();
  double areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(circleFrameBefore.width, circleFrameAfter.width, accuracy);
  BOOST_CHECK_CLOSE(circleFrameBefore.height, circleFrameAfter.height, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);

  circle.move({ 6, 3 });
  circleFrameAfter = circle.getFrameRect();
  areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(circleFrameBefore.width, circleFrameAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(circleFrameBefore.height, circleFrameAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);
}

BOOST_AUTO_TEST_CASE(quadraticAreaChanging)
{
  ivleva::Circle circle(6, { 2, 3 });
  double areaBefore = circle.getArea();
  circle.scale(coefficient);
  double areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(areaBefore*coefficient*coefficient, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(incorrectParametersSearching)
{
  BOOST_CHECK_THROW(ivleva::Circle(-1, { 2, 3 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(testingOfRectangle)

BOOST_AUTO_TEST_CASE(constancyOfSettings)
{
  ivleva::Rectangle rectangle({ 4, 2, {1, 3} });
  ivleva::rectangle_t rectangleFrameBefore = crectangle.getFrameRect();
  double areaBefore = rectangle.getArea();
  rectangle.move(3, 7);
  ivleva::rectangle_t rectangleFrameAfter = rectangle.getFrameRect();
  double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(rectangleFrameBefore.width, rectangleFrameAfter.width, accuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBefore.height, rectangleFrameAfter.height, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);

  rectangle.move({ 4, 3 });
  rectangleFrameAfter = rectangle.getFrameRect();
  areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(rectangleFrameBefore.width, rectangleFrameAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBefore.height, rectangleFrameAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);
}

BOOST_AUTO_TEST_CASE(quadraticAreaChanging)
{
  ivleva::Rectangle rectangle({ 4, 2, {1, 3} });
  double areaBefore = rectangle.getArea();
  rectangle.scale(coefficient);
  double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaBefore*coefficient*coefficient, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(incorrectParametersSearching)
{
  BOOST_CHECK_THROW(ivleva::Rectangle({ -4, 2, {1, 3} }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
