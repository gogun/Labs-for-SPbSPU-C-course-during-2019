#define BOOST_TEST_MAIN
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(A2_test)

const double FAULT = 0.01;

BOOST_AUTO_TEST_CASE(testRectangleAfterMove) {
  sachuk::Rectangle testRect({12, 3}, 13, 10);
  const double areaBeforeMove = testRect.getArea();
  const sachuk::rectangle_t frameBeforeMove = testRect.getFrameRect();

  testRect.move({4, 9});

  double areaAfterMove = testRect.getArea();
  sachuk::rectangle_t frameAfterMove = testRect.getFrameRect();
  BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMove.width, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMove.height, FAULT);

  testRect.move(4, 5);

  areaAfterMove = testRect.getArea();
  frameAfterMove = testRect.getFrameRect();
  BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMove.width, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMove.height, FAULT);
}

BOOST_AUTO_TEST_CASE(testRectangleScale) {
  sachuk::Rectangle testRect({12, 3}, 13, 10);
  const double areaBeforeScale = testRect.getArea();

  const double multiplier = 5;
  testRect.scale(multiplier);

  const double areaAfterScale = testRect.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScale * multiplier * multiplier, areaAfterScale, FAULT);
}

BOOST_AUTO_TEST_CASE(testRectangleParameters) {
  BOOST_CHECK_THROW(sachuk::Rectangle({12, -3}, -10, 20), std::invalid_argument);
  BOOST_CHECK_THROW(sachuk::Rectangle({12, -3}, 10, -4), std::invalid_argument);
  sachuk::Rectangle testRect({12, -3}, 4, 5);
  BOOST_CHECK_THROW(testRect.scale(-4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleAfterMove) {
  sachuk::Circle testCircle({2, 5}, 8);
  const double areaBeforeMove = testCircle.getArea();
  const sachuk::rectangle_t frameBeforeMove = testCircle.getFrameRect();

  testCircle.move({6, 8});

  double areaAfterMove = testCircle.getArea();
  sachuk::rectangle_t frameAfterMove = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMove.width, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMove.height, FAULT);

  testCircle.move(6, 8);

  areaAfterMove = testCircle.getArea();
  frameAfterMove = testCircle.getFrameRect();
  BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.width, frameAfterMove.width, FAULT);
  BOOST_CHECK_CLOSE(frameBeforeMove.height, frameAfterMove.height, FAULT);
}

BOOST_AUTO_TEST_CASE(testCircleScale) {
  sachuk::Circle testCircle({2, 5}, 8);
  const double areaBeforeScale = testCircle.getArea();

  const double multiplier = 4;

  testCircle.scale(4);
  const double areaAfterScale = testCircle.getArea();

  BOOST_CHECK_CLOSE(areaBeforeScale * multiplier * multiplier, areaAfterScale, FAULT);
}

BOOST_AUTO_TEST_CASE(testCircleParameters) {
  BOOST_CHECK_THROW(sachuk::Circle({-3, 1}, -4), std::invalid_argument);
  sachuk::Circle testCircle({-3, 1}, 4);
  BOOST_CHECK_THROW(testCircle.scale(-4), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
