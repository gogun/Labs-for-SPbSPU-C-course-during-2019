#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>

#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(chizhovCircleTestSuite)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(circleConstantAfterMove)
{
  chizhov::Circle dummyCircle({5, 5}, 4);
  const chizhov::rectangle_t frameBefore = dummyCircle.getFrameRect();
  const double areaBefore = dummyCircle.getArea();

  dummyCircle.move({0, 0});
  chizhov::rectangle_t frameAfter = dummyCircle.getFrameRect();
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

BOOST_AUTO_TEST_CASE(circleScale)
{
  chizhov::Circle dummyCircle({5, 5}, 2);
  const double areaBefore = dummyCircle.getArea();

  const int scaleMultiplier = 2;
  dummyCircle.scale(scaleMultiplier);
  double areaAfter = dummyCircle.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleMultiplier * scaleMultiplier, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(throwingExceptions)
{
  BOOST_CHECK_THROW(chizhov::Circle({5, 5}, -10), std::invalid_argument);

  chizhov::Circle dummyCircle({5, 5}, 2);
  BOOST_CHECK_THROW(dummyCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
