#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double ACCURACY = 0.01;

BOOST_AUTO_TEST_SUITE(rectangleTestA2)

BOOST_AUTO_TEST_CASE(permanencyOfDataAfterMovingBySeveralUnits)
{
  borshchev::Rectangle rectangle({3, 8}, 4, 6);
  const borshchev::rectangle_t primaryFrame = rectangle.getFrameRect();
  const double primaryArea = rectangle.getArea();

  rectangle.move(3, -5);
  borshchev::rectangle_t secondaryFrame = rectangle.getFrameRect();
  double secondaryArea = rectangle.getArea();
  BOOST_CHECK_CLOSE(primaryFrame.width, secondaryFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(primaryFrame.height, secondaryFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(primaryArea, secondaryArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(permanencyOfDataAfterMovingIntoAPoint)
{
  borshchev::Rectangle rectangle({1, 5}, 6, 4);
  const borshchev::rectangle_t primaryFrame = rectangle.getFrameRect();
  const double primaryArea = rectangle.getArea();

  rectangle.move({0, 10});
  borshchev::rectangle_t secondaryFrame = rectangle.getFrameRect();
  double secondaryArea = rectangle.getArea();
  BOOST_CHECK_CLOSE(primaryFrame.width, secondaryFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(primaryFrame.height, secondaryFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(primaryArea, secondaryArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(squareIncrease)
{
  borshchev::Rectangle rectangle({2, 2}, 3, 7);
  const double primaryArea = rectangle.getArea();

  double coefficient = 2;
  rectangle.scale(coefficient);
  const double secondaryArea = rectangle.getArea();
  BOOST_CHECK_CLOSE(primaryArea * coefficient * coefficient, secondaryArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(constructorExceptionHandling)
{
  BOOST_CHECK_THROW(borshchev::Rectangle rectangle({0, 0}, 3, -3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(scaleExceptionHandling)
{
  borshchev::Rectangle rectangle({15, 7}, 3, 4);
  BOOST_CHECK_THROW(rectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleTestA2)

BOOST_AUTO_TEST_CASE(permanencyOfDataAfterMovingBySeveralUnits)
{
  borshchev::Circle circle({6, 2}, 4);
  const borshchev::rectangle_t primaryFrame = circle.getFrameRect();
  const double primaryArea = circle.getArea();

  circle.move(6, 6);
  borshchev::rectangle_t secondaryFrame = circle.getFrameRect();
  double secondaryArea = circle.getArea();
  BOOST_CHECK_CLOSE(primaryFrame.width, secondaryFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(primaryFrame.height, secondaryFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(primaryArea, secondaryArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(permanencyOfDataAfterMovingIntoAPoint)
{
  borshchev::Circle circle({2, 6}, 5);
  const borshchev::rectangle_t primaryFrame = circle.getFrameRect();
  const double primaryArea = circle.getArea();

  circle.move({10, -1});
  borshchev::rectangle_t secondaryFrame = circle.getFrameRect();
  double secondaryArea = circle.getArea();
  BOOST_CHECK_CLOSE(primaryFrame.width, secondaryFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(primaryFrame.height, secondaryFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(primaryArea, secondaryArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(squareIncrease)
{
  borshchev::Circle circle({2, 2}, 5);
  const double primaryArea = circle.getArea();

  double coefficient = 2;
  circle.scale(coefficient);
  double secondaryArea = circle.getArea();
  BOOST_CHECK_CLOSE(primaryArea * coefficient * coefficient, secondaryArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(constructorExceptionHandling)
{
  BOOST_CHECK_THROW(borshchev::Circle circle({1, 1}, -3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(scaleExceptionHandling)
{
  borshchev::Circle circle({7, 15}, 9);
  BOOST_CHECK_THROW(circle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
