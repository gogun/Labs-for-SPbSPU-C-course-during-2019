#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testsForRectangle)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  gusarov::Rectangle testingRect({1.0, 2.0}, 3.0, 4.0, 0.0);

  const double width = testingRect.getWidth();
  const double height = testingRect.getHeight();
  const double area = testingRect.getArea();

  testingRect.move(5.0, 5.5);
  BOOST_CHECK_CLOSE(testingRect.getWidth(), width, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getHeight(), height, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getArea(), area, EPSILON);

  testingRect.move({10.0, 12.0});
  BOOST_CHECK_CLOSE(testingRect.getWidth(), width, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getHeight(), height, EPSILON);
  BOOST_CHECK_CLOSE(testingRect.getArea(), area, EPSILON);
}

BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  gusarov::Rectangle testingRect({1.0, 2.0}, 3.0, 4.0, 0.0);

  const double area = testingRect.getArea();
  const double scale = 3.0;
  testingRect.scale(scale);
  BOOST_CHECK_CLOSE(testingRect.getArea(), area * scale * scale, EPSILON);
}

BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(gusarov::Rectangle testingRect({0.0, -1.0}, -1.0, 0.0, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleRotate)
{
  gusarov::Rectangle testRec({0, 1}, 5, 6, 0);
  double areaBefore = testRec.getArea();

  double angle = -50.0;
  BOOST_CHECK_NO_THROW(testRec.rotate(angle));

  angle = 90.0;
  testRec.rotate(angle);
  BOOST_CHECK_CLOSE(testRec.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END();
