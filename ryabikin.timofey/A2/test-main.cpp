#define BOOST_TEST_MODULE
#include "rectangle.hpp"
#include "circle.hpp"
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

BOOST_AUTO_TEST_SUITE(TestCircle)

const double fault = 0.001;

BOOST_AUTO_TEST_CASE(TestCircleMoved)
{
  ryabikin::Circle circle(5.00, { 16.00, 16.00 });
  const double AreaBeforeMove = circle.getArea();
  const ryabikin::rectangle_t frameBeforeMove = circle.getFrameRect();
  circle.move(3.2, 5.0);
  const double AreaAfterMove = circle.getArea();
  const ryabikin::rectangle_t frameAfterMove = circle.getFrameRect();
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBeforeMove, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestCircleMovedPos)
{
  ryabikin::Circle circle(5.00, { 16.00, 16.00 });
  const double AreaBeforeMove = circle.getArea();
  const ryabikin::rectangle_t frameBeforeMove = circle.getFrameRect();
  circle.move({ 3.2, 5.00 });
  const double AreaAfterMove = circle.getArea();
  const ryabikin::rectangle_t frameAfterMove = circle.getFrameRect();
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBeforeMove, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestCircleScaled)
{
  ryabikin::Circle circle(5.00, { 16.00, 16.00 });
  const double AreaBeforeScale = circle.getArea();
  const double coefficient = 2.0;
  const double multipler = coefficient * coefficient;
  circle.scale(coefficient);
  const double AreaAfterScale = circle.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScale * multipler, AreaAfterScale, fault);
}

BOOST_AUTO_TEST_CASE(TestCircleParametrs)
{
  BOOST_CHECK_THROW(ryabikin::Circle circle(-1.00, { 16.00, 16.00 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestCircleScaleCoefficient)
{
  ryabikin::Circle circle(5.00, { 16.00, 16.00 });
  BOOST_CHECK_THROW(c1.scale(-1.00), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(TestRectangle)

const double fault = 0.001;

BOOST_AUTO_TEST_CASE(TestRectangleMoved)
{
  ryabikin::Rectangle rectangle(5.00, 7.00, { 15.00, 15.00 });
  const double AreaBeforeMove = rectangle.getArea();
  const ryabikin::rectangle_t frameBeforeMove = rectangle.getFrameRect();
  rectangle.move(3.5, 5.00);
  const double AreaAfterMove = rectangle.getArea();
  const ryabikin::rectangle_t frameAfterMove = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBeforeMove, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestRectangleMovedPos)
{
  ryabikin::Rectangle rectangle(5.00, 7.00, { 15.00, 15.00 });
  const double AreaBeforeMove = rectangle.getArea();
  const ryabikin::rectangle_t frameBefore = rectangle.getFrameRect();
  rectangle.move({ 3.5, 5.00 });
  const double AreaAfterMove = rectangle.getArea();
  const ryabikin::rectangle_t frameAfterMove = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBeforeMove, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestRectangleScaled)
{
  ryabikin::Rectangle rectangle(5.00, 7.00, { 15.00, 15.00 });
  const double AreaBeforeScale = rectangle.getArea();
  const double coefficient = 2.0;
  const double multipler = coefficient * coefficient;
  rectangle.scale(coefficient);
  const double AreaAfterScale = rectangle.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScale * multipler, AreaAfterScale, fault);
}

BOOST_AUTO_TEST_CASE(TestRectangleParametrs)
{
  BOOST_CHECK_THROW(ryabikin::Rectangle rectangle(-1.00, 5.00, { 15.00, 15.00 }), std::invalid_argument);
  BOOST_CHECK_THROW(ryabikin::Rectangle rectangle(5.00, -1.00, { 15.00, 15.00 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestRectangleScaleCoefficient)
{
  ryabikin::Rectangle rectangle(5.00, 7.00, { 15.00, 15.00 });
  BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
