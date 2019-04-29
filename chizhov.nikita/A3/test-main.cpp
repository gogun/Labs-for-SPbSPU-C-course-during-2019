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
  chizhov::Circle circle({1, 2}, 1);
  chizhov::Rectangle rectangle({2 ,1}, 2);
  chizhov::CompositeShape composite(&circle);
  composite.addShape(&rectangle);
  const chizhov::rectangle_t frameBefore = composite.getFrameRect();
  const double areaBefore = composite.getArea();

  composite.move({0, 0});
  chizhov::rectangle_t frameAfter = composite.getFrameRect();
  double areaAfter = composite.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);

  composite.move(5, 5);
  frameAfter = composite.getFrameRect();
  areaAfter = composite.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(compositeScale)
{
  chizhov::Circle circle({1, 2}, 1);
  chizhov::Rectangle rectangle({2 ,1}, 2);
  chizhov::CompositeShape composite(&circle);
  composite.addShape(&rectangle);
  const double areaBefore = composite.getArea();

  const int scaleMultiplier = 2;
  composite.scale(scaleMultiplier);
  double areaAfter = composite.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleMultiplier * scaleMultiplier, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(throwingExceptions)
{
  chizhov::Circle circle({1, 2}, 1);
  chizhov::CompositeShape composite;
  BOOST_CHECK_THROW(composite.scale(2), std::logic_error);
  BOOST_CHECK_THROW(composite.move({1, 1}), std::logic_error);

  composite.addShape(&circle);
  BOOST_CHECK_THROW(composite.scale(0), std::invalid_argument);

  composite = chizhov::CompositeShape();
  BOOST_CHECK_THROW(composite.addShape(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(chizhov::CompositeShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
