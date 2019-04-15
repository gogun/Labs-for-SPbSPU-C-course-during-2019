#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

  const double calculationError = 0.01;

  BOOST_AUTO_TEST_CASE(immutabilityAfterMovingRectangle)
  {
    konev::Rectangle movableRectangle({6.0, 6.0}, 1.3, 2.4);
    const konev::rectangle_t rectangleBefore = movableRectangle.getFrameRect();
    const double areaBefore = movableRectangle.getArea();

    movableRectangle.move({1.9, 1.9});
    BOOST_CHECK_CLOSE(rectangleBefore.width, movableRectangle.getFrameRect().width, calculationError);
    BOOST_CHECK_CLOSE(rectangleBefore.height, movableRectangle.getFrameRect().height, calculationError);
    BOOST_CHECK_CLOSE(areaBefore, movableRectangle.getArea(), calculationError);

    movableRectangle.move(5.0, -7.0);
    BOOST_CHECK_CLOSE(rectangleBefore.width, movableRectangle.getFrameRect().width, calculationError);
    BOOST_CHECK_CLOSE(rectangleBefore.height, movableRectangle.getFrameRect().height, calculationError);
    BOOST_CHECK_CLOSE(areaBefore, movableRectangle.getArea(), calculationError);
  }

  BOOST_AUTO_TEST_CASE(immutabilityAfterMovingCircle)
  {
    konev::Circle movableCircle({1.0, 2.0}, 5.0);
    const konev::rectangle_t rectangleBefore = movableCircle.getFrameRect();
    const double areaBefore = movableCircle.getArea();

    movableCircle.move(-1.0, 9.7);
    BOOST_CHECK_CLOSE(rectangleBefore.width, movableCircle.getFrameRect().width, calculationError);
    BOOST_CHECK_CLOSE(rectangleBefore.height, movableCircle.getFrameRect().height, calculationError);
    BOOST_CHECK_CLOSE(areaBefore, movableCircle.getArea(), calculationError);

    movableCircle.move({2.5, 3.2});
    BOOST_CHECK_CLOSE(rectangleBefore.width, movableCircle.getFrameRect().width, calculationError);
    BOOST_CHECK_CLOSE(rectangleBefore.height, movableCircle.getFrameRect().height, calculationError);
    BOOST_CHECK_CLOSE(areaBefore, movableCircle.getArea(), calculationError);
  }

  BOOST_AUTO_TEST_CASE(scalingRectangle)
  {
    konev::Rectangle scalableRectangle({5.0, 5.0}, 2.0, 2.0);
    const double areaBefore = scalableRectangle.getArea();
    const double coefficient = 3.0;
    scalableRectangle.scale(coefficient);
    BOOST_CHECK_CLOSE(scalableRectangle.getArea(), coefficient * coefficient * areaBefore, calculationError);
  }

  BOOST_AUTO_TEST_CASE(scalingCircle)
  {
    konev::Circle scalableCircle({1.0, 1.0}, 10.0);
    const double areaBefore = scalableCircle.getArea();
    const double coefficient = 5.2;
    scalableCircle.scale(coefficient);
    BOOST_CHECK_CLOSE(scalableCircle.getArea(), coefficient * coefficient * areaBefore, calculationError);
  }

  BOOST_AUTO_TEST_CASE(invalidRectangleValues)
  {
    BOOST_CHECK_THROW(konev::Rectangle({4.5, 1.0}, -2.0, 5.0), std::invalid_argument);
    BOOST_CHECK_THROW(konev::Rectangle({2.0, 4.1}, -1.0, -3.0), std::invalid_argument);

    konev::Rectangle wrongRectangle1({2.0, 2.0}, 1.0, 1.0);
    BOOST_CHECK_THROW(wrongRectangle1.scale(-1.0), std::invalid_argument);

    konev::Rectangle wrongRectangle2({1.0, 1.0}, 2.0, 2.0);
    BOOST_CHECK_THROW(wrongRectangle2.scale(-2.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(invalidCircleValues)
  {
    BOOST_CHECK_THROW(konev::Circle({2.0, 3.5}, -2.0), std::invalid_argument);
    BOOST_CHECK_THROW(konev::Circle({1.0, 2.5}, -1.0), std::invalid_argument);

    konev::Circle wrongCircle1({2.0, 2.0}, 1.0);
    BOOST_CHECK_THROW(wrongCircle1.scale(-2.0), std::invalid_argument);

    konev::Circle wrongCircle2({1.0, 1.0}, 2.0);
    BOOST_CHECK_THROW(wrongCircle1.scale(-1.0), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
