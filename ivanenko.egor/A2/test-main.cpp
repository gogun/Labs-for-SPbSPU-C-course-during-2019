#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double CHECK = 0.01;

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(movementConstRect)
{
  ivanenko::Rectangle rectangle(1.0, 1.0, {1.0, 1.0});
  const ivanenko::rectangle_t beforeRectFrame = rectangle.getFrameRect();
  const double beforeRectArea = rectangle.getArea();

  rectangle.move(1,1);
  BOOST_CHECK_EQUAL(beforeRectFrame.width, rectangle.getFrameRect().width);
  BOOST_CHECK_EQUAL(beforeRectFrame.height, rectangle.getFrameRect().height);
  BOOST_CHECK_CLOSE(beforeRectArea, rectangle.getArea(), CHECK);

  rectangle.move({10,10});
  BOOST_CHECK_EQUAL(beforeRectFrame.width, rectangle.getFrameRect().width);
  BOOST_CHECK_EQUAL(beforeRectFrame.height, rectangle.getFrameRect().height);
  BOOST_CHECK_CLOSE(beforeRectArea, rectangle.getArea(), CHECK);
}

BOOST_AUTO_TEST_CASE(scalingRect)
{
  ivanenko::Rectangle rectangle(5.0, 5.0, {5.0, 5.0});
  const double beforeRectArea = rectangle.getArea();
  const double scaling = 1.5;

  rectangle.scale(scaling);
  BOOST_CHECK_CLOSE(beforeRectArea * scaling * scaling, rectangle.getArea(), CHECK);
}

BOOST_AUTO_TEST_CASE(wrongArgumentsRect)
{
  BOOST_CHECK_THROW(ivanenko::Rectangle rectangle(-5.0, 5.0, {5.0, 5.0}), std::invalid_argument);
  BOOST_CHECK_THROW(ivanenko::Rectangle rectangle(5.0, -5.0, {5.0, 5.0}), std::invalid_argument);

  ivanenko::Rectangle rectangle(5.0, 5.0, {5.0, 5.0});
  BOOST_CHECK_THROW(rectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(movementConstCircle)
{
  ivanenko::Circle circle({5.0, 5.0}, 5.0);
  const ivanenko::rectangle_t beforeCircleFrame = circle.getFrameRect();
  const double beforeCircleArea = circle.getArea();

  circle.move(1,1);
  BOOST_CHECK_EQUAL(beforeCircleFrame.width, circle.getFrameRect().width);
  BOOST_CHECK_EQUAL(beforeCircleFrame.height, circle.getFrameRect().height);
  BOOST_CHECK_CLOSE(beforeCircleArea, circle.getArea(), CHECK);

  circle.move({10,10});
  BOOST_CHECK_EQUAL(beforeCircleFrame.width, circle.getFrameRect().width);
  BOOST_CHECK_EQUAL(beforeCircleFrame.height, circle.getFrameRect().height);
  BOOST_CHECK_CLOSE(beforeCircleArea, circle.getArea(), CHECK);
}

BOOST_AUTO_TEST_CASE(scalingCircle)
{
  ivanenko::Circle circle({5.0, 5.0}, 5.0);
  const double beforeCircleArea = circle.getArea();
  const double scaling = 1.5;

  circle.scale(scaling);
  BOOST_CHECK_CLOSE(beforeCircleArea * scaling * scaling, circle.getArea(), CHECK);
}

BOOST_AUTO_TEST_CASE(wrongArgumentsCircle)
{
  BOOST_CHECK_THROW(ivanenko::Circle circle({5.0, 5.0}, -5.0), std::invalid_argument);

  ivanenko::Circle circle({5.0, 5.0}, 5.0);
  BOOST_CHECK_THROW(circle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

