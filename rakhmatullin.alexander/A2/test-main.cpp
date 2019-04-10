#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double DIFF = 0.0001;

BOOST_AUTO_TEST_SUITE(testRectangleMethods)

BOOST_AUTO_TEST_CASE(testRectangleSavedParamAfterShiftMoving)
{
  //Initialization of begins values
  rakhmatullin::Rectangle testRectangle({2.6, 4.4}, 15.0, 20.0);
  const double rectangleParamAreaBeforeMoving = testRectangle.getArea();
  const rakhmatullin::rectangle_t rectangleParamFrameBeforeMoving = testRectangle.getFrameRect();

  //shift rectangle on (-2.3, 1.0)
  testRectangle.move(-2.3, 1.0);

  //rectangle parameter check
  BOOST_CHECK_CLOSE(rectangleParamAreaBeforeMoving, testRectangle.getArea(), DIFF);
  rakhmatullin::rectangle_t rectangleParamFrameAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_EQUAL(rectangleParamFrameBeforeMoving.width, rectangleParamFrameAfterMoving.width);
  BOOST_CHECK_EQUAL(rectangleParamFrameBeforeMoving.height, rectangleParamFrameAfterMoving.height);
}

BOOST_AUTO_TEST_CASE(testRectangleSavedParamAfterMovingTo)
{
  //Initialization of begins values
  rakhmatullin::Rectangle testRectangle({2.6, 4.4}, 15.0, 20.0);
  const double rectangleParamAreaBeforeMoving = testRectangle.getArea();
  const rakhmatullin::rectangle_t rectangleParamFrameBeforeMoving = testRectangle.getFrameRect();

  //move rectangle to (3.7, 2.2)
  testRectangle.move({3.7, 2.2});

  //rectangle parameter check
  BOOST_CHECK_CLOSE(rectangleParamAreaBeforeMoving, testRectangle.getArea(), DIFF);
  rakhmatullin::rectangle_t rectangleParamFrameAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_EQUAL(rectangleParamFrameBeforeMoving.width, rectangleParamFrameAfterMoving.width);
  BOOST_CHECK_EQUAL(rectangleParamFrameBeforeMoving.height, rectangleParamFrameAfterMoving.height);
}

BOOST_AUTO_TEST_CASE(testRectangleFunctionScale)
{
  //Initialization of begins values
  rakhmatullin::Rectangle testRectangle({2.6, 4.4}, 15.0, 20.0);
  const double rectangleParamAreaBeforeScale = testRectangle.getArea();
  const rakhmatullin::rectangle_t rectangleParamFrameBeforeScale = testRectangle.getFrameRect();
  const double testScale = 3;

  //scale rectangle in 3 times
  testRectangle.scale(testScale);

  //rectangle parameter check (The area should increase 9 times)
  BOOST_CHECK_CLOSE(rectangleParamAreaBeforeScale * testScale * testScale, testRectangle.getArea(), DIFF);
  const rakhmatullin::rectangle_t rectangleParamFrameAfterScale = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangleParamFrameBeforeScale.width * testScale, rectangleParamFrameAfterScale.width, DIFF);
  BOOST_CHECK_CLOSE(rectangleParamFrameBeforeScale.height * testScale, rectangleParamFrameAfterScale.height, DIFF);
}

BOOST_AUTO_TEST_CASE(rectangleTestInvalidConstructorParam)
{
  //invalid width param
  BOOST_CHECK_THROW(rakhmatullin::Rectangle({2.6, 4.4}, -15.0, 20.0), std::invalid_argument);
  //invalid height param
  BOOST_CHECK_THROW(rakhmatullin::Rectangle({3.6, 6.3}, 7.0, -3.0), std::invalid_argument);
  //invalid width and height param
  BOOST_CHECK_THROW(rakhmatullin::Rectangle({1.2, 8.1}, -6.0, -13.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleTestInvalidScale)
{
  rakhmatullin::Rectangle testRectangle({2.6, 6.3}, 15.5, 20.0);
  BOOST_CHECK_THROW(testRectangle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(testCircleMethods)

BOOST_AUTO_TEST_CASE(testCircleSavedParamAfterShiftMoving)
{
  //Initialization of begins values
  rakhmatullin::Circle testCircle({7.2, 6.8}, 10.0);
  const double circleParamAreaBeforeMoving = testCircle.getArea();
  const rakhmatullin::rectangle_t circleParamFrameBeforeMoving = testCircle.getFrameRect();

  //shift circle on (-2.3, 1.0)
  testCircle.move(-2.3, 1.0);

  //circle parameter check
  BOOST_CHECK_CLOSE(circleParamAreaBeforeMoving, testCircle.getArea(), DIFF);
  rakhmatullin::rectangle_t circleParamFrameAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_EQUAL(circleParamFrameBeforeMoving.width, circleParamFrameAfterMoving.width);
  BOOST_CHECK_EQUAL(circleParamFrameBeforeMoving.height, circleParamFrameAfterMoving.height);
}

BOOST_AUTO_TEST_CASE(testCircleSavedParamAfterMovingTo)
{
  //Initialization of begins values
  rakhmatullin::Circle testCircle({7.2, 6.8}, 10.0);
  const double circleParamAreaBeforeMoving = testCircle.getArea();
  const rakhmatullin::rectangle_t circleParamFrameBeforeMoving = testCircle.getFrameRect();

  //Move circle to (5.2, -3.9)
  testCircle.move({5.2, -3.9});

  //circle parameter check
  BOOST_CHECK_CLOSE(circleParamAreaBeforeMoving, testCircle.getArea(), DIFF);
  rakhmatullin::rectangle_t circleParamFrameAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_EQUAL(circleParamFrameBeforeMoving.width, circleParamFrameAfterMoving.width);
  BOOST_CHECK_EQUAL(circleParamFrameBeforeMoving.height, circleParamFrameAfterMoving.height);
}

BOOST_AUTO_TEST_CASE(testCircleFunctionScale)
{
  //Initialization of begins values
  rakhmatullin::Circle testCircle({7.2, 6.8}, 10.0);
  const double circleParamAreaBeforeScale = testCircle.getArea();
  const double testScale = 3;

  //scale circle in 3 times
  testCircle.scale(testScale);

  //circle parameter check (The area should increase 9 times)
  BOOST_CHECK_CLOSE(circleParamAreaBeforeScale * testScale * testScale, testCircle.getArea(), DIFF);
}

BOOST_AUTO_TEST_CASE(circleTestInvalidConstructorParam)
{
  //invalid radius param
  BOOST_CHECK_THROW(rakhmatullin::Circle({7.2, 6.8}, -10.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleTestInvalidScale)
{
  rakhmatullin::Circle testCircle({7.2, 6.8}, 10.0);
  BOOST_CHECK_THROW(testCircle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()