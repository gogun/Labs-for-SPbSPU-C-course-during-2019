#include <boost/test/auto_unit_test.hpp>
#inclede "circle.hpp"
#include <stdexcept>

const double FAULT = 0.001;
const double INCORRECT_ARG = -47.0;

BOOST_AUTO_TEST_SUITE(TestCircle)

  BOOST_AUTO_TEST_CASE(TestCircleAfterMove)
  {
    lebedev::Circle c1(3.00, {1.00, 3.00 });
    const double AreaBefore = c1.getArea();
    const lebedev::rectangle_t frameBefore = c1.getFrameRect();
    c1.move(2.00, 5.4);
    const double AreaAfterMove = c1.getArea();
    const lebedev::rectangle_t frameAfterMove = c1.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestCiecleAfterMovePos)
  {
    lebedev::Circle c1(3.00, {1.00, 3.00 });
    const double AreaBefore = c1.getArea();
    const lebedev::rectangle_t frameBefore = c1.getFrameRect();
    c1.move({3.00, 4.00});
    const double AreaAfterMove = c1.getArea();
    const lebedev::rectangle_t frameAfterMove = c1.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestCircleScale)
  {
    lebedev::Circle c1(3.00, {1.00, 3.00});
    const double AreaBeforeScale = c1.getArea();
    const double multiplier = 2.0;
    c1.scale(multiplier);
    const double AreaAfterScale = c1.getArea();
    BOOST_CHECK_CLOSE(AreaBeforeScale * multiplier * multiplier, AreaAfterScale, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestCircleInvalidParametrs)
  {
    BOOST_CHECK_THROW(lebedev::Circle(INCORRECT_ARG, {1.00, 3.00}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCircleInvalidMultiplier)
  {
    lebedev::Circle c1(1.5, {1.00, 3.00});
    BOOST_CHECK_THROW(c1.scale(INCORRECT_ARG), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();
