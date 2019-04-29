#define BOOST_TEST_MODULE

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double TOLERANCE = 0.01; // tolerance in percents

BOOST_AUTO_TEST_SUITE(test_A2)

BOOST_AUTO_TEST_CASE(Test_rectangle_area)
{
  dyu::Rectangle testRect(3.0, 6.0, {10.0, 10.0});
  const double areaBeforeMoving = testRect.getArea();
  const dyu::rectangle_t frameBeforeMove = testRect.getFrameRect();
  
  testRect.move({0, 0});
  
  double areaAfterMoving = testRect.getArea();
  dyu::rectangle_t frameAfterMoving = testRect.getFrameRect();
  
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMoving.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMoving.height, TOLERANCE);
  
  testRect.move(4, 5);

  areaAfterMoving = testRect.getArea();
  frameAfterMoving = testRect.getFrameRect();
  
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMoving.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMoving.height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(Test_rectangle_scale)
{
  dyu::Rectangle testRect(3.0, 6.0, {10.0, 10.0});
  const double areaBeforeScaling = testRect.getArea();
  
  const double coeficient = 2;
  testRect.scale(coeficient);
  
  const double areaAfterScaling = testRect.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * coeficient * coeficient, areaAfterScaling, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(Test_rectangle_constructor_fail_throw)
{
  BOOST_CHECK_THROW(dyu::Rectangle rect(-3.0, 6.0, {10.0, 10.0}), std::invalid_argument);
  BOOST_CHECK_THROW(dyu::Rectangle rect(3.0, -6.0, {10.0, 10.0}), std::invalid_argument);
  BOOST_CHECK_THROW(dyu::Rectangle rect(-3.0, -6.0, {10.0, 10.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Test_scale_rectangle_negativer_fail_throw)
{
  dyu::Rectangle testRect(3.0, 6.0, {10.0, 10.0});
  BOOST_CHECK_THROW(testRect.scale(-1.0), std::invalid_argument);
}


BOOST_AUTO_TEST_CASE(Test_circle_area)
{
  dyu::Circle testCircle(3.0, {10.0, 10.0});
  const double areaBeforeMoving = testCircle.getArea ();
  const dyu::rectangle_t frameBeforeMoving = testCircle.getFrameRect ();
  
  testCircle.move({0, 0});
  
  double areaAfterMoving = testCircle.getArea();
  dyu::rectangle_t frameAfterMoving = testCircle.getFrameRect();
  
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMoving.width, frameAfterMoving.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMoving.height, frameAfterMoving.height, TOLERANCE);
  
  testCircle.move(4, 5);
  
  areaAfterMoving = testCircle.getArea();
  frameAfterMoving = testCircle.getFrameRect();
  
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMoving.width, frameAfterMoving.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBeforeMoving.height, frameAfterMoving.height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(Test_circle_scale)
{
  dyu::Circle testCircle(3.0, {10.0, 10.0});
  const double areaBeforeScaling = testCircle.getArea();
  
  const double coeficient = 2;
  testCircle.scale(coeficient);
  
  const double areaAfterScaling = testCircle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * coeficient * coeficient, areaAfterScaling, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(Test_circle_constructor_fail_throw)
{
  BOOST_CHECK_THROW(dyu::Circle circle(-3.0, {3.0, 2.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Test_scale_circle_negativer_fail_throw)
{
  dyu::Circle testCircle(3.0, {10.0, 10.0});
  BOOST_CHECK_THROW(testCircle.scale(-1.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
