#define BOOST_TEST_MODULE A2
#include "rectangle.hpp"
#include "circle.hpp"
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

const double ACCURACY = 0.001;

BOOST_AUTO_TEST_SUITE(TestA2)

BOOST_AUTO_TEST_CASE(constRectangleAfterMovingByIncrements)
{
  afanasiev::Rectangle testRectangle({1, 1}, 1, 1);
  const afanasiev::rectangle_t initialRect = testRectangle.getFrameRect();
  const double initialArea = testRectangle.getArea();

  testRectangle.move(5, 5);

  BOOST_CHECK_CLOSE(initialRect.width, testRectangle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(initialRect.height, testRectangle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(constCircleAfterMovingByIncrements)
{
  afanasiev::Circle testCircle({1, 1}, 1);
  const afanasiev::rectangle_t initialCircle = testCircle.getFrameRect();
  const double initialArea = testCircle.getArea();

  testCircle.move(5, 5);

  BOOST_CHECK_CLOSE(initialCircle.width, testCircle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(initialCircle.height, testCircle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(constRectangleAfterMovingToPoint)
{
  afanasiev::Rectangle testRectangle({1, 1}, 1, 1);
  const afanasiev::rectangle_t initialRect = testRectangle.getFrameRect();
  const double initialArea = testRectangle.getArea();

  testRectangle.move({5, 5});

  BOOST_CHECK_CLOSE(initialRect.width, testRectangle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(initialRect.height, testRectangle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(constCircleAfterMovingToPoint)
{
  afanasiev::Circle testCircle({1, 1}, 1);
  const afanasiev::rectangle_t initialCircle = testCircle.getFrameRect();
  const double initialArea = testCircle.getArea();

  testCircle.move({5, 5});

  BOOST_CHECK_CLOSE(initialCircle.width, testCircle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(initialCircle.height, testCircle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(quadraticChangeRectangleAreaAfterScaling)
{
  afanasiev::Rectangle testRectangle({1, 1}, 1, 1);
  const double initialArea = testRectangle.getArea();
  const double zoomFactor = 0.5;

  testRectangle.scale(zoomFactor);

  BOOST_CHECK_CLOSE(testRectangle.getArea(), initialArea * zoomFactor * zoomFactor, ACCURACY);
}

BOOST_AUTO_TEST_CASE(quadraticChangeCircleAreaAfterScaling)
{
  afanasiev::Rectangle testCircle({1, 1}, 1, 1);
  const double initialArea = testCircle.getArea();
  const double zoomFactor = 2;

  testCircle.scale(zoomFactor);

  BOOST_CHECK_CLOSE(testCircle.getArea(), initialArea * zoomFactor * zoomFactor, ACCURACY);
}

BOOST_AUTO_TEST_CASE(invalidRectangleParameteres)
{
  BOOST_CHECK_THROW(afanasiev::Rectangle({1, 1}, -1, 1), std::invalid_argument);
  BOOST_CHECK_THROW(afanasiev::Rectangle({1, 1}, 1, -1), std::invalid_argument);

  afanasiev::Rectangle testRectangle({1, 1}, 1, 1);
  BOOST_CHECK_THROW(testRectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidCircleParameteres)
{
  BOOST_CHECK_THROW(afanasiev::Circle({1, 1}, -1), std::invalid_argument);

  afanasiev::Circle testCircle({1, 1}, 1);
  BOOST_CHECK_THROW(testCircle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
