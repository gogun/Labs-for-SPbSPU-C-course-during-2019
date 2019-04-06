#define BOOST_TEST_MODULE test_A2
#include <cmath>
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testForRectangle)

BOOST_AUTO_TEST_CASE(scaleTest)
{
  for (int i = 1; i < 100; i++) {
    kotov::Rectangle rectangle({0.0, 0.0}, 10.0, 10.0);
    double areaRect = rectangle.getArea() * i * i / 625;
    rectangle.scale(((double) i) / 25);
    BOOST_CHECK_CLOSE(areaRect, rectangle.getArea(), 1000 * std::numeric_limits<double>::epsilon());
  }
}

BOOST_AUTO_TEST_CASE(displacementMovingTest) 
{
  for (int i = 0; i < 100; i++) {
    kotov::Rectangle rectangle({0.0, 0.0}, 10.0, 10.0);
    kotov::rectangle_t frameRect = rectangle.getFrameRect();
    rectangle.move(std::pow(-1, i) * i / 25, std::pow(-1, i + 1) * i / 25);
    BOOST_CHECK_CLOSE(frameRect.height, rectangle.getFrameRect().height, std::numeric_limits<double>::epsilon());
    BOOST_CHECK_CLOSE(frameRect.width, rectangle.getFrameRect().width, std::numeric_limits<double>::epsilon());
  }
}

BOOST_AUTO_TEST_CASE(movingInPositionTest)
{
  for (int i = 0; i < 100; i++) {
    kotov::Rectangle rectangle({0.0, 0.0}, 10.0, 10.0);
    kotov::rectangle_t frameRect = rectangle.getFrameRect();
    rectangle.move({std::pow(-1, i) * i / 2, std::pow(-1, i + 1) * i / 2});
    BOOST_CHECK_CLOSE(frameRect.height, rectangle.getFrameRect().height, std::numeric_limits<double>::epsilon());
    BOOST_CHECK_CLOSE(frameRect.width, rectangle.getFrameRect().width, std::numeric_limits<double>::epsilon());
  }
}

BOOST_AUTO_TEST_CASE(invalidArgumentsTest)
{
  for (int i = 0; i < 10; i++) {
    BOOST_CHECK_THROW(kotov::Rectangle({0, 0}, std::pow(-1, i) * i, std::pow(-1, i + 1) * i), std::invalid_argument);
  }
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testForCircle)

BOOST_AUTO_TEST_CASE(scaleTest)
{
  for (int i = 1; i < 100; i++) {
    kotov::Circle circle({0.0, 0.0}, 10.0);
    double areaCircle = circle.getArea() * i * i / 625;
    circle.scale(((double) i) / 25);
    BOOST_CHECK_CLOSE(areaCircle, circle.getArea(), 1000 * std::numeric_limits<double>::epsilon());
  }
}

BOOST_AUTO_TEST_CASE(displacementMovingTest)
{
  for (int i = 0; i < 100; i++) {
    kotov::Circle circle({0.0, 0.0}, 10.0);
    kotov::rectangle_t frameCircle = circle.getFrameRect();
    circle.move(std::pow(-1, i) * i / 25, std::pow(-1, i + 1) * i / 25);
    BOOST_CHECK_CLOSE(frameCircle.height, circle.getFrameRect().height, std::numeric_limits<double>::epsilon());
    BOOST_CHECK_CLOSE(frameCircle.width, circle.getFrameRect().width, std::numeric_limits<double>::epsilon());
  }
}

BOOST_AUTO_TEST_CASE(movingInPositionTest)
{
  for (int i = 0; i < 100; i++) {
    kotov::Circle circle({0.0, 0.0}, 10.0);
    kotov::rectangle_t frameCircle = circle.getFrameRect();
    circle.move({std::pow(-1, i) * i / 2, std::pow(-1, i + 1) * i / 2});
    BOOST_CHECK_CLOSE(frameCircle.height, circle.getFrameRect().height, std::numeric_limits<double>::epsilon());
    BOOST_CHECK_CLOSE(frameCircle.width, circle.getFrameRect().width, std::numeric_limits<double>::epsilon());
  }
}

BOOST_AUTO_TEST_CASE(invalidArgumentsTest)
{
  for (int i = 0; i < 5; i++) {
    BOOST_CHECK_THROW(kotov::Circle({0, 0}, -i / 2), std::invalid_argument);
  }
}

BOOST_AUTO_TEST_SUITE_END()
