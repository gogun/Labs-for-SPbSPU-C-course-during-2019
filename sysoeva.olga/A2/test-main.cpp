#define BOOST_TEST_MODULE A2

#include "boost/test/included/unit_test.hpp"
#include <boost/test/floating_point_comparison.hpp>

#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

const double fault = 0.01;

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(invarianceRectParametersAfterMovingTo)
{
  sysoeva::Rectangle tempRectangle(5.2, 6.5, {4.0, 3.0});
  const double initialArea = tempRectangle.getArea();
  const sysoeva::rectangle_t initialRectangle = tempRectangle.getFrameRect();

  tempRectangle.move({14.3,5.2});

  BOOST_CHECK_CLOSE(initialRectangle.width, tempRectangle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(initialRectangle.height, tempRectangle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(initialArea, tempRectangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(invarianceRectParametersAfterMovingBy)
{
  sysoeva::Rectangle tempRectangle(5.2, 6.5, {4.0, 3.0});
  const double initialArea = tempRectangle.getArea();
  const sysoeva::rectangle_t initialRectangle = tempRectangle.getFrameRect();

  tempRectangle.move(3.4, 7.5);

  BOOST_CHECK_CLOSE(initialRectangle.width, tempRectangle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(initialRectangle.height, tempRectangle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(initialArea, tempRectangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(squareChangeOfAreaAfterScale)
{
  sysoeva::Rectangle tempRectangle(5.2, 6.5, {4.0, 3.0});
  const double initialArea = tempRectangle.getArea();
  double coefficient = 2.0;

  tempRectangle.scale(coefficient);

  BOOST_CHECK_CLOSE(initialArea * coefficient * coefficient, tempRectangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(invalidValues)
{
  BOOST_CHECK_THROW(sysoeva::Rectangle rectangle(0, 6.5, {4.0, 3.0}), std::invalid_argument);
  BOOST_CHECK_THROW(sysoeva::Rectangle rectangle(5.2, 0, {4.0, 3.0}), std::invalid_argument);
  BOOST_CHECK_THROW(sysoeva::Rectangle rectangle(-5.2, 6.5, {4.0, 3.0}), std::invalid_argument);
  BOOST_CHECK_THROW(sysoeva::Rectangle rectangle(5.2, -6.5, {4.0, 3.0}), std::invalid_argument);

  sysoeva::Rectangle tempRectangle(10.0, 12.0, {12.5, 9.5});

  BOOST_CHECK_THROW(tempRectangle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(tempRectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(invarianceRectParametersAfterMovingTo)
{
  sysoeva::Circle tempCircle(2.5, {3.2, 4.5});
  const double initialArea = tempCircle.getArea();
  const sysoeva::rectangle_t initialRectangle = tempCircle.getFrameRect();

  tempCircle.move({4.2,5.2});

  BOOST_CHECK_CLOSE(initialRectangle.width, tempCircle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(initialRectangle.height, tempCircle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(initialArea, tempCircle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(invarianceRectParametersAfterMovingBy)
{
  sysoeva::Circle tempCircle(2.5, {3.2, 4.5});
  const double initialArea = tempCircle.getArea();
  const sysoeva::rectangle_t initialRectangle = tempCircle.getFrameRect();

  tempCircle.move(3.5, 17.7);

  BOOST_CHECK_CLOSE(initialRectangle.width, tempCircle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(initialRectangle.height, tempCircle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(initialArea, tempCircle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(squareChangeOfAreaAfterScale)
{
  sysoeva::Circle tempCircle(2.5, {3.2, 4.5});
  const double initialArea = tempCircle.getArea();
  double coefficient = 2.5;

  tempCircle.scale(coefficient);

  BOOST_CHECK_CLOSE(initialArea * coefficient * coefficient, tempCircle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(invalidValues)
{
  BOOST_CHECK_THROW(sysoeva::Circle circle(0, {3.2, 4.5}), std::invalid_argument);
  BOOST_CHECK_THROW(sysoeva::Circle circle(-2.5, {3.2, 4.5}), std::invalid_argument);

  sysoeva::Circle tempCircle(5.7, {6.2, 7.3});

  BOOST_CHECK_THROW(tempCircle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(tempCircle.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(triangleTest)

BOOST_AUTO_TEST_CASE(invarianceRectParametersAfterMovingTo)
{
  sysoeva::Triangle tempTriangle({2.3, 6.7}, {7.8, 3.4}, {4.5, 5.6});
  const double initialArea = tempTringle.getArea();
  const sysoeva::rectangle_t initialRectangle = tempTriangle.getFrameRect();

  tempTriangle.move({4.2,5.4});

  BOOST_CHECK_CLOSE(initialRectangle.width, tempTriangle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(initialRectangle.height, tempTriangle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(initialArea, tempTriangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(invarianceRectParametersAfterMovingBy)
{
  sysoeva::Triangle tempCircle({2.3, 6.7}, {7.8, 3.4}, {4.5, 5.6});
  const double initialArea = tempTriangle.getArea();
  const sysoeva::rectangle_t initialRectangle = tempTriangle.getFrameRect();

  tempTriangle.move(3.3, 17.5);

  BOOST_CHECK_CLOSE(initialRectangle.width, tempTriangle.getFrameRect().width, fault);
  BOOST_CHECK_CLOSE(initialRectangle.height, tempTriangle.getFrameRect().height, fault);
  BOOST_CHECK_CLOSE(initialArea, tempTriangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(squareChangeOfAreaAfterScale)
{
  sysoeva::Triangle tempTriangle({2.3, 6.7}, {7.8, 3.4}, {4.5, 5.6});
  const double initialArea = tempTriangle.getArea();
  double coefficient = 3.0;

  tempTriangle.scale(coefficient);

  BOOST_CHECK_CLOSE(initialArea * coefficient * coefficient, tempTriangle.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(invalidValues)
{
  BOOST_CHECK_THROW(sysoeva::Triangle triangle({2.3, 6.7}, {7.8, 6.7}, {4.5, 6.7}), std::invalid_argument);
  BOOST_CHECK_THROW(sysoeva::Triangle triangle({2.0, 2.0}, {7.0, 7.0}, {7.0, 7.0}), std::invalid_argument);
  BOOST_CHECK_THROW(sysoeva::Triangle triangle({7.8, 6.7}, {7.8, 3.4}, {7.8, 5.6}), std::invalid_argument);

  sysoeva::Triangle tempTriangle({3.4, 4.5}, {2.3, 7.8}, {14.5, 3.4});

  BOOST_CHECK_THROW(tempTrinagle.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(tempTriangle.scale(-1.5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
