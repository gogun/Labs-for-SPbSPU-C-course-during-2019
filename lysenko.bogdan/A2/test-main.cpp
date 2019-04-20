#define BOOST_TEST_MODULE TEST_A2
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

const double deviation = 0.0001;

BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(constParametersAfterMovingByDistance)
{
  lysenko::Circle testCircle(4, {2, 3});
  const double testCircleArea = testCircle.getArea();
  const lysenko::rectangle_t testFrameRect = testCircle.getFrameRect();

  testCircle.move(4, 2);
  BOOST_CHECK_CLOSE(testCircle.getArea(), testCircleArea, deviation);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, testFrameRect.height, deviation);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, testFrameRect.width, deviation);
}

BOOST_AUTO_TEST_CASE(constParametersAfterMovingToPoint)
{
  lysenko::Circle testCircle(4, {2, 3});
  const double testCircleArea = testCircle.getArea();
  const lysenko::rectangle_t testFrameRect = testCircle.getFrameRect();

  testCircle.move({1.5, 7});
  BOOST_CHECK_CLOSE(testCircle.getArea(), testCircleArea, deviation);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, testFrameRect.height, deviation);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, testFrameRect.width, deviation);
}

BOOST_AUTO_TEST_CASE(squareChangeAfterScale)
{
  lysenko::Circle testCircle(4, {2, 7});
  const double testArea = testCircle.getArea();
  const double coefficient = 3.5;

  testCircle.scale(coefficient);

  BOOST_CHECK_CLOSE(testCircle.getArea(), (testArea * coefficient * coefficient), deviation);
}
  
BOOST_AUTO_TEST_CASE(invalidValues)
{
  BOOST_CHECK_THROW(lysenko::Circle testCircle(0, {2, 4}), std::invalid_argument);
  BOOST_CHECK_THROW(lysenko::Circle testCircle(-4, {3, 4.1}), std::invalid_argument);
  
  lysenko::Circle testCircle(6, {1, 8.2});

  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(testCircle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(constParametersAfterMovingByDistance)
{
  lysenko::Rectangle testRectangle({4, 6, {2, 3}});
  const double testRectangleArea = testRectangle.getArea();
  const lysenko::rectangle_t testFrameRect = testRectangle.getFrameRect();

  testRectangle.move(4, 2);

  BOOST_CHECK_CLOSE(testRectangle.getArea(), testRectangleArea, deviation);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, testFrameRect.height, deviation);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, testFrameRect.width, deviation);
}

BOOST_AUTO_TEST_CASE(constParametersAfterMovingToPoint)
{
  lysenko::Rectangle testRectangle({4, 2, { 2, 3 }});
  const double testRectangleArea = testRectangle.getArea();
  const lysenko::rectangle_t testFrameRect = testRectangle.getFrameRect();

  testRectangle.move({1.5, 7});
  BOOST_CHECK_CLOSE(testRectangle.getArea(), testRectangleArea, deviation);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, testFrameRect.height, deviation);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, testFrameRect.width, deviation);
}

BOOST_AUTO_TEST_CASE(squareChangeAfterScale)
{
  lysenko::Rectangle testRectangle({1, 4, { 2, 7 }});
  const double testArea = testRectangle.getArea();
  const double coefficient = 3.5;

  testRectangle.scale(coefficient);

  BOOST_CHECK_CLOSE(testRectangle.getArea(), (testArea * coefficient * coefficient), deviation);
}

BOOST_AUTO_TEST_CASE(invalidValues)
{
  BOOST_CHECK_THROW(lysenko::Rectangle testRectangle({1, 0, {2, 4 }}), std::invalid_argument);
  BOOST_CHECK_THROW(lysenko::Rectangle testRectangle({0, 2, {3, 4.1}}), std::invalid_argument);
  BOOST_CHECK_THROW(lysenko::Rectangle testRectangle({-4, 7, {2, 4 }}), std::invalid_argument);
  BOOST_CHECK_THROW(lysenko::Rectangle testRectangle({3, -1, {3, 4.1}}), std::invalid_argument);

  lysenko::Rectangle testRectangle({2, 1, {1, 8.2}});

  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(testRectangle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
