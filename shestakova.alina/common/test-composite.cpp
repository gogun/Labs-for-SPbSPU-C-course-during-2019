#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

const double fault = 0.01;

BOOST_AUTO_TEST_SUITE(compositeTests)

BOOST_AUTO_TEST_CASE(compositeShapeConstancyOfParameters)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.add(circ);
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

BOOST_AUTO_TEST_CASE(compositeShapeScaleCoefficientMoreThanOne)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.add(circ);
  const shestakova::rectangle_t frameBeforeScale = compSh.getFrameRect();
  const int coefMoreThanOne = 3;
  compSh.scale(coefMoreThanOne);
  shestakova::rectangle_t frameAfterScale = compSh.getFrameRect();

  BOOST_CHECK_CLOSE(frameBeforeScale.height * coefMoreThanOne, frameAfterScale.height, fault);
  BOOST_CHECK_CLOSE(frameBeforeScale.width * coefMoreThanOne, frameAfterScale.width, fault);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.x, frameAfterScale.pos.x, fault);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.y, frameAfterScale.pos.y, fault);
  BOOST_CHECK(frameBeforeScale.height < frameAfterScale.height);
  BOOST_CHECK(frameBeforeScale.width < frameAfterScale.width);
}

BOOST_AUTO_TEST_CASE(compositeShapeScaleCoefficientLessThanOne)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.add(circ);
  const shestakova::rectangle_t frameBeforeScale = compSh.getFrameRect();
  const double coefLessThanOne = 0.3;
  compSh.scale(coefLessThanOne);
  shestakova::rectangle_t frameAfterScale = compSh.getFrameRect();

  BOOST_CHECK_CLOSE(frameBeforeScale.height * coefLessThanOne, frameAfterScale.height, fault);
  BOOST_CHECK_CLOSE(frameBeforeScale.width * coefLessThanOne, frameAfterScale.width, fault);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.x, frameAfterScale.pos.x, fault);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.y, frameAfterScale.pos.y, fault);
  BOOST_CHECK(frameBeforeScale.height > frameAfterScale.height);
  BOOST_CHECK(frameBeforeScale.width > frameAfterScale.width);
}

BOOST_AUTO_TEST_CASE(compositeShapeIncorrectScaleParameter)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.add(circ);

  BOOST_CHECK_THROW(compSh.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compositeShapeAreaAfterAddAndDelete)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  const double compShAreaBeforeAdd = compSh.getArea();
  const double rectArea = rect.getArea();
  const double circArea = circ.getArea();

  compSh.add(circ);
  double compShAreaAfterAdd = compSh.getArea();
  BOOST_CHECK_CLOSE(compShAreaBeforeAdd + circArea, compShAreaAfterAdd, fault);

  compSh.remove(0);
  BOOST_CHECK_CLOSE(compShAreaAfterAdd - rectArea, compSh.getArea(), fault);
}

BOOST_AUTO_TEST_CASE(compositeShapeThrowingExeptions)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(rect);
  compSh.add(circ);

  BOOST_CHECK_THROW(compSh.remove(10), std::invalid_argument);
  BOOST_CHECK_THROW(compSh.remove(-10), std::invalid_argument);

  BOOST_CHECK_THROW(compSh[2], std::out_of_range);
  BOOST_CHECK_THROW(compSh[-2], std::out_of_range);

  compSh.remove(1);
  BOOST_CHECK_THROW(compSh[1], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(emptyCompositeShapeThrowingExeptions)
{
  shestakova::CompositeShape emptyCompSh;

  BOOST_CHECK_THROW(emptyCompSh.move(3, 5), std::logic_error);
  BOOST_CHECK_THROW(emptyCompSh.move({1, 1}), std::logic_error);
  BOOST_CHECK_THROW(emptyCompSh.getFrameRect(), std::logic_error);
  BOOST_CHECK_THROW(emptyCompSh.scale(2), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()
