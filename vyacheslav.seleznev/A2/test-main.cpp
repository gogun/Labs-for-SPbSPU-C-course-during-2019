#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

const double INACCURACY  = 0.0001;

BOOST_AUTO_TEST_SUITE(triangleTests)

BOOST_AUTO_TEST_CASE(checkUnchangedLengthA)
{
  seleznev::Triangle triangleCheck({-7, 10}, {11, 44}, {5, -7});
  double lengthA = triangleCheck.getLengthA();
  triangleCheck.move(6, -11);
  BOOST_CHECK_CLOSE(triangleCheck.getLengthA(), lengthA, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkUnchangedLengthB)
{
  seleznev::Triangle triangleCheck({-7, 10}, {11, 44}, {5, -7});
  double lengthB = triangleCheck.getLengthB();
  triangleCheck.move(6, -11);
  BOOST_CHECK_CLOSE(triangleCheck.getLengthB(), lengthB, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkUnchangedLengthC)
{
  seleznev::Triangle triangleCheck({-7, 10}, {11, 44}, {5, -7});
  double lengthC = triangleCheck.getLengthC();
  triangleCheck.move(6, -11);
  BOOST_CHECK_CLOSE(triangleCheck.getLengthC(), lengthC, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkArea)
{
  seleznev::Triangle triangleCheck({-7, 10}, {11, 44}, {5, -7});
  double area = triangleCheck.getArea();
  triangleCheck.move(6, -11);
  BOOST_CHECK_CLOSE(triangleCheck.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkScaling)
{
  seleznev::Triangle triangleCheck({-7, 10}, {11, 44}, {5, -7});
  double area = triangleCheck.getArea();
  double coefficient = 4.1;
  triangleCheck.scale(coefficient);
  BOOST_CHECK_CLOSE(triangleCheck.getArea(), coefficient * coefficient * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkParametrsTriangleProperties)
{
  BOOST_CHECK_THROW(seleznev::Triangle triangleCheck({-7, -7}, {-7, -7}, {-7, -7}), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(checkTriangleParametrsScale)
{
  seleznev::Triangle triangleCheck({-7, 10}, {11, 44}, {5, -7});

  BOOST_CHECK_THROW(triangleCheck.scale(-9), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangleTests)

BOOST_AUTO_TEST_CASE(checkUnchangedHeight)
{
  seleznev::Rectangle rectangleCheck(10, 8, {-7, 5});
  double height = rectangleCheck.getHeight();
  rectangleCheck.move(16, -8);
  BOOST_CHECK_CLOSE(rectangleCheck.getFrameRect().height, height, INACCURACY);
  rectangleCheck.move(15, 15);
  BOOST_CHECK_CLOSE(rectangleCheck.getFrameRect().height, height, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkUnchangedWidth)
{
  seleznev::Rectangle rectangleCheck(10, 8, {-7, 5});
  double width = rectangleCheck.getWidth();
  rectangleCheck.move(16, -8);
  BOOST_CHECK_CLOSE(rectangleCheck.getFrameRect().width, width, INACCURACY);
  rectangleCheck.move(15, 15);
  BOOST_CHECK_CLOSE(rectangleCheck.getFrameRect().width, width, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkArea)
{
  seleznev::Rectangle rectangleCheck(10, 8, {-7, 5});
  double area = rectangleCheck.getArea();
  rectangleCheck.move(16, -8);
  BOOST_CHECK_CLOSE(rectangleCheck.getArea(), area, INACCURACY);
  rectangleCheck.move(15, 15);
  BOOST_CHECK_CLOSE(rectangleCheck.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkScaling)
{
  seleznev::Rectangle rectangleCheck(10, 8, {-7, 5});
  double area = rectangleCheck.getArea();
  double coefficient = 5.8;
  rectangleCheck.scale(coefficient);
  BOOST_CHECK_CLOSE(rectangleCheck.getArea(), coefficient * coefficient * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkParametrsWidth)
{
  BOOST_CHECK_THROW(seleznev::Rectangle rectangleCheck(-10, 8, {-7, 5}), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(checkParametrsHeight)
{
  BOOST_CHECK_THROW(seleznev::Rectangle rectangleCheck(10, -8, {-7, 5}), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(checkRectangleParametrsScale)
{
  seleznev::Rectangle rectangleCheck(10, 8, {-7, 5});

  BOOST_CHECK_THROW(rectangleCheck.scale(-4), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circleTests)

BOOST_AUTO_TEST_CASE(checkUnchangedRadius)
{
  seleznev::Circle circleCheck(10, { -7, 5 });
  double radius = circleCheck.getRadius();
  circleCheck.move(65, 33);
  BOOST_CHECK_CLOSE(circleCheck.getRadius(), radius, INACCURACY);
  circleCheck.move(14, 31);
  BOOST_CHECK_CLOSE(circleCheck.getRadius(), radius, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkArea)
{
  seleznev::Circle circleCheck(10, { -7, 5 });
  double area = circleCheck.getArea();
  circleCheck.move(43, -11);
  BOOST_CHECK_CLOSE(circleCheck.getArea(), area, INACCURACY);
  circleCheck.move(4, 3);
  BOOST_CHECK_CLOSE(circleCheck.getArea(), area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkScaling)
{
  seleznev::Circle circleCheck(10, { -7, 5 });
  double area = circleCheck.getArea();
  double coefficient = 7.8;
  circleCheck.scale(coefficient);
  BOOST_CHECK_CLOSE(circleCheck.getArea(), coefficient * coefficient * area, INACCURACY);
}

BOOST_AUTO_TEST_CASE(checkParametrsRadius)
{
  BOOST_CHECK_THROW(seleznev::Circle circleCheck(-10, { -7, 5 }), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(checkParametrsScale)
{
  seleznev::Circle circleCheck(10, { -7, 5 });

  BOOST_CHECK_THROW(circleCheck.scale(-4), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
