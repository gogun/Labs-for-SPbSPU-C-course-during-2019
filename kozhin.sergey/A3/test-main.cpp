#define BOOST_TEST_MODULE A3_TEST

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

const double DIFF = 0.001;

BOOST_AUTO_TEST_SUITE(compositeShapeTestSuite)

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingShapeRelatively)
{
  kozhin::Circle testCircle({5, -6}, 4);
  kozhin::Rectangle testRectangle({-10, 6}, 3, 7);

  kozhin::CompositeShape testComposite(testCircle);
  testComposite.add(testRectangle);
  const double initialArea = testComposite.getArea();
  const kozhin::rectangle_t initialFrameRect = testComposite.getFrameRect();

  testComposite.move(3, -5);
  const kozhin::rectangle_t newFrameRect = testComposite.getFrameRect();
  BOOST_CHECK_CLOSE(newFrameRect.width, initialFrameRect.width, DIFF);
  BOOST_CHECK_CLOSE(newFrameRect.height, initialFrameRect.height, DIFF);
  BOOST_CHECK_CLOSE(testComposite.getArea(), initialArea, DIFF);
}

BOOST_AUTO_TEST_CASE(sameParamsAfterMovingShapeAbsolutely)
{
  kozhin::Circle testCircle({5, -6}, 4);
  kozhin::Rectangle testRectangle({-10, 6}, 3, 7);

  kozhin::CompositeShape testComposite(testCircle);
  testComposite.add(testRectangle);
  const double initialArea = testComposite.getArea();
  const kozhin::rectangle_t initialFrameRect = testComposite.getFrameRect();

  testComposite.move({-5, 3});
  const kozhin::rectangle_t newFrameRect = testComposite.getFrameRect();
  BOOST_CHECK_CLOSE(newFrameRect.width, initialFrameRect.width, DIFF);
  BOOST_CHECK_CLOSE(newFrameRect.height, initialFrameRect.height, DIFF);
  BOOST_CHECK_CLOSE(testComposite.getArea(), initialArea, DIFF);
}

BOOST_AUTO_TEST_CASE(areaChangeAfterShapeScaling)
{
  kozhin::Circle testCircle({-7, 8}, 3);
  kozhin::Rectangle testRectangle({8, -3}, 3, 7);

  kozhin::CompositeShape testComposite(testCircle);
  testComposite.add(testRectangle);

  const double scaleRate = 3.2;
  const double initialArea = testComposite.getArea();

  testComposite.scale(scaleRate);
  BOOST_CHECK_CLOSE(testComposite.getArea(), initialArea * scaleRate * scaleRate, DIFF);
}

BOOST_AUTO_TEST_CASE(frameRectChangeAfterShapeScaling)
{
  kozhin::Circle testCircle({-7, 8}, 3);
  kozhin::Rectangle testRectangle({8, -3}, 3, 7);

  kozhin::CompositeShape testComposite(testCircle);
  testComposite.add(testRectangle);

  const double scaleRate = 3.2;
  const kozhin::rectangle_t initialFrame = testComposite.getFrameRect();

  testComposite.scale(scaleRate);

  const kozhin::rectangle_t newFrame = testComposite.getFrameRect();
  BOOST_CHECK_CLOSE(initialFrame.width * scaleRate, newFrame.width, DIFF);
  BOOST_CHECK_CLOSE(initialFrame.height * scaleRate, newFrame.height, DIFF);
  BOOST_CHECK_CLOSE(initialFrame.pos.x, newFrame.pos.x, DIFF);
  BOOST_CHECK_CLOSE(initialFrame.pos.y, newFrame.pos.y, DIFF);
}

BOOST_AUTO_TEST_CASE(areaChangeAfterAdding)
{
  kozhin::Circle testCircle({10, -5}, 5);
  kozhin::CompositeShape testComposite(testCircle);
  const double initialArea = testComposite.getArea();

  kozhin::Rectangle testRectangle({-7, 6}, 5, 4);
  testComposite.add(testRectangle);
  const double newArea = testComposite.getArea();

  BOOST_CHECK_CLOSE(initialArea + testRectangle.getArea(), newArea, DIFF);
}

BOOST_AUTO_TEST_CASE(areaChangeAfterDeleting)
{
  kozhin::Circle testCircle({10, -5}, 5);
  kozhin::CompositeShape testComposite(testCircle);
  kozhin::Rectangle testRectangle({-7, 6}, 5, 4);
  testComposite.add(testRectangle);
  const double initialArea = testComposite.getArea();

  testComposite.remove(0);
  const double newArea = testComposite.getArea();

  BOOST_CHECK_CLOSE(initialArea - testCircle.getArea(), newArea, DIFF);
}

BOOST_AUTO_TEST_CASE(movingEmptyShapeHandling)
{
  kozhin::CompositeShape testComposite;

  BOOST_CHECK_THROW(testComposite.move(3,5), std::logic_error);
  BOOST_CHECK_THROW(testComposite.move({5,6}), std::logic_error);
}

BOOST_AUTO_TEST_CASE(gettingEmptyShapeAreaHandling)
{
  kozhin::CompositeShape testComposite;

  BOOST_CHECK_THROW(testComposite.getArea(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(gettingEmptyShapeFrameHandling)
{
  kozhin::CompositeShape testComposite;

  BOOST_CHECK_THROW(testComposite.getFrameRect(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(nonPositiveScaleRateHandling)
{
  kozhin::Circle testCircle({5, -6}, 4);
  kozhin::Rectangle testRectangle({-10, 6}, 3, 7);
  kozhin::CompositeShape testComposite(testCircle);
  testComposite.add(testRectangle);

  BOOST_CHECK_THROW(testComposite.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(accesingOutOfRangeHandling)
{
  kozhin::Circle testCircle({5, -6}, 4);
  kozhin::Rectangle testRectangle({-10, 6}, 3, 7);
  kozhin::CompositeShape testComposite(testCircle);
  testComposite.add(testRectangle);

  BOOST_CHECK_THROW(testComposite.get(5), std::out_of_range);
  BOOST_CHECK_THROW(testComposite[-1], std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
