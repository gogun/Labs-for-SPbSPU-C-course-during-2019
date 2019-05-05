#include <stdexcept>
#include <iostream>
#include <cmath>
#include <boost/test/auto_unit_test.hpp>
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(TestForCircle)

const double INACCURACY = 0.001;

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
  const double decrease_number = 0.25;
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
