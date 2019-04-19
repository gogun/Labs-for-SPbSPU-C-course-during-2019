#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

#define TOLERANCE 0.0001

BOOST_AUTO_TEST_SUITE(circleTest)

// проверка перемещения круга
BOOST_AUTO_TEST_CASE(paramsConstancyAfterMoving)
{
  const double radius = 10;
  const marashov::point_t circleCenter = { 0, 0 };
  marashov::Circle circle(circleCenter, radius);

  const double circleArea = circle.getArea();

  // перемещение центра круга в другую точку
  const marashov::point_t newCircleCenter = { 100, 100 };
  circle.move(newCircleCenter);

  // проверка неизменности радиуса и площади круга
  // (допускается погрешность TOLERANCE)
  BOOST_CHECK_CLOSE(circle.getRadius(), radius, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getArea(), circleArea, TOLERANCE);
}

// проверка масштабирования круга
BOOST_AUTO_TEST_CASE(quadraticSquareIncreaseAfterScaling)
{
  const double radius = 5;
  const marashov::point_t circleCenter = { 0, 0 };
  marashov::Circle circle(circleCenter, radius);

  const double circleArea = circle.getArea();

  // масштабирование круга
  const double amount = 2;
  circle.scale(amount);

  // проверка квадратичного изменения площади
  // (допускается погрешность TOLERANCE)
  BOOST_CHECK_CLOSE(circle.getArea(), circleArea * amount * amount, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(constructorExceptions)
{
  // проверка на наличие исключения "некорректный аргумент" при попытке задать
  // отрицательный или нулевой радиус круга
  const double incorrectArg1 = -2;
  const double incorrectArg2 = 0;
  BOOST_CHECK_THROW(marashov::Circle({ 0, 0 }, incorrectArg1), std::invalid_argument);
  BOOST_CHECK_THROW(marashov::Circle({ 0, 0 }, incorrectArg2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(scaleExceptions)
{
  const marashov::point_t circleCenter = { 0, 0 };
  marashov::Circle circle = marashov::Circle(circleCenter, 10);
  // проверка на наличие исключения "некорректный аргумент" при попытке задать
  // отрицательное или нулевое значение масштабирования
  const double incorrectArg1 = -2;
  const double incorrectArg2 = 0;
  BOOST_CHECK_THROW(circle.scale(incorrectArg1), std::invalid_argument);
  BOOST_CHECK_THROW(circle.scale(incorrectArg2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangleTest)

// проверка перемещения прямоугольника
BOOST_AUTO_TEST_CASE(paramsConstancyAfterMoving)
{
  const double width = 100;
  const double height = 50;
  const marashov::point_t rectangleCenter = { 0, 0 };
  marashov::Rectangle rectangle(rectangleCenter, width, height);
  const double rectArea = rectangle.getArea();

  // перемещение центра прямоугольника в другую точку
  const marashov::point_t newRectCenter = { 10, 10 };
  rectangle.move(newRectCenter);

  // проверка неизменности высоты, ширины и площади прямоугольника
  // (допускается погрешность TOLERANCE)
  BOOST_CHECK_CLOSE(rectangle.getWidth(), width, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), height, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getArea(), rectArea, TOLERANCE);
}

// проверка масштабирования прямоугольника
BOOST_AUTO_TEST_CASE(quadraticSquareIncreaseAfterScaling)
{
  const double width = 100;
  const double height = 50;
  const marashov::point_t rectangleCenter = { 0, 0 };
  marashov::Rectangle rectangle(rectangleCenter, width, height);
  const double rectArea = rectangle.getArea();

  // масштабирование прямоугольника
  const double amount = 2;
  rectangle.scale(amount);

  // проверка квадратичного изменения площади
  // (допускается погрешность TOLERANCE)
  BOOST_CHECK_CLOSE(rectangle.getArea(), rectArea * amount * amount, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(constructorExceptions)
{
  // проверка на наличие исключения "некорректный аргумент" при попытке задать
  // отрицательную или нулевую высоту или ширину прямоугольника
  const double incorrectArg1 = -2;
  const double incorrectArg2 = 0;
  const double correctArg = 10;
  BOOST_CHECK_THROW(marashov::Rectangle({ 0, 0 }, incorrectArg1, correctArg), std::invalid_argument);
  BOOST_CHECK_THROW(marashov::Rectangle({ 0, 0 }, incorrectArg2, correctArg), std::invalid_argument);
  BOOST_CHECK_THROW(marashov::Rectangle({ 0, 0 }, correctArg, incorrectArg1), std::invalid_argument);
  BOOST_CHECK_THROW(marashov::Rectangle({ 0, 0 }, correctArg, incorrectArg2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(scaleExceptions)
{
  marashov::Rectangle rectangle = marashov::Rectangle({ 0, 0 }, 10, 5);
  // проверка на наличие исключения "некорректный аргумент" при попытке задать
  // отрицательное или нулевое значение масштабирования
  const double incorrectArg1 = -2;
  const double incorrectArg2 = 0;
  BOOST_CHECK_THROW(rectangle.scale(incorrectArg1), std::invalid_argument);
  BOOST_CHECK_THROW(rectangle.scale(incorrectArg2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
