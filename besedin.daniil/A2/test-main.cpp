#define BOOST_TEST_MODULE A2

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double EPSILON = 0.01;

BOOST_AUTO_TEST_SUITE(TestSuiteA2)

BOOST_AUTO_TEST_CASE(frameRectangleConstantAfterMove)
{
  besedin::Rectangle rectangle(5.0, 5.0, {10.0, 10.0});
  const besedin::rectangle_t frameRectBefore = rectangle.getFrameRect();
  const double areaBefore = rectangle.getArea();

  rectangle.move(5, 5);
  BOOST_CHECK_CLOSE(frameRectBefore.width, rectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.height, rectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, rectangle.getArea(), EPSILON);

  rectangle.move({20, 20});
  BOOST_CHECK_CLOSE(frameRectBefore.width, rectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.height, rectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, rectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(frameCircleConstantAfterMove)
{
  besedin::Circle circle(5.0, {10.0, 10.0});
  const besedin::rectangle_t frameRectBefore = circle.getFrameRect();
  const double areaBefore = circle.getArea();

  circle.move(5, 5);
  BOOST_CHECK_CLOSE(frameRectBefore.width, circle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.height, circle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, circle.getArea(), EPSILON);

  circle.move({20, 20});
  BOOST_CHECK_CLOSE(frameRectBefore.width, circle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectBefore.height, circle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, circle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(rectangleScaleChange)
{
  besedin::Rectangle rectangle(5.0, 5.0, {10.0, 10.0});
  const double areaBefore = rectangle.getArea();
  const double scale = 2.0;

  rectangle.scale(scale);
  BOOST_CHECK_CLOSE(areaBefore * scale * scale, rectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(circleScaleChange)
{
  besedin::Circle circle(5.0, {10.0, 10.0});
  const double areaBefore = circle.getArea();
  const double scale = 2.0;

  circle.scale(scale);
  BOOST_CHECK_CLOSE(areaBefore * scale * scale, circle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(wrongRectangleParameteresAndScaling)
{
  BOOST_CHECK_THROW(besedin::Rectangle rectangle(-5.0, 5.0, {10.0, 10.0}), std::invalid_argument);
  BOOST_CHECK_THROW(besedin::Rectangle rectangle(5.0, -5.0, {10.0, 10.0}), std::invalid_argument);

  const double scale = -10;
  besedin::Rectangle rectangle(5.0, 5.0, {10.0, 10.0});
  BOOST_CHECK_THROW(rectangle.scale(scale), std::invalid_argument);

}

BOOST_AUTO_TEST_CASE(wrongCircleParameteresAndScaling)
{
  BOOST_CHECK_THROW(besedin::Circle circle(-5.0, {10.0, 10.0}), std::invalid_argument);

  const double scale = -10;
  besedin::Circle circle(5.0, {10.0, 10.0});
  BOOST_CHECK_THROW(circle.scale(scale), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
