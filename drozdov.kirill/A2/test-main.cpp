#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"
#define ACCURACY 0.001

const double incorrectArgument = -10.0;

BOOST_AUTO_TEST_SUITE(A2TestsRectangle)

  BOOST_AUTO_TEST_CASE(testCorrectnessAfterMove)
  {
    drozdov::Rectangle rectangle(5.0, 3.0, {4.3, 1.0});
    const drozdov::rectangle_t rectBeforeMove = rectangle.getFrameRect();
    const double areaBeforeMove = rectangle.getArea();

    rectangle.move(2.4, 5.6);

    const drozdov::rectangle_t rectAfterMove = rectangle.getFrameRect();
    const double areaAfterMove = rectangle.getArea();

    BOOST_CHECK_CLOSE(rectBeforeMove.width, rectAfterMove.width, ACCURACY);
    BOOST_CHECK_CLOSE(rectBeforeMove.height, rectAfterMove.height, ACCURACY);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, ACCURACY);
  } //testCorrectnessAfterMove

  BOOST_AUTO_TEST_CASE(testCorrectnessAfterScale)
  {
    drozdov::Rectangle rectangle(5.0, 3.0, {4.3, 1.0});
    const double areaBeforeScale = rectangle.getArea();

    const double coefficientScaleRect = 4.0;
    rectangle.scale(coefficientScaleRect);

    const double areaAfterScale = rectangle.getArea();
    BOOST_CHECK_CLOSE(areaBeforeScale * coefficientScaleRect * coefficientScaleRect, areaAfterScale, ACCURACY);
  } //testCorrectnessAfterScale

  BOOST_AUTO_TEST_CASE(testIncorrectParameters)
  {
    BOOST_CHECK_THROW(drozdov::Rectangle(incorrectArgument, 3.0, {4.3, 1.0}), std::invalid_argument);
    BOOST_CHECK_THROW(drozdov::Rectangle(5.0, incorrectArgument, {4.3, 1.0}), std::invalid_argument);

    drozdov::Rectangle rectangle(5.0, 3.0, {4.3, 1.0});
    BOOST_CHECK_THROW(rectangle.scale(incorrectArgument), std::invalid_argument);
  } //testIncorrectParameters

BOOST_AUTO_TEST_SUITE_END() //A2TestsRectangle

BOOST_AUTO_TEST_SUITE(A2TestsCircle)

  BOOST_AUTO_TEST_CASE(testCorrectnessAfterMove)
  {
    drozdov::Circle circle(5.0, {4.3, 1.0});
    const double radiusBeforeMove = circle.getRadius();
    const double areaBeforeMove = circle.getArea();

    circle.move(2.4, 5.6);

    const double radiusAfterMove = circle.getRadius();
    const double areaAfterMove = circle.getArea();

    BOOST_CHECK_CLOSE(radiusBeforeMove, radiusAfterMove, ACCURACY);
    BOOST_CHECK_CLOSE(radiusBeforeMove, radiusAfterMove, ACCURACY);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, ACCURACY);
  } //testCorrectnessAfterMove

  BOOST_AUTO_TEST_CASE(testCorrectnessAfterScale)
  {
    drozdov::Circle circle(5.0, {4.3, 1.0});
    const double areaBeforeScale = circle.getArea();

    const double coefficientScaleCirc = 4.0;
    circle.scale(coefficientScaleCirc);

    const double areaAfterScale = circle.getArea();
    BOOST_CHECK_CLOSE(areaBeforeScale * coefficientScaleCirc * coefficientScaleCirc, areaAfterScale, ACCURACY);
  } //testCorrectnessAfterScale

  BOOST_AUTO_TEST_CASE(testIncorrectParameters)
  {
    BOOST_CHECK_THROW(drozdov::Circle(incorrectArgument, {4.3, 1.0}), std::invalid_argument);

    drozdov::Circle circle(5.0, {4.3, 1.0});
    BOOST_CHECK_THROW(circle.scale(incorrectArgument), std::invalid_argument);
  } //testIncorrectParameters

BOOST_AUTO_TEST_SUITE_END() //A2TestsCircle
