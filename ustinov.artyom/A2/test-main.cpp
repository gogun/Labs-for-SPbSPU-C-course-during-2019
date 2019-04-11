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
  testRectangle.move({12, 2});
  BOOST_CHECK_CLOSE(6, testRectangle.getFrameRect().width, IMPRECISION);
  BOOST_CHECK_CLOSE(3, testRectangle.getFrameRect().height, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(constantWidthAndHeightAfterMovingWithOffset)
{
  ustinov::Rectangle testRectangle({6, 7}, 12, 10);
  testRectangle.move(22, 21);
  BOOST_CHECK_CLOSE(12, testRectangle.getFrameRect().width, IMPRECISION);
  BOOST_CHECK_CLOSE(10, testRectangle.getFrameRect().height, IMPRECISION);
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
  testRectangle.scale(2);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), testing_area * 4, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(changeAfterScalingDecrease)
{
  ustinov::Rectangle testRectangle({4, 7}, 14, 19);
  const auto testing_area = testRectangle.getArea(); //double
  testRectangle.scale(0.5);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), testing_area * 0.25, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(IncorrectWidth)
{
  BOOST_CHECK_THROW(ustinov::Rectangle testRectangle({4, 2}, -15, 2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectHeight)
{
  BOOST_CHECK_THROW(ustinov::Rectangle testRectangle({3, 1}, 33, -8), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficient)
{
  ustinov::Rectangle testRectangle {{12, 3}, 5, 2};
  BOOST_CHECK_THROW(testRectangle.scale(-5), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(constantRadiusAfterMovingCenter)
{
  ustinov::Circle testCircle({2, 3}, 6);
  testCircle.move({12, 2});
  BOOST_CHECK_CLOSE(6, testCircle.getFrameRect().width / 2, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(constantRadiusAfterToPoint)
{
  ustinov::Circle testCircle({2, 3}, 6);
  testCircle.move(7, 4);
  BOOST_CHECK_CLOSE(6, testCircle.getFrameRect().width / 2, IMPRECISION);
}

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
  testCircle.scale(3);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area * 9, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(areaCircleDecrease)
{
  ustinov::Circle testCircle({3, 5}, 6);
  const auto area = testCircle.getArea(); //double
  testCircle.scale(0.2);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area * 0.04, IMPRECISION);
}

BOOST_AUTO_TEST_CASE(inncorrectRadius)
{
  BOOST_CHECK_THROW(ustinov::Circle testCircle({12, 3}, -3.4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficient)
{
  ustinov::Circle testCircle({12, 3}, 3.4);
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

