#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double miscalculation = 0.001;

BOOST_AUTO_TEST_SUITE(testingRectangle)

BOOST_AUTO_TEST_CASE(testingRectangleAfterMovingToThePoint)
{
  sherman::Rectangle testRectangle({10.5, 6.9, {8.0, 9.0}});
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const sherman::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move({5.0, -3.5});

  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeMoving, miscalculation);
  sherman::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, miscalculation);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, miscalculation);
}

BOOST_AUTO_TEST_CASE(testingRectangleAfterMovingAlongAbscissaAndOrdinate)
{
  sherman::Rectangle testRectangle({10.5, 6.9, {8.0, 9.0}});
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const sherman::rectangle_t frameRectBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move(-2.1, 6.0);

  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeMoving, miscalculation);
  sherman::rectangle_t frameRectAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, miscalculation);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, miscalculation);
}

BOOST_AUTO_TEST_CASE(testingRectangleAfterScale)
{
  sherman::Rectangle testRectangle({10.5, 6.9, {8.0, 9.0}});
  const double rectangleAreaBeforeZoomingScale = testRectangle.getArea();
  const sherman::rectangle_t frameRectBeforeZoomingScale = testRectangle.getFrameRect();
  const double coefficient = 10.0;
  testRectangle.scale(coefficient);

  BOOST_CHECK_CLOSE(testRectangle.getArea(), rectangleAreaBeforeZoomingScale * coefficient * coefficient, miscalculation);
  sherman::rectangle_t frameRectAfterZoomingScale = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterZoomingScale.width, frameRectBeforeZoomingScale.width * coefficient, miscalculation);
  BOOST_CHECK_CLOSE(frameRectAfterZoomingScale.height, frameRectBeforeZoomingScale.height * coefficient, miscalculation);
}

BOOST_AUTO_TEST_CASE(rectangleInvalidWidthValue)
{
  BOOST_CHECK_THROW(sherman::Rectangle({-45.0, 6.9, {8.0, 9.0}}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleInvalidHeightValue)
{
  BOOST_CHECK_THROW(sherman::Rectangle({10.5, -67.0, {8.0, 9.0}}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleInvalidScaleValue)
{
  sherman::Rectangle testRectangle({10.5, 6.9, {8.0, 9.0}});
  BOOST_CHECK_THROW(testRectangle.scale(-6), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testingCircle)

BOOST_AUTO_TEST_CASE(testingCicleAfterMovingToThePoint)
{
  sherman::Circle testCircle({12.0, {8.0, 9.0}});
  const double circleAreaBeforeMoving = testCircle.getArea();
  const sherman::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();
  testCircle.move({5.0, -3.5});

  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMoving, miscalculation);
  sherman::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, miscalculation);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, miscalculation);
}

BOOST_AUTO_TEST_CASE(testingCircleAfterMovingAlongAbscissaAndOrdinate)
{
  sherman::Circle testCircle({12.0, {8.0, 9.0}});
  const double circleAreaBeforeMoving = testCircle.getArea();
  const sherman::rectangle_t frameRectBeforeMoving = testCircle.getFrameRect();
  testCircle.move(-2.1, 6.0);

  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMoving, miscalculation);
  sherman::rectangle_t frameRectAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterMoving.width, frameRectBeforeMoving.width, miscalculation);
  BOOST_CHECK_CLOSE(frameRectAfterMoving.height, frameRectBeforeMoving.height, miscalculation);
}

BOOST_AUTO_TEST_CASE(testingCircleAfterScale)
{
  sherman::Circle testCircle({12.0, {8.0, 9.0}});
  const double circleAreaBeforeZoomingScale = testCircle.getArea();
  const sherman::rectangle_t frameRectBeforeZoomingScale = testCircle.getFrameRect();
  const double coefficient = 10.0;
  testCircle.scale(coefficient);

  BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeZoomingScale * coefficient * coefficient, miscalculation);
  sherman::rectangle_t frameRectAfterZoomingScale = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectAfterZoomingScale.width, frameRectBeforeZoomingScale.width * coefficient, miscalculation);
  BOOST_CHECK_CLOSE(frameRectAfterZoomingScale.height, frameRectBeforeZoomingScale.height * coefficient, miscalculation);
}

BOOST_AUTO_TEST_CASE(circleInvalidRadiusValue)
{
  BOOST_CHECK_THROW(sherman::Circle({-19.0, {8.0, 9.0}}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleInvalidScaleValue)
{
  sherman::Circle testCircle({12.0, {8.0, 9.0}});
  BOOST_CHECK_THROW(testCircle.scale(-7), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
