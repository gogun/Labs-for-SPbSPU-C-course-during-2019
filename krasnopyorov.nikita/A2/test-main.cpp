#define BOOST_TEST_MODULE A2;
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"


const double INACCURACY = 0.0001;


BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(testConstancy)
{
  krasnopyorov::Circle testCircle(2, {0, 0});
  const double radiusBefore = testCircle.getRadius();
  const double areaBefore = testCircle.getArea();
  const krasnopyorov::point_t dot = {1, 2};

  testCircle.move(dot);

  BOOST_CHECK_CLOSE_FRACTION(radiusBefore, testCircle.getRadius(), INACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(areaBefore, testCircle.getArea(), INACCURACY);

  const double dx = 3.0;
  const double dy = -1.0;

  testCircle.move(dx, dy);

  BOOST_CHECK_CLOSE_FRACTION(radiusBefore, testCircle.getRadius(), INACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(areaBefore, testCircle.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(testAreaAfterScale)
{
  krasnopyorov::Circle testCircle(2, {0, 0});
  const double k = 2.0;
  const double areaAfterScaling = testCircle.getArea() * k * k;

  testCircle.scale(k);

  BOOST_CHECK_CLOSE_FRACTION(areaAfterScaling, testCircle.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(testIncorrectArgumets)
{
  BOOST_CHECK_THROW(krasnopyorov::Circle(-1, {0, 0}), std::invalid_argument);

  krasnopyorov::Circle testCircle(2, {0, 0});
  const double k = -1.2;

  BOOST_CHECK_THROW(testCircle.scale(k), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(testConstancy)
{
  krasnopyorov::Rectangle testRect({2.5, 1.0, {0, 0}});
  const double heightBefore = testRect.getHeight();
  const double widthBefore = testRect.getWidth();
  const double areaBefore = testRect.getArea();
  const krasnopyorov::point_t dot = {1, 2};

  testRect.move(dot);

  BOOST_CHECK_CLOSE_FRACTION(testRect.getHeight(), heightBefore, INACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getWidth(), widthBefore, INACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaBefore, INACCURACY);

  const double dx = 3.0;
  const double dy = -1.0;

  testRect.move(dx, dy);

  BOOST_CHECK_CLOSE_FRACTION(testRect.getHeight(), heightBefore, INACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getWidth(), widthBefore, INACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaBefore, INACCURACY);

}

BOOST_AUTO_TEST_CASE(testAreaAfterScale)
{
  krasnopyorov::Rectangle testRect({2.5, 1.0, {0, 0}});
  const double k = 3.3;
  const double areaAfterScaling = testRect.getArea() * k * k;

  testRect.scale(k);

  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaAfterScaling, INACCURACY);
}

BOOST_AUTO_TEST_CASE(testIncorrectArgumets)
{
  BOOST_CHECK_THROW(krasnopyorov::Rectangle({-2.5, 1.0, {0, 0}}), std::invalid_argument);
  BOOST_CHECK_THROW(krasnopyorov::Rectangle({-2.5, -1.0, {0, 0}}), std::invalid_argument);

  krasnopyorov::Rectangle testRect({2.5, 1.0, {0, 0}});
  const double k = -3.0;

  BOOST_CHECK_THROW(testRect.scale(k), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
