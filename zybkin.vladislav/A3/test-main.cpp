#define BOOST_TEST_MODULE A3

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

const double FAULT = 0.0001;

BOOST_AUTO_TEST_SUITE(compositeShapeMethodsTesting)

BOOST_AUTO_TEST_CASE(compositeTestSavedAfterShiftMoving)
{
  zybkin::Circle testCircle({3.5, 6.1}, 3.2);
  zybkin::Rectangle testRectangle({2.2, 5.5}, 3.5, 7.8);
  zybkin::CompositeShape testComposite(testRectangle);
  testComposite.addShape(testCircle);

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
  zybkin::CompositeShape testComposite(testRectangle);
  testComposite.addShape(testCircle);

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
  zybkin::CompositeShape testComposite(testRectangle);
  testComposite.addShape(testCircle);

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
  zybkin::CompositeShape testComposite(testRectangle);
  const double compositeAreaBeforeAdd = testComposite.getArea();
  const int countOfShapesBeforeAdd = testComposite.getCount();
  const int testIndex = 2;
  const double circleArea = testCircle.getArea();
  const double rect2Area = testRectangle2.getArea();

  testComposite.addShape(testCircle);
  testComposite.addShape(testRectangle2);
  double compositeAreaAfterAdd = testComposite.getArea();
  const int countOfShapesAfterAdd = testComposite.getCount();
  //check that area increase after adding of element and check count of shapes
  BOOST_CHECK_CLOSE(compositeAreaBeforeAdd + circleArea + rect2Area, compositeAreaAfterAdd, FAULT);
  BOOST_CHECK_EQUAL(countOfShapesBeforeAdd + 2, countOfShapesAfterAdd);

  const double areaOfDeletingShape = testComposite[testIndex]->getArea();
  testComposite.deleteShape(testIndex);
  //check that area decrease after adding of element and check count of shapes
  BOOST_CHECK_CLOSE(compositeAreaAfterAdd - areaOfDeletingShape, testComposite.getArea(), FAULT);
  BOOST_CHECK_EQUAL(countOfShapesAfterAdd - 1, testComposite.getCount());
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionAfterScale)
{
  zybkin::Rectangle testRectangle({-7.8, 3.4}, 5.4, 7.9);
  zybkin::CompositeShape testComposite(testRectangle);
  //check that if put in function invalid scale argument function will throw exception
  BOOST_CHECK_THROW(testComposite.scale(-4.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionAfterDelete)
{
  zybkin::Circle testCircle({3.5, 6.1}, 3.2);
  zybkin::Rectangle testRectangle({2.2, 5.5}, 3.5, 7.8);
  zybkin::CompositeShape testComposite(testRectangle);
  //check that method throw exception if we try to delete last shape in composite
  BOOST_CHECK_THROW(testComposite.deleteShape(0), std::invalid_argument);

  testComposite.addShape(testCircle);
  //check that method throw exception if we send index which more than real count of shapes in composite
  BOOST_CHECK_THROW(testComposite.deleteShape(5), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(compositeTestThrowExceptionAfterUsingOperator)
{
  zybkin::Circle testCircle({-5.9, 9.1}, 5.2);
  zybkin::Rectangle testRectangle({3.1, 9.2}, 5.1, 2.8);
  zybkin::CompositeShape testComposite(testRectangle);
  testComposite.addShape(testCircle);

  //check that operator throw exception about out of range if we send index which more than max index in composite
  BOOST_CHECK_THROW(testComposite[5], std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
