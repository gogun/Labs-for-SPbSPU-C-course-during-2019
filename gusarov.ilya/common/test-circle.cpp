#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(testsForCircle)

const double EPSILON = 0.1;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  gusarov::Circle testingCircle({2.0, 3.0}, 5.0);
  const double radius = testingCircle.getRadius();
  const double area = testingCircle.getArea();

  testingCircle.move(1.0, 2.0);
  BOOST_CHECK_CLOSE(testingCircle.getRadius(), radius, EPSILON);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), area, EPSILON);

  testingCircle.move({3.0, 5.0});
  BOOST_CHECK_CLOSE(testingCircle.getRadius(), radius, EPSILON);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), area, EPSILON);
}

BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  gusarov::Circle testingCircle({2.0, 3.0}, 5.0);

  const double area = testingCircle.getArea();
  const double scale = 3.0;

  testingCircle.scale(scale);
  BOOST_CHECK_CLOSE(testingCircle.getArea(), area * scale * scale, EPSILON);
}

BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(gusarov::Circle testingCircle({-1.0, -1.0}, -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleRotate)
{
  gusarov::Circle testCircle({0, 1}, 5);
  double areaBefore = testCircle.getArea();

  double angle = -50.0;
  BOOST_CHECK_NO_THROW(testCircle.rotate(angle));

  angle = 90.0;
  testCircle.rotate(angle);
  BOOST_CHECK_CLOSE(testCircle.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END();
