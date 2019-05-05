#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

const double ACCURACY = 0.01;

//Тест на неизменность после перемещения круга
BOOST_AUTO_TEST_CASE(invariabilityAfterMovingCircle)
{
  shahbazly::Circle testCircle(2.5, {0, 0});
  const shahbazly::rectangle_t rectangleFrameBeforeMoving  = testCircle.getFrameRect();
  const double areaBeforeMoving = testCircle.getArea();

  testCircle.move({2.3, 8.6});
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.width, testCircle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.height, testCircle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(areaBeforeMoving, testCircle.getArea(), ACCURACY);
}

//Тест на неизменность после перемещения прямоугольника
BOOST_AUTO_TEST_CASE(invariabilityAfterMovingRectangle)
{
  shahbazly::Rectangle testRectangle({0, 0}, 7.2, 6.4);
  const shahbazly::rectangle_t rectangleFrameBeforeMoving = testRectangle.getFrameRect();
  const double areaBeforeMoving = testRectangle.getArea();

  testRectangle.move({6.9, 9.6});
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.width, testRectangle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(rectangleFrameBeforeMoving.height, testRectangle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(areaBeforeMoving, testRectangle.getArea(), ACCURACY);
}

//Тест на неизменность площади кргуа после его масштабирования
BOOST_AUTO_TEST_CASE(areaAfterScalingCircle)
{
  shahbazly::Circle testCircle(4, {0, 0});
  const double areaBeforeMoving = testCircle.getArea();
  const double scaleFactor = 6.8;
  testCircle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testCircle.getArea(), scaleFactor * scaleFactor * areaBeforeMoving, ACCURACY);
}

//Тест на неизменность площади прямоугольника после его масштабирования
BOOST_AUTO_TEST_CASE(areaAfterScalingRectangle)
{
  shahbazly::Rectangle testRectangle({0, 0}, 2, 8);
  const double areaBeforeMoving = testRectangle.getArea();
  const double scaleFactor = 6.8;
  testRectangle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), scaleFactor * scaleFactor * areaBeforeMoving, ACCURACY);
}

//Тест на неправильные аргументы круга
BOOST_AUTO_TEST_CASE(invalidArgumentsCircle)
{
  BOOST_CHECK_THROW(shahbazly::Circle(-6, {3, 5}), std::invalid_argument);

  shahbazly::Circle testCircle(2, {5, 3});
  BOOST_CHECK_THROW(testCircle.scale(-9), std::invalid_argument);
}

//Тест на неправильные аргументы прямоугольника
BOOST_AUTO_TEST_CASE(invalidArgumentsRectangle)
{
  BOOST_CHECK_THROW(shahbazly::Rectangle({1, 2}, -3, -3), std::invalid_argument);
  BOOST_CHECK_THROW(shahbazly::Rectangle({1, 2}, -1, 2), std::invalid_argument);
  BOOST_CHECK_THROW(shahbazly::Rectangle({1, 2}, 1, -2), std::invalid_argument);

  shahbazly::Rectangle testRectangle({1, 2}, 3, 4);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
