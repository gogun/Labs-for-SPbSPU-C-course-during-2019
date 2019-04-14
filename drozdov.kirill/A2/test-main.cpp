#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

const double calculationError = 0.01;

BOOST_AUTO_TEST_SUITE(A2TestRectangle)

  BOOST_AUTO_TEST_CASE(testCorrectnessAfterMove)
  {
    drozdov::Rectangle rectangle(5.0, 3.0, {4.3, 1.0});
    const rectangle_t beforeMoveRect = rectangle.getFrameRect();
    const double areaBeforeMove = rectangle.getArea();

    rectangle.move(2.4, 5.6);

    const rectangle_t afterMoveRect = rectangle.getFrameRect();
    const double areaAfterMove = rectangle.getArea();

    BOOST_CHECK_CLOSE(beforeMoveRect.width, afterMoveRect.width, calculationError);
    BOOST_CHECK_CLOSE(beforeMoveRect.height, afterMoveRect.height, calculationError);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, calculationError);
  }

  BOOST_AUTO_TEST_CASE(testCorrectnessAftersScale)
  {
    drozdov::Rectangle rectangle(5.0, 3.0, {4.3, 1.0});
    const double beforeAreaScale = rectangle.getArea();

    const double factor = 4.0;
    rectangle.scale(factor);

    const double afterAreaScale = rectangle.getArea();
    BOOST_CHECK_CLOSE(beforeAreaScale * factor * factor, afterAreaScale, calculationError);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(A2TestCircle)

  BOOST_AUTO_TEST_CASE(testCorrectnessAfterMove)
  {
    drozdov::Circle circle(5.0, {4.3, 1.0});
    const double radiusBeforeMove = circle.getRadius();
    const double areaBeforeMove = circle.getArea();

    circle.move(2.4, 5.6);

    const double radiusAfterMove = circle.getRadius();
    const double areaAfterMove = circle.getArea();

    BOOST_CHECK_CLOSE(radiusBeforeMove, radiusAfterMove, calculationError);
    BOOST_CHECK_CLOSE(radiusBeforeMove, radiusAfterMove, calculationError);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, calculationError);
  }

  BOOST_AUTO_TEST_CASE(testCorrectnessAftersScale)
  {
    drozdov::Circle circle(5.0, {4.3, 1.0});
    const double beforeAreaScale = circle.getArea();

    const double factor = 4.0;
    circle.scale(factor);
    
    const double afterAreaScale = circle.getArea();
    BOOST_CHECK_CLOSE(beforeAreaScale * factor * factor, afterAreaScale, calculationError);
  }

BOOST_AUTO_TEST_SUITE_END()
