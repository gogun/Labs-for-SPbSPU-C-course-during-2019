#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

const double accuracy = 0.01;

BOOST_AUTO_TEST_CASE(moveCircleTest)
{
  neupokoev::Circle testCircle({ 3, 4 }, 5);
  const neupokoev::rectangle_t InitialFrameRect = testCircle.getFrameRect();
  const double InitialArea = testCircle.getArea();

  testCircle.move({ 7, 8 });
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testCircle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testCircle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(InitialArea, testCircle.getArea(), accuracy);

  testCircle.move(-5, -6);
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testCircle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testCircle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(InitialArea, testCircle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(moveRectangleTest)
{
  neupokoev::Rectangle testRectangle({{ 3, 4 }, 5, 6});
  const neupokoev::rectangle_t InitialFrameRect = testRectangle.getFrameRect();
  const double InitialArea = testRectangle.getArea();

  testRectangle.move({ 7, 8 });
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testRectangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testRectangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(InitialArea, testRectangle.getArea(), accuracy);

  testRectangle.move(-5, -6);
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testRectangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testRectangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(InitialArea, testRectangle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(moveTriangleTest)
{
  neupokoev::Triangle testTriangle({0, 0}, {4, 1}, {3, 7});
  const neupokoev::rectangle_t InitialFrameRect = testTriangle.getFrameRect();
  const double InitialArea = testTriangle.getArea();

  testTriangle.move({ 7, 8 });
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testTriangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testTriangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(InitialArea, testTriangle.getArea(), accuracy);

  testTriangle.move(-5, -6);
  BOOST_CHECK_CLOSE(InitialFrameRect.width, testTriangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(InitialFrameRect.height, testTriangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(InitialArea, testTriangle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(areaAfterScalingCircleTest)
{
  neupokoev::Circle testCircle({ 3, 4 }, 5);
  const double InitialArea = testCircle.getArea();
  const double scaleFactor = 4;

  testCircle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testCircle.getArea(), scaleFactor * scaleFactor * InitialArea, accuracy);
}

BOOST_AUTO_TEST_CASE(areaAfterScalingRectangleTest)
{
  neupokoev::Rectangle testRectangle({{ 4, 5 }, 6, 7});
  const double InitialArea = testRectangle.getArea();
  const double scaleFactor = 3;

  testRectangle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), scaleFactor * scaleFactor * InitialArea, accuracy);
}

BOOST_AUTO_TEST_CASE(areaAfterScalingTriangleTest)
{
  neupokoev::Triangle testTriangle({ 0, 0 }, { 4, 1 }, { 3, 7 });
  const double InitialArea = testTriangle.getArea();
  const double scaleFactor = 4;

  testTriangle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), scaleFactor * scaleFactor * InitialArea, accuracy);
}

BOOST_AUTO_TEST_CASE(invalidScaleArgumentsCircle)
{
  BOOST_CHECK_THROW(neupokoev::Circle({ 1, 2 }, -3), std::invalid_argument);

  neupokoev::Circle testCircle({ 1, 2 }, 3);
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidScaleArgumentsRectangle)
{
  BOOST_CHECK_THROW(neupokoev::Rectangle({{ 1, 2 }, 3, -4}), std::invalid_argument);
  BOOST_CHECK_THROW(neupokoev::Rectangle({{ 1, 2 }, -3, 4}), std::invalid_argument);

  neupokoev::Rectangle testRectangle({{ 1, 2 }, 3, 4});
  BOOST_CHECK_THROW(testRectangle.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidScaleArgumentsTriangle)
{
  neupokoev::Triangle testTriangle({ 0, 0 }, { 4, 1 }, { 3, 7 });
  BOOST_CHECK_THROW(testTriangle.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidPointsTriangle)
{
  BOOST_CHECK_THROW(neupokoev::Triangle({ 0, 0 }, { 4, 0 }, { 8, 0 }), std::invalid_argument);
  BOOST_CHECK_THROW(neupokoev::Triangle({ 0, 0 }, { 0, 0 }, { 0, 0 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
