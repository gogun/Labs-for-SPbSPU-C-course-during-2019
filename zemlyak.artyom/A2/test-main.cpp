#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testCorrectnessModule)

const double error = 0.0001;

BOOST_AUTO_TEST_CASE(circleAfterMoveParameters)
{
  zemlyak::Circle circle_test({1, 2}, 3);
  const double initialArea = circle_test.getArea();
  const zemlyak::rectangle_t initialFrameRect = circle_test.getFrameRect();

  circle_test.move(10, 15);
  double currentArea = circle_test.getArea();
  zemlyak::rectangle_t currentFrameRect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initialArea, currentArea, error);
  BOOST_CHECK_CLOSE(initialFrameRect.width, currentFrameRect.width, error);
  BOOST_CHECK_CLOSE(initialFrameRect.height, currentFrameRect.height, error);

  circle_test.move({0, 1});
  currentArea = circle_test.getArea();
  currentFrameRect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initialArea, currentArea, error);
  BOOST_CHECK_CLOSE(initialFrameRect.width, currentFrameRect.width, error);
  BOOST_CHECK_CLOSE(initialFrameRect.height, currentFrameRect.height, error);
}

BOOST_AUTO_TEST_CASE(circleAfterScaleParameters)
{
  zemlyak::Circle circle_test({1, 2}, 3);
  const double initialArea = circle_test.getArea();
  const zemlyak::rectangle_t initialFrameRect = circle_test.getFrameRect();

  const int factor = 2;
  circle_test.scale(factor);
  double currentArea = circle_test.getArea();
  zemlyak::rectangle_t currentFrameRect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initialArea * factor * factor, currentArea, error);
  BOOST_CHECK_CLOSE(initialFrameRect.width * factor, currentFrameRect.width, error);
  BOOST_CHECK_CLOSE(initialFrameRect.height * factor, currentFrameRect.height, error);
}

BOOST_AUTO_TEST_CASE(circleThrowException)
{
  BOOST_CHECK_THROW(zemlyak::Circle({1, 2}, -1), std::invalid_argument);

  zemlyak::Circle circle_test({1, 2}, 5);
  BOOST_CHECK_THROW(circle_test.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleAfterMoveParameters)
{
  zemlyak::Rectangle rectangle_test({1, 2}, 3, 5);
  const double initialArea = rectangle_test.getArea();
  const zemlyak::rectangle_t initialFrameRect = rectangle_test.getFrameRect();

  rectangle_test.move(10, 15);
  double currentArea = rectangle_test.getArea();
  zemlyak::rectangle_t currentFrameRect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initialArea, currentArea, error);
  BOOST_CHECK_CLOSE(initialFrameRect.width, currentFrameRect.width, error);
  BOOST_CHECK_CLOSE(initialFrameRect.height, currentFrameRect.height, error);

  rectangle_test.move({0, 1});
  currentArea = rectangle_test.getArea();
  currentFrameRect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initialArea, currentArea, error);
  BOOST_CHECK_CLOSE(initialFrameRect.width, currentFrameRect.width, error);
  BOOST_CHECK_CLOSE(initialFrameRect.height, currentFrameRect.height, error);
}

BOOST_AUTO_TEST_CASE(rectangleAfterScaleParameters)
{
  zemlyak::Rectangle rectangle_test({1, 2}, 3, 5);
  const double initialArea = rectangle_test.getArea();
  const zemlyak::rectangle_t initialFrameRect = rectangle_test.getFrameRect();

  const int factor = 2;
  rectangle_test.scale(factor);
  double currentArea = rectangle_test.getArea();
  zemlyak::rectangle_t currentFrameRect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initialArea * factor * factor, currentArea, error);
  BOOST_CHECK_CLOSE(initialFrameRect.width * factor, currentFrameRect.width, error);
  BOOST_CHECK_CLOSE(initialFrameRect.height * factor, currentFrameRect.height, error);
}

BOOST_AUTO_TEST_CASE(rectangleThrowException)
{
  BOOST_CHECK_THROW(zemlyak::Rectangle({1, 2}, -1, -2), std::invalid_argument);

  zemlyak::Rectangle rectangle_test({1, 2}, 10, 15);
  BOOST_CHECK_THROW(rectangle_test.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
