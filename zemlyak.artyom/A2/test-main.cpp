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
  const double initial_area = circle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = circle_test.getFrameRect();

  circle_test.move(10, 15);
  double current_area = circle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);

  circle_test.move({0, 1});
  current_area = circle_test.getArea();
  current_frame_rect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(circleAfterScaleParameters)
{
  zemlyak::Circle circle_test({1, 2}, 3);
  const double initial_area = circle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = circle_test.getFrameRect();

  const int factor = 2;
  circle_test.scale(factor);
  double current_area = circle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area * factor * factor, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width * factor, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height * factor, current_frame_rect.height, error);
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
  const double initial_area = rectangle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = rectangle_test.getFrameRect();

  rectangle_test.move(10, 15);
  double current_area = rectangle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);

  rectangle_test.move({0, 1});
  current_area = rectangle_test.getArea();
  current_frame_rect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(rectangleAfterScaleParameters)
{
  zemlyak::Rectangle rectangle_test({1, 2}, 3, 5);
  const double initial_area = rectangle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = rectangle_test.getFrameRect();

  const int factor = 2;
  rectangle_test.scale(factor);
  double current_area = rectangle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area * factor * factor, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width * factor, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height * factor, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(rectangleThrowException)
{
  BOOST_CHECK_THROW(zemlyak::Rectangle({1, 2}, -1, -2), std::invalid_argument);

  zemlyak::Rectangle rectangle_test({1, 2}, 10, 15);
  BOOST_CHECK_THROW(rectangle_test.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
