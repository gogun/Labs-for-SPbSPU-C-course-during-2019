#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

const double OFFSET = 0.01;

BOOST_AUTO_TEST_SUITE(testComposite)

BOOST_AUTO_TEST_CASE(compositeShapeTestAreaAndSizeAfterOffset)
{
  kvashnin::Circle testingCircle({0, 0}, 2);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const double testingArea = comShp.getArea();
  const kvashnin::rectangle_t testingFrameBefore = comShp.getFrameRect();
  comShp.move(100, 100);
  const kvashnin::rectangle_t testingFrameAfter = comShp.getFrameRect();
  BOOST_CHECK_CLOSE(comShp.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestAreaAndSizeAfterMoveToPoint)
{
  kvashnin::Circle testingCircle({0, 0}, 2);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const double testingArea = comShp.getArea();
  const kvashnin::rectangle_t testingFrameBefore = comShp.getFrameRect();
  comShp.move({150, 150});
  const kvashnin::rectangle_t testingFrameAfter = comShp.getFrameRect();
  BOOST_CHECK_CLOSE(comShp.getArea(), testingArea, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.width, testingFrameAfter.width, OFFSET);
  BOOST_CHECK_CLOSE(testingFrameBefore.height, testingFrameAfter.height, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestAfterScale)
{
  kvashnin::Circle testingCircle({15, 15}, 10);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const double testingArea = comShp.getArea();
  const double scaleFactor = 2;
  comShp.scale(scaleFactor);
  BOOST_CHECK_CLOSE(comShp.getArea(), testingArea * scaleFactor * scaleFactor, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestFrameRectAreaScale)
{
  kvashnin::Circle testingCircle({0, 0}, 10);
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  comShp.add(&testingCircle);
  const kvashnin::rectangle_t testingRect = comShp.getFrameRect();
  const double scaleFactor = 2;
  comShp.scale(scaleFactor);
  const kvashnin::rectangle_t supposedRect = comShp.getFrameRect();
  BOOST_CHECK_CLOSE(testingRect.width * scaleFactor, supposedRect.width, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.height * scaleFactor, supposedRect.height, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.x, supposedRect.pos.x, OFFSET);
  BOOST_CHECK_CLOSE(testingRect.pos.y, supposedRect.pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestThrowingExceptions)
{
  kvashnin::CompositeShape comShp = kvashnin::CompositeShape();
  BOOST_CHECK_THROW(comShp.getFrameRect(), std::invalid_argument);
  BOOST_CHECK_THROW(comShp.scale(-2), std::invalid_argument);
  BOOST_CHECK_THROW(comShp.add(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(comShp.remove(-2), std::out_of_range);
  BOOST_CHECK_THROW(comShp[-2], std::out_of_range);
  BOOST_CHECK_THROW(kvashnin::CompositeShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestThrowingExceptionsTestCopyConstructor)
{
  kvashnin::Rectangle testRect({1, 0}, 1, 2);
  kvashnin::CompositeShape testCompShape(&testRect);
  kvashnin::Circle testCircle({0, 0}, 3);
  testCompShape.add(&testCircle);
  kvashnin::CompositeShape compShape(testCompShape);

  BOOST_CHECK_CLOSE(compShape.getArea(), testCompShape.getArea(), OFFSET);
  BOOST_CHECK_CLOSE(compShape.getFrameRect().height, testCompShape.getFrameRect().height, OFFSET);
  BOOST_CHECK_CLOSE(compShape.getFrameRect().width, testCompShape.getFrameRect().width, OFFSET);
  BOOST_CHECK_CLOSE(compShape.getFrameRect().pos.x, testCompShape.getFrameRect().pos.x, OFFSET);
  BOOST_CHECK_CLOSE(compShape.getFrameRect().pos.y, testCompShape.getFrameRect().pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestThrowingExceptionsTestMoveConstructor)
{
  kvashnin::Circle testCircle({2, 3}, 1);
  kvashnin::CompositeShape testCompShape(&testCircle);
  kvashnin::Rectangle testRect({3, 0}, 1, 2);
  testCompShape.add(&testRect);
  double areaBefore = testCompShape.getArea();
  kvashnin::rectangle_t frameRectBefore = testCompShape.getFrameRect();
  kvashnin::CompositeShape compShape(std::move(testCompShape));

  BOOST_CHECK_CLOSE(areaBefore, compShape.getArea(), OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.height, compShape.getFrameRect().height, OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.width, compShape.getFrameRect().width, OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.pos.x, compShape.getFrameRect().pos.x, OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.pos.y, compShape.getFrameRect().pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestThrowingExceptionsTestCopyAssignmentOperator)
{
  kvashnin::Circle testCircle1({0, 0}, 2.4);
  kvashnin::CompositeShape testCompShape1(&testCircle1);
  kvashnin::Circle testCircle2({2, 3}, 6);
  testCompShape1.add(&testCircle2);
  kvashnin::CompositeShape testCompShape2(&testCircle1);
  testCompShape2 = testCompShape1;

  BOOST_CHECK_CLOSE(testCompShape1.getArea(), testCompShape2.getArea(), OFFSET);
  BOOST_CHECK_CLOSE(testCompShape1.getFrameRect().height, testCompShape2.getFrameRect().height, OFFSET);
  BOOST_CHECK_CLOSE(testCompShape1.getFrameRect().width, testCompShape2.getFrameRect().width, OFFSET);
  BOOST_CHECK_CLOSE(testCompShape1.getFrameRect().pos.x, testCompShape2.getFrameRect().pos.x, OFFSET);
  BOOST_CHECK_CLOSE(testCompShape1.getFrameRect().pos.y, testCompShape2.getFrameRect().pos.y, OFFSET);
}

BOOST_AUTO_TEST_CASE(compositeShapeTestThrowingExceptionsTestMoveAssignmentOperator)
{
  kvashnin::Rectangle testRect1({{0, 0}, 1, 2});
  kvashnin::CompositeShape testCompShape1(&testRect1);
  kvashnin::Rectangle testRect2({{10, -2}, 3, 4});
  testCompShape1.add(&testRect2);
  double areaBefore = testCompShape1.getArea();
  kvashnin::rectangle_t frameRectBefore = testCompShape1.getFrameRect();
  kvashnin::CompositeShape testCompShape2(&testRect1);
  testCompShape2 = std::move(testCompShape1);

  BOOST_CHECK_CLOSE(areaBefore, testCompShape2.getArea(), OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.height, testCompShape2.getFrameRect().height, OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.width, testCompShape2.getFrameRect().width, OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.pos.x, testCompShape2.getFrameRect().pos.x, OFFSET);
  BOOST_CHECK_CLOSE(frameRectBefore.pos.y, testCompShape2.getFrameRect().pos.y, OFFSET);
}

BOOST_AUTO_TEST_SUITE_END()
