#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

const double FAULT = 0.0001;

BOOST_AUTO_TEST_SUITE(circleMethodsTesting)

BOOST_AUTO_TEST_CASE(circleTestSavedAfterShiftMoving)
{
  zybkin::Circle testCircle({5.0, 5.2}, 2.0);
  const double circleAreaBeforeMoving = testCircle.getArea();
  const zybkin::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();
  //moving circle to point (7.0,8.2)
  testCircle.move(2.0, 3.0);

  //area and frame rectangle security check
  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMoving, FAULT);
  zybkin::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_EQUAL(frameRectAfterMoving.height, frameRectBeforeMoving.height);
  BOOST_CHECK_EQUAL(frameRectAfterMoving.width, frameRectBeforeMoving.width);
}

BOOST_AUTO_TEST_CASE(circleTestSavedAfterMovingTo)
{
  zybkin::Circle testCircle({5.0, 5.2}, 2.0);
  const double circleAreaBeforeMoving = testCircle.getArea();
  const zybkin::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();

  //moving cicle to point (-1.7,5.2)
  testCircle.move({-1.7, 5.2});

  //area and frame rectangle security check
  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMoving, FAULT);
  zybkin::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_EQUAL(frameRectAfterMoving.height, frameRectBeforeMoving.height);
  BOOST_CHECK_EQUAL(frameRectAfterMoving.width, frameRectBeforeMoving.width);
}

BOOST_AUTO_TEST_CASE(circleTestScale)
{
  zybkin::Circle testCircle({5.0, 5.0}, 2.0);
  const double circleAreaBeforeScale = testCircle.getArea();
  const double testScale = 2.5;

  //scale in 2,5 times
  testCircle.scale(testScale);
  //check that area scale in 6.25 times
  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeScale * testScale * testScale, FAULT);
}

BOOST_AUTO_TEST_CASE(circleTestThrowExceptionAfterScale)
{
  zybkin::Circle testCircle({2.1, 5.3}, 2);
  BOOST_CHECK_THROW(testCircle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleTestThrowException)
{
  BOOST_CHECK_THROW(zybkin::Circle({5.1,4.2}, -2), std::invalid_argument);
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangleMethodsTesting)

BOOST_AUTO_TEST_CASE(rectangleTestSavedAfterShiftMoving)
{
  zybkin::Rectangle testRectangle({5.0, 5.2}, 2.0, 3.0);
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const zybkin::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  //moving rectangle to point (7.0,8.2)
  testRectangle.move(2.0, 3.0);

  //area and frame rectangle security check
  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeMoving, FAULT);
  zybkin::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_EQUAL(frameRectAfterMoving.height, frameRectBeforeMoving.height);
  BOOST_CHECK_EQUAL(frameRectAfterMoving.width, frameRectBeforeMoving.width);
}

BOOST_AUTO_TEST_CASE(rectangleTestSavedAfterMovingTo)
{
  zybkin::Rectangle testRectangle({5.0, 5.2}, 2.0, 3.0);
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const zybkin::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  //moving rectangle to point (1.0,-3.2)
  testRectangle.move({1.0, -3.2});

  //area and frame rectangle security check
  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeMoving, FAULT);
  zybkin::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_EQUAL(frameRectAfterMoving.height, frameRectBeforeMoving.height);
  BOOST_CHECK_EQUAL(frameRectAfterMoving.width, frameRectBeforeMoving.width);
}

BOOST_AUTO_TEST_CASE(rectangleTestScale)
{
  zybkin::Rectangle testRectangle({5.0, 5.0}, 2.0, 5.0);
  const double rectangleAreaBeforeScale = testRectangle.getArea();
  const zybkin::rectangle_t frameRectBeforeScale = testRectangle.getFrameRect();
  const double testScale = 2.5;

  //scale in 2,5 times
  testRectangle.scale(testScale);
  //check that area scale in 6.25 times
  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeScale * testScale * testScale, FAULT);
  const zybkin::rectangle_t frameRectAfterScale = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterScale.height, frameRectBeforeScale.height * testScale, FAULT);
  BOOST_CHECK_CLOSE(frameRectAfterScale.width, frameRectBeforeScale.width * testScale, FAULT);
}

BOOST_AUTO_TEST_CASE(rectangleTestThrowExceptionAfterScale)
{
  zybkin::Rectangle testRectangle({2.1, 5.3}, 5.5, 6.2);
  BOOST_CHECK_THROW(testRectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleTestWidthThrowException)
{
  BOOST_CHECK_THROW(zybkin::Rectangle({5.1,4.2}, -2.0, 3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleTestHeightThrowException)
{
  BOOST_CHECK_THROW(zybkin::Rectangle({5.1,4.2}, 3.0, -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
