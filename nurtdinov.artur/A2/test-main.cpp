#define BOOST_TEST_MODULE A2_TESTING

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double ORDER = 0.0001;

BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(circleParamsSavedAfterMovingToPoint)
{
  nurtdinov::Circle circle({4.4, 2.5}, 5.0);
  const double areaBefore = circle.getArea();
  const nurtdinov::rectangle_t frameBefore = circle.getFrameRect();
  circle.move({2.2, 3.1});
  const double areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, ORDER);
  const nurtdinov::rectangle_t frameAfter = circle.getFrameRect();
  BOOST_CHECK_CLOSE(frameAfter.height, frameBefore.height, ORDER);
  BOOST_CHECK_CLOSE(frameAfter.width, frameBefore.width, ORDER);
}

BOOST_AUTO_TEST_CASE(circleParamsSavedAfterShiftMove)
{
  nurtdinov::Circle circle({4.4, 2.5}, 5.0);
  const double areaBefore = circle.getArea();
  const nurtdinov::rectangle_t frameBefore = circle.getFrameRect();
  circle.move(4.6, 2.5);
  const double areaAfter = circle.getArea();
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, ORDER);
  const nurtdinov::rectangle_t frameAfter = circle.getFrameRect();
  BOOST_CHECK_CLOSE(frameAfter.height, frameBefore.height, ORDER);
  BOOST_CHECK_CLOSE(frameAfter.width, frameBefore.width, ORDER);
}

BOOST_AUTO_TEST_CASE(circleScaleTest)
{
  nurtdinov::Circle circle({2.5, 4.1}, 3.0);
  const double areaBefore = circle.getArea();
  const double ratio = 2.0;

  circle.scale(ratio);

  BOOST_CHECK_CLOSE(circle.getArea(), areaBefore * ratio * ratio, ORDER);
}

BOOST_AUTO_TEST_CASE(circleThrowInvalidScale)
{
  nurtdinov::Circle circle({2.2, 4.8}, 5.0);
  BOOST_CHECK_THROW(circle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleTestThrowException)
{
  BOOST_CHECK_THROW(nurtdinov::Circle({2.2, 4.4}, -1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(rectangleParamsSavedAfterMovingToPoint)
{
  nurtdinov::Rectangle rectangle({3.3, 5.8}, 4.0, 5.0);
  const double areaBefore = rectangle.getArea();
  const nurtdinov::rectangle_t frameBefore = rectangle.getFrameRect();
  rectangle.move({5.5, -2.3});

  const double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, ORDER);
  const nurtdinov::rectangle_t frameAfter = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameAfter.height, frameBefore.height, ORDER);
  BOOST_CHECK_CLOSE(frameAfter.width, frameBefore.width, ORDER);
}

BOOST_AUTO_TEST_CASE(rectangleParamsSavedAfterShiftMove)
{
  nurtdinov::Rectangle rectangle({4.8, 5.1}, 4.0, 5.0);
  const double areaBefore = rectangle.getArea();
  const nurtdinov::rectangle_t frameBefore = rectangle.getFrameRect();
  rectangle.move(2.2, 3.9);

  const double areaAfter = rectangle.getArea();
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, ORDER);
  const nurtdinov::rectangle_t frameAfter = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameAfter.height, frameBefore.height, ORDER);
  BOOST_CHECK_CLOSE(frameAfter.width, frameBefore.width, ORDER);
}

BOOST_AUTO_TEST_CASE(rectangleScaleTest)
{
  nurtdinov::Rectangle rectangle({2.5, 4.1}, 3.0, 4.0);
  const double areaBefore = rectangle.getArea();
  const nurtdinov::rectangle_t frameBefore = rectangle.getFrameRect();
  const double ratio = 4.0;

  rectangle.scale(ratio);
  BOOST_CHECK_CLOSE(rectangle.getArea(), areaBefore * ratio * ratio, ORDER);
  const nurtdinov::rectangle_t frameAfter = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameAfter.height, frameBefore.height * ratio, ORDER);
  BOOST_CHECK_CLOSE(frameAfter.width, frameBefore.width * ratio, ORDER);
}

BOOST_AUTO_TEST_CASE(rectangleThrowInvalidScale)
{
  nurtdinov::Rectangle rectangle({5.1, 4.2}, 3.0, 4.0);
  BOOST_CHECK_THROW(rectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleThrowInvalidWidth)
{
  BOOST_CHECK_THROW(nurtdinov::Rectangle({2.2, 4.4}, -3.0, 4.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleThrowInvalidHeight)
{
  BOOST_CHECK_THROW(nurtdinov::Rectangle({2.2, 4.4}, 3.0, -4.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
