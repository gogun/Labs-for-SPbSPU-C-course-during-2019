#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

const double accuracy = 0.001;

BOOST_AUTO_TEST_SUITE(testRectangle)

  BOOST_AUTO_TEST_CASE(testRectangleMove1)
  {
    alexandrov::Rectangle rectangle1({{0.0, 0.0}, 2.0, 2.0});
    rectangle1.move({1.1, 2.2});
    BOOST_CHECK_EQUAL(rectangle1.getFrameRect().pos.x, 1.1);
    BOOST_CHECK_EQUAL(rectangle1.getFrameRect().pos.y, 2.2);
  }

  BOOST_AUTO_TEST_CASE(testRectangleMove2)
  {
    alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, 2.0});
    rectangle1.move(1.1, 2.2);
    BOOST_CHECK_CLOSE_FRACTION(rectangle1.getFrameRect().pos.x, 2.2, accuracy);
    BOOST_CHECK_CLOSE_FRACTION(rectangle1.getFrameRect().pos.y, 4.4, accuracy);
  }

  BOOST_AUTO_TEST_CASE(testRectangleMoveWidth)
  {
    alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, 2.0});
    rectangle1.move(1.1, 2.2);
    BOOST_CHECK_CLOSE_FRACTION(rectangle1.getFrameRect().width, 2.0, accuracy);
  }

  BOOST_AUTO_TEST_CASE(testRectangleMoveHeight)
  {
    alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, 2.0});
    rectangle1.move(1.1, 2.2);
    BOOST_CHECK_CLOSE_FRACTION(rectangle1.getFrameRect().height, 2.0, accuracy);
  }

  BOOST_AUTO_TEST_CASE(testRectangleMoveArea)
  {
    alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, 2.0});
    double areaRect = rectangle1.getArea();
    rectangle1.move(1.1, 2.2);
    BOOST_CHECK_CLOSE_FRACTION(areaRect, rectangle1.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(testRectangleScale)
  {
    alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, 2.0});
    double areaRect = rectangle1.getArea();
    rectangle1.scale(0.5);
    BOOST_CHECK_CLOSE_FRACTION(rectangle1.getArea(), areaRect * 0.5 * 0.5, accuracy);
  }

  BOOST_AUTO_TEST_CASE(testRectangleInit)
  {
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{1.1, 2.2}, -2.0, 2.0}), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, -2.0}), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{1.1, 2.2}, 0.0, 2.0}), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, 0.0}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testRectangleScale)
  {
    alexandrov::Rectangle rectangle1({{1.1, 2.2}, 2.0, 2.0});
    BOOST_CHECK_THROW(rectangle1.scale(-1.0), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(testCircle)

  BOOST_AUTO_TEST_CASE(testCircleMove1)
  {
    alexandrov::Circle circle1({0.0, 0.0}, 3.0);
    circle1.move({1.1, 2.2});
    BOOST_CHECK_EQUAL(circle1.getFrameRect().pos.x, 1.1);
    BOOST_CHECK_EQUAL(circle1.getFrameRect().pos.y, 2.2);
  }

  BOOST_AUTO_TEST_CASE(testCircleMove2)
  {
    alexandrov::Circle circle1({1.11, 2.21}, 3.0);
    circle1.move(1.11, 2.22);
    BOOST_CHECK_CLOSE_FRACTION(circle1.getFrameRect().pos.x, 2.22, accuracy);
    BOOST_CHECK_CLOSE_FRACTION(circle1.getFrameRect().pos.y, 4.43, accuracy);
  }

  BOOST_AUTO_TEST_CASE(testCircleMoveRadius)
  {
    alexandrov::Circle circle1({1.1, 2.2}, 3.0);
    circle1.move(1.11, 2.22);
    BOOST_CHECK_CLOSE_FRACTION(circle1.getFrameRect().width/2.0, 3.0, accuracy);
  }

  BOOST_AUTO_TEST_CASE(testCircleMoveArea)
  {
    alexandrov::Circle circle1({1.1, 2.2}, 3.0);
    double areaCircle = circle1.getArea();
    circle1.move(1.11, 2.22);
    BOOST_CHECK_CLOSE_FRACTION(areaCircle, circle1.getArea(), accuracy);
  }

 BOOST_AUTO_TEST_CASE(testCircleScaleArea)
  {
    alexandrov::Circle circle1({1.1, 2.2}, 3.0);
    double areaCircle = circle1.getArea();
    circle1.scale(2.5);
    BOOST_CHECK_CLOSE_FRACTION(circle1.getArea(), areaCircle * 2.5 * 2.5, accuracy);
  }

  BOOST_AUTO_TEST_CASE(testCircleInit)
  {
    BOOST_CHECK_THROW(alexandrov::Circle circle1({1.1, 2.2}, -1.0), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Circle circle1({1.1, 2.2}, 0.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testCircleScale)
  {
    alexandrov::Circle circle1({1.1, 2.2}, 3.0);
    BOOST_CHECK_THROW(circle1.scale(-1.0), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();
