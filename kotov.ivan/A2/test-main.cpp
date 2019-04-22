#define BOOST_TEST_MODULE test_A2
#include <cmath>
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(TestForRectangle)

BOOST_AUTO_TEST_CASE(scaleTest)
{
  kotov::Rectangle rectangle({0.0, 0.0}, 10.0, 5.0);
  const double scale = 6.7;
  const double areaRect = rectangle.getArea() * scale * scale;
  rectangle.scale(scale);
  BOOST_CHECK_CLOSE(areaRect, rectangle.getArea(), std::numeric_limits<double>::epsilon());
}

BOOST_AUTO_TEST_CASE(displacementMovingTest)
{
  kotov::Rectangle rectangle({0.0, 0.0}, 10.0, 9.0);
  const kotov::rectangle_t frameRect = rectangle.getFrameRect();
  rectangle.move(25, -12);
  BOOST_CHECK_CLOSE(frameRect.height, rectangle.getFrameRect().height, std::numeric_limits<double>::epsilon());
  BOOST_CHECK_CLOSE(frameRect.width, rectangle.getFrameRect().width, std::numeric_limits<double>::epsilon());
}

BOOST_AUTO_TEST_CASE(movingInPositionTest)
{
  kotov::Rectangle rectangle({0.0, 0.0}, 10.0, 9.0);
  const kotov::rectangle_t frameRect = rectangle.getFrameRect();
  rectangle.move({65, -7});
  BOOST_CHECK_CLOSE(frameRect.height, rectangle.getFrameRect().height, std::numeric_limits<double>::epsilon());
  BOOST_CHECK_CLOSE(frameRect.width, rectangle.getFrameRect().width, std::numeric_limits<double>::epsilon());
}

BOOST_AUTO_TEST_CASE(invalidArgumentsTest)
{
  BOOST_CHECK_THROW(kotov::Rectangle({0, 0}, 0, 2), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Rectangle({0, 0}, 1, 0), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Rectangle({0, 0}, 3, -4), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Rectangle({0, 0}, -5, 6), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Rectangle({0, 0}, 7, 8).scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Rectangle({0, 0}, 9, 10).scale(-11), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestForCircle)

BOOST_AUTO_TEST_CASE(scaleTest)
{
  kotov::Circle circle({0.0, 0.0}, 10.0);
  const double scale = 8.9;
  const double areaCircle = circle.getArea() * scale * scale;
  circle.scale(scale);
  BOOST_CHECK_CLOSE(areaCircle, circle.getArea(), std::numeric_limits<double>::epsilon());
}

BOOST_AUTO_TEST_CASE(displacementMovingTest)
{
  kotov::Circle circle({0.0, 0.0}, 10.0);
  const kotov::rectangle_t frameCircle = circle.getFrameRect();
  circle.move(63, -89);
  BOOST_CHECK_CLOSE(frameCircle.height, circle.getFrameRect().height, std::numeric_limits<double>::epsilon());
  BOOST_CHECK_CLOSE(frameCircle.width, circle.getFrameRect().width, std::numeric_limits<double>::epsilon());
}

BOOST_AUTO_TEST_CASE(movingInPositionTest)
{
  kotov::Circle circle({0.0, 0.0}, 10.0);
  const kotov::rectangle_t frameCircle = circle.getFrameRect();
  circle.move({-45, 45});
  BOOST_CHECK_CLOSE(frameCircle.height, circle.getFrameRect().height, std::numeric_limits<double>::epsilon());
  BOOST_CHECK_CLOSE(frameCircle.width, circle.getFrameRect().width, std::numeric_limits<double>::epsilon());
}

BOOST_AUTO_TEST_CASE(invalidArgumentsTest)
{
  BOOST_CHECK_THROW(kotov::Circle({0, 0}, 0), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Circle({0, 0}, -0.5), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Circle({0, 0}, 1).scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(kotov::Circle({0, 0}, 2).scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
