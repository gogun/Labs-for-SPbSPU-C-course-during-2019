#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double epsilon = 0.01;

BOOST_AUTO_TEST_SUITE(testsRectangle)

BOOST_AUTO_TEST_CASE(testRectangleImmutabilityMoving)
{
  golikov::Rectangle rectangle1({{5, 5}, 6, 4});
  const double areaBeforeMoving = rectangle1.getArea();
  const double widthBeforeMoving = rectangle1.getFrameRect().width;
  const double heightBeforeMoving = rectangle1.getFrameRect().height;
  rectangle1.move({10, 10});

  BOOST_CHECK_CLOSE(areaBeforeMoving, rectangle1.getArea(), epsilon);
  BOOST_CHECK_CLOSE(widthBeforeMoving, rectangle1.getFrameRect().width, epsilon);
  BOOST_CHECK_CLOSE(heightBeforeMoving, rectangle1.getFrameRect().height, epsilon);
}

BOOST_AUTO_TEST_CASE(testRectangleImmutabilityScaling)
{
  golikov::Rectangle rectangle1({{5, 5}, 6, 4});
  const double coefficient = 3;
  const double areaBeforeScaling = rectangle1.getArea();
  rectangle1.scale(coefficient);

  BOOST_CHECK_CLOSE(areaBeforeScaling * coefficient * coefficient, rectangle1.getArea(), epsilon);
}

BOOST_AUTO_TEST_CASE(testRectangleIncorrectParams)
{
  golikov::Rectangle rectangle1({{5, 5}, 6, 4});
  BOOST_CHECK_THROW(golikov::Rectangle rectangle1({{5, 5}, -6, 4}), std::invalid_argument);
  // check not positive width or height
  BOOST_CHECK_THROW(rectangle1.scale(-1), std::invalid_argument);
  BOOST_CHECK_THROW(rectangle1.scale(0), std::invalid_argument);
  // check not positive coefficients when scaling
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testsCircle)

BOOST_AUTO_TEST_CASE(testCircleImmutabilityMoving)
{
  golikov::Circle circle1(5, 5, 5);
  const double areaBeforeMoving = circle1.getArea();
  const double radiusBeforeMoving = circle1.getFrameRect().width / 2;
  // the value of private radius by frame rectangle of the circle
  circle1.move({10, 10});

  BOOST_CHECK_CLOSE(areaBeforeMoving, circle1.getArea(), epsilon);
  BOOST_CHECK_CLOSE(radiusBeforeMoving, circle1.getFrameRect().width / 2, epsilon);
  // the value of private radius by frame rectangle of the circle
}

BOOST_AUTO_TEST_CASE(testCircleImmutabilityScaling)
{
  golikov::Circle circle1(5, 5, 5);
  const double coefficient = 0.5;
  const double areaBeforeScaling = circle1.getArea();
  circle1.scale(coefficient);

  BOOST_CHECK_CLOSE(areaBeforeScaling * coefficient * coefficient, circle1.getArea(), epsilon);
}

BOOST_AUTO_TEST_CASE(testCircleIncorrectParams)
{
  golikov::Circle circle1(5, 5, 5);
  BOOST_CHECK_THROW(golikov::Circle circle1(-2, 5, 5), std::invalid_argument);
  // check not positive width or height
  BOOST_CHECK_THROW(circle1.scale(-1), std::invalid_argument);
  BOOST_CHECK_THROW(circle1.scale(0), std::invalid_argument);
  // check not positive coefficients when scaling
}

BOOST_AUTO_TEST_SUITE_END()
