#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>

#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

const double calcError = 0.01;

BOOST_AUTO_TEST_CASE(invariabilityOfCircleAfterMoving)
{
  gnatishin::Circle testCircle({3.0, 5.5}, 2.0);
  const gnatishin::rectangle_t frameBefore = testCircle.getFrameRect();
  const double areaBefore = testCircle.getArea();

  testCircle.move({5.0, 7.8});
  gnatishin::rectangle_t frameNow = testCircle.getFrameRect();
  double areaNow = testCircle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameNow.width, calcError);
  BOOST_CHECK_CLOSE(frameBefore.height, frameNow.height, calcError);
  BOOST_CHECK_CLOSE(areaBefore, areaNow, calcError);

  testCircle.move(-2.0, 8.6);
  frameNow = testCircle.getFrameRect();
  areaNow = testCircle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameNow.width, calcError);
  BOOST_CHECK_CLOSE(frameBefore.height, frameNow.height, calcError);
  BOOST_CHECK_CLOSE(areaBefore, areaNow, calcError);
}

BOOST_AUTO_TEST_CASE(invariabilityOfRectangleAfterMoving)
{
  gnatishin::Rectangle testRectangle({6.3, 4.0}, 5.0, 10.0);
  const gnatishin::rectangle_t frameBefore = testRectangle.getFrameRect();
  const double areaBefore = testRectangle.getArea();

  testRectangle.move({5.0, 1.5});
  gnatishin::rectangle_t frameNow = testRectangle.getFrameRect();
  double areaNow = testRectangle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameNow.width, calcError);
  BOOST_CHECK_CLOSE(frameBefore.height, frameNow.height, calcError);
  BOOST_CHECK_CLOSE(areaBefore, areaNow, calcError);

  testRectangle.move(7.5, 4.0);
  frameNow = testRectangle.getFrameRect();
  areaNow = testRectangle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameNow.width, calcError);
  BOOST_CHECK_CLOSE(frameBefore.height, frameNow.height, calcError);
  BOOST_CHECK_CLOSE(areaBefore, areaNow, calcError);
}

BOOST_AUTO_TEST_CASE(changingAfterScalingCircle)
{
  gnatishin::Circle testCircle({2.0, 4.0}, 3.0);
  const double areaBefore = testCircle.getArea();
  const double scaleFactor = 2.0;

  testCircle.scale(scaleFactor);
  double areaNow = testCircle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleFactor * scaleFactor, areaNow, calcError);
}

BOOST_AUTO_TEST_CASE(changingAfterScalingRectangle)
{
  gnatishin::Rectangle testRectangle({2.0, 4.0}, 3.0, 5.0);
  const double areaBefore = testRectangle.getArea();
  const double scaleFactor = 2.5;

  testRectangle.scale(scaleFactor);
  double areaNow = testRectangle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleFactor * scaleFactor, areaNow, calcError);
}

BOOST_AUTO_TEST_CASE(invalidParametersValidation)
{
  BOOST_CHECK_THROW(gnatishin::Circle({2.5, 3.5}, -3.0), std::invalid_argument);
  BOOST_CHECK_THROW(gnatishin::Rectangle({2.5, 3.5}, 3.0, -6.0), std::invalid_argument);
  BOOST_CHECK_THROW(gnatishin::Rectangle({2.5, 3.5}, -3.0, 6.0), std::invalid_argument);
  BOOST_CHECK_THROW(gnatishin::Rectangle({2.5, 3.5}, -3.0, -6.0), std::invalid_argument);

  gnatishin::Circle testCircle({-6.0, 3.5}, 5.5);
  BOOST_CHECK_THROW(testCircle.scale(-8.8), std::invalid_argument);

  gnatishin::Rectangle testRectangle({-6.0, 3.5}, 5.5, 8.0);
  BOOST_CHECK_THROW(testRectangle.scale(-0.1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
