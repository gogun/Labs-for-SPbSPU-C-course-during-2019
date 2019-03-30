#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#define INACCURACY 0.001

BOOST_AUTO_TEST_SUITE(TestForCircle)

BOOST_AUTO_TEST_CASE(immutabilityRadiusAfterMovingCenter)
{
  maschenko::Circle test_circle({15, 15}, 5);
  const double radius = test_circle.getRadius();
  test_circle.move({50, 50});
  BOOST_CHECK_CLOSE(test_circle.getRadius(), radius, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityRadiusAfterMovingOnDxAndDy)
{
  maschenko::Circle test_circle({15, 15}, 5);
  const double radius = test_circle.getRadius();
  test_circle.move(10, 10);
  BOOST_CHECK_CLOSE(test_circle.getRadius(), radius, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityAreaAfterMovingCenter)
{
  maschenko::Circle test_circle({15, 15}, 5);
  const double area = test_circle.getArea();
  test_circle.move({50, 50});
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityAreaAfterMovingOnDxAndDy)
{
  maschenko::Circle test_circle({15, 15}, 5);
  const double area = test_circle.getArea();
  test_circle.move(10, 10);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(AreaScalingIncrease)
{
  maschenko::Circle test_circle {{15, 15}, 5};
  const double area = test_circle.getArea();
  const double increase_number = 3;
  test_circle.scale(increase_number);
  BOOST_CHECK_CLOSE(test_circle.getArea(), increase_number * increase_number * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(AreaScalingDecrease)
{
  maschenko::Circle test_circle {{15, 15}, 5};
  const double area = test_circle.getArea();
  const double decrease_number = 0.25
  test_circle.scale(decrease_number);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area * decrease_number * decrease_number, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ThrowExceptionAfterScale)
{
  maschenko::Circle test_circle {{15, 15}, 5};
  BOOST_CHECK_THROW(test_circle.scale(-10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ThrowExceptionDueIncorrectRadius)
{
  BOOST_CHECK_THROW(maschenko::Circle test_circle({15, 15}, -5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestForRectangle)

BOOST_AUTO_TEST_CASE(immutabilityWidthAfterMovingCenter)
{
  maschenko::Rectangle test_rectangle({10, 10}, 5, 8);
  const double width = test_rectangle.getFrameRect().width;
  test_rectangle.move({50, 50});
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityWidthAfterMovingOnDxAndDY)
{
  maschenko::Rectangle test_rectangle({10, 10}, 5, 8);
  const double width = test_rectangle.getFrameRect().width;
  test_rectangle.move(10, 10);
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityHeightAfterMovingCenter)
{
  maschenko::Rectangle test_rectangle({10, 10}, 5, 8);
  const double height = test_rectangle.getFrameRect().height;
  test_rectangle.move({50, 50});
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().height, height, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityHeightAfterMovingOnDxAndDy)
{
  maschenko::Rectangle test_rectangle({10, 10}, 5, 8);
  const double height = test_rectangle.getFrameRect().height;
  test_rectangle.move(10, 10);
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().height, height, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityAreaAfterMovingCenter)
{
  maschenko::Rectangle test_rectangle({10, 10}, 5, 8);
  const double area = test_rectangle.getArea();
  test_rectangle.move({50, 50});
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityAreaAfterMovingOnDxAndDy)
{
  maschenko::Rectangle test_rectangle({10, 10}, 5, 8);
  const double area = test_rectangle.getArea();
  test_rectangle.move(10, 10);
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(AreaScalingIncrease)
{
  maschenko::Rectangle test_rectangle {{10, 10}, 5, 8};
  const double area = test_rectangle.getArea();
  const double increase_number = 3;
  test_rectangle.scale(increase_number);
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), increase_number * increase_number * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(AreaScalingDecrease)
{
  maschenko::Rectangle test_rectangle {{10, 10}, 5, 8};
  const double area = test_rectangle.getArea();
  const double decrease_number = 0.25
  test_rectangle.scale(decrease_number);
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), area * decrease_number * decrease_number, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleTest)
{
  maschenko::Rectangle test_rectangle {{ 10, 10}, 5, 8};
  BOOST_CHECK_THROW(test_rectangle.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ThrowExceptionDueIncorrectWidth)
{
  BOOST_CHECK_THROW(maschenko::Rectangle test_rectangle ({10, 10}, -5, 8), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ThrowExceptionDueIncorrectHeight)
{
  BOOST_CHECK_THROW(maschenko::Rectangle test_rectangle ({10, 10}, 5, -8), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()
