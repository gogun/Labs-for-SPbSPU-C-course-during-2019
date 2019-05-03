#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

BOOST_AUTO_TEST_SUITE(suiteTest)

const double EPS = 0.01;

BOOST_AUTO_TEST_CASE(moveRectangleConstant)
{
  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  const nazarov::rectangle_t beforeFrame = rectangleTest.getFrameRect();
  const double beforeArea = rectangleTest.getArea();

  rectangleTest.move(5, 5);
  BOOST_CHECK_CLOSE(beforeFrame.width, rectangleTest.getFrameRect().width, EPS);
  BOOST_CHECK_CLOSE(beforeFrame.height, rectangleTest.getFrameRect().height, EPS);
  BOOST_CHECK_CLOSE(beforeArea, rectangleTest.getArea(), EPS);

  rectangleTest.move({ 20, 20 });
  BOOST_CHECK_CLOSE(beforeFrame.width, rectangleTest.getFrameRect().width, EPS);
  BOOST_CHECK_CLOSE(beforeFrame.height, rectangleTest.getFrameRect().height, EPS);
  BOOST_CHECK_CLOSE(beforeArea, rectangleTest.getArea(), EPS);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  const double beforeArea = rectangleTest.getArea();
  const double scaleFactor = 3;

  rectangleTest.scale(scaleFactor);
  BOOST_CHECK_CLOSE(beforeArea * scaleFactor * scaleFactor, rectangleTest.getArea(), EPS);
}

BOOST_AUTO_TEST_CASE(invalidRectArguments)
{
  BOOST_CHECK_THROW(nazarov::Rectangle rectangleTest({ 0, 0 }, -20, 10), std::invalid_argument);
  BOOST_CHECK_THROW(nazarov::Rectangle rectangleTest({ 0, 0 }, -10, 20), std::invalid_argument);

  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  BOOST_CHECK_THROW(rectangleTest.scale(-4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveCircleConstant)
{
  nazarov::Circle circleTest({ 0, 0 }, 20);
  const nazarov::rectangle_t beforeFrame = circleTest.getFrameRect();
  const double beforeArea = circleTest.getArea();

  circleTest.move(5, 5);
  BOOST_CHECK_CLOSE(beforeFrame.width, circleTest.getFrameRect().width, EPS);
  BOOST_CHECK_CLOSE(beforeFrame.height, circleTest.getFrameRect().height, EPS);
  BOOST_CHECK_CLOSE(beforeArea, circleTest.getArea(), EPS);

  circleTest.move({ 20, 20 });
  BOOST_CHECK_CLOSE(beforeFrame.width, circleTest.getFrameRect().width, EPS);
  BOOST_CHECK_CLOSE(beforeFrame.height, circleTest.getFrameRect().height, EPS);
  BOOST_CHECK_CLOSE(beforeArea, circleTest.getArea(), EPS);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  nazarov::Circle circleTest({ 0, 0 }, 20);
  const double beforeArea = circleTest.getArea();
  const double scaleFactor = 3;

  circleTest.scale(scaleFactor);
  BOOST_CHECK_CLOSE(beforeArea * scaleFactor * scaleFactor, circleTest.getArea(), EPS);
}

BOOST_AUTO_TEST_CASE(invalidCircleArguments)
{
  BOOST_CHECK_THROW(nazarov::Circle circleTest({ 0, 0 }, -20), std::invalid_argument);

  nazarov::Circle circleTest({ 0, 0 }, 20);
  BOOST_CHECK_THROW(circleTest.scale(-4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveTriangleConstant)
{
  nazarov::Triangle triangleTest({ 0, 0 }, { 10, 10 }, { 20, -10 });
  const nazarov::rectangle_t beforeFrame = triangleTest.getFrameRect();
  const double beforeArea = triangleTest.getArea();

  triangleTest.move(5, 5);
  BOOST_CHECK_CLOSE(beforeFrame.width, triangleTest.getFrameRect().width, EPS);
  BOOST_CHECK_CLOSE(beforeFrame.height, triangleTest.getFrameRect().height, EPS);
  BOOST_CHECK_CLOSE(beforeArea, triangleTest.getArea(), EPS);

  triangleTest.move({ 20, 20 });
  BOOST_CHECK_CLOSE(beforeFrame.width, triangleTest.getFrameRect().width, EPS);
  BOOST_CHECK_CLOSE(beforeFrame.height, triangleTest.getFrameRect().height, EPS);
  BOOST_CHECK_CLOSE(beforeArea, triangleTest.getArea(), EPS);
}

BOOST_AUTO_TEST_CASE(scaleTriangle)
{
  nazarov::Triangle triangleTest({ 0, 0 }, { 10, 10 }, { 20, -10 });
  const double beforeArea = triangleTest.getArea();
  const double scaleFactor = 3;

  triangleTest.scale(scaleFactor);
  BOOST_CHECK_CLOSE(beforeArea * scaleFactor * scaleFactor, triangleTest.getArea(), EPS);
}

BOOST_AUTO_TEST_CASE(invalidTriangleArguments)
{
  BOOST_CHECK_THROW(nazarov::Triangle triangleTest({ 0, 0 }, { 0, 0 }, { 10, 10 }), std::invalid_argument);
  BOOST_CHECK_THROW(nazarov::Triangle triangleTest({ 0, 0 }, { 10, 10 }, { 10, 10 }), std::invalid_argument);
  BOOST_CHECK_THROW(nazarov::Triangle triangleTest({ 0, 0 }, { 0, 0 }, { 0, 0 }), std::invalid_argument);

  nazarov::Triangle triangleTest({ 0, 0 }, { 10, 10 }, { 20, -10 });
  BOOST_CHECK_THROW(triangleTest.scale(-4), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
