#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double TOLERANCE = 0.001;

BOOST_AUTO_TEST_SUITE(RectangleTests)

BOOST_AUTO_TEST_CASE(InvariabilityAfterAxialMovingTest)
{
  zakharova::Rectangle testRectangle(5, 6, {7, 8});
  zakharova::rectangle_t frameBefore = testRectangle.getFrameRect();
  double areaBefore = testRectangle.getArea();

  testRectangle.move(5, 5);
  zakharova::rectangle_t frameAfter = testRectangle.getFrameRect();
  double areaAfter = testRectangle.getArea();

  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(InvariabilityAfterMovingCenterTest)
{
  zakharova::Rectangle testRectangle(5, 6, {7, 8});
  zakharova::rectangle_t frameBefore = testRectangle.getFrameRect();
  double areaBefore = testRectangle.getArea();

  testRectangle.move({0, 0});
  zakharova::rectangle_t frameAfter = testRectangle.getFrameRect();
  double areaAfter = testRectangle.getArea();

  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(ScalingTest)
{
  zakharova::Rectangle testRectangle(5, 6, {7, 8});
  double areaBefore = testRectangle.getArea();
  double factor = 1.5;
  testRectangle.scale(factor);
  double areaAfter = testRectangle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * factor * factor, areaAfter, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(IncorrectWidthTest)
{
  BOOST_CHECK_THROW(zakharova::Rectangle(-5, 6, {7, 8}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectHeightTest)
{
  BOOST_CHECK_THROW(zakharova::Rectangle(5, -6, {7, 8}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectScaleArgumentTest)
{
  zakharova::Rectangle testRectangle(5, 6, {7, 8});
  BOOST_CHECK_THROW(testRectangle.scale(-1.5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(InvariabilityAfterAxialMovingTest)
{
  zakharova::Circle testCircle(5, {6, 7});
  zakharova::rectangle_t frameBefore = testCircle.getFrameRect();
  double areaBefore = testCircle.getArea();

  testCircle.move(5, 5);
  zakharova::rectangle_t frameAfter = testCircle.getFrameRect();
  double areaAfter = testCircle.getArea();

  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(InvariabilityAfterMovingCenterTest)
{
  zakharova::Circle testCircle(5, {6, 7});
  zakharova::rectangle_t frameBefore = testCircle.getFrameRect();
  double areaBefore = testCircle.getArea();

  testCircle.move({0, 0});
  zakharova::rectangle_t frameAfter = testCircle.getFrameRect();
  double areaAfter = testCircle.getArea();

  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(ScalingTest)
{
  zakharova::Circle testCircle(5, {6, 7});
  double areaBefore = testCircle.getArea();
  double factor = 1.5;
  testCircle.scale(factor);
  double areaAfter = testCircle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * factor * factor, areaAfter, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(IncorrectRadiusTest)
{
  BOOST_CHECK_THROW(zakharova::Circle(-5, {6, 7}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectScaleArgumentTest)
{
  zakharova::Circle testCircle(5, {6, 7});
  BOOST_CHECK_THROW(testCircle.scale(-1.5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
