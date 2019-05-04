#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>

#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

BOOST_AUTO_TEST_SUITE(chizhovCompositeTestSuite)

const double EPSILON = 0.01;
chizhov::Circle circle({1, 2}, 1);
chizhov::Rectangle rectangle({2 ,1}, 2);

BOOST_AUTO_TEST_CASE(compositeConstantAfterMove)
{
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
  chizhov::CompositeShape composite(&circle);
  composite.addShape(&rectangle);
  const double areaBefore = composite.getArea();

  const int scaleMultiplier = 2;
  composite.scale(scaleMultiplier);
  double areaAfter = composite.getArea();
  BOOST_CHECK_CLOSE(areaBefore * scaleMultiplier * scaleMultiplier, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(scaleEmptyException)
{
  chizhov::CompositeShape emptyComposite;
  BOOST_CHECK_THROW(emptyComposite.scale(2), std::logic_error);
}

BOOST_AUTO_TEST_CASE(moveEmptyException)
{
  chizhov::CompositeShape emptyComposite;
  BOOST_CHECK_THROW(emptyComposite.move({1, 1}), std::logic_error);
}

BOOST_AUTO_TEST_CASE(scaleZeroException)
{
  chizhov::CompositeShape composite(&circle);
  BOOST_CHECK_THROW(composite.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(nullShapeException)
{
  chizhov::CompositeShape emptyComposite;
  BOOST_CHECK_THROW(emptyComposite.addShape(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(chizhov::CompositeShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(outOfRangeException)
{
  chizhov::CompositeShape emptyComposite;
  BOOST_CHECK_THROW(emptyComposite[-1], std::out_of_range);
  BOOST_CHECK_THROW(emptyComposite[0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(CompositeGetAndDelete)
{
  chizhov::CompositeShape composite(&circle);
  const chizhov::rectangle_t frameBefore = composite.getFrameRect();
  const double areaBefore = composite.getArea();

  composite.addShape(&rectangle);

  int count = composite.getCount();
  chizhov::Shape* shapeToDelete = composite[count - 1];
  composite.deleteShape(shapeToDelete);

  chizhov::rectangle_t frameAfter = composite.getFrameRect();
  double areaAfter = composite.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(moveSemanticsComposite)
{
  chizhov::CompositeShape compositeFrom(&circle);
  chizhov::CompositeShape compositeTo(&rectangle);

  const chizhov::rectangle_t frameBefore = compositeFrom.getFrameRect();
  const double areaBefore = compositeFrom.getArea();

  compositeTo = std::move(compositeFrom);

  chizhov::rectangle_t frameAfter = compositeTo.getFrameRect();
  double areaAfter = compositeTo.getArea();
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, EPSILON);
}

BOOST_AUTO_TEST_CASE(copySemanticsComposite)
{
  chizhov::CompositeShape compositeFrom(&circle);
  chizhov::CompositeShape compositeTo(&rectangle);

  const double targetArea = circle.getArea() + rectangle.getArea();

  compositeTo = compositeFrom;
  compositeTo.addShape(&rectangle);

  BOOST_CHECK_CLOSE(targetArea, compositeTo.getArea(), EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
