#define BOOST_TEST_MODULE
#include <stdexcept>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double ACCURACY = 0.0001;

BOOST_AUTO_TEST_SUITE(Circle_Suite_Testing)

BOOST_AUTO_TEST_CASE(Circle_Immutability_After_Moving)
{
  che::Circle testCircle({ 2.0, 3.5 }, 1.5);
  const che::rectangle_t CircleBeforeMoving = testCircle.getFrameRect();
  const double AreaBeforeMoving = testCircle.getArea();
  testCircle.move(1.5, 3.0);
  BOOST_CHECK_CLOSE(CircleBeforeMoving.width, testCircle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(CircleBeforeMoving.height, testCircle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(AreaBeforeMoving, testCircle.getArea(), ACCURACY);

  testCircle.move({ 3.5, 1.2 });
  BOOST_CHECK_CLOSE(CircleBeforeMoving.width, testCircle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(CircleBeforeMoving.height, testCircle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(AreaBeforeMoving, testCircle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(Circle_Scale_Tetsting)
{
  che::Circle testCircle({ 2.0, 3.5 }, 1.5);
  const double AreaBeforeScaling = testCircle.getArea();
  testCircle.scale(1.8);
  double AreaAfterScaling = testCircle.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScaling * AreaBeforeScaling, AreaAfterScaling, ACCURACY);
}

BOOST_AUTO_TEST_CASE(Circle_Invalid_Values)
{
  BOOST_CHECK_THROW(che::Circle({ 2.0,3.0 }, -1.5), std::invalid_argument);
  che::Circle testCircle1({ 3.0, 3.0 }, 2.0);
  BOOST_CHECK_THROW(testCircle1.scale(-3.0), std::invalid_argument);
  che::Circle testCircle2({ 2.0, 2.0 }, 3.0);
  BOOST_CHECK_THROW(testCircle1.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Rectangle_Suite_Testing)

BOOST_AUTO_TEST_CASE(Rectangle_Immutability_After_Moving)
{
  che::Rectangle testRectangle({ 4.0, 9.0 }, 2.0, 4.0);
  const che::rectangle_t FrameBeforeMoving = testRectangle.getFrameRect();
  const double  AreaBeforeMoving = testRectangle.getArea();
  testRectangle.move(2.0, 3.0);
  BOOST_CHECK_CLOSE(AreaBeforeMoving.height, testRectangle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(AreaBeforeMoving.width, testRectangle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(FrameBeforeMoving, testRectangle.getArea(), ACCURACY);

  testRectangle.move({ 2.0, 4.0 });
  BOOST_CHECK_CLOSE(AreaBeforeMoving.width, testRectangle.getFrameRect().width, ACCURACY);
  BOOST_CHECK_CLOSE(AreaBeforeMoving.height, testRectangle.getFrameRect().height, ACCURACY);
  BOOST_CHECK_CLOSE(FrameBeforeMoving, testRectangle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(Rectangle_Scale_Testing)
{
  che::Rectangle testRectangle({ 4.0, 9.0 }, 2.0, 5.0);
  const double AreaBeforeScaling = testRectangle.getArea();
  testRectangle.scale(2.2);
  const double AreaAfterScaling = testRectangle.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScaling * AreaBeforeScaling, AreaAfterScaling, ACCURACY);
}

BOOST_AUTO_TEST_CASE(Rectangle_Invalid_Values)
{
  BOOST_CHECK_THROW(che::Rectangle testRectangle({ 2.0, 4.0 }, -3.0, 5.0), std::invalid_argument);
  che::Rectangle testRectangle({ 2.0, 2.0 }, 5.0, 10.0);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

