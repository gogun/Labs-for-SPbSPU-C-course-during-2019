#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(A2Test)

const double PRECISION = 0.001;

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingCircleByIncrement)
{
  firsov::Circle testCircle(3, { 9, -4 });
  const firsov::rectangle_t frameBefore = testCircle.getFrameRect();
  const double initialArea = testCircle.getArea();

  testCircle.move(4, 4);
  BOOST_CHECK_CLOSE(frameBefore.width, testCircle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(frameBefore.height, testCircle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingCircleToPoint)
{
  firsov::Circle testCircle(3, { 9, -4 });
  const firsov::rectangle_t frameBefore = testCircle.getFrameRect();
  const double initialArea = testCircle.getArea();

  testCircle.move(-14, -7);
  BOOST_CHECK_CLOSE(frameBefore.width, testCircle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(frameBefore.height, testCircle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(quadraticCircleScaleChange)
{
  firsov::Circle testCircle(6, { 13.3, 7 });
  const double initialArea = testCircle.getArea();
  const double multiplier = 2.0;

  testCircle.scale(multiplier);
  BOOST_CHECK_CLOSE(initialArea * multiplier * multiplier, testCircle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(invalidCircleParametersAndScaling)
{
  BOOST_CHECK_THROW(firsov::Circle testCircle(-5.7, { 30, 6 }), std::invalid_argument);

  firsov::Circle testCircle(5.7, { 30, 6 } );
  BOOST_CHECK_THROW(testCircle.scale(-3.4), std::invalid_argument);
}


BOOST_AUTO_TEST_CASE(invariabilityAfterMovingRectangleByIncrements)
{
  firsov::Rectangle testRectangle(7, 6, { 3, 4 });
  const firsov::rectangle_t initialBefore = testRectangle.getFrameRect();
  const double initialArea = testRectangle.getArea();

  testRectangle.move(-4.5, 5.2);
  BOOST_CHECK_CLOSE(initialBefore.width, testRectangle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(initialBefore.height, testRectangle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingRectangleToPoint)
{
  firsov::Rectangle testRectangle(7, 6, { 3, 4 });
  const firsov::rectangle_t initialBefore = testRectangle.getFrameRect();
  const double initialArea = testRectangle.getArea();

  testRectangle.move(-4.5, 5.2);
  BOOST_CHECK_CLOSE(initialBefore.width, testRectangle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(initialBefore.height, testRectangle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(quadraticRectangleScaleChange)
{
  firsov::Rectangle testRectangle(3, 7, { 4, 5 });
  const double initialArea = testRectangle.getArea();
  const double multiplier = 0.5;

  testRectangle.scale(multiplier);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), initialArea * multiplier * multiplier, PRECISION);
}

BOOST_AUTO_TEST_CASE(invalidRectangleParametersAndScaling)
{
  BOOST_CHECK_THROW(firsov::Rectangle(-4, 5, { 6, 7 }), std::invalid_argument);

  firsov::Rectangle testRectangle(4, 5, { 6, 7 });
  BOOST_CHECK_THROW(testRectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
