#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

const double FAULT = 0.01;

BOOST_AUTO_TEST_SUITE(compositeTests)

BOOST_AUTO_TEST_CASE(compositeShapeCopyConstructor)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);
  const shestakova::rectangle_t frameRect = compSh.getFrameRect();

  shestakova::CompositeShape copyCompSh(compSh);
  const shestakova::rectangle_t copyFrameRect = copyCompSh.getFrameRect();
  BOOST_CHECK_CLOSE(frameRect.height, copyFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, copyFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, copyFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, copyFrameRect.pos.y, FAULT);
  BOOST_CHECK_CLOSE(compSh.getArea(), copyCompSh.getArea(), FAULT);
  BOOST_CHECK_EQUAL(compSh.getCount(), copyCompSh.getCount());
}

BOOST_AUTO_TEST_CASE(compositeShapeCopyOperator)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);
  const shestakova::rectangle_t frameRect = compSh.getFrameRect();

  shestakova::CompositeShape copyCompSh(&rect);
  copyCompSh = compSh;
  const shestakova::rectangle_t copyFrameRect = copyCompSh.getFrameRect();
  BOOST_CHECK_CLOSE(frameRect.height, copyFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, copyFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, copyFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, copyFrameRect.pos.y, FAULT);
  BOOST_CHECK_CLOSE(compSh.getArea(), copyCompSh.getArea(), FAULT);
  BOOST_CHECK_EQUAL(compSh.getCount(), copyCompSh.getCount());
}

BOOST_AUTO_TEST_CASE(compositeShapeMoveConstructor)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);
  const shestakova::rectangle_t frameRect = compSh.getFrameRect();
  const double compShArea = compSh.getArea();
  const int compShCount = compSh.getCount();

  shestakova::CompositeShape moveCompSh(std::move(compSh));
  const shestakova::rectangle_t moveFrameRect = moveCompSh.getFrameRect();

  BOOST_CHECK_CLOSE(frameRect.height, moveFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, moveFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, moveFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, moveFrameRect.pos.y, FAULT);
  BOOST_CHECK_CLOSE(compShArea, moveCompSh.getArea(), FAULT);
  BOOST_CHECK_EQUAL(compShCount, moveCompSh.getCount());
  BOOST_CHECK_CLOSE(compSh.getArea(), 0, FAULT);
  BOOST_CHECK_EQUAL(compSh.getCount(), 0);
}

BOOST_AUTO_TEST_CASE(compositeShapeMoveOperator)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);
  const shestakova::rectangle_t frameRect = compSh.getFrameRect();
  const double compShArea = compSh.getArea();
  const int compShCount = compSh.getCount();

  shestakova::CompositeShape moveCompSh(&rect);
  moveCompSh = std::move(compSh);
  const shestakova::rectangle_t moveFrameRect = moveCompSh.getFrameRect();
  BOOST_CHECK_CLOSE(frameRect.height, moveFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, moveFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, moveFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, moveFrameRect.pos.y, FAULT);
  BOOST_CHECK_CLOSE(compShArea, moveCompSh.getArea(), FAULT);
  BOOST_CHECK_EQUAL(compShCount, moveCompSh.getCount());
  BOOST_CHECK_EQUAL(compSh.getCount(), 0);
  BOOST_CHECK_CLOSE(compSh.getArea(), 0, FAULT);
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionAfterUseingOfOperator)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);

  BOOST_CHECK_THROW(compSh[2], std::out_of_range);
  BOOST_CHECK_THROW(compSh[-2], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionNullPtr)
{
  BOOST_CHECK_THROW(shestakova::CompositeShape(nullptr), std::invalid_argument);

  shestakova::Rectangle rect({-7.1, 13.2}, 0.1, 2.8);
  shestakova::CompositeShape testComposite(&rect);

  BOOST_CHECK_THROW(testComposite.add(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compositeShapeConstancyOfParameters)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);
  const double areaBeforeMoving = compSh.getArea();
  const shestakova::rectangle_t frameRectBeforeMoving = compSh.getFrameRect();
  compSh.move(3, 5);
  shestakova::rectangle_t frameRectAfterMoving = compSh.getFrameRect();
  double areaAfterMoving = compSh.getArea();

  BOOST_CHECK_CLOSE(areaAfterMoving, areaBeforeMoving, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, FAULT);

  compSh.move({3, 4});
  frameRectAfterMoving = compSh.getFrameRect();
  areaAfterMoving = compSh.getArea();

  BOOST_CHECK_CLOSE(areaAfterMoving, areaBeforeMoving, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(compositeShapeScaleCoefficientMoreThanOne)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);
  const shestakova::rectangle_t frameBeforeScale = compSh.getFrameRect();
  const int coefMoreThanOne = 3;
  compSh.scale(coefMoreThanOne);
  shestakova::rectangle_t frameAfterScale = compSh.getFrameRect();

  BOOST_CHECK_CLOSE(frameBeforeScale.height * coefMoreThanOne, frameAfterScale.height, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeScale.width * coefMoreThanOne, frameAfterScale.width, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.x, frameAfterScale.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.y, frameAfterScale.pos.y, FAULT);
  BOOST_CHECK(frameBeforeScale.height < frameAfterScale.height);
  BOOST_CHECK(frameBeforeScale.width < frameAfterScale.width);
}

BOOST_AUTO_TEST_CASE(compositeShapeScaleCoefficientLessThanOne)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);
  const shestakova::rectangle_t frameBeforeScale = compSh.getFrameRect();
  const double coefLessThanOne = 0.3;
  compSh.scale(coefLessThanOne);
  shestakova::rectangle_t frameAfterScale = compSh.getFrameRect();

  BOOST_CHECK_CLOSE(frameBeforeScale.height * coefLessThanOne, frameAfterScale.height, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeScale.width * coefLessThanOne, frameAfterScale.width, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.x, frameAfterScale.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeScale.pos.y, frameAfterScale.pos.y, FAULT);
  BOOST_CHECK(frameBeforeScale.height > frameAfterScale.height);
  BOOST_CHECK(frameBeforeScale.width > frameAfterScale.width);
}

BOOST_AUTO_TEST_CASE(compositeShapeIncorrectScaleParameter)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);

  BOOST_CHECK_THROW(compSh.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compositeShapeAreaAfterAddAndDelete)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  const double compShAreaBeforeAdd = compSh.getArea();
  const double rectArea = rect.getArea();
  const double circArea = circ.getArea();

  compSh.add(&circ);
  double compShAreaAfterAdd = compSh.getArea();
  BOOST_CHECK_CLOSE(compShAreaBeforeAdd + circArea, compShAreaAfterAdd, FAULT);

  compSh.remove(0);
  BOOST_CHECK_CLOSE(compShAreaAfterAdd - rectArea, compSh.getArea(), FAULT);
}

BOOST_AUTO_TEST_CASE(compositeShapeThrowingExeptions)
{
  shestakova::Rectangle rect({4, 7}, 2, 12);
  shestakova::Circle circ({2, 1}, 10);
  shestakova::CompositeShape compSh(&rect);
  compSh.add(&circ);

  BOOST_CHECK_THROW(compSh.remove(10), std::invalid_argument);
  BOOST_CHECK_THROW(compSh.remove(-10), std::invalid_argument);

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
