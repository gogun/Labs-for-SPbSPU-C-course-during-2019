#define BOOST_TEST_MAIN A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(MyTests)

const double ALLOWABLE_ERROR = 0.001;

BOOST_AUTO_TEST_CASE(ImmutabilityofRectangleParameters)
{
  lukina::Rectangle rec({0.0, 0.0}, 2.0, 4.0);
  const lukina::rectangle_t recBefore = rec.getFrameRect();
  const double areaBefore = rec.getArea();

  rec.move(1.0, 2.0);
  BOOST_CHECK_CLOSE(recBefore.width, rec.getFrameRect().width, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(recBefore.height, rec.getFrameRect().height, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(areaBefore, rec.getArea(), ALLOWABLE_ERROR);

  rec.move({3.0, 6.0});
  BOOST_CHECK_CLOSE(recBefore.width, rec.getFrameRect().width, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(recBefore.height, rec.getFrameRect().height, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(areaBefore, rec.getArea(), ALLOWABLE_ERROR);
}

BOOST_AUTO_TEST_CASE(ImmutabilityofCircleParameters)
{
  lukina::Circle cir({0.1, 0.1}, 5.0);
  const lukina::rectangle_t cirBefore = cir.getFrameRect();
  const double areaBefore = cir.getArea();

  cir.move(1.0, 2.0);
  BOOST_CHECK_CLOSE(cirBefore.width, cir.getFrameRect().width, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(cirBefore.height, cir.getFrameRect().height, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(areaBefore, cir.getArea(), ALLOWABLE_ERROR);


  cir.move({-1.0, -1.0});
  BOOST_CHECK_CLOSE(cirBefore.width, cir.getFrameRect().width, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(cirBefore.height, cir.getFrameRect().height, ALLOWABLE_ERROR);
  BOOST_CHECK_CLOSE(areaBefore, cir.getArea(), ALLOWABLE_ERROR);
}

BOOST_AUTO_TEST_CASE(RectangleAreaAfterScale)
{
  lukina::Rectangle rec({2.0, 2.0}, 4.0, 5.0);
  const double areaBefore = rec.getArea();
  const double scaleFactor = 2.0;

  rec.scale(scaleFactor);
  BOOST_CHECK_CLOSE(areaBefore * scaleFactor * scaleFactor, rec.getArea(), ALLOWABLE_ERROR);
}

BOOST_AUTO_TEST_CASE(CircleAreaAfterScale)
{
  lukina::Circle cir({2.0, 2.0}, 3.0);
  const double areaBefore = cir.getArea();
  const double scaleFactor = 2.0;

  cir.scale(scaleFactor);
  BOOST_CHECK_CLOSE(areaBefore * scaleFactor * scaleFactor, cir.getArea(), ALLOWABLE_ERROR);
}

BOOST_AUTO_TEST_CASE(RectangleIncorrectParameters)
{
  BOOST_CHECK_THROW(lukina::Rectangle({0.0, 0.0}, -1.0, 2.0), std::invalid_argument);
  BOOST_CHECK_THROW(lukina::Rectangle({0.0, 0.0}, 1.0, -2.0), std::invalid_argument);

  lukina::Rectangle rec({0.0, 0.1}, 2.0, 3.0);
  BOOST_CHECK_THROW(rec.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleIncorrectParameters)
{
  BOOST_CHECK_THROW(lukina::Circle({0.0, 0.0}, -1.0), std::invalid_argument);

  lukina::Circle cir({0.0, 0.1}, 2.0);
  BOOST_CHECK_THROW(cir.scale(-1.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
