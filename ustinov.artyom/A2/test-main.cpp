#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

#define imprecision 0.001

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(constantWidthAndHeightAfterMovingToPoint)
{
  ustinov::Rectangle test_rectangle({2, 3}, 6, 3);
  test_rectangle.move({12, 2});
  BOOST_CHECK_CLOSE(6, test_rectangle.getFrameRect().width, imprecision);
  BOOST_CHECK_CLOSE(3, test_rectangle.getFrameRect().height, imprecision);
}

BOOST_AUTO_TEST_CASE(constantWidthAndHeightAfterMovingWithOffset)
{
  ustinov::Rectangle test_rectangle({6, 7}, 12, 10);
  test_rectangle.move(22, 21);
  BOOST_CHECK_CLOSE(12, test_rectangle.getFrameRect().width, imprecision);
  BOOST_CHECK_CLOSE(10, test_rectangle.getFrameRect().height, imprecision);
}

BOOST_AUTO_TEST_CASE(constantAreaMovingToPoint)
{
  ustinov::Rectangle test_rectangle({12, 23}, 9, 15);
  const auto rectArea = test_rectangle.getArea(); //double
  test_rectangle.move({22, 21});
  BOOST_CHECK_CLOSE(rectArea, test_rectangle.getArea(), imprecision);
}

BOOST_AUTO_TEST_CASE(constantAreaMovingWithOffset)
{
  ustinov::Rectangle test_rectangle({2, 3}, 4, 5);
  const auto rectArea = test_rectangle.getArea(); //double
  test_rectangle.move(22, 20);
  BOOST_CHECK_CLOSE(rectArea, test_rectangle.getArea(), imprecision);
}

BOOST_AUTO_TEST_CASE(changeAfterScalingIncrease)
{
  ustinov::Rectangle test_rectangle({4, 7}, 14, 19);
  const auto testing_area = test_rectangle.getArea(); //double
  test_rectangle.scale(2);
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), testing_area * 4, imprecision);
}

BOOST_AUTO_TEST_CASE(changeAfterScalingDecrease)
{
  ustinov::Rectangle testing_rectangle({4, 7}, 14, 19);
  const auto testing_area = testing_rectangle.getArea(); //double
  testing_rectangle.scale(0.5);
  BOOST_CHECK_CLOSE(testing_rectangle.getArea(), testing_area * 0.25, imprecision);
}

BOOST_AUTO_TEST_CASE(IncorrectWidth)
{
  BOOST_CHECK_THROW(ustinov::Rectangle test_rectangle ({4, 2}, -15, 2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectHeight)
{
  BOOST_CHECK_THROW(ustinov::Rectangle test_rectangle ({3, 1}, 33, -8), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficient)
{
  ustinov::Rectangle test_rectangle {{12, 3}, 5, 2};
  BOOST_CHECK_THROW(test_rectangle.scale(-5), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(constantRadiusAfterMovingCenter)
{
  ustinov::Circle test_circle({2, 3}, 6);
  test_circle.move({12, 2});
  BOOST_CHECK_CLOSE(6, test_circle.getFrameRect().width / 2, imprecision);
}

BOOST_AUTO_TEST_CASE(constantRadiusAfterToPoint)
{
  ustinov::Circle test_circle({2, 3}, 6);
  test_circle.move(7, 4);
  BOOST_CHECK_CLOSE(6, test_circle.getFrameRect().width / 2, imprecision);
}

BOOST_AUTO_TEST_CASE(areaAfterMovingCenter)
{
  ustinov::Circle test_circle({3, 5}, 6);
  const auto area = test_circle.getArea(); //double
  test_circle.move({12, 2});
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, imprecision);
}

BOOST_AUTO_TEST_CASE(areaAfterMoovingCenter)
{
  ustinov::Circle test_circle({3, 5}, 6);
  const auto area = test_circle.getArea(); //double
  test_circle.move(5, 2);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, imprecision);
}

BOOST_AUTO_TEST_CASE(areaCircleIncrease)
{
  ustinov::Circle test_circle({3, 5}, 6);
  const auto area = test_circle.getArea(); //double
  test_circle.scale(3);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area * 9, imprecision);
}

BOOST_AUTO_TEST_CASE(areaCircleDecrease)
{
  ustinov::Circle test_circle({3, 5}, 6);
  const auto area = test_circle.getArea(); //double
  test_circle.scale(0.2);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area * 0.04, imprecision);
}

BOOST_AUTO_TEST_CASE(inncorrectRadius)
{
  BOOST_CHECK_THROW(ustinov::Circle test_circle({12, 3}, -3.4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(inncorrectCoefficient)
{
  ustinov::Circle test_circle({12, 3}, 3.4);
  BOOST_CHECK_THROW(test_circle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

