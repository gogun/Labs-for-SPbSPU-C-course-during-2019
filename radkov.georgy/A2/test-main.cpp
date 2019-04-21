#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

using namespace radkov;
const double TOLERANCE = 0.0001;

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(move)
{
  Rectangle rectangle({0, 0}, 4, 8);
  rectangle.move({10, 20});

  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 10, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, 20, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 4, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 8, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getArea(), 32, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(scale)
{
  Rectangle rectangle({0, 0}, 2, 3);
  rectangle.scale(2);

  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 0, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, 0, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 4, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 6, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getArea(), 24, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(invalid_width)
{
  BOOST_CHECK_THROW(Rectangle rectangle({0, 0}, -10, 3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_height)
{
  BOOST_CHECK_THROW(Rectangle rectangle({0, 0}, 5, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_scale)
{
  Rectangle rectangle({0, 0}, 10, 10);
  BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(move)
{
  Circle circle({5, -1}, 3);
  circle.move(30, 10);

  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, 35, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, 9, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getRadius(), 3, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 9, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(scale)
{
  Circle circle({-10, 2}, 5);
  circle.scale(2);

  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, -10, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, 2, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getRadius(), 10, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 100, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(invalid_radius)
{
  BOOST_CHECK_THROW(Circle circle({0, 0}, -1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_scale)
{
  Circle circle({0, 0}, 1);
  BOOST_CHECK_THROW(circle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testTriangle)

BOOST_AUTO_TEST_CASE(move_center)
{
  Triangle triangle({-3, 0}, {0, 9}, {3, 0});
  triangle.move(5, 6);

  BOOST_CHECK_CLOSE(triangle.getCenter().x, 5, TOLERANCE);
  BOOST_CHECK_CLOSE(triangle.getCenter().y, 9, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(move_area)
{
  Triangle triangle({0, 0}, {0, 2}, {3, 0});
  triangle.move({7, 3});

  BOOST_CHECK_CLOSE(triangle.getArea(), 3, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(scale_center)
{
  Triangle triangle({1, 0}, {2, 3}, {3, 0});
  triangle.scale(3);

  BOOST_CHECK_CLOSE(triangle.getCenter().x, 2, TOLERANCE);
  BOOST_CHECK_CLOSE(triangle.getCenter().y, 1, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  Triangle triangle({1, -1}, {3, -1}, {1, -3});
  triangle.scale(2);

  BOOST_CHECK_CLOSE(triangle.getArea(), 8, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(invalid_constructor)
{ 
  BOOST_CHECK_THROW(Triangle triangle({1, 0}, {2, 0}, {3, 0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_scale)
{
  Triangle triangle({6, 2}, {0, 3}, {5, 2});
  BOOST_CHECK_THROW(triangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
