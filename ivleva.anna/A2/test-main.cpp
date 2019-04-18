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
  BOOST_CHECK_CLOSE(circleFrameBefore.width, circleFrameAfter.width, accuracy);
  BOOST_CHECK_CLOSE(circleFrameBefore.height, circleFrameAfter.height, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(quadraticAreaChanging)
{
  ivleva::Circle circle(6, { 2, 3 });
  double areaBefore = circle.getArea();
  double coefficient = 2.0;
  circle.scale(coefficient);
  double areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(areaBefore*coefficient*coefficient, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(incorrectParametersSearching)
{
  ivleva::Circle circle(6, { 2, 3 });
  BOOST_CHECK_THROW(circle.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(testingOfRectangle)

BOOST_AUTO_TEST_CASE(constancyOfSettings)
{
  ivleva::Rectangle rectangle({ 4, 2, {1, 3} });
  ivleva::rectangle_t rectangleFrameBefore = rectangle.getFrameRect();
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
  BOOST_CHECK_CLOSE(rectangleFrameBefore.width, rectangleFrameAfter.width, accuracy);
  BOOST_CHECK_CLOSE(rectangleFrameBefore.height, rectangleFrameAfter.height, accuracy);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(quadraticAreaChanging)
{
  ivleva::Rectangle rectangle({ 4, 2, {1, 3} });
  double areaBefore = rectangle.getArea();
  double coefficient = 2.2;
  rectangle.scale(coefficient);
  double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaBefore*coefficient*coefficient, areaAfter, accuracy);
}

BOOST_AUTO_TEST_CASE(incorrectParametersSearching)
{
  ivleva::Rectangle rectangle({ 4, 2, { 1, 3 } });
  BOOST_CHECK_THROW(rectangle.scale(-2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
