#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

#define IMPRECISION 0.001

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(constantWidthAndHeightAfterMovingToPoint)
{
  ustinov::Rectangle testRectangle({2, 3}, 6, 3);
  ustinov::rectangle_t frameBefore = testRectangle.getFrameRect();
  testRectangle.move({12, 2});
  ustinov::rectangle_t frameAfter = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, IMPRECISION);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(constantWidthAndHeightAfterMovingWithOffset)
{
  ustinov::Rectangle testRectangle({6, 7}, 12, 10);
  ustinov::rectangle_t frameBefore = testRectangle.getFrameRect();
  testRectangle.move(22, 21);
  ustinov::rectangle_t frameAfter = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, IMPRECISION);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(constantAreaMovingToPoint)
{
  ustinov::Rectangle testRectangle({12, 23}, 9, 15);
  const auto rectArea = testRectangle.getArea(); //double
  testRectangle.move({22, 21});
  BOOST_CHECK_CLOSE(rectArea, testRectangle.getArea(), IMPRECISION);
}

BOOST_AUTO_TEST_CASE(constantAreaMovingWithOffset)
{
  ustinov::Rectangle testRectangle({2, 3}, 4, 5);
  const auto rectArea = testRectangle.getArea(); //double
  testRectangle.move(22, 20);
  BOOST_CHECK_CLOSE(rectArea, testRectangle.getArea(), IMPRECISION);
}

BOOST_AUTO_TEST_CASE(changeAfterScalingIncrease)
{
  ustinov::Rectangle testRectangle({4, 7}, 14, 19);
  const auto testing_area = testRectangle.getArea(); //double
  auto parameter = 2; //double
  testRectangle.scale(parameter);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), testing_area * parameter * parameter, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(changeAfterScalingDecrease)
{
  ustinov::Rectangle testRectangle({4, 7}, 14, 19);
  const auto testing_area = testRectangle.getArea(); //double
  auto parameter = 0.5; //double 
  testRectangle.scale(parameter);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), testing_area * parameter * parameter, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(incorrectWidth)
{
  BOOST_CHECK_THROW(ustinov::Rectangle testRectangle({4, 2}, -15, 2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(incorrectHeight)
{
  BOOST_CHECK_THROW(ustinov::Rectangle testRectangle({3, 1}, 33, -8), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficientScale)
{
  ustinov::Rectangle testRectangle {{12, 3}, 5, 2};
  BOOST_CHECK_THROW(testRectangle.scale(-5), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(areaAfterMovingCenter)
{
  ustinov::Circle testCircle({3, 5}, 6);
  const auto area = testCircle.getArea(); //double
  testCircle.move({12, 2});
  BOOST_CHECK_CLOSE(testCircle.getArea(), area, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(areaAfterMoovingCenter)
{
  ustinov::Circle testCircle({3, 5}, 6);
  const auto area = testCircle.getArea(); //double
  testCircle.move(5, 2);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(areaCircleIncrease)
{
  ustinov::Circle testCircle({3, 5}, 6);
  const auto area = testCircle.getArea(); //double 
  auto parameter = 3; //double
  testCircle.scale(parameter);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area * parameter * parameter, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(areaCircleDecrease)
{
  ustinov::Circle testCircle({3, 5}, 6);
  const auto area = testCircle.getArea(); //double
  auto parameter = 0.2;
  testCircle.scale(parameter);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area * parameter * parameter, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(inncorrectRadius)
{
  BOOST_CHECK_THROW(ustinov::Circle testCircle({12, 3}, -3.4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficientScale)
{
  ustinov::Circle testCircle({12, 3}, 3.4);
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

