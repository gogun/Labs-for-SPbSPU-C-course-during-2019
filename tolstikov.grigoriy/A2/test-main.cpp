#define BOOST_TEST_MODULE A2;

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double DELTA = 0.00001;

BOOST_AUTO_TEST_SUITE(testCircleSuite)

BOOST_AUTO_TEST_CASE(constCircleAfterMovingByValue)
{
  tolstikov::Circle testCircle({ 2.5, 3.5 }, 3);
  const double radiusBefore = testCircle.getRadius();
  const double areaBefore = testCircle.getArea();

  testCircle.move(5, 10);
  const double radiusAfter = testCircle.getRadius();
  const double areaAfter = testCircle.getArea();
  BOOST_CHECK_CLOSE(radiusAfter, radiusBefore, DELTA);
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, DELTA);
}

BOOST_AUTO_TEST_CASE(constCircleAfterMovingToAPoint)
{
  tolstikov::Circle testCircle({ 1.5, 1.5 }, 5);
  const double radiusBefore = testCircle.getRadius();
  const double areaBefore = testCircle.getArea();

  testCircle.move({ 1, 5 });
  const double radiusAfter = testCircle.getRadius();
  const double areaAfter = testCircle.getArea();
  BOOST_CHECK_CLOSE(radiusAfter, radiusBefore, DELTA);
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, DELTA);
}

BOOST_AUTO_TEST_CASE(quadraticIncreaseAreaAfterScaling)
{
  tolstikov::Circle testCircle({ 0.5, 1 }, 2);
  const double scaleFactor = 3;
  const double areaBefore = testCircle.getArea();

  testCircle.scale(scaleFactor);
  const double areaAfter = testCircle.getArea();
  BOOST_CHECK_CLOSE(areaAfter, areaBefore * scaleFactor * scaleFactor, DELTA);
}

BOOST_AUTO_TEST_CASE(quadraticDecreaseAreaAfterScaling)
{
  tolstikov::Circle testCircle({ -2, 1 }, 10);
  const double scaleFactor = 0.2;
  const double areaBefore = testCircle.getArea();

  testCircle.scale(scaleFactor);
  const double areaAfter = testCircle.getArea();
  BOOST_CHECK_CLOSE(areaAfter, areaBefore * scaleFactor * scaleFactor, DELTA);
}

BOOST_AUTO_TEST_CASE(exceptInvalidRadius)
{
  BOOST_CHECK_THROW(tolstikov::Circle testCircle1({ -2, 1 }, -6), std::invalid_argument);
  BOOST_CHECK_THROW(tolstikov::Circle testCircle2({ -2, 1 }, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(exceptInvalidScaleFactor)
{
  tolstikov::Circle testCircle({ 0.5, 1 }, 2);
  const double scaleFactor1 = 0;
  const double scaleFactor2 = -11;
  BOOST_CHECK_THROW(testCircle.scale(scaleFactor1), std::invalid_argument);
  BOOST_CHECK_THROW(testCircle.scale(scaleFactor2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testRectangleSuite)

BOOST_AUTO_TEST_CASE(constRectangleAfterMovingByValue)
{
  tolstikov::Rectangle testRectangle({ 1, 3 }, 5, 7);
  const double widthBefore = testRectangle.getFrameRect().width;
  const double heightBefore = testRectangle.getFrameRect().height;
  const double areaBefore = testRectangle.getArea();

  testRectangle.move(11, -30);
  const double widthAfter = testRectangle.getFrameRect().width;
  const double heightAfter = testRectangle.getFrameRect().height;
  const double areaAfter = testRectangle.getArea();
  BOOST_CHECK_CLOSE(widthAfter, widthBefore, DELTA);
  BOOST_CHECK_CLOSE(heightAfter, heightBefore, DELTA);
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, DELTA);
}

BOOST_AUTO_TEST_CASE(constSquareAfterMovingByValue)
{
  tolstikov::Rectangle testSquare({ 0, 0 }, 4);
  const double widthBefore = testSquare.getFrameRect().width;
  const double heightBefore = testSquare.getFrameRect().height;
  const double areaBefore = testSquare.getArea();

  testSquare.move(1, 1);
  const double widthAfter = testSquare.getFrameRect().width;
  const double heightAfter = testSquare.getFrameRect().height;
  const double areaAfter = testSquare.getArea();
  BOOST_CHECK_CLOSE(widthAfter, widthBefore, DELTA);
  BOOST_CHECK_CLOSE(heightAfter, widthAfter, DELTA);
  BOOST_CHECK_CLOSE(heightAfter, heightBefore, DELTA);
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, DELTA);
}

BOOST_AUTO_TEST_CASE(constRectangleAfterMovingToAPoint)
{
  tolstikov::Rectangle testRectangle({ 2, 6 }, 6, 7);
  const double widthBefore = testRectangle.getFrameRect().width;
  const double heightBefore = testRectangle.getFrameRect().height;
  const double areaBefore = testRectangle.getArea();

  testRectangle.move({ 0, 0 });
  const double widthAfter = testRectangle.getFrameRect().width;
  const double heightAfter = testRectangle.getFrameRect().height;
  const double areaAfter = testRectangle.getArea();
  BOOST_CHECK_CLOSE(widthAfter, widthBefore, DELTA);
  BOOST_CHECK_CLOSE(heightAfter, heightBefore, DELTA);
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, DELTA);
}

BOOST_AUTO_TEST_CASE(constSquareAfterMovingToAPoint)
{
  tolstikov::Rectangle testSquare({ 3, 3 }, 7);
  const double widthBefore = testSquare.getFrameRect().width;
  const double heightBefore = testSquare.getFrameRect().height;
  const double areaBefore = testSquare.getArea();

  testSquare.move({ 41, -18 });
  const double widthAfter = testSquare.getFrameRect().width;
  const double heightAfter = testSquare.getFrameRect().height;
  const double areaAfter = testSquare.getArea();
  BOOST_CHECK_CLOSE(widthAfter, widthBefore, DELTA);
  BOOST_CHECK_CLOSE(heightAfter, widthAfter, DELTA);
  BOOST_CHECK_CLOSE(heightAfter, heightBefore, DELTA);
  BOOST_CHECK_CLOSE(areaAfter, areaBefore, DELTA);
}

BOOST_AUTO_TEST_CASE(quadraticIncreaseAreaAfterScaling)
{
  tolstikov::Rectangle testRectangle({ 1, 1 }, 2.4, 9);
  tolstikov::Rectangle testSquare({ 3, 3 }, 10.2);
  const double scaleFactor = 4;
  const double areaRectangleBefore = testRectangle.getArea();
  const double areaSquareBefore = testSquare.getArea();

  testRectangle.scale(scaleFactor);
  testSquare.scale(scaleFactor);
  const double areaRectangleAfter = testRectangle.getArea();
  const double areaSquareAfter = testSquare.getArea();
  BOOST_CHECK_CLOSE(areaRectangleAfter, areaRectangleBefore * scaleFactor * scaleFactor, DELTA);
  BOOST_CHECK_CLOSE(areaSquareAfter, areaSquareBefore * scaleFactor * scaleFactor, DELTA);
}

BOOST_AUTO_TEST_CASE(quadraticDecreaseAreaAfterScaling)
{
  tolstikov::Rectangle testRectangle({ 7, 2 }, 7.1, 2);
  tolstikov::Rectangle testSquare({ 1, 5 }, 9.5);
  const double scaleFactor = 0.4;
  const double areaRectangleBefore = testRectangle.getArea();
  const double areaSquareBefore = testSquare.getArea();

  testRectangle.scale(scaleFactor);
  testSquare.scale(scaleFactor);
  const double areaRectangleAfter = testRectangle.getArea();
  const double areaSquareAfter = testSquare.getArea();
  BOOST_CHECK_CLOSE(areaRectangleAfter, areaRectangleBefore * scaleFactor * scaleFactor, DELTA);
  BOOST_CHECK_CLOSE(areaSquareAfter, areaSquareBefore * scaleFactor * scaleFactor, DELTA);
}

BOOST_AUTO_TEST_CASE(exceptInvalidWidthAndHeight)
{
  BOOST_CHECK_THROW(tolstikov::Rectangle testRectangle1({ -2, 1 }, -6, 1), std::invalid_argument);
  BOOST_CHECK_THROW(tolstikov::Rectangle testRectangle2({ -2, 1 }, 1, -6), std::invalid_argument);
  BOOST_CHECK_THROW(tolstikov::Rectangle testRectangle3({ -2, 1 }, -6, -6), std::invalid_argument);

  BOOST_CHECK_THROW(tolstikov::Rectangle testSquare1({ -2, 1 }, 0), std::invalid_argument);
  BOOST_CHECK_THROW(tolstikov::Rectangle testSquare2({ -2, 1 }, -5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(exceptInvalidScaleFactor)
{
  tolstikov::Rectangle testRectangle({ 0.5, 1 }, 5, 11);
  tolstikov::Rectangle testSquare({ 1, 2 }, 3);
  const double scaleFactor1 = 0;
  const double scaleFactor2 = -11;
  BOOST_CHECK_THROW(testRectangle.scale(scaleFactor1), std::invalid_argument);
  BOOST_CHECK_THROW(testRectangle.scale(scaleFactor2), std::invalid_argument);
  BOOST_CHECK_THROW(testSquare.scale(scaleFactor1), std::invalid_argument);
  BOOST_CHECK_THROW(testSquare.scale(scaleFactor2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
