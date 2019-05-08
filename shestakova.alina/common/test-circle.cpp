#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"

const double FAULT = 0.01;

BOOST_AUTO_TEST_SUITE(circleTests)

BOOST_AUTO_TEST_CASE(circleConstancyOfParameters)
{
  shestakova::Circle circ({2, 1}, 10);
  const double areaBeforeMoving = circ.getArea();
  const shestakova::rectangle_t frameRectBeforeMoving = circ.getFrameRect();
  circ.move({3, 5});
  shestakova::rectangle_t frameRectAfterMoving = circ.getFrameRect();
  double areaAfterMoving = circ.getArea();

  BOOST_CHECK_CLOSE(areaAfterMoving, areaBeforeMoving, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(circleScale)
{
  shestakova::Circle circ({2, 1}, 10);
  const double areaBeforeScale = circ.getArea();
  const double scaleCoefficient = 1.5;
  circ.scale(scaleCoefficient);
  double areaAfterScale = circ.getArea();

  BOOST_CHECK_CLOSE(areaBeforeScale * scaleCoefficient * scaleCoefficient, areaAfterScale, FAULT);
}

BOOST_AUTO_TEST_CASE(circleIncorrectParameters)
{
  BOOST_CHECK_THROW(shestakova::Circle({2, 1}, -10), std::invalid_argument);

  shestakova::Circle circ({2, 1}, 10);
  BOOST_CHECK_THROW(circ.scale(-1.5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
