#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"

#define INACCURACY 0.001

BOOST_AUTO_TEST_SUITE(TestForRectangle)

BOOST_AUTO_TEST_CASE(PermanenceOfWidthAfterMoving)
{
  moreva::Rectangle test_rectangle({10, 10}, 8, 8);
  const double width = test_rectangle.getFrameRect().width;
  test_rectangle.move({20, 20});
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().width, width, INACCURACY);

  test_rectangle.move(30, 30);
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(PermanenceOfHeightAfterMoving)
{
  moreva::Rectangle test_rectangle({10, 10}, 8, 8);
  const double height = test_rectangle.getFrameRect().height;
  test_rectangle.move({20, 20});
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().height, height, INACCURACY);

  test_rectangle.move(30, 30);
  BOOST_CHECK_CLOSE(test_rectangle.getFrameRect().height, height, INACCURACY);
}

BOOST_AUTO_TEST_CASE(PermanenceOfAreaAfterMoving)
{
  moreva::Rectangle test_rectangle({10, 10}, 8, 8);
  const double area = test_rectangle.getArea();
  test_rectangle.move({20, 20});
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), area, INACCURACY);

  test_rectangle.move(30, 30);
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingIncreaseOfArea)
{
  moreva::Rectangle test_rectangle ({10, 10}, 8, 8);
  const double area = test_rectangle.getArea();
  const double increase_value = 4;
  test_rectangle.scale(increase_value);
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), increase_value * increase_value * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingDecreaseOfArea)
{
  moreva::Rectangle test_rectangle ({10, 10}, 8, 8);
  const double area = test_rectangle.getArea();
  const double decrease_value = 0.5;
  test_rectangle.scale(decrease_value);
  BOOST_CHECK_CLOSE(test_rectangle.getArea(), area * decrease_value * decrease_value, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleTest)
{
  moreva::Rectangle test_rectangle ({ 10, 10}, 8, 8);
  BOOST_CHECK_THROW(test_rectangle.scale(-10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestOfIncorrectWidth)
{
  BOOST_CHECK_THROW(moreva::Rectangle test_rectangle ({10, 10}, -8, 8), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestOfIncorrectHeight)
{
  BOOST_CHECK_THROW(moreva::Rectangle test_rectangle ({10, 10}, 8, -8), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestForCircle)

BOOST_AUTO_TEST_CASE(permanenceOfRadiusAfterMovingCenter)
{
  moreva::Circle test_circle({8, 8}, 10);
  const double radius = test_circle.getRadius();
  test_circle.move({30, 30});
 BOOST_CHECK_CLOSE(test_circle.getRadius(), radius, INACCURACY);

  test_circle.move(20, 20);
  BOOST_CHECK_CLOSE(test_circle.getRadius(), radius, INACCURACY);
}

BOOST_AUTO_TEST_CASE(permanenceOfAreaAfterMovingCenter)
{
  moreva::Circle test_circle({8, 8}, 10);
  const double area = test_circle.getArea();
  test_circle.move({30, 30});
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);

  test_circle.move(20, 20);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingIncreaseOfArea)
{
  moreva::Circle test_circle ({8, 8}, 10);
  const double area = test_circle.getArea();
  const double increase_value = 4;
  test_circle.scale(increase_value);
  BOOST_CHECK_CLOSE(test_circle.getArea(), increase_value * increase_value * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalingDecreaseOfArea)
{
  moreva::Circle test_circle ({8, 8}, 10);
  const double area = test_circle.getArea();
  const double decrease_value = 0.5;
  test_circle.scale(decrease_value);
  BOOST_CHECK_CLOSE(test_circle.getArea(), area * decrease_value * decrease_value, INACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleTest)
{
  moreva::Circle test_circle ({8, 8}, 10);
  BOOST_CHECK_THROW(test_circle.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestOfIncorrectRadius)
{
  BOOST_CHECK_THROW(moreva::Circle test_circle({8, 8}, -10), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
