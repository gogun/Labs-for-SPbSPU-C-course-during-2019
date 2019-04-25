#define BOOST_TEST_MODULE A3
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

const double fault = 0.01;

BOOST_AUTO_TEST_SUITE(figuresTests)

BOOST_AUTO_TEST_CASE(compositeShapeConstancyOfParameters)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.addShape(circ);
  const double areaBeforeMoving = compSh.getArea();
  const shestakova::rectangle_t frameRectBeforeMoving = compSh.getFrameRect();
  compSh.move(3, 5);
  shestakova::rectangle_t frameRectAfterMoving = compSh.getFrameRect();
  double areaAfterMoving = compSh.getArea();

  BOOST_CHECK_CLOSE(areaAfterMoving, areaBeforeMoving, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, fault);

  compSh.move({3, 4});
  frameRectAfterMoving = compSh.getFrameRect();
  areaAfterMoving = compSh.getArea();

  BOOST_CHECK_CLOSE(areaAfterMoving, areaBeforeMoving, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, fault);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, fault);

}

BOOST_AUTO_TEST_CASE(compositeShapeScale)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.addShape(circ);
  const double areaBeforeScale = compSh.getArea();
  const int scaleCoefficient = 3;
  compSh.scale(scaleCoefficient);
  double areaAfterScale = compSh.getArea();

  BOOST_CHECK_CLOSE(areaBeforeScale * scaleCoefficient * scaleCoefficient, areaAfterScale, fault);
}

BOOST_AUTO_TEST_CASE(compositeShapeAreaAfterAddAndDelete)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  const double compShAreaBeforeAdd = compSh.getArea();
  const double rectArea = rect.getArea();
  const double circArea = circ.getArea();

  compSh.addShape(circ);
  double compShAreaAfterAdd = compSh.getArea();
  BOOST_CHECK_CLOSE(compShAreaBeforeAdd + circArea, compShAreaAfterAdd, fault);

  compSh.deleteShape(0);
  BOOST_CHECK_CLOSE(compShAreaAfterAdd - rectArea, compSh.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(compositeShapeIncorrectParameters)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.addShape(circ);

  BOOST_CHECK_THROW(compSh.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
