#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(rectangleConstancyAfterMoving)
{
  tsygarova::Rectangle testRectangle({4, 2, {1, 3}});
  const tsygarova::rectangle_t initFrame = testRectangle.getFrameRect();
  const double initArea = testRectangle.getArea();

  testRectangle.move(4, 7);
  tsygarova::rectangle_t currentFrame = testRectangle.getFrameRect();
  double currentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(initFrame.width, currentFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(initFrame.height, currentFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(initArea, currentArea, EPSILON);

  testRectangle.move({8, 6});
  currentFrame = testRectangle.getFrameRect();
  currentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(initFrame.width, currentFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(initFrame.height, currentFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(initArea, currentArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(circleConstancyAfterMoving)
{
  tsygarova::Circle testCircle(6, {2, 3});
  const tsygarova::rectangle_t initFrame = testCircle.getFrameRect();
  const double initArea = testCircle.getArea();

  testCircle.move(5, 9);
  tsygarova::rectangle_t currentFrame = testCircle.getFrameRect();
  double currentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(initFrame.width, currentFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(initFrame.height, currentFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(initArea, currentArea, EPSILON);

  testCircle.move({9, 3});
  currentFrame = testCircle.getFrameRect();
  currentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(initFrame.width, currentFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(initFrame.height, currentFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(initArea, currentArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(rectangleScaling)
{
  tsygarova::Rectangle testRectangle({4, 2, {1, 3}});
  const double initArea = testRectangle.getArea();
  const double scaleCoefficient = 4;

  testRectangle.scale(ScaleCoefficient);
  double currentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(initArea * scaleCoefficient * scaleCoefficient, currentArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(circleScaling)
{
  tsygarova::Circle testCircle(6, {2, 3});
  const double initArea = testCircle.getArea();
  const double scaleCoefficient = 2;

  testCircle.scale(ScaleCoefficient);
  double currentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(initArea * scaleCoefficient * scaleCoefficient, currentArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(invalidParametersRectangle)
{
  BOOST_CHECK_THROW(tsygarova::Rectangle({-6, 3, {1, 3}}), std::invalid_argument);
  BOOST_CHECK_THROW(tsygarova::Rectangle({6, -3, {1, 3}}), std::invalid_argument);
  BOOST_CHECK_THROW(tsygarova::Rectangle({-6, -3, {1, 3}}), std::invalid_argument);
    
  tsygarova::Rectangle testRectangle({6, 3, {1, 3}});
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidParametersCircle)
{
  BOOST_CHECK_THROW(tsygarova::Circle(-7, {3, 4}), std::invalid_argument);
    
  tsygarova::Circle testCircle(7, {3, 4});
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
