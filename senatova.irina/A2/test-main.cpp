#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(A2Test)

const double PRECISION = 0.001;

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingCircleByIncrement)
{
  senatova::Circle testCircle({9, -5}, 3);
  const senatova::rectangle_t frameBefore = testCircle.getFrameRect();
  const double initialArea = testCircle.getArea();

  testCircle.move(7, 7);
  BOOST_CHECK_CLOSE(frameBefore.width, testCircle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(frameBefore.height, testCircle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingCircleToPoint)
{
  senatova::Circle testCircle({9, -5}, 3);
  const senatova::rectangle_t frameBefore = testCircle.getFrameRect();
  const double initialArea = testCircle.getArea();

  testCircle.move(-5, -9);
  BOOST_CHECK_CLOSE(frameBefore.width, testCircle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(frameBefore.height, testCircle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(quadraticCircleScaleChange)
{
  senatova::Circle testCircle({13.2, 4}, 7);
  const double initialArea = testCircle.getArea();
  const double multiplier = 2.0;

  testCircle.scale(multiplier);
  BOOST_CHECK_CLOSE(initialArea * multiplier * multiplier, testCircle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(invalidCircleParametersAndScaling)
{
  BOOST_CHECK_THROW(senatova::Circle testCircle({20, 11}, -4.2), std::invalid_argument);

  senatova::Circle testCircle({20, 11}, 4.2);
  BOOST_CHECK_THROW(testCircle.scale(-3.6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingRectangleByIncrements)
{
  senatova::Rectangle testRectangle({3, 6}, 2, 4);
  const senatova::rectangle_t initialBefore = testRectangle.getFrameRect();
  const double initialArea = testRectangle.getArea();

  testRectangle.move(5.8, -4);
  BOOST_CHECK_CLOSE(initialBefore.width, testRectangle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(initialBefore.height, testRectangle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingRectangleToPoint)
{
  senatova::Rectangle testRectangle({3, 6}, 2, 4);
  const senatova::rectangle_t initialBefore = testRectangle.getFrameRect();
  const double initialArea = testRectangle.getArea();

  testRectangle.move(5.8, -4);
  BOOST_CHECK_CLOSE(initialBefore.width, testRectangle.getFrameRect().width, PRECISION);
  BOOST_CHECK_CLOSE(initialBefore.height, testRectangle.getFrameRect().height, PRECISION);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), PRECISION);
}

BOOST_AUTO_TEST_CASE(quadraticRectangleScaleChange)
{
  senatova::Rectangle testRectangle({4, 5}, 7, 2);
  const double initialArea = testRectangle.getArea();
  const double multiplier = 0.5;

  testRectangle.scale(multiplier);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), initialArea * multiplier * multiplier, PRECISION);
}

BOOST_AUTO_TEST_CASE(invalidRectangleParametersAndScaling)
{
  BOOST_CHECK_THROW(senatova::Rectangle({6, 7}, -3, 2), std::invalid_argument);

  senatova::Rectangle testRectangle({6, 7}, 3, 2);
  BOOST_CHECK_THROW(testRectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
