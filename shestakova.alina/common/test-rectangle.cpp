#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"

const double fault = 0.01;

BOOST_AUTO_TEST_SUITE(rectangleTests)

BOOST_AUTO_TEST_CASE(rectangleConstancyOfParameters)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  const double areaBeforeMoving = rect.getArea();
  const shestakova::rectangle_t frameRectBeforeMoving = rect.getFrameRect();
  rect.move(3, 5);
  shestakova::rectangle_t frameRectAfterMoving = rect.getFrameRect();
  double areaAfterMoving = rect.getArea();

  BOOST_CHECK_CLOSE(areaAfterMoving, areaBeforeMoving, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, fault);

  rect.move({3, 4});
  frameRectAfterMoving = rect.getFrameRect();
  areaAfterMoving = rect.getArea();

  BOOST_CHECK_CLOSE(areaAfterMoving, areaBeforeMoving, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, fault);
}

BOOST_AUTO_TEST_CASE(rectangleScale)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  const double areaBeforeScale = rect.getArea();
  const int scaleCoefficient = 3;
  rect.scale(scaleCoefficient);
  double areaAfterScale = rect.getArea();

  BOOST_CHECK_CLOSE(areaBeforeScale * scaleCoefficient * scaleCoefficient, areaAfterScale, fault);
}

BOOST_AUTO_TEST_CASE(rectangleIncorrectParameters)
{
  BOOST_CHECK_THROW(shestakova::Rectangle({4, 7}, -2, -12), std::invalid_argument);

  shestakova::Rectangle rect({4, 7}, 2, 12);
  BOOST_CHECK_THROW(rect.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
