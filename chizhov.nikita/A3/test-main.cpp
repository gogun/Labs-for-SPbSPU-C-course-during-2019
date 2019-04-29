#define BOOST_TEST_MODULE A3

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>

#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

BOOST_AUTO_TEST_SUITE(chizhovA3TestSuite)

const double EPSILON = 0.01;

BOOST_AUTO_TEST_CASE(compositeConstantAfterMove)
{
  chizhov::Circle dummyCircle({1, 2}, 1);
  chizhov::Rectangle dummyRectangle({2 ,1}, 2);
  chizhov::CompositeShape dummyComposite(&dummyCircle);
  dummyComposite.addShape(&dummyRectangle);
  const chizhov::rectangle_t frameBefore = dummyComposite.getFrameRect();
  const double areaBefore = dummyComposite.getArea();

  dummyComposite.move({0, 0});
  chizhov::rectangle_t frameAfter = dummyComposite.getFrameRect();
  double areaAfter = dummyComposite.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);

  dummyComposite.move(5, 5);
  frameAfter = dummyComposite.getFrameRect();
  areaAfter = dummyComposite.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(compositeScale)
{
  chizhov::Circle dummyCircle({1, 2}, 1);
  chizhov::Rectangle dummyRectangle({2 ,1}, 2);
  chizhov::CompositeShape dummyComposite(&dummyCircle);
  dummyComposite.addShape(&dummyRectangle);
  const double areaBefore = dummyComposite.getArea();

  const int scaleMultiplier = 2;
  dummyComposite.scale(scaleMultiplier);
  double areaAfter = dummyComposite.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleMultiplier * scaleMultiplier, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(throwingExceptions)
{
  chizhov::Circle dummyCircle({1, 2}, 1);
  chizhov::CompositeShape dummyComposite;
  BOOST_CHECK_THROW(dummyComposite.scale(2), std::logic_error);
  BOOST_CHECK_THROW(dummyComposite.move({1, 1}), std::logic_error);

  dummyComposite.addShape(&dummyCircle);
  BOOST_CHECK_THROW(dummyComposite.scale(0), std::invalid_argument);

  BOOST_CHECK_THROW(dummyComposite.addShape(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(chizhov::CompositeShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
