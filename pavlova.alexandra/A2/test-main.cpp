#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testSuiteA2)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(constCircleAfterMove)
{
  pavlova::Circle circle(3, {6, 6});
  pavlova::rectangle_t circleBefore = circle.getFrameRect();
  double areaBefore = circle.getArea();

  circle.move(4, 9);
  BOOST_CHECK_CLOSE(circleBefore.height, circle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(circleBefore.width, circle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, circle.getArea(), EPSILON);
  circle.move({2, 2});
  BOOST_CHECK_CLOSE(circleBefore.height, circle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(circleBefore.width, circle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, circle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(constRectangleAfterMove)
{
  pavlova::Rectangle rectangle(3, 5, {6, 6});
  pavlova::rectangle_t rectangleBefore = rectangle.getFrameRect();
  double areaBefore = rectangle.getArea();

  rectangle.move(4, 9);
  BOOST_CHECK_CLOSE(rectangleBefore.height, rectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(rectangleBefore.width, rectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, rectangle.getArea(), EPSILON);
  rectangle.move({2, 2});
  BOOST_CHECK_CLOSE(rectangleBefore.height, rectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(rectangleBefore.width, rectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, rectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(changeCircleAreaAfterScale)
{
  pavlova::Circle circle(3, {6, 6});
  double coeff = 6;
  double areaBefore = circle.getArea();
  circle.scale(coeff);
  BOOST_CHECK_CLOSE(coeff * coeff, circle.getArea() / areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(changeRectangleAreaAfterScale)
{
  pavlova::Rectangle rectangle(3, 5, {6, 6});
  double coeff = 6;
  double areaBefore = rectangle.getArea();
  rectangle.scale(coeff);
  BOOST_CHECK_CLOSE(coeff * coeff, rectangle.getArea() / areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(incorrectCircle)
{
  BOOST_CHECK_THROW(pavlova::Circle(-3, {6, 6}), std::invalid_argument);
  pavlova::Circle circle(3, {6, 6});
  BOOST_CHECK_THROW(circle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(incorrectRectangle)
{
  BOOST_CHECK_THROW(pavlova::Rectangle(-3, 5, {6, 6}), std::invalid_argument);
  BOOST_CHECK_THROW(pavlova::Rectangle(3, -5, {6, 6}), std::invalid_argument);
  pavlova::Rectangle rectangle(3, 5, {6, 6});
  BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
