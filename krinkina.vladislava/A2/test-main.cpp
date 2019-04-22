#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"

#define INACCURACY 0.001

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(invarianceOfRadiusAfterMovingCenter)
{
  krinkina::Circle circle({4, 4}, 6);
  const double radius = circle.getRadius();
  circle.move({10, 10});
  BOOST_CHECK_CLOSE(circle.getRadius(), radius, INACCURACY);

  circle.move(25, 25);
  BOOST_CHECK_CLOSE(circle.getRadius(), radius, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invarianceOfAreaAfterMovingCenter)
{
  krinkina::Circle circle({4, 4}, 6);
  const double area = circle.getArea();
  circle.move({10, 10});
  BOOST_CHECK_CLOSE(circle.getArea(), area, INACCURACY);

  circle.move(25, 25);
  BOOST_CHECK_CLOSE(circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingIncreaseOfArea)
{
  krinkina::Circle circle({4, 4}, 6);
  const double area = circle.getArea();
  const double increase_value = 2;
  circle.scale(increase_value);
  BOOST_CHECK_CLOSE(circle.getArea(), increase_value * increase_value * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingDecreaseOfArea)
{
  krinkina::Circle circle({4, 4}, 6);
  const double area = circle.getArea();
  const double decrease_value = 0.5;
  circle.scale(decrease_value);
  BOOST_CHECK_CLOSE(circle.getArea(), area * decrease_value * decrease_value, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleTest)
{
  krinkina::Circle circle({4, 4}, 6);
  BOOST_CHECK_THROW(circle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestOfIncorrectRadius)
{
  BOOST_CHECK_THROW(krinkina::Circle circle({4, 4}, -6), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(invarianceOfWidthAfterMovingCenter)
{
  krinkina::Rectangle rectangle({8, 8}, 6, 6);
  const double width = rectangle.getFrameRect().width;
  rectangle.move({10, 10});
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, width, INACCURACY);

  rectangle.move(20, 20);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invarianceOfHeightAfterMovingCenter)
{
  krinkina::Rectangle rectangle({8, 8}, 6, 6);
  const double height = rectangle.getFrameRect().height;
  rectangle.move({10, 10});
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, height, INACCURACY);

  rectangle.move(20, 20);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, height, INACCURACY);
}

BOOST_AUTO_TEST_CASE(invarianceOfAreaAfterMovingCenter)
{
  krinkina::Rectangle rectangle({8, 8}, 6, 6);
  const double area = rectangle.getArea();
  rectangle.move({10, 10});
  BOOST_CHECK_CLOSE(rectangle.getArea(), area, INACCURACY);

  rectangle.move(20, 20);
  BOOST_CHECK_CLOSE(rectangle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingIncreaseOfArea)
{
  krinkina::Rectangle rectangle({8, 8}, 6, 6);
  const double area = rectangle.getArea();
  const double increase_value = 4;
  rectangle.scale(increase_value);
  BOOST_CHECK_CLOSE(rectangle.getArea(), increase_value * increase_value * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingDecreaseOfArea)
{
  krinkina::Rectangle rectangle({8, 8}, 6, 6);
  const double area = rectangle.getArea();
  const double decrease_value = 0.5;
  rectangle.scale(decrease_value);
  BOOST_CHECK_CLOSE(rectangle.getArea(), area * decrease_value * decrease_value, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleTest)
{
  krinkina::Rectangle rectangle({8, 8}, 6, 6);
  BOOST_CHECK_THROW(rectangle.scale(-10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestOfIncorrectWidth)
{
  BOOST_CHECK_THROW(krinkina::Rectangle rectangle({8, 8}, -6, 6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestOfIncorrectHeight)
{
  BOOST_CHECK_THROW(krinkina::Rectangle rectangle({8, 8}, 6, -6), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
