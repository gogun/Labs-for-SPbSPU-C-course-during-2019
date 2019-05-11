#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "triangle.hpp"

BOOST_AUTO_TEST_SUITE(testsForTriangle)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  gusarov::Triangle testTriangle({0.0, 0.0}, {0.0, 4.0}, {3.0, 4.0});

  const double width = testTriangle.getFrameRect().width;
  const double height = testTriangle.getFrameRect().height;
  const double area = testTriangle.getArea();

  testTriangle.move(5.0, 5.5);
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().width, width, EPSILON);
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().height, height, EPSILON);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area, EPSILON);

  testTriangle.move({7.0, 8.0});
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().width, width, EPSILON);
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().height, height, EPSILON);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area, EPSILON);
}

BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  gusarov::Triangle testTriangle({0.0, 0.0}, {8.0, 4.0}, {2.0, 6.0});

  const double area = testTriangle.getArea();
  const double scale = 5.0;

  testTriangle.scale(scale);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area * scale * scale, EPSILON);
}

BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(gusarov::Triangle testTriangle({0.0, 0.0}, {0.0, 0.0}, {3.0, 4.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
