#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

const double PRECISION = 0.001;

BOOST_AUTO_TEST_SUITE(testShape)

BOOST_AUTO_TEST_CASE (TestCorrectnessOfShapeParameters)
{
  BOOST_CHECK_THROW(shreder::Circle({1.0, 6.6}, 0.0), std::invalid_argument);
  BOOST_CHECK_THROW(shreder::Rectangle({5.6, 4.0}, -3.5, -1.7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE (TestCorrectnessOfScaleValue)
{
  shreder::Circle testCircle({{5.2,5.4},7.9});
  BOOST_CHECK_THROW(testCircle.scale(-4), std::invalid_argument);

  shreder::Rectangle testRectangle({{1.0,5.0},5.1,4.2});
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testShapeMoving)

BOOST_AUTO_TEST_CASE(TestRectangleMovingToThePoint)
{
  shreder::Rectangle testRectangle({{6.0, 5.0}, 12.3, 3.1});
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const shreder::rectangle_t frameRectangleBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move({4.0, -1.5}); //moving rectangle to the point with coordinates (10.0, 3.5)

  BOOST_CHECK_CLOSE(rectangleAreaBeforeMoving, testRectangle.getArea(), PRECISION);
  shreder::rectangle_t frameRectangleAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectangleBeforeMoving.height, frameRectangleAfterMoving.height, PRECISION);
  BOOST_CHECK_CLOSE(frameRectangleBeforeMoving.width, frameRectangleAfterMoving.width, PRECISION);
}

BOOST_AUTO_TEST_CASE(TestCircleMovingToThePoint)
{
  shreder::Circle testCircle({{7.0, 8.0}, 12.3});
  const double circleAreaBeforeMoving = testCircle.getArea();
  const shreder::rectangle_t frameCircleBeforeMoving = testCircle.getFrameRect();
  testCircle.move({4.0, -1.5}); //moving circle to the point with coordinates (10.0, 3.5)

  BOOST_CHECK_CLOSE(circleAreaBeforeMoving, testCircle.getArea(), PRECISION);
  shreder::rectangle_t frameCircleAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameCircleBeforeMoving.height, frameCircleAfterMoving.height, PRECISION);
  BOOST_CHECK_CLOSE(frameCircleBeforeMoving.width, frameCircleAfterMoving.width, PRECISION);
}

BOOST_AUTO_TEST_CASE(TestRectangleMovingAlongAbscissaAndOrdinate)
{
  shreder::Rectangle testRectangle({{6.0, 5.0}, 12.3, 3.1});
  const double rectangleAreaBeforeMoving = testRectangle.getArea();
  const shreder::rectangle_t frameRectangleBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move({2.0, -0.5});

  BOOST_CHECK_CLOSE(rectangleAreaBeforeMoving, testRectangle.getArea(), PRECISION);
  shreder::rectangle_t frameRectangleAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectangleBeforeMoving.height, frameRectangleAfterMoving.height, PRECISION);
  BOOST_CHECK_CLOSE(frameRectangleBeforeMoving.width, frameRectangleAfterMoving.width, PRECISION);
}

BOOST_AUTO_TEST_CASE(TestCircleMovingAlongAbscissaAndOrdinate)
{
  shreder::Circle testCircle({{6.0, 5.0}, 12.0});
  const double circleAreaBeforeMoving = testCircle.getArea();
  const shreder::rectangle_t frameCircleBeforeMoving = testCircle.getFrameRect();
  testCircle.move({2.5, -7.5});

  BOOST_CHECK_CLOSE(circleAreaBeforeMoving, testCircle.getArea(), PRECISION);
  shreder::rectangle_t frameCircleAfterMoving = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameCircleBeforeMoving.height, frameCircleAfterMoving.height, PRECISION);
  BOOST_CHECK_CLOSE(frameCircleBeforeMoving.width, frameCircleAfterMoving.width, PRECISION);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testShapeScale)

BOOST_AUTO_TEST_CASE(TestRectangleAfterScale)
{
  shreder::Rectangle testRectangle({{6.0, 5.0}, 12.3, 3.1});
  const double rectangleAreaBeforeZooming = testRectangle.getArea();
  const shreder::rectangle_t frameRectangleBeforeZooming = testRectangle.getFrameRect();
  const double testScale = 4.0;
  testRectangle.scale(testScale);

  BOOST_CHECK_CLOSE(rectangleAreaBeforeZooming * testScale * testScale, testRectangle.getArea(), PRECISION);
  shreder::rectangle_t frameRectangleAfterZooming = testRectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectangleBeforeZooming.height * testScale, frameRectangleAfterZooming.height, PRECISION);
  BOOST_CHECK_CLOSE(frameRectangleBeforeZooming.width * testScale, frameRectangleAfterZooming.width, PRECISION);
}

BOOST_AUTO_TEST_CASE(TestCircleAfterScale)
{
  shreder::Circle testCircle({{5.5,3.8},7.9});
  const double circleAreaBeforeZooming = testCircle.getArea();
  const shreder::rectangle_t frameRectangleBeforeZooming = testCircle.getFrameRect();
  const double testScale = 4.0;
  testCircle.scale(testScale);

  BOOST_CHECK_CLOSE(circleAreaBeforeZooming * testScale * testScale, testCircle.getArea(), PRECISION);
  shreder::rectangle_t frameRectangleAfterZooming = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectangleBeforeZooming.height * testScale, frameRectangleAfterZooming.height, PRECISION);
  BOOST_CHECK_CLOSE(frameRectangleBeforeZooming.width * testScale, frameRectangleAfterZooming.width, PRECISION);
}

BOOST_AUTO_TEST_SUITE_END()
