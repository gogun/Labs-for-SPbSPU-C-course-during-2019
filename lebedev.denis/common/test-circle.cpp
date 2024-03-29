#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"

const double FAULT = 0.001;
const double INCORRECT_ARG = -47.0;

BOOST_AUTO_TEST_SUITE(A2TestCircle)

  BOOST_AUTO_TEST_CASE(TestCircleAfterMove)
  {
    lebedev::Circle testCircle(3.00, {1.00, 3.00 });
    const double areaBeforeMove = testCircle.getArea();
    const lebedev::rectangle_t frameBefore = testCircle.getFrameRect();
    testCircle.move(2.00, 5.4);
    const double areaAfterMove = testCircle.getArea();
    const lebedev::rectangle_t frameAfterMove = testCircle.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestCiecleAfterMovePos)
  {
    lebedev::Circle testCircle(3.00, {1.00, 3.00 });
    const double areaBeforeMove = testCircle.getArea();
    const lebedev::rectangle_t frameBefore = testCircle.getFrameRect();
    testCircle.move({3.00, 4.00});
    const double areaAfterMove = testCircle.getArea();
    const lebedev::rectangle_t frameAfterMove = testCircle.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestCircleScale)
  {
    lebedev::Circle testCircle(3.00, {1.00, 3.00});
    const double areaBeforeScale = testCircle.getArea();
    const double multiplier = 2.0;
    testCircle.scale(multiplier);
    const double areaAfterScale = testCircle.getArea();
    BOOST_CHECK_CLOSE(areaBeforeScale * multiplier * multiplier, areaAfterScale, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestCircleInvalidParametrs)
  {
    BOOST_CHECK_THROW(lebedev::Circle(INCORRECT_ARG, {1.00, 3.00}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCircleInvalidMultiplier)
  {
    lebedev::Circle testCircle(1.5, {1.00, 3.00});
    BOOST_CHECK_THROW(testCircle.scale(INCORRECT_ARG), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();
