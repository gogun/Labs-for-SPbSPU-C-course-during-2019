#define BOOST_AUTO_MODULE A2_TEST

#include <stdexcept>

#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(testSuiteShapes)

const double LAPSE = 0.01;

BOOST_AUTO_TEST_CASE(afterMoveTestingRectangle)
{
  karpenko::Rectangle rectangle({3.5, 6.3, {2.0, 7.0}});
  const karpenko::rectangle_t originalRect = rectangle.getFrameRect();
  const double originalSquare = rectangle.getArea();

  rectangle.move(5.0, 6.0);
  karpenko::rectangle_t afterMoveData = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangle.getArea(), originalSquare, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalRect.height, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalRect.width, LAPSE);

  rectangle.move({3.0, 2.0});
  afterMoveData = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangle.getArea(), originalSquare, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalRect.height, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalRect.width, LAPSE);
}

BOOST_AUTO_TEST_CASE(afterMoveTestingCircle)
{
  karpenko::Circle circle({6.5, {2.0, 7.0}});
  const karpenko::rectangle_t originalFrame = circle.getFrameRect();
  const double originalSquare = circle.getArea();

  circle.move(4.0, 2.4);
  karpenko::rectangle_t afterMoveData = circle.getFrameRect();
  BOOST_CHECK_CLOSE(circle.getArea(), originalSquare, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalFrame.height, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalFrame.width, LAPSE);

  circle.move({3.0, 7.0});
  afterMoveData = circle.getFrameRect();
  BOOST_CHECK_CLOSE(circle.getArea(), originalSquare, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalFrame.height, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalFrame.width, LAPSE);
}

BOOST_AUTO_TEST_CASE(quadroMetamaorphoseRectangleTesting)
{
  karpenko::Rectangle rectangle({3.5, 6.3, {2.0, 7.0}});
  const double originalSquare = rectangle.getArea();

  const double scaleRatio = 3.3;
  rectangle.scale(scaleRatio);
  BOOST_CHECK_CLOSE(rectangle.getArea(), originalSquare * scaleRatio * scaleRatio, LAPSE);
}

BOOST_AUTO_TEST_CASE(quadroMetamaorphoseCircleTesting)
{
  karpenko::Circle circle({6.5, {2.0, 7.0}});
  const double originalSquare = circle.getArea();

  const double scaleRatio = 3.3;
  circle.scale(scaleRatio);
  BOOST_CHECK_CLOSE(circle.getArea(), originalSquare * scaleRatio * scaleRatio, LAPSE);
}

BOOST_AUTO_TEST_CASE(argumentTesting)
{
  BOOST_CHECK_THROW(karpenko::Rectangle({-2.0, 7.0, {2.0, 2.0}}), std::invalid_argument);
  BOOST_CHECK_THROW(karpenko::Rectangle({2.0, -7.0, {2.0, 2.0}}), std::invalid_argument);

  BOOST_CHECK_THROW(karpenko::Circle(-5.0, {2.0, 6.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
