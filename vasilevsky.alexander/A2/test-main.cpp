#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

const double fault = 0.001;

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(constantParametersAfterMovingToDistance)
{
  vasilevsky::Rectangle testRectangle(2.1, 3.3, {5.0, 3.9});
  const double testArea = testRectangle.getArea();
  const vasilevsky::rectangle_t testFrameRect = testRectangle.getFrameRect();

  testRectangle.move(1.0, 8.3);

  BOOST_CHECK_CLOSE(testFrameRect.width, testRectangle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(testFrameRect.height, testRectangle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(testArea, testRectangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(constantParametersAfterMovingToPoint)
{
  vasilevsky::Rectangle testRectangle(2.1, 3.3, {5.0, 3.9});
  const double testArea = testRectangle.getArea();
  const vasilevsky::rectangle_t testFrameRect = testRectangle.getFrameRect();

  testRectangle.move({3.1, 5.0});

  BOOST_CHECK_CLOSE(testFrameRect.width, testRectangle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(testFrameRect.height, testRectangle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(testArea, testRectangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(squareСhangeAreaAfterScale)
{
  vasilevsky::Rectangle testRectangle(2.1, 3.3, {5.0, 3.9});
  const double testArea = testRectangle.getArea();
  const double coefficient = 2.1;

  testRectangle.scale(coefficient);

  BOOST_CHECK_CLOSE(testRectangle.getArea(), testArea * coefficient * coefficient, fault);
}

BOOST_AUTO_TEST_CASE(invalidValues)
{
  BOOST_CHECK_THROW(vasilevsky::Rectangle(-2.1, 3.3, {5.0, 3.9}), std::invalid_argument);
  BOOST_CHECK_THROW(vasilevsky::Rectangle(2.1, -3.3, {5.0, 3.9}), std::invalid_argument);
  BOOST_CHECK_THROW(vasilevsky::Rectangle(0.0, 3.3, {5.0, 3.9}), std::invalid_argument);
  BOOST_CHECK_THROW(vasilevsky::Rectangle(2.1, 0.0, {5.0, 3.9}), std::invalid_argument);

  vasilevsky::Rectangle testRectangle(2.1, 3.3, {5.0, 3.9});

  BOOST_CHECK_THROW(testRectangle.scale(-3), std::invalid_argument);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(constantParametersAfterMovingToDistance)
{
  vasilevsky::Circle testCircle(2.5, {5.9, 3.0});
  const double testArea = testCircle.getArea();
  const vasilevsky::rectangle_t testFrameRect = testCircle.getFrameRect();

  testCircle.move(1.0, 8.3);

  BOOST_CHECK_CLOSE(testFrameRect.width, testCircle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(testFrameRect.height, testCircle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(testArea, testCircle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(constantParametersAfterMovingToPoint)
{
  vasilevsky::Circle testCircle(2.5, {5.9, 3.0});
  const double testArea = testCircle.getArea();
  const vasilevsky::rectangle_t testFrameRect = testCircle.getFrameRect();

  testCircle.move({3.1, 5.0});

  BOOST_CHECK_CLOSE(testFrameRect.width, testCircle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(testFrameRect.height, testCircle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(testArea, testCircle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(squareСhangeAreaAfterScale)
{
  vasilevsky::Circle testCircle(2.5, {5.9, 3.0});
  const double testArea = testCircle.getArea();
  const double coefficient = 2.1;

  testCircle.scale(coefficient);

  BOOST_CHECK_CLOSE(testCircle.getArea(), testArea * coefficient * coefficient, fault);
}

BOOST_AUTO_TEST_CASE(invalidValues)
{
  BOOST_CHECK_THROW(vasilevsky::Circle(-2.5, {5.0, 3.9}), std::invalid_argument);
  BOOST_CHECK_THROW(vasilevsky::Circle(0.0, {5.0, 3.9}), std::invalid_argument);

  vasilevsky::Circle testCircle(2.5, {5.0, 3.9});

  BOOST_CHECK_THROW(testCircle.scale(-3), std::invalid_argument);
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
