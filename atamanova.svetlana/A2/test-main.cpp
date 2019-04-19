#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>

#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testSuiteForShapes)

const double accuracy = 0.001;

BOOST_AUTO_TEST_CASE(immutabilityCircleAfterMoving)
{
  atamanova::Circle testCircle({5.0, 5.0}, 4.0);
  const atamanova::rectangle_t rectBeforeMoving = testCircle.getFrameRect();
  const double areaBeforeMoving = testCircle.getArea();

  testCircle.move({5.0, 5.0});
  atamanova::rectangle_t rectAfterMoving = testCircle.getFrameRect();
  double areaAfterMoving = testCircle.getArea();
  BOOST_CHECK_CLOSE(rectBeforeMoving.width, rectAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(rectBeforeMoving.height, rectAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);

  testCircle.move(5.0, 5.0);
  rectAfterMoving = testCircle.getFrameRect();
  areaAfterMoving = testCircle.getArea();
  BOOST_CHECK_CLOSE(rectBeforeMoving.width, rectAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(rectBeforeMoving.height, rectAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);
}

BOOST_AUTO_TEST_CASE(immutabilityRectangleAfterMoving)
{
  atamanova::Rectangle testRectangle({5.0, 5.0}, 4.0, 4.0);
  const atamanova::rectangle_t rectBeforeMoving = testRectangle.getFrameRect();
  const double areaBeforeMoving = testRectangle.getArea();

  testRectangle.move({5.0, 5.0});
  atamanova::rectangle_t rectAfterMoving = testRectangle.getFrameRect();
  double areaAfterMoving = testRectangle.getArea();
  BOOST_CHECK_CLOSE(rectBeforeMoving.width, rectAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(rectBeforeMoving.height, rectAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);

  testRectangle.move(5.0, 5.0);
  rectAfterMoving = testRectangle.getFrameRect();
  areaAfterMoving = testRectangle.getArea();
  BOOST_CHECK_CLOSE(rectBeforeMoving.width, rectAfterMoving.width, accuracy);
  BOOST_CHECK_CLOSE(rectBeforeMoving.height, rectAfterMoving.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMoving, areaAfterMoving, accuracy);
}

BOOST_AUTO_TEST_CASE(checkAreaOfCircleAfterScaling)
{
  atamanova::Circle testCircle({5.0, 5.0}, 4.0);
  const double areaBeforeScaling = testCircle.getArea();
  const double coefficientScale = 2.0;
  testCircle.scale(coefficientScale);
  double areaAfterScaling = testCircle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * coefficientScale * coefficientScale, areaAfterScaling, accuracy);
}

BOOST_AUTO_TEST_CASE(checkAreaOfRectangleAfterScaling)
{
  atamanova::Rectangle testRectangle({5.0, 5.0}, 4.0, 4.0);
  const double areaBeforeScaling = testRectangle.getArea();
  const double coefficientScale = 3.0;
  testRectangle.scale(coefficientScale);
  double areaAfterScaling = testRectangle.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * coefficientScale * coefficientScale, areaAfterScaling, accuracy);
}

BOOST_AUTO_TEST_CASE(incorrectFunctionParametersRectangle)
{
  BOOST_CHECK_THROW(atamanova::Rectangle({6.0, 3.0}, -4.0, 6.0), std::invalid_argument);
  BOOST_CHECK_THROW(atamanova::Rectangle({5.0, -3.0}, -4.0, -6.0), std::invalid_argument);

  atamanova::Rectangle testRect1({1.0, 1.0}, 1.0, 1.0);
  BOOST_CHECK_THROW(testRect1.scale(-1.0), std::invalid_argument);

  atamanova::Rectangle testRect2({1.0, 1.0}, 1.0, 1.0);
  BOOST_CHECK_THROW(testRect2.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(incorrrectFunctionParametersCircle)
{
  BOOST_CHECK_THROW(atamanova::Circle({2.0, 3.0}, -2.0), std::invalid_argument);
  BOOST_CHECK_THROW(atamanova::Circle({2.0, -2.0}, -1.0), std::invalid_argument);

  atamanova::Circle testCircle1({1.0, 1.0}, 1.0);
  BOOST_CHECK_THROW(testCircle1.scale(-2.0), std::invalid_argument);

  atamanova::Circle testCircle2({1.0, 1.0}, 1.0);
  BOOST_CHECK_THROW(testCircle2.scale(-1.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
