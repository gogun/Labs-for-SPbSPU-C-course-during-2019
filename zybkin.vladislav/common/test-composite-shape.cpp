#include <boost/test/auto_unit_test.hpp>

#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

const double FAULT = 0.0001;

BOOST_AUTO_TEST_SUITE(compositeShapeMethodsTesting)

BOOST_AUTO_TEST_CASE(compositeTestSavedAfterShiftMoving)
{
  zybkin::Circle testCircle({3.5, 6.1}, 3.2);
  zybkin::Rectangle testRectangle({2.2, 5.5}, 3.5, 7.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);

  const double areaBeforeMoving = testComposite.getArea();
  const zybkin::rectangle_t frameRectBeforeMoving = testComposite.getFrameRect();
  //shift composite to (5.0, 3.0);
  testComposite.move(5.0, 3.0);

  //area and frame rectangle security check
  BOOST_CHECK_CLOSE(testComposite.getArea(), areaBeforeMoving, FAULT);
  zybkin::rectangle_t frameRectAfterMoving = testComposite.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(compositeTestSavedAfterMovingTo)
{
  zybkin::Circle testCircle({3.5, 6.1}, 3.2);
  zybkin::Rectangle testRectangle({2.2, 5.5}, 3.5, 7.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);

  const double areaBeforeMoving = testComposite.getArea();
  const zybkin::rectangle_t frameRectBeforeMoving = testComposite.getFrameRect();
  //moving composite to point (-2.3, 7.1);
  testComposite.move({-2.3, 7.1});

  //area and frame rectangle security check
  BOOST_CHECK_CLOSE(testComposite.getArea(), areaBeforeMoving, FAULT);
  zybkin::rectangle_t frameRectAfterMoving = testComposite.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.height, frameRectAfterMoving.height, FAULT);
  BOOST_CHECK_CLOSE(frameRectBeforeMoving.width, frameRectAfterMoving.width, FAULT);
}

BOOST_AUTO_TEST_CASE(compositeTestScale)
{
  zybkin::Circle testCircle({3.5, 6.1}, 3.2);
  zybkin::Rectangle testRectangle({2.2, 5.5}, 3.5, 7.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);

  const double areaBeforeMoving = testComposite.getArea();
  const double testScale = 1.5;

  //scale in 1.5 times
  testComposite.scale(testScale);
  //check that area scale in 2.25 times
  BOOST_CHECK_CLOSE(areaBeforeMoving * testScale * testScale, testComposite.getArea(), FAULT);
}

BOOST_AUTO_TEST_CASE(compositeTestChangingAreaAfterAddAndDelete)
{
  zybkin::Circle testCircle({-5.1, 3.4}, 2.0);
  zybkin::Rectangle testRectangle({2.2, 5.5}, 3.5, 7.8);
  zybkin::Rectangle testRectangle2({-8.1, -3.2}, 5.6, 7.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  const double compositeAreaBeforeAdd = testComposite.getArea();
  const int countOfShapesBeforeAdd = testComposite.getCount();
  const int testIndex = 2;
  const double circleArea = testCircle.getArea();
  const double rect2Area = testRectangle2.getArea();

  testComposite.add(&testCircle);
  testComposite.add(&testRectangle2);
  double compositeAreaAfterAdd = testComposite.getArea();
  const int countOfShapesAfterAdd = testComposite.getCount();
  //check that area increase after adding of element and check count of shapes
  BOOST_CHECK_CLOSE(compositeAreaBeforeAdd + circleArea + rect2Area, compositeAreaAfterAdd, FAULT);
  BOOST_CHECK_EQUAL(countOfShapesBeforeAdd + 2, countOfShapesAfterAdd);

  const double areaOfDeletingShape = testComposite[testIndex]->getArea();
  testComposite.remove(testIndex);
  //check that area decrease after adding of element and check count of shapes
  BOOST_CHECK_CLOSE(compositeAreaAfterAdd - areaOfDeletingShape, testComposite.getArea(), FAULT);
  BOOST_CHECK_EQUAL(countOfShapesAfterAdd - 1, testComposite.getCount());
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionAfterScale)
{
  zybkin::Rectangle testRectangle({-7.8, 3.4}, 5.4, 7.9);
  zybkin::CompositeShape testComposite(&testRectangle);
  //check that if put in function invalid scale argument function will throw exception
  BOOST_CHECK_THROW(testComposite.scale(-4.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionAfterDelete)
{
  zybkin::Circle testCircle({3.5, 6.1}, 3.2);
  zybkin::Rectangle testRectangle({2.2, 5.5}, 3.5, 7.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  //check that method throw exception if we try to delete last shape in composite
  BOOST_CHECK_THROW(testComposite.remove(0), std::invalid_argument);

  testComposite.add(&testCircle);
  //check that method throw exception if we send index which more than real count of shapes in composite
  BOOST_CHECK_THROW(testComposite.remove(5), std::out_of_range);
  BOOST_CHECK_THROW(testComposite.remove(-8), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionAfterUsingOperator)
{
  zybkin::Circle testCircle({-5.9, 9.1}, 5.2);
  zybkin::Rectangle testRectangle({3.1, 9.2}, 5.1, 2.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);

  //check that operator throw exception about out of range if we send index which more than max index in composite
  BOOST_CHECK_THROW(testComposite[5], std::out_of_range);
  BOOST_CHECK_THROW(testComposite[-7], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionNullPtr)
{
  BOOST_CHECK_THROW(zybkin::CompositeShape(nullptr), std::invalid_argument);

  zybkin::Rectangle testRectangle({-7.1, 13.2}, 0.1, 2.8);
  zybkin::CompositeShape testComposite(&testRectangle);

  BOOST_CHECK_THROW(testComposite.add(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compositeTestCopyConstructor)
{
  zybkin::Circle testCircle({2.3, 5.7}, 3.0);
  zybkin::Rectangle testRectangle({0.2, 8.1}, 2.3, 2.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);
  const zybkin::rectangle_t frameRect = testComposite.getFrameRect();

  zybkin::CompositeShape copyComposite(testComposite);
  const zybkin::rectangle_t copyFrameRect = copyComposite.getFrameRect();
  BOOST_CHECK_CLOSE(testComposite.getArea(), copyComposite.getArea(), FAULT);
  BOOST_CHECK_CLOSE(frameRect.height, copyFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, copyFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, copyFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, copyFrameRect.pos.y, FAULT);
  BOOST_CHECK_EQUAL(testComposite.getCount(), copyComposite.getCount());
}

BOOST_AUTO_TEST_CASE(compositeTestCopyOperator)
{
  zybkin::Circle testCircle({2.3, 5.7}, 3.0);
  zybkin::Rectangle testRectangle({0.2, 8.1}, 2.3, 2.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);
  const zybkin::rectangle_t frameRect = testComposite.getFrameRect();

  zybkin::Circle testCircle2({2.1, 3.2}, 5.6);
  zybkin::CompositeShape copyComposite(&testCircle2);
  copyComposite = testComposite;
  const zybkin::rectangle_t copyFrameRect = copyComposite.getFrameRect();
  BOOST_CHECK_CLOSE(testComposite.getArea(), copyComposite.getArea(), FAULT);
  BOOST_CHECK_CLOSE(frameRect.height, copyFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, copyFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, copyFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, copyFrameRect.pos.y, FAULT);
  BOOST_CHECK_EQUAL(testComposite.getCount(), copyComposite.getCount());
}

BOOST_AUTO_TEST_CASE(compositeTestMoveConstructor)
{
  zybkin::Circle testCircle({2.3, 5.7}, 3.0);
  zybkin::Rectangle testRectangle({0.2, 8.1}, 2.3, 2.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);
  const zybkin::rectangle_t frameRect = testComposite.getFrameRect();
  const double compositeArea = testComposite.getArea();
  const int compositeCount = testComposite.getCount();

  zybkin::CompositeShape moveComposite(std::move(testComposite));
  const zybkin::rectangle_t moveFrameRect = moveComposite.getFrameRect();
  BOOST_CHECK_CLOSE(compositeArea, moveComposite.getArea(), FAULT);
  BOOST_CHECK_CLOSE(frameRect.height, moveFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, moveFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, moveFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, moveFrameRect.pos.y, FAULT);
  BOOST_CHECK_EQUAL(compositeCount, moveComposite.getCount());
  BOOST_CHECK_EQUAL(testComposite.getCount(), 0);
  BOOST_CHECK_CLOSE(testComposite.getArea(), 0, FAULT);
}

BOOST_AUTO_TEST_CASE(compositeTestMoveOperator)
{
  zybkin::Circle testCircle({2.3, 5.7}, 3.0);
  zybkin::Rectangle testRectangle({0.2, 8.1}, 2.3, 2.8);
  zybkin::CompositeShape testComposite(&testRectangle);
  testComposite.add(&testCircle);
  const zybkin::rectangle_t frameRect = testComposite.getFrameRect();
  const double compositeArea = testComposite.getArea();
  const int compositeCount = testComposite.getCount();

  zybkin::Circle testCircle2({2.1, 3.2}, 5.6);
  zybkin::CompositeShape moveComposite(&testCircle2);
  moveComposite = std::move(testComposite);
  const zybkin::rectangle_t moveFrameRect = moveComposite.getFrameRect();
  BOOST_CHECK_CLOSE(compositeArea, moveComposite.getArea(), FAULT);
  BOOST_CHECK_CLOSE(frameRect.height, moveFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, moveFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, moveFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, moveFrameRect.pos.y, FAULT);
  BOOST_CHECK_EQUAL(compositeCount, moveComposite.getCount());
  BOOST_CHECK_EQUAL(testComposite.getCount(), 0);
  BOOST_CHECK_CLOSE(testComposite.getArea(), 0, FAULT);
  moveComposite = std::move(moveComposite);
  BOOST_CHECK_CLOSE(compositeArea, moveComposite.getArea(), FAULT);
  BOOST_CHECK_CLOSE(frameRect.height, moveFrameRect.height, FAULT);
  BOOST_CHECK_CLOSE(frameRect.width, moveFrameRect.width, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.x, moveFrameRect.pos.x, FAULT);
  BOOST_CHECK_CLOSE(frameRect.pos.y, moveFrameRect.pos.y, FAULT);
  BOOST_CHECK_EQUAL(compositeCount, moveComposite.getCount());
}

BOOST_AUTO_TEST_SUITE_END()
