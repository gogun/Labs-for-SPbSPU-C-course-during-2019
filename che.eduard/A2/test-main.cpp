#define BOOST_TEST_MODULE
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double ACCURACY = 0.0001;

BOOST_AUTO_TEST_SUITE(Circle_Suite_Testing)

BOOST_AUTO_TEST_CASE(Circle_Immutability_After_Moving)
{
  che::Circle testCircle({ 2.0, 3.5 }, 1.5);
  const che::rectangle_t RectBeforeMoving = testCircle.getFrameRect();
  const double AreaBeforeMoving = testCircle.getArea();
  circle.move(1.5, 3.0);
  che::rectangle_t RectAfterMoving
  BOOST_CHECK_EQUAL(RectBeforeMoving.width, testCircle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_EQUAL(RectBeforeMoving.height, testCircle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(AreaBeforeMoving, testCircle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(Circle_Scale_Tetsting)
{
  che:Circle testCircle({ 2.0, 3.5 }, 1.5);
  const double AreaBeforeScaling = testCircle.getArea();
  const double circle.coef = 1.8;
  testCircle.scale(circle.coef);
  BOOST_CHECK_CLOSE(testCircle.getArea(), AreaBeforeScaling * circle.coef * circle.coef, ACCURACY);
}

BOOST_AUTO_TEST_CASE(Circle_Invalid_Values)
{
  BOOST_CHECK_THROW(che::Circle({ 2.0,3.5 }, -1.5), std::invalid_argument);
  che::Circle testCircle1({ 3.0, 3.0 }, 2.0);
  BOOST_CHECK_THROW(wrongCircle1.scale(-3.0), std::invalid_argument);
  che::Circle testCircle2({ 2.0, 2.0 }, 3.0);
  BOOST_CHECK_THROW(wrongCircle1.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Rectangle_Suite_Testing)
{
  che::Rectangle testRectangle({ 4.0, 9.0 }, 2.0, 4.0);
  const double AreaBeforeMoving = testRectangle.getArea();
  const che::rectangle_t FrameBeforeMoving = testRectangle.getFrameRect();
  testRectangle.move(2.0, 3.0);
  che::rectangle_t AreaAfterMoving = testRectangle.getFrameRect();
  BOOST_CHECK_EQUAL(AreaAfterMoving.height, AreaBeforeMoving.height);
  BOOST_CHECK_EQUAL(AreaAfterMoving.width, AreaBeforeMoving.width);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), AreaBeforeMoving, ACCURACY);
}
BOOST_AUTO_TEST_CASE(Rectangle_Scale_Testing)
{
  che::Rectangle rec({ 4.0, 9.0 }, 2.0, 5.0);
  const double AreaBeforeScaling = rec.getArea();
  rec.coef(2.2);
  const double AreaAfterScaling = rec.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScaling * AreaBeforeScaling, AreaAfterScaling, ACCURACY);
}
BOOST_AUTO_TEST_CASE(Rectangle_Invalid_Values)
{
  BOOST_CHECK_THROW(che::Rectangle({ 2.0, 4.0 }, -3.0, 5.0), std::invalid_argument);
  che::Rectangle testRectangle({ 2.0, 2.0 }, 5.0, 10.0);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

