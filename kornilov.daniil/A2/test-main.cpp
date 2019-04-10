#define BOOST_TEST_MODULE lab_A2

#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double CHECKERROR = 0.0001;

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(WidthPermanencyAfterMovingdXdY)
{
  const double width = 10.1;
  kornilov::Rectangle rectangle({{0, 0}, width, 11});
  rectangle.move(10, 10);
  BOOST_CHECK_CLOSE(width, rectangle.getFrameRect().width, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(WidthPermanencyAfterMovingToPoint)
{
  const double width = 10.1;
  kornilov::Rectangle rectangle({{0, 0}, width, 11});
  rectangle.move({10, 10});
  BOOST_CHECK_CLOSE(width, rectangle.getFrameRect().width, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(HeightPermanencyAfterMovingdXdY)
{
  const double height = 11.1;
  kornilov::Rectangle rectangle({{0, 0}, 10, height});
  rectangle.move(10, 10);
  BOOST_CHECK_CLOSE(height, rectangle.getFrameRect().height, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(HeightPermanencyAfterMovingToPoint)
{
  const double height = 11.1;
  kornilov::Rectangle rectangle({{0, 0}, 10, height});
  rectangle.move({10, 10});
  BOOST_CHECK_CLOSE(height, rectangle.getFrameRect().height, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingdXdY)
{
  kornilov::Rectangle rectangle({{0, 0}, 10.1, 11.1});
  const double rectArea = rectangle.getArea();
  rectangle.move(10, 10);
  BOOST_CHECK_CLOSE(rectArea, rectangle.getArea(), CHECKERROR);
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingToPoint)
{
  kornilov::Rectangle rectangle({{0, 0}, 10.1, 11.1});
  const double rectArea = rectangle.getArea();
  rectangle.move({10, 10});
  BOOST_CHECK_CLOSE(rectArea, rectangle.getArea(), CHECKERROR);
}

BOOST_AUTO_TEST_CASE(SquareChangingAfterScaling)
{
  kornilov::Rectangle rectangle({{0, 0}, 10.1, 11.1});
  const double rectArea = rectangle.getArea();
  const double coef = 2.1;
  rectangle.scale(coef);
  BOOST_CHECK_CLOSE(coef * coef, rectangle.getArea() / rectArea, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(InvalidWidth)
{
  const double width = -0.1;
  BOOST_CHECK_THROW(kornilov::Rectangle rectangle({{0, 0}, width, 11}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidHeight)
{
  const double height = -0.1;
  BOOST_CHECK_THROW(kornilov::Rectangle rectangle({{0, 0}, 10, height}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient)
{
  const double coef = -0.1;
  kornilov::Rectangle rectangle({{0, 0}, 10, 11});
  BOOST_CHECK_THROW(rectangle.scale(coef), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(RadiusPermanencyAfterMovingdXdY)
{
  const double radius = 10.1;
  kornilov::Circle circle({0, 0}, radius);
  circle.move(10, 10);
  BOOST_CHECK_CLOSE(radius, circle.getFrameRect().height / 2, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(RadiusPermanencyAfterMovingToPoint)
{
  const double radius = 10.1;
  kornilov::Circle circle({0, 0}, radius);
  circle.move({10, 10});
  BOOST_CHECK_CLOSE(radius, circle.getFrameRect().height / 2, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingdXdY)
{
  kornilov::Circle circle({0, 0}, 10.1);
  const double circArea = circle.getArea();
  circle.move(10, 10);
  BOOST_CHECK_CLOSE(circArea, circle.getArea(), CHECKERROR);
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingToPoint)
{
  kornilov::Circle circle({0, 0}, 10.1);
  const double circArea = circle.getArea();
  circle.move({10, 10});
  BOOST_CHECK_CLOSE(circArea, circle.getArea(), CHECKERROR);
}

BOOST_AUTO_TEST_CASE(SquareChangingAfterScaling)
{
  kornilov::Circle circle({0, 0}, 10.1);
  const double circArea = circle.getArea();
  const double coef = 2.1;
  circle.scale(coef);
  BOOST_CHECK_CLOSE(coef * coef, circle.getArea() / circArea, CHECKERROR);
}

BOOST_AUTO_TEST_CASE(InvalidRadius)
{
  const double radius = -0.1;
  BOOST_CHECK_THROW(kornilov::Circle circle({0, 0}, radius), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient)
{
  kornilov::Circle circle({0, 0}, 10);
  const double coef = -0.1;
  BOOST_CHECK_THROW(circle.scale(coef), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
