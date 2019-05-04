#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"

const double FAULT = 0.001;
const double INCORRECT_ARG = -47.0;

BOOST_AUTO_TEST_SUITE(A2TestRectangle)

  BOOST_AUTO_TEST_CASE(TestRectangleAfterMove)
  {
    lebedev::Rectangle testRectangle(3.00, 4.00, {5.00, 4.00});
    const double areaBefore = testRectangle.getArea();
    const lebedev::rectangle_t frameBefore = testRectangle.getFrameRect();
    testRectangle.move(2.00, 5.4);
    const double areaAfterMove = testRectangle.getArea();
    const lebedev::rectangle_t frameAfterMove = testRectangle.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(areaBefore, areaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleAfterMovePos)
  {
    lebedev::Rectangle testRectangle(3.00, 4.00, {5.00, 4.00 });
    const double areaBefore = testRectangle.getArea();
    const lebedev::rectangle_t frameBefore = testRectangle.getFrameRect();
    testRectangle.move({3.00, 4.00});
    const double areaAfterMove = testRectangle.getArea();
    const lebedev::rectangle_t frameAfterMove = testRectangle.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(areaBefore, areaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleScale)
  {
    lebedev::Rectangle testRectangle(3.00, 4.00, {5.00, 4.00 });
    const double areaBeforeScale = testRectangle.getArea();
    const double multiplier = 2.0;
    testRectangle.scale(multiplier);
    const double areaAfterScale = testRectangle.getArea();
    BOOST_CHECK_CLOSE(areaBeforeScale * multiplier * multiplier, areaAfterScale, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleInvalidParametrs)
  {
    BOOST_CHECK_THROW(lebedev::Rectangle (INCORRECT_ARG, 4.00, {5.00, 4.00 }), std::invalid_argument);
    BOOST_CHECK_THROW(lebedev::Rectangle (3.00, INCORRECT_ARG, {5.00, 4.00 }), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleInvalidCoefficient)
  {
    lebedev::Rectangle testRectangle(3.00, 4.00, {5.00, 4.00 });
    BOOST_CHECK_THROW(testRectangle.scale(INCORRECT_ARG), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();
