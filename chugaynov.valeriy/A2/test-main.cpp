#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double tolerance = 0.0001;

BOOST_AUTO_TEST_SUITE(testForA2)
BOOST_AUTO_TEST_CASE(rectangleInvariantAfterMove)
{
  const double width = 18.89;
  const double height = 10.9;
  chugaynov::Rectangle testRect({ 12.26, 2.8 }, width, height);
  const double rectangleAreaBeforeMove = testRect.getArea();
  testRect.move(1.2, 1.9);
  BOOST_CHECK_CLOSE(rectangleAreaBeforeMove, testRect.getArea(), tolerance);
  BOOST_CHECK_CLOSE(width, testRect.getFrameRect().width, tolerance);
  BOOST_CHECK_CLOSE(height, testRect.getFrameRect().height, tolerance);
  testRect.move({ 1.2, 1.9 });
  BOOST_CHECK_CLOSE(rectangleAreaBeforeMove, testRect.getArea(), tolerance);
  BOOST_CHECK_CLOSE(width, testRect.getFrameRect().width, tolerance);
  BOOST_CHECK_CLOSE(height, testRect.getFrameRect().height, tolerance);
}

BOOST_AUTO_TEST_CASE(circleInvariantAfterMove)
{
  const double radius = 12.2;
  chugaynov::Circle testCirc({ 17.2, 1.39 }, radius);
  const double circleAreaBeforeMove = testCirc.getArea();
  testCirc.move(17.8, 1);
  BOOST_CHECK_CLOSE(circleAreaBeforeMove, testCirc.getArea(), tolerance);
  BOOST_CHECK_CLOSE(radius, testCirc.getRadius(), tolerance);
  testCirc.move({ 17.8, 1 });
  BOOST_CHECK_CLOSE(circleAreaBeforeMove, testCirc.getArea(), tolerance);
  BOOST_CHECK_CLOSE(radius, testCirc.getRadius(), tolerance);
}

BOOST_AUTO_TEST_CASE(rectangleSquareAreaChangeAfterMove)
{
  const double coeff = 10.4;
  chugaynov::Circle testCirc({ 17.2, 1.39 }, 12.2);
  const double circleAreaBeforeScale = testCirc.getArea();
  testCirc.scale(coeff);
  BOOST_CHECK_CLOSE(circleAreaBeforeScale * coeff * coeff, testCirc.getArea(), tolerance);
}
BOOST_AUTO_TEST_CASE(circleSquareAreaChangeAfterMove)
{
  const double coeff = 12.4;
  chugaynov::Rectangle testRect({ 12.26, 2.8 }, 12.2, 102.3);
  const double rectangleAreaBeforeScale = testRect.getArea();
  testRect.scale(coeff);
  BOOST_CHECK_CLOSE(rectangleAreaBeforeScale * coeff * coeff, testRect.getArea(), tolerance);
}

BOOST_AUTO_TEST_CASE(checkThrowExceptions)
{
  BOOST_CHECK_THROW(chugaynov::Circle({ 13.2, 23 }, -1), std::invalid_argument);
  BOOST_CHECK_THROW(chugaynov::Rectangle({ 13.2, 23 }, -1, 4), std::invalid_argument);
  chugaynov::Rectangle testRect({ 12.26, 2.8 }, 12.2, 102.3);
  BOOST_CHECK_THROW(testRect.scale(0), std::invalid_argument);
  chugaynov::Circle testCirc({ 17.2, 1.39 }, 12.2);
  BOOST_CHECK_THROW(testCirc.scale(-0.2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
