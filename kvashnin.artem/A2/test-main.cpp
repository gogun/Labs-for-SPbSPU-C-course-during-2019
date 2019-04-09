#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

const double OFFSET = 0.01;

BOOST_AUTO_TEST_SUITE(KvashninArtemTestSuite)

BOOST_AUTO_TEST_CASE(circleTestAreaAndSizeAfterOffset)
{
  kvashnin::Circle testing_circle({0, 0}, 2);
  const double testing_area = testing_circle.getArea();
  const kvashnin::rectangle_t testing_frame_before = testing_circle.getFrameRect();
  testing_circle.move(100, 100);
  const kvashnin::rectangle_t testing_frame_after = testing_circle.getFrameRect();
  BOOST_CHECK_EQUAL(testing_circle.getArea(), testing_area);
  BOOST_CHECK_EQUAL(testing_frame_before.width, testing_frame_after.width);
  BOOST_CHECK_EQUAL(testing_frame_before.height, testing_frame_after.height);
}

BOOST_AUTO_TEST_CASE(circleTestAreaAndSizeAfterMoveToPoint)
{
  kvashnin::Circle testing_circle({10, 10}, 7);
  const double testing_area = testing_circle.getArea();
  const kvashnin::rectangle_t testing_frame_before = testing_circle.getFrameRect();
  testing_circle.move({150, 150});
  const kvashnin::rectangle_t testing_frame_after = testing_circle.getFrameRect();
  BOOST_CHECK_EQUAL(testing_circle.getArea(), testing_area);
  BOOST_CHECK_EQUAL(testing_frame_before.width, testing_frame_after.width);
  BOOST_CHECK_EQUAL(testing_frame_before.height, testing_frame_after.height);
}

BOOST_AUTO_TEST_CASE(circleTestAfterScale)
{
  kvashnin::Circle testing_circle({15, 15}, 10);
  const double testing_area = testing_circle.getArea();
  testing_circle.scale(2);
  BOOST_CHECK_CLOSE(testing_circle.getArea(), testing_area * 4, OFFSET);
}

BOOST_AUTO_TEST_CASE(circleTestFrameRectAreaScale)
{
  kvashnin::Circle testing_circle({15, 15}, 10);
  const kvashnin::rectangle_t testing_rect = testing_circle.getFrameRect();
  testing_circle.scale(2);
  const kvashnin::rectangle_t supposed_rect = testing_circle.getFrameRect();
  BOOST_CHECK_CLOSE(testing_rect.width * 2, supposed_rect.width, OFFSET);
  BOOST_CHECK_CLOSE(testing_rect.height * 2, supposed_rect.height, OFFSET);
  BOOST_CHECK_EQUAL(testing_rect.pos.x, testing_rect.pos.x);
  BOOST_CHECK_EQUAL(testing_rect.pos.y, testing_rect.pos.y);
}

BOOST_AUTO_TEST_CASE(circleTestThrowingExceptions)
{
  BOOST_CHECK_THROW(kvashnin::Circle({0, 0}, -2), std::invalid_argument);
  kvashnin::Circle testing_circle({15, 15}, 10);
  BOOST_CHECK_THROW(testing_circle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleTestAreaAndSizeAfterOffset)
{
  kvashnin::Rectangle testing_rectangle({0, 0}, 2, 4);
  const double testing_area = testing_rectangle.getArea();
  const kvashnin::rectangle_t testing_frame_before = testing_rectangle.getFrameRect();
  testing_rectangle.move(100, 100);
  const kvashnin::rectangle_t testing_frame_after = testing_rectangle.getFrameRect();
  BOOST_CHECK_EQUAL(testing_rectangle.getArea(), testing_area);
  BOOST_CHECK_EQUAL(testing_frame_before.width, testing_frame_after.width);
  BOOST_CHECK_EQUAL(testing_frame_before.height, testing_frame_after.height);
}

BOOST_AUTO_TEST_CASE(rectangleTestAreaAndSizeAfterMoveToPoint)
{
  kvashnin::Rectangle testing_rectangle({2, 2}, 8, 10);
  const double testing_area = testing_rectangle.getArea();
  const kvashnin::rectangle_t testing_frame_before = testing_rectangle.getFrameRect();
  testing_rectangle.move({150, 150});
  const kvashnin::rectangle_t testing_frame_after = testing_rectangle.getFrameRect();
  BOOST_CHECK_EQUAL(testing_rectangle.getArea(), testing_area);
  BOOST_CHECK_EQUAL(testing_frame_before.width, testing_frame_after.width);
  BOOST_CHECK_EQUAL(testing_frame_before.height, testing_frame_after.height);
}

BOOST_AUTO_TEST_CASE(rectangleTestAreaScale)
{
  kvashnin::Rectangle testing_rectangle({4, 4}, 16, 20);
  const double testing_area = testing_rectangle.getArea();
  testing_rectangle.scale(2);
  BOOST_CHECK_CLOSE(testing_rectangle.getArea(), testing_area * 4, OFFSET);
}

BOOST_AUTO_TEST_CASE(rectangleTestFrameRectAfterScale)
{
  kvashnin::Rectangle testing_rectangle({4, 4}, 16, 20);
  const kvashnin::rectangle_t testing_rect = testing_rectangle.getFrameRect();
  testing_rectangle.scale(2);
  const kvashnin::rectangle_t supposed_rect = testing_rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(testing_rect.width * 2, supposed_rect.width, OFFSET);
  BOOST_CHECK_CLOSE(testing_rect.height * 2, supposed_rect.height, OFFSET);
  BOOST_CHECK_EQUAL(testing_rect.pos.x, testing_rect.pos.x);
  BOOST_CHECK_EQUAL(testing_rect.pos.y, testing_rect.pos.y);
}

BOOST_AUTO_TEST_CASE(rectangleTestThrowingExceptions)
{
  BOOST_CHECK_THROW(kvashnin::Rectangle({0, 0}, -1, 2), std::invalid_argument);
  kvashnin::Rectangle testing_rectangle({4, 4}, 16, 20);
  BOOST_CHECK_THROW(testing_rectangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
