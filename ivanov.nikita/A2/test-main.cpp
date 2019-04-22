#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double tolerance = 0.001;

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(rectangleConstantParametersAfterMovingByDistance)
{
  ivanov::Rectangle testRectangle({3, 6.2, { 1, 3 }});
  const double testRectangleArea = testRectangle.getArea();
  const ivanov::rectangle_t testFrameRect = testRectangle.getFrameRect();
  testRectangle.move(4, 2);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, testFrameRect.height, tolerance);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, testFrameRect.width, tolerance);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), testRectangleArea, tolerance);
}

BOOST_AUTO_TEST_CASE(rectangleConstantParametersAfterMovingToPoint)
{
  ivanov::Rectangle testRectangle({4.1, 2, { 2, 3.6 }});
  const double testRectangleArea = testRectangle.getArea();
  const ivanov::rectangle_t testFrameRect = testRectangle.getFrameRect();
  testRectangle.move({4.2, 7});
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, testFrameRect.height, tolerance);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, testFrameRect.width, tolerance);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), testRectangleArea, tolerance);
}

BOOST_AUTO_TEST_CASE(boundingRectangleChangeAfterScalingRectangle)
{
  ivanov::Rectangle testRectangle({1.9, 8.4, { 2.7, 7 }});
  const double testArea = testRectangle.getArea();
  const double coefficient = 3.5;
  testRectangle.scale(coefficient);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), (testArea * coefficient * coefficient), tolerance);
}

BOOST_AUTO_TEST_CASE(rectangleInvalidValues)
{
  BOOST_CHECK_THROW(ivanov::Rectangle testRectangle({0, 2.5, { 3, 4.1 }}), std::invalid_argument);
  BOOST_CHECK_THROW(ivanov::Rectangle testRectangle({ 3.1, 0, { 4, 4 }}), std::invalid_argument);
  BOOST_CHECK_THROW(ivanov::Rectangle testRectangle({-1.8, 7, { 2, 4 }}), std::invalid_argument);
  BOOST_CHECK_THROW(ivanov::Rectangle testRectangle({6, -1, { 7, 4.9 }}), std::invalid_argument);

  ivanov::Rectangle testRectangle({2, 1, { 1, 8.2 }});

  BOOST_CHECK_THROW(testRectangle.scale(-1), std::invalid_argument);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(circleConstantParametersAfterMovingCircleToPoint)
{
  ivanov::Circle testCircle(4, { 2, 3 });
  const double testCircleArea = testCircle.getArea();
  const ivanov::rectangle_t testFrameRect = testCircle.getFrameRect();
  testCircle.move({ 1.5, 7 });
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, testFrameRect.height, tolerance);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, testFrameRect.width, tolerance);
  BOOST_CHECK_CLOSE(testCircle.getArea(), testCircleArea, tolerance);
}

BOOST_AUTO_TEST_CASE(circleConstantParametersAfterMovingByDistance)
{
  ivanov::Circle testCircle(8.2, { 2.4, 3.6 });
  const double testCircleArea = testCircle.getArea();
  const ivanov::rectangle_t testFrameRect = testCircle.getFrameRect();
  testCircle.move(11.4, 2.3);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, testFrameRect.height, tolerance);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, testFrameRect.width, tolerance);
  BOOST_CHECK_CLOSE(testCircle.getArea(), testCircleArea, tolerance);
}

BOOST_AUTO_TEST_CASE(boundingCircleChangeAfterScaling)
{
  ivanov::Circle testCircle(4, { 2.1, 7.7 });
  const double testArea = testCircle.getArea();
  const double coefficient = 3.5;
  testCircle.scale(coefficient);
  BOOST_CHECK_CLOSE(testCircle.getArea(), (testArea * coefficient * coefficient), tolerance);
}

BOOST_AUTO_TEST_CASE(circleInvalidValues)
{
  BOOST_CHECK_THROW(ivanov::Circle testCircle(0, { 1.2, 4 }), std::invalid_argument);
  BOOST_CHECK_THROW(ivanov::Circle testCircle(-4, { 4.3, 4.1 }), std::invalid_argument);
  ivanov::Circle testCircle(6, { 1, 8.2 });
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(testCircle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
