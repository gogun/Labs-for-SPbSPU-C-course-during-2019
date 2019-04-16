#define BOOST_TEST_MODULE A3

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

BOOST_AUTO_TEST_SUITE(compositeShapeTestSuite)

const double ErrorValue = 0.01;

BOOST_AUTO_TEST_CASE(invariabilityAfterMovingComposite)
{
  barekov::Circle testCircle({4, 4}, 8.7);
  barekov::Rectangle testRectangle({5, 6}, 7.8, 8.9);
  barekov::CompositeShape testComposite(&testCircle);
  testComposite.addShape(&testRectangle);
  const barekov::rectangle_t InitialFrameRect = testComposite.getFrameRect();
  const double InitialArea = testComposite.getArea();

  testComposite.move({1.9, 1.9});
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testComposite.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testComposite.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(InitialArea, testComposite.getArea(), ErrorValue);

  testComposite.move(5, -7);
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testComposite.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testComposite.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(InitialArea, testComposite.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterScalingComposite)
{
  barekov::Circle testCircle({4, 4}, 3);
  barekov::Rectangle testRectangle({5, 6}, 2.1, 1);
  barekov::CompositeShape testComposite(&testCircle);
  testComposite.addShape(&testRectangle);
  const double InitialArea = testComposite.getArea();
  const double scaleFactor = 2.75;
  testComposite.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testComposite.getArea(), scaleFactor * scaleFactor * InitialArea, ErrorValue);
}

BOOST_AUTO_TEST_CASE(invalidArgumentsComposite)
{
  BOOST_CHECK_THROW(barekov::CompositeShape(nullptr), std::invalid_argument);

  barekov::Circle testCircle({1, 2}, 3);
  barekov::Rectangle testRectangle({4, 5}, 6, 7);
  barekov::CompositeShape testComposite(&testCircle);
  testComposite.addShape(&testRectangle);
  BOOST_CHECK_THROW(testComposite.scale(-2), std::invalid_argument);

  BOOST_CHECK_THROW(testComposite.addShape(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(testComposite.deleteShape(4), std::out_of_range);
  BOOST_CHECK_THROW(testComposite.deleteShape(-2), std::out_of_range);

  testComposite.deleteShape(1);
  BOOST_CHECK_THROW(testComposite.deleteShape(0), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
