#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

#define TOLERANCE 0.0001

// тестирование разбито на группы:
// 1) moveTest - проверка корректности перемещения фигур
// 2) scaleTest - проверка корректности масштабирования фигур
// 3) incorrectParamsTest - проверка правильности обработки
// некорректных входных параметров при создании фигур

BOOST_AUTO_TEST_SUITE(moveTest)

  // проверка перемещения прямоугольника
  BOOST_AUTO_TEST_CASE(rectangleWidthHeightAreaConstancy) {
    const double width = 100;
    const double height = 50;
    marashov::Rectangle rectangle({0, 0}, width, height);
    const double rectArea = rectangle.getArea();

    // перемещение центра прямоугольника в другую точку
    const marashov::point_t newRectPoint = {10, 10};
    rectangle.move(newRectPoint);

    // проверка неизменности высоты, ширины и площади прямоугольника
    // (погрешность не допускается, параметры должны быть неизменны)
    BOOST_CHECK_EQUAL(rectangle.getWidth(), width);
    BOOST_CHECK_EQUAL(rectangle.getHeight(), height);
    BOOST_CHECK_EQUAL(rectangle.getArea(), rectArea);
  }

  // проверка перемещения круга
  BOOST_AUTO_TEST_CASE(circleRadiusAreaConstancy) {
    const double radius = 10;
    marashov::Circle circle({0, 0}, radius);
    const double circleArea = circle.getArea();

    // перемещение центра круга в другую точку
    const marashov::point_t newCirclePoint = {100, 100};
    circle.move(newCirclePoint);

    // проверка неизменности радиуса и площади круга
    // (погрешность не допускается, параметры должны быть неизменны)
    BOOST_CHECK_EQUAL(circle.getRadius(), radius);
    BOOST_CHECK_EQUAL(circle.getArea(), circleArea);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(scaleTest)

  // проверка масштабирования прямоугольника
  BOOST_AUTO_TEST_CASE(rectangleQuadraticSquareIncrease) {
    const double width = 100;
    const double height = 50;
    marashov::Rectangle rectangle({0, 0}, width, height);
    const double rectArea = rectangle.getArea();

    // масштабирование прямоугольника
    const double amount = 2;
    rectangle.scale(amount);

    // проверка квадратичного изменения площади
    // (допускается погрешность TOLERANCE)
    BOOST_CHECK_CLOSE(rectangle.getArea(), rectArea * amount * amount, TOLERANCE);
  }

  // проверка масштабирования круга
  BOOST_AUTO_TEST_CASE(circleQuadraticSquareIncrease) {
    const double radius = 5;
    marashov::Circle circle({0, 0}, radius);
    const double circleArea = circle.getArea();

    // масштабирование круга
    const double amount = 2;
    circle.scale(amount);

    // проверка квадратичного изменения площади
    // (допускается погрешность TOLERANCE)
    BOOST_CHECK_CLOSE(circle.getArea(), circleArea * amount * amount, TOLERANCE);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(incorrectParamsTest)

  BOOST_AUTO_TEST_CASE(rectangleConstructor) {
    // проверка на наличие исключения "некорректный аргумент" при попытке задать
    // отрицательную высоту или ширину прямоугольника
    BOOST_CHECK_THROW(marashov::Rectangle({0, 0}, -10, 10), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(circleConstructor) {
    // проверка на наличие исключения "некорректный аргумент" при попытке задать
    // отрицательный радиус круга
    BOOST_CHECK_THROW(marashov::Circle({0, 0}, -10), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(rectangleScale) {
    marashov::Rectangle rectangle = marashov::Rectangle({0, 0}, 10, 5);
    // проверка на наличие исключения "некорректный аргумент" при попытке задать
    // отрицательное или нулевое значение масштабирования
    const double incorrectArg = 0;
    BOOST_CHECK_THROW(rectangle.scale(incorrectArg), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(circleScale) {
    marashov::Circle circle = marashov::Circle({0, 0}, 10);
    // проверка на наличие исключения "некорректный аргумент" при попытке задать
    // отрицательное или нулевое значение масштабирования
    const double incorrectArg = -2;
    BOOST_CHECK_THROW(circle.scale(incorrectArg), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
