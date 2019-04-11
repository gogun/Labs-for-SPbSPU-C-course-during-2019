#define BOOST_TEST_MODULE A2

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

const double Epsilon = 0.01;

BOOST_AUTO_TEST_CASE(RectangleConstancyAfterMoving)
{
  tsygarova::Rectangle testRectangle({4, 2, {1, 3}});
  const tsygarova::rectangle_t InitFrame = testRectangle.getFrameRect();
  const double InitArea = testRectangle.getArea();

  testRectangle.move(4, 7);
  tsygarova::rectangle_t CurrentFrame = testRectangle.getFrameRect();
  double CurrentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(InitFrame.width, CurrentFrame.width, Epsilon);
  BOOST_CHECK_CLOSE(InitFrame.height, CurrentFrame.height, Epsilon);
  BOOST_CHECK_CLOSE(InitArea, CurrentArea, Epsilon);

  testRectangle.move({8, 6});
  CurrentFrame = testRectangle.getFrameRect();
  CurrentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(InitFrame.width, CurrentFrame.width, Epsilon);
  BOOST_CHECK_CLOSE(InitFrame.height, CurrentFrame.height, Epsilon);
  BOOST_CHECK_CLOSE(InitArea, CurrentArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(CircleConstancyAfterMoving)
{
  tsygarova::Circle testCircle(6, {2, 3});
  const tsygarova::rectangle_t InitFrame = testCircle.getFrameRect();
  const double InitArea = testCircle.getArea();

  testCircle.move(5, 9);
  tsygarova::rectangle_t CurrentFrame = testCircle.getFrameRect();
  double CurrentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(InitFrame.width, CurrentFrame.width, Epsilon);
  BOOST_CHECK_CLOSE(InitFrame.height, CurrentFrame.height, Epsilon);
  BOOST_CHECK_CLOSE(InitArea, CurrentArea, Epsilon);

  testCircle.move({9, 3});
  CurrentFrame = testCircle.getFrameRect();
  CurrentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(InitFrame.width, CurrentFrame.width, Epsilon);
  BOOST_CHECK_CLOSE(InitFrame.height, CurrentFrame.height, Epsilon);
  BOOST_CHECK_CLOSE(InitArea, CurrentArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(RectangleScaling)
{
  tsygarova::Rectangle testRectangle({4, 2, {1, 3}});
  const double InitArea = testRectangle.getArea();
  const double ScaleCoefficient = 4;

  testRectangle.scale(ScaleCoefficient);
  double CurrentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(InitArea * ScaleCoefficient * ScaleCoefficient, CurrentArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(CircleScaling)
{
  tsygarova::Circle testCircle(6, {2, 3});
  const double InitArea = testCircle.getArea();
  const double ScaleCoefficient = 2;

  testCircle.scale(ScaleCoefficient);
  double CurrentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(InitArea * ScaleCoefficient * ScaleCoefficient, CurrentArea, Epsilon);
}

BOOST_AUTO_TEST_CASE(InvalidParametersRectangle)
{
  BOOST_CHECK_THROW(tsygarova::Rectangle({-6, 3, {1, 3}}), std::invalid_argument);
  BOOST_CHECK_THROW(tsygarova::Rectangle({6, -3, {1, 3}}), std::invalid_argument);
  BOOST_CHECK_THROW(tsygarova::Rectangle({-6, -3, {1, 3}}), std::invalid_argument);
    
  tsygarova::Rectangle testRectangle({6, 3, {1, 3}});
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidParametersCircle)
{
  BOOST_CHECK_THROW(tsygarova::Circle(-7, {3, 4}), std::invalid_argument);
    
  tsygarova::Circle testCircle(7, {3, 4});
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
