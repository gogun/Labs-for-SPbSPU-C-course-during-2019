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
  circle.move(4, 9);
  BOOST_CHECK_EQUAL(3, circle.getFrameRect().width / 2);
  circle.move({2, 2});
  BOOST_CHECK_EQUAL(3, circle.getFrameRect().width / 2);

  double areaBefore = circle.getArea();
  circle.move(2, 5);
  BOOST_CHECK_EQUAL(areaBefore, circle.getArea());
}

BOOST_AUTO_TEST_CASE(constRectangleAfterMove)
{
  pavlova::Rectangle rectangle(3, 5, {6, 6});
  rectangle.move(4, 9);
  BOOST_CHECK_EQUAL(5, rectangle.getFrameRect().height);
  rectangle.move({2, 2});
  BOOST_CHECK_EQUAL(5, rectangle.getFrameRect().height);
  rectangle.move(4, 9);
  BOOST_CHECK_EQUAL(3, rectangle.getFrameRect().width);
  rectangle.move({2, 2});
  BOOST_CHECK_EQUAL(3, rectangle.getFrameRect().width);

  double areaBefore = rectangle.getArea();
  rectangle.move(2, 5);
  BOOST_CHECK_EQUAL(areaBefore, rectangle.getArea());
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
