#define BOOST_TEST_MODULE A2

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(A2TestSuite)

const double ACCURACY = 0.01;

BOOST_AUTO_TEST_CASE(circleConstancyAfterMoving)
{
  khismatullin::Circle testCircle({2, 4}, 5);
  const khismatullin::rectangle_t InitialFrame = testCircle.getFrameRect();
  const double InitialArea = testCircle.getArea();

  testCircle.move({3.2, 3.5});
  khismatullin::rectangle_t CurrentFrame = testCircle.getFrameRect();
  double CurrentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(InitialFrame.width, CurrentFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(InitialFrame.height, CurrentFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(InitialArea, CurrentArea, ACCURACY);

  testCircle.move(3.8, 3.5);
  CurrentFrame = testCircle.getFrameRect();
  CurrentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(InitialFrame.width, CurrentFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(InitialFrame.height, CurrentFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(InitialArea, CurrentArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangleConstancyAfterMoving)
{
  khismatullin::Rectangle testRectangle({2, 4}, 7, 10);
  const khismatullin::rectangle_t InitialFrame = testRectangle.getFrameRect();
  const double InitialArea = testRectangle.getArea();

  testRectangle.move({-3.2, 3.3});
  khismatullin::rectangle_t CurrentFrame = testRectangle.getFrameRect();
  double CurrentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(InitialFrame.width, CurrentFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(InitialFrame.height, CurrentFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(InitialArea, CurrentArea, ACCURACY);

  testRectangle.move(4.3, 2.2);
  CurrentFrame = testRectangle.getFrameRect();
  CurrentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(InitialFrame.width, CurrentFrame.width, ACCURACY);
  BOOST_CHECK_CLOSE(InitialFrame.height, CurrentFrame.height, ACCURACY);
  BOOST_CHECK_CLOSE(InitialArea, CurrentArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(circleScaling)
{
  khismatullin::Circle testCircle({5, 4}, 2);
  const double InitialArea = testCircle.getArea();

  const double ScaleMultiplier = 2.5;
  testCircle.scale(ScaleMultiplier);
  double CurrentArea = testCircle.getArea();
  BOOST_CHECK_CLOSE(InitialArea * ScaleMultiplier * ScaleMultiplier, CurrentArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangleScaling)
{
  khismatullin::Rectangle testRectangle({4, 2}, 10, 7);
  const double InitialArea = testRectangle.getArea();

  const double ScaleMultiplier = 3.3;
  testRectangle.scale(ScaleMultiplier);
  double CurrentArea = testRectangle.getArea();
  BOOST_CHECK_CLOSE(InitialArea * ScaleMultiplier * ScaleMultiplier, CurrentArea, ACCURACY);
}

BOOST_AUTO_TEST_CASE(throwingExceptions)
{
  BOOST_CHECK_THROW(khismatullin::Circle({5, 25}, -22.8), std::invalid_argument);
  BOOST_CHECK_THROW(khismatullin::Rectangle({4, 9}, -7, 3), std::invalid_argument);
  BOOST_CHECK_THROW(khismatullin::Rectangle({4, 9}, 7, -3), std::invalid_argument);
  BOOST_CHECK_THROW(khismatullin::Rectangle({4, 9}, -7, -3), std::invalid_argument);

  khismatullin::Rectangle testRectangle({15, 25}, 5, 6);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);

  khismatullin::Circle testCircle({15, 25}, 5.6);
  BOOST_CHECK_THROW(testCircle.scale(-6), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
