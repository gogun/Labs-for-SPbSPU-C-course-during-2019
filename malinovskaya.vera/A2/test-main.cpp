#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double TOLERANCE = 0.001;

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(testCircleMove)
{
  malinovskaya::Circle circleTest({4.0, 2.0}, 3.0);
  double areaBefore = circleTest.getArea();
  malinovskaya::rectangle_t frameBefore = circleTest.getFrameRect();
  circleTest.move(7.0, -2.0);
  BOOST_CHECK_CLOSE(areaBefore, circleTest.getArea(), TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.width, circleTest.getFrameRect().width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, circleTest.getFrameRect().height, TOLERANCE);
  circleTest.move({-3.0, -10.0});
  BOOST_CHECK_CLOSE(areaBefore, circleTest.getArea(), TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.width, circleTest.getFrameRect().width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, circleTest.getFrameRect().height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testRectangleMove)
{
  malinovskaya::Rectangle rectangleTest({10.0, 7.0, {4.0, 2.0}});
  double areaBefore = rectangleTest.getArea();
  malinovskaya::rectangle_t frameBefore = rectangleTest.getFrameRect();
  rectangleTest.move(7.0, -2.0);
  BOOST_CHECK_CLOSE(areaBefore, rectangleTest.getArea(), TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.width, rectangleTest.getFrameRect().width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, rectangleTest.getFrameRect().height, TOLERANCE);
  rectangleTest.move({-3.0, -10.0});
  BOOST_CHECK_CLOSE(areaBefore, rectangleTest.getArea(), TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.width, rectangleTest.getFrameRect().width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, rectangleTest.getFrameRect().height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCircleScale)
{
  malinovskaya::Circle circleTest({4.0, 2.0}, 3.0);
  double areaBefore = circleTest.getArea();
  double scaleCoeff = 4.0;
  circleTest.scale(scaleCoeff);
  BOOST_CHECK_CLOSE(areaBefore * scaleCoeff * scaleCoeff, circleTest.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testRectangleScale)
{
  malinovskaya::Rectangle rectangleTest({10.0, 4.0, {1.0, -5.0}});
  double areaBefore = rectangleTest.getArea();
  double scaleCoeff = 8.0;
  rectangleTest.scale(scaleCoeff);
  BOOST_CHECK_CLOSE(areaBefore * scaleCoeff * scaleCoeff, rectangleTest.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCircleIncorrectRadius)
{
  BOOST_CHECK_THROW(malinovskaya::Circle circleTest({4.0, 2.0}, -3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleIncorrectScale)
{
  malinovskaya::Circle circleTest({4.0, 2.0}, 3.0);
  BOOST_CHECK_THROW(circleTest.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleIncorrectParameters)
{
  BOOST_CHECK_THROW(malinovskaya::Rectangle rectangleTest({-10.0, 4.0, {1.0, -5.0}}), std::invalid_argument);
  BOOST_CHECK_THROW(malinovskaya::Rectangle rectangleTest({-10.0, -4.0, {1.0, -5.0}}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleIncorrectScale)
{
  malinovskaya::Rectangle rectangleTest({10.0, 4.0, {1.0, -5.0}});
  BOOST_CHECK_THROW(rectangleTest.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
