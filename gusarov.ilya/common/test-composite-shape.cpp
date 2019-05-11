#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "triangle.hpp"


BOOST_AUTO_TEST_SUITE(testsForCompShape)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  gusarov::Rectangle testingRect({4.0, 6.0}, 2.0, 4.0);
  gusarov::Circle testingCirc({1.0, 2.0}, 1.0);
  gusarov::CompositeShape testingCompShape(testingRect);
  testingCompShape.addNewShape(testingCirc);

  const gusarov::rectangle_t testingFrameRect = testingCompShape.getFrameRect();
  const double testingArea = testingCompShape.getArea();

  const double width = testingFrameRect.width;
  const double height = testingFrameRect.height;

  testingCompShape.move(5.0, 5.5);
  BOOST_CHECK_CLOSE(testingCompShape.getFrameRect().width, width, EPSILON);
  BOOST_CHECK_CLOSE(testingCompShape.getFrameRect().height, height, EPSILON);
  BOOST_CHECK_CLOSE(testingCompShape.getArea(), testingArea, EPSILON);

  testingCompShape.move({10.0, 12.0});
  BOOST_CHECK_CLOSE(testingCompShape.getFrameRect().width, width, EPSILON);
  BOOST_CHECK_CLOSE(testingCompShape.getFrameRect().height, height, EPSILON);
  BOOST_CHECK_CLOSE(testingCompShape.getArea(), testingArea, EPSILON);
}
BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  gusarov::Rectangle testingRect({4.0, 6.0}, 2.0, 4.0);
  gusarov::Circle testingCirc({1.0, 2.0}, 1.0);
  gusarov::CompositeShape testingCompShape(testingRect);
  testingCompShape.addNewShape(testingCirc);

  const double area = testingCompShape.getArea();
  const double scale = 3.0;
  testingCompShape.scale(scale);
  BOOST_CHECK_CLOSE(testingCompShape.getArea(), area * scale * scale, EPSILON);
}
BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  gusarov::Rectangle testingRect({4.0, 6.0}, 2.0, 4.0);
  gusarov::Circle testingCirc({1.0, 2.0}, 1.0);
  gusarov::CompositeShape testingCompShape(testingRect);
  testingCompShape.addNewShape(testingCirc);

  BOOST_CHECK_THROW(testingCompShape.scale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(testingCompShape.deleteShape(5), std::out_of_range);
  BOOST_CHECK_THROW(testingCompShape[3], std::out_of_range);

  gusarov::CompositeShape testingNewCompShape;
  BOOST_CHECK_THROW(testingNewCompShape.getFrameRect(), std::logic_error);
  BOOST_CHECK_THROW(testingNewCompShape.getArea(), std::logic_error);
}
BOOST_AUTO_TEST_CASE(testCopyConstructor)
{
  gusarov::Rectangle testingRect({4.0, 6.0}, 2.0, 4.0);
  gusarov::Circle testingCirc({1.0, 2.0}, 1.0);
  gusarov::CompositeShape testingCompShape(testingRect);
  testingCompShape.addNewShape(testingCirc);
  const gusarov::rectangle_t frameRect = testingCompShape.getFrameRect();

  gusarov::CompositeShape copyCompShape(testingCompShape);
  const gusarov::rectangle_t copyFrameRect = copyCompShape.getFrameRect();

  BOOST_CHECK_CLOSE(testingCompShape.getArea(), copyCompShape.getArea(), EPSILON);
  BOOST_CHECK_EQUAL(testingCompShape.getSize(), copyCompShape.getSize());
  BOOST_CHECK_CLOSE(frameRect.height, copyFrameRect.height, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.width, copyFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.x, copyFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.y, copyFrameRect.pos.y, EPSILON);
}
BOOST_AUTO_TEST_CASE(testMoveConstructor)
{
  gusarov::Rectangle testingRect({4.0, 6.0}, 2.0, 4.0);
  gusarov::Circle testingCirc({1.0, 2.0}, 1.0);
  gusarov::CompositeShape testingCompShape(testingRect);
  testingCompShape.addNewShape(testingCirc);
  const gusarov::rectangle_t frameRect = testingCompShape.getFrameRect();
  const double compositeArea = testingCompShape.getArea();
  const size_t compositeSize = testingCompShape.getSize();

  gusarov::CompositeShape moveCompShape(std::move(testingCompShape));
  const gusarov::rectangle_t moveFrameRect = moveCompShape.getFrameRect();
  BOOST_CHECK_CLOSE(compositeArea, moveCompShape.getArea(), EPSILON);
  BOOST_CHECK_CLOSE(frameRect.height, moveFrameRect.height, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.width, moveFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.x, moveFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.y, moveFrameRect.pos.y, EPSILON);
  BOOST_CHECK_EQUAL(compositeSize, moveCompShape.getSize());
  BOOST_CHECK_EQUAL(testingCompShape.getSize(), 0);

}
BOOST_AUTO_TEST_CASE(testMoveOperator)
{
  gusarov::Rectangle testingRect({4.0, 6.0}, 2.0, 4.0);
  gusarov::Circle testingCirc({1.0, 2.0}, 1.0);
  gusarov::CompositeShape testingCompShape(testingRect);
  testingCompShape.addNewShape(testingCirc);
  const gusarov::rectangle_t frameRect = testingCompShape.getFrameRect();
  const double compositeArea = testingCompShape.getArea();
  const size_t compositeSize = testingCompShape.getSize();

  gusarov::Triangle testingTri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
  gusarov::CompositeShape moveCompShape(testingTri);
  moveCompShape = std::move(testingCompShape);
  const gusarov::rectangle_t moveFrameRect = moveCompShape.getFrameRect();
  BOOST_CHECK_CLOSE(compositeArea, moveCompShape.getArea(), EPSILON);
  BOOST_CHECK_CLOSE(frameRect.height, moveFrameRect.height, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.width, moveFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.x, moveFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.y, moveFrameRect.pos.y, EPSILON);
  BOOST_CHECK_EQUAL(compositeSize, moveCompShape.getSize());
  BOOST_CHECK_EQUAL(testingCompShape.getSize(), 0);
}
BOOST_AUTO_TEST_CASE(testCopyOperator)
{
  gusarov::Rectangle testingRect({4.0, 6.0}, 2.0, 4.0);
  gusarov::Circle testingCirc({1.0, 2.0}, 1.0);
  gusarov::CompositeShape testingCompShape(testingRect);
  testingCompShape.addNewShape(testingCirc);
  const gusarov::rectangle_t frameRect = testingCompShape.getFrameRect();

  gusarov::Triangle testingTri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
  gusarov::CompositeShape copyCompShape(testingTri);
  copyCompShape = testingCompShape;
  const gusarov::rectangle_t copyFrameRect = copyCompShape.getFrameRect();
  BOOST_CHECK_CLOSE(testingCompShape.getArea(), copyCompShape.getArea(), EPSILON);
  BOOST_CHECK_EQUAL(testingCompShape.getSize(), copyCompShape.getSize());
  BOOST_CHECK_CLOSE(frameRect.height, copyFrameRect.height, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.width, copyFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.x, copyFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(frameRect.pos.y, copyFrameRect.pos.y, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END();
