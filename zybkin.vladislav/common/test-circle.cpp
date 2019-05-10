#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>

#include "circle.hpp"

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
