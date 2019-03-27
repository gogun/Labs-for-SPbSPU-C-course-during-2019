#define BOOST_TEST_MODULE A2

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

#define EPSILON 0.01

BOOST_AUTO_TEST_SUITE(chizhovA2TestSuite)

BOOST_AUTO_TEST_CASE(circleConstantAfterMove)
{
  chizhov::Circle dummyCircle({5, 5}, 4);
  const rectangle_t frameBefore = dummyCircle.getFrameRect();
  const double areaBefore = dummyCircle.getArea();

  dummyCircle.move({0, 0});
  rectangle_t frameAfter = dummyCircle.getFrameRect();
  double areaAfter = dummyCircle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);

  dummyCircle.move(5, 5);
  frameAfter = dummyCircle.getFrameRect();
  areaAfter = dummyCircle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(rectangleConstantAfterMove)
{
  chizhov::Rectangle dummyRectangle({5, 5}, 4, 6);
  const rectangle_t frameBefore = dummyRectangle.getFrameRect();
  const double areaBefore = dummyRectangle.getArea();

  dummyRectangle.move({0, 0});
  rectangle_t frameAfter = dummyRectangle.getFrameRect();
  double areaAfter = dummyRectangle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);

  dummyRectangle.move(5, 5);
  frameAfter = dummyRectangle.getFrameRect();
  areaAfter = dummyRectangle.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(circleScale)
{
  chizhov::Circle dummyCircle({5, 5}, 2);
  const double areaBefore = dummyCircle.getArea();

  const int scaleMultiplier = 2;
  dummyCircle.scale(scaleMultiplier);
  double areaAfter = dummyCircle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleMultiplier * scaleMultiplier, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(rectangleScale)
{
  chizhov::Rectangle dummyRectangle({5, 5}, 2, 6);
  const double areaBefore = dummyRectangle.getArea();

  const int scaleMultiplier = 2;
  dummyRectangle.scale(scaleMultiplier);
  double areaAfter = dummyRectangle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleMultiplier * scaleMultiplier, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(throwingExceptions)
{
  BOOST_CHECK_THROW(chizhov::Circle({5, 5}, -10), std::invalid_argument);
  BOOST_CHECK_THROW(chizhov::Rectangle({5, 5}, -2, -6), std::invalid_argument);

  chizhov::Rectangle dummyRectangle({5, 5}, 2, 6);
  BOOST_CHECK_THROW(dummyRectangle.scale(0), std::invalid_argument);

  chizhov::Circle dummyCircle({5, 5}, 2);
  BOOST_CHECK_THROW(dummyCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
