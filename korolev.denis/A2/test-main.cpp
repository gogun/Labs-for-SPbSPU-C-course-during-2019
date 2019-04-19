#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "circle.hpp"
#include "rectangle.hpp"

const double EPSILON = 0.01;

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(constAfterMovingToPoint)
{
  korolev::Rectangle rectangle({ -3, 2.5 }, 2, 5);
  const double widthBefore = rectangle.getFrameRect().width;
  const double heightBefore = rectangle.getFrameRect().height;
  const double areaBefore = rectangle.getArea();
  rectangle.move({2, 3});
  BOOST_CHECK_CLOSE(widthBefore, rectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(heightBefore, rectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, rectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterMovingToDxDy)
{
  korolev::Rectangle rectangle({ -3, 2.5 }, 2, 5);
  const double widthBefore = rectangle.getFrameRect().width;
  const double heightBefore = rectangle.getFrameRect().height;
  const double areaBefore = rectangle.getArea();
  rectangle.move(2, 3);
  BOOST_CHECK_CLOSE(widthBefore, rectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(heightBefore, rectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, rectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterScaling)
{
  korolev::Rectangle rectangle({ 5.2, -8.1 }, 5, 6);
  const double widthBefore = rectangle.getFrameRect().width;
  const double heightBefore = rectangle.getFrameRect().height;
  const double areaBefore = rectangle.getArea();
  const double coefficient = 2.7;
  rectangle.scale(coefficient);
  BOOST_CHECK_CLOSE(widthBefore * coefficient, rectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(heightBefore * coefficient, rectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore * coefficient * coefficient, rectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(invalidWidth)
{
  BOOST_CHECK_THROW(korolev::Rectangle rectangle({ 0.5, 2 }, -12.4, 4), std::invalid_argument);
  BOOST_CHECK_THROW(korolev::Rectangle rectangle({ 0.5, 2 }, 0, 4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidHeight)
{
  BOOST_CHECK_THROW(korolev::Rectangle rectangle({ 0.5, 2 }, 18.4, -4.6), std::invalid_argument);
  BOOST_CHECK_THROW(korolev::Rectangle rectangle({ 0.5, 2 }, 18.4, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidCoefficientOfScaling)
{
  korolev::Rectangle rectangle({ 0.5, 2.3 }, 3, 6.3);
  BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(rectangle.scale(-2.5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(constAfterMovingPoint)
{
  korolev::Circle circle({ -3.2, 5 }, 3.6);
  const double radiusBefore = circle.getRadius();
  const double areaBefore = circle.getArea();
  circle.move({5.3, 7});
  BOOST_CHECK_CLOSE(radiusBefore, circle.getRadius(), EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, circle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterMovingDxDy)
{
  korolev::Circle circle({ -3.2, 5 }, 3.6);
  const double radiusBefore = circle.getRadius();
  const double areaBefore = circle.getArea();
  circle.move(5.3, 7);
  BOOST_CHECK_CLOSE(radiusBefore, circle.getRadius(), EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, circle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterScaling)
{
  korolev::Circle circle({ 0, 0 }, 6);
  const double areaBefore = circle.getArea();
  const double radiusBefore = circle.getRadius();
  const double coefficient = 5.6;
  circle.scale(coefficient);
  BOOST_CHECK_CLOSE(areaBefore * coefficient * coefficient, circle.getArea(), EPSILON);
  BOOST_CHECK_CLOSE(radiusBefore * coefficient, circle.getRadius(), EPSILON);
}

BOOST_AUTO_TEST_CASE(invalidRadius)
{
  BOOST_CHECK_THROW(korolev::Circle circle({ 0.5, 2 }, -6.3), std::invalid_argument);
  BOOST_CHECK_THROW(korolev::Circle circle({ 0.5, 2 }, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidCoefficientOfScaling)
{
  korolev::Circle circle({ 0.3, 1.3 }, 3);
  BOOST_CHECK_THROW(circle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(circle.scale(-4.5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

