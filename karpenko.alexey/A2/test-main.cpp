#define BOOST_AUTO_MODULE A2_TEST

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"


const double LAPSE = 0.01;

BOOST_AUTO_TEST_SUITE(testSuiteShapes)

BOOST_AUTO_TEST_CASE(afterMoveTestingRectangle)
{
  karpenko::Rectangle rectangle({3, 6, {2, 7}});
  const karpenko::rectangle_t originalRect = rectangle.getFrameRect();
  const double originalSquare = rectangle.getArea();

  rectangle.move(5, 6);
  const karpenko::rectangle_t afterMoveData = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangle.getArea, originalSquare, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalRect.height, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalRect.width, LAPSE);

  rectangle.move({3, 2});
  const karpenko::rectangle_t afterMoveData = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangle.getArea, originalSquare, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalRect.height, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalRect.width, LAPSE);
}

BOOST_AUTO_TEST_CASE(afterMoveTestingCircle)
{
  karpenko::Circle circle({6, {2, 7}});
  const karpenko::Circle originalFrame = circle.getFrameRect();
  const double originalSquare = circle.getArea();

  rectangle.move(4, 2);
  const karpenko::rectangle_t afterMoveData = circle.getFrameRect();
  BOOST_CHECK_CLOSE(circle.getArea, originalSquare, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalRect.height, LAPSE);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalRect.width, LAPSE);

  rectangle.move({3, 7});
  const karpenko::rectangle_t afterMoveData = circle.getFrameRect();
  BOOST_CHECK_CLOSE(circle.getArea, originalSquare);
  BOOST_CHECK_CLOSE(afterMoveData.height, originalRect.height);
  BOOST_CHECK_CLOSE(afterMoveData.width, originalRect.width);
}

BOOST_AUTO_TEST_CASE(quadroMetamaorphoseRectangleTesting)
{
  karpenko::Rectangle rectangle({3, 6, {2, 7}});
  const double originalSquare = rectangle.getArea();

  const double scaleRatio = 3.3;
  rectangle.scale(scaleRatio);
  BOOST_CHECK_CLOSE(rectangle.getArea, originalSquare * scaleRatio * scaleRatio, LAPSE);
}

BOOST_AUTO_TEST_CASE(quadroMetamaorphoseCircleTesting)
{
  karpenko::Circle circle({6, {2, 7}});
  const double originalSquare = circle.getArea();

  const double scaleRatio = 3.3;
  rectangle.scale(scaleRatio);
  BOOST_CHECK_CLOSE(circle.getArea, originalSquare * scaleRatio * scaleRatio, LAPSE);
}

BOOST_AUTO_TEST_CASE(argumentTesting)
{
  BOOST_CHECK_THROW(karpenko::Rectangle({-2, 7, {2, 2}}), std::invalid_argument);
  BOOST_CHECK_THROW(karpenko::Rectangle({2, -7, {2, 2}}), std::invalid_argument);

  BOOST_CHECK_THROW(karpenko::Circle(-5, {2, 6}}, std::invalid_argument);

BOOST_AUTO_TEST_SUITE_END

