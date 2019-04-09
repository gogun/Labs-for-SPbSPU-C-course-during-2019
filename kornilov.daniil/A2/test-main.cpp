#define BOOST_TEST_MODULE lab_A2

#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(WidthPermanencyAfterMovingdXdY)
{
  double width = 10;
  kornilov::Rectangle rectangle({{0, 0}, width, 11});
  rectangle.move(10, 10);
  BOOST_CHECK_EQUAL(width, rectangle.getFrameRect().width);
}

BOOST_AUTO_TEST_CASE(WidthPermanencyAfterMovingToPoint)
{
  double width = 10;
  kornilov::Rectangle rectangle({{0, 0}, width, 11});
  rectangle.move({10, 10});
  BOOST_CHECK_EQUAL(width, rectangle.getFrameRect().width);
}

BOOST_AUTO_TEST_CASE(HeightPermanencyAfterMovingdXdY)
{
  double height = 11;
  kornilov::Rectangle rectangle({{0, 0}, 10, height});
  rectangle.move(10, 10);
  BOOST_CHECK_EQUAL(height, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(HeightPermanencyAfterMovingToPoint)
{
  double height = 11;
  kornilov::Rectangle rectangle({{0, 0}, 10, height});
  rectangle.move({10, 10});
  BOOST_CHECK_EQUAL(height, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingdXdY)
{
  kornilov::Rectangle rectangle({{0, 0}, 10, 11});
  double rectArea = rectangle.getArea();
  rectangle.move(10, 10);
  BOOST_CHECK_EQUAL(rectArea, rectangle.getArea());
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingToPoint)
{
  kornilov::Rectangle rectangle({{0, 0}, 10, 11});
  double rectArea = rectangle.getArea();
  rectangle.move({10, 10});
  BOOST_CHECK_EQUAL(rectArea, rectangle.getArea());
}

BOOST_AUTO_TEST_CASE(SquareChangingAfterScaling)
{
  kornilov::Rectangle rectangle({{0, 0}, 10, 11});
  double rectArea = rectangle.getArea();
  double coef = 2;
  rectangle.scale(coef);
  BOOST_CHECK_EQUAL(coef * coef, rectangle.getArea() / rectArea);
}

BOOST_AUTO_TEST_CASE(InvalidWidth)
{
  double width = 0;
  BOOST_CHECK_THROW(kornilov::Rectangle rectangle({{0, 0}, width, 11}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidHeight)
{
  double height = 0;
  BOOST_CHECK_THROW(kornilov::Rectangle rectangle({{0, 0}, 10, height}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient)
{
  double coef = 0;
  kornilov::Rectangle rectangle({{0, 0}, 10, 11});
  BOOST_CHECK_THROW(rectangle.scale(coef), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(RadiusPermanencyAfterMovingdXdY)
{
  double radius = 10;
  kornilov::Circle circle({0, 0}, radius);
  circle.move(10, 10);
  BOOST_CHECK_EQUAL(radius, circle.getFrameRect().height / 2);
}

BOOST_AUTO_TEST_CASE(RadiusPermanencyAfterMovingToPoint)
{
  double radius = 10;
  kornilov::Circle circle({0, 0}, radius);
  circle.move({10, 10});
  BOOST_CHECK_EQUAL(radius, circle.getFrameRect().height / 2);
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingdXdY)
{
  kornilov::Circle circle({0, 0}, 10);
  double circArea = circle.getArea();
  circle.move(10, 10);
  BOOST_CHECK_EQUAL(circArea, circle.getArea());
}

BOOST_AUTO_TEST_CASE(AreaPermanencyAfterMovingToPoint)
{
  kornilov::Circle circle({0, 0}, 10);
  double circArea = circle.getArea();
  circle.move({10, 10});
  BOOST_CHECK_EQUAL(circArea, circle.getArea());
}

BOOST_AUTO_TEST_CASE(SquareChangingAfterScaling)
{
  kornilov::Circle circle({0, 0}, 10);
  double circArea = circle.getArea();
  double coef = 2;
  circle.scale(coef);
  BOOST_CHECK_EQUAL(coef * coef, circle.getArea() / circArea);
}

BOOST_AUTO_TEST_CASE(InvalidRadius)
{
  double radius = 0;
  BOOST_CHECK_THROW(kornilov::Circle circle({0, 0}, radius), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient)
{
  kornilov::Circle circle({0, 0}, 10);
  double coef = 0;
  BOOST_CHECK_THROW(circle.scale(coef), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
