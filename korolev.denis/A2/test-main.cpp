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
  const korolev::rectangle_t frameRectBefore = rectangle.getFrameRect();
  const double areaBefore = rectangle.getArea();
  rectangle.move({2, 3});
  const korolev::rectangle_t frameRectAfter = rectangle.getFrameRect();
  const double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(frameRectBefore.width, frameRectAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.height, frameRectAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterMovingToDxDy)
{
  korolev::Rectangle rectangle({ -3, 2.5 }, 2, 5);
  const korolev::rectangle_t frameRectBefore = rectangle.getFrameRect();
  const double areaBefore = rectangle.getArea();
  rectangle.move(2, 3);
  const korolev::rectangle_t frameRectAfter = rectangle.getFrameRect();
  const double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(frameRectBefore.width, frameRectAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.height, frameRectAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterScaling)
{
  korolev::Rectangle rectangle({ 5.2, -8.1 }, 5, 6);
  const korolev::rectangle_t frameRectBefore = rectangle.getFrameRect();
  const double areaBefore = rectangle.getArea();
  const double coefficient = 2.7;
  rectangle.scale(coefficient);
  const korolev::rectangle_t frameRectAfter = rectangle.getFrameRect();
  const double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * coefficient * coefficient, areaAfter, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.width * coefficient, frameRectAfter, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.height * coefficient, frameRectAfter, EPSILON);
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
  const double radiusAfter = circle.getRadius();
  const double areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(radiusBefore, radiusAfter, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterMovingDxDy)
{
  korolev::Circle circle({ -3.2, 5 }, 3.6);
  const double radiusBefore = circle.getRadius();
  const double areaBefore = circle.getArea();
  circle.move(5.3, 7);
  const double radiusAfter = circle.getRadius();
  const double areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(radiusBefore, radiusAfter, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(constAfterScaling)
{
  korolev::Circle circle({ 0, 0 }, 6);
  const double areaBefore = circle.getArea();
  const double radiusBefore = circle.getRadius();
  const double coefficient = 5.6;
  circle.scale(coefficient);
  const double areaAfter = circle.getArea();
  const double radiusAfter = circle.getRadius();
  BOOST_CHECK_CLOSE(areaBefore * coefficient * coefficient, areaAfter, EPSILON);
  BOOST_CHECK_CLOSE(radiusBefore * coefficient, radiusAfter, EPSILON);
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

