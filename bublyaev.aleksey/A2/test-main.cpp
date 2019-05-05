#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(a2TestSuite)

const double accuracy = 0.00001;

BOOST_AUTO_TEST_CASE(circleInvatianceAfterAbsoluteMoving)
{
  const double initialRadius = 5.4;
  bublyaev::Circle testCircle({0, 0}, initialRadius);
  const double initialArea = testCircle.getArea();

  testCircle.move({1, 6});
  BOOST_CHECK_CLOSE(initialRadius, testCircle.getRadius(), accuracy);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(circleInvatianceAfterRelativeMoving)
{
  const double initialRadius = 5.4;
  bublyaev::Circle testCircle({1, 5}, initialRadius);
  const double initialArea = testCircle.getArea();

  testCircle.move(4, 0.6);
  BOOST_CHECK_CLOSE(initialRadius, testCircle.getRadius(), accuracy);
  BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), accuracy);
}


BOOST_AUTO_TEST_CASE(rectangleInvarianceAfterAbsoluteMoving)
{
  const double initialWidth = 2;
  const double initialHeight = 12.5;
  bublyaev::Rectangle testRectangle({1, 2}, initialWidth, initialHeight);
  const double initialArea = testRectangle.getArea();

  testRectangle.move({14, 7.5});
  BOOST_CHECK_CLOSE(initialWidth, testRectangle.getWidth(), accuracy);
  BOOST_CHECK_CLOSE(initialHeight, testRectangle.getHeight(), accuracy);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(rectangleInvarianceAfterRelativeMoving)
{
  const double initialWidth = 3;
  const double initialHeight = 15.5;
  bublyaev::Rectangle testRectangle({4, 2}, initialWidth, initialHeight);
  const double initialArea = testRectangle.getArea();

  testRectangle.move(0, 14.32);
  BOOST_CHECK_CLOSE(initialWidth, testRectangle.getWidth(), accuracy);
  BOOST_CHECK_CLOSE(initialHeight, testRectangle.getHeight(), accuracy);
  BOOST_CHECK_CLOSE(initialArea, testRectangle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(circleInvarianceAfterScaling)
{
  const double multiplier = 4;
  bublyaev::Circle testCircle({1, 2}, 7);
  const double initialArea = testCircle.getArea();
  const bublyaev::rectangle_t initialFrame = testCircle.getFrameRect();

  testCircle.scale(multiplier);
  const bublyaev::rectangle_t resultFrame = testCircle.getFrameRect();

  BOOST_CHECK_CLOSE(initialArea * multiplier * multiplier, testCircle.getArea(), accuracy);
  BOOST_CHECK_CLOSE(initialFrame.width * multiplier, resultFrame.width, accuracy);
  BOOST_CHECK_CLOSE(initialFrame.height * multiplier, resultFrame.height, accuracy);
}

BOOST_AUTO_TEST_CASE(rectangleInvarianceAfterScaling)
{
  const double multiplier = 0.5;
  bublyaev::Rectangle testRectangle({0, 0}, 5, 12);
  const double initialArea = testRectangle.getArea();
  const bublyaev::rectangle_t initialFrame = testRectangle.getFrameRect();

  testRectangle.scale(multiplier);
  const bublyaev::rectangle_t resultFrame = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(initialArea * multiplier * multiplier, testRectangle.getArea(), accuracy);
  BOOST_CHECK_CLOSE(initialFrame.width * multiplier, resultFrame.width, accuracy);
  BOOST_CHECK_CLOSE(initialFrame.height * multiplier, resultFrame.height, accuracy);
}

BOOST_AUTO_TEST_CASE(exceptionHandling)
{
  BOOST_CHECK_THROW(bublyaev::Circle({1, 5}, -4), std::invalid_argument);
  BOOST_CHECK_THROW(bublyaev::Rectangle({5, 4}, 0, -1), std::invalid_argument);

  bublyaev::Circle testCircle({1, 7}, 4);
  BOOST_CHECK_THROW(testCircle.scale(-4), std::invalid_argument);

  bublyaev::Rectangle testRectangle({0, 0}, 4, 6);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
