#define BOOST_TEST_MODULE unittest

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"


//circle

BOOST_AUTO_TEST_SUITE(testsForCircle)

const double EPS = 0.01;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  tagiev::Circle testCircle({1.0, 2.0}, 3.0);
  const double width = testCircle.getFrameRect().width;
  const double height = testCircle.getFrameRect().height;
  const double area = testCircle.getArea();

  testCircle.move(4.0, 5.0);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, width, EPS);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, height, EPS);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area, EPS);

  testCircle.move({6.0, 7.0});
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, width, EPS);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, height, EPS);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area, EPS);
}

BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  tagiev::Circle testCircle({1.0, 2.0}, 3.0);

  const double area = testCircle.getArea();
  const double scale = 4.0;

  testCircle.scale(scale);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area * scale * scale, EPS);
}

BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(tagiev::Circle testCircle({-1.0, -2.0}, -3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

//rectangle

BOOST_AUTO_TEST_SUITE(testsForRectangle)

const double EPS = 0.01;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  tagiev::Rectangle testRect({1.0, 2.0}, 3.0, 4.0);

  const double width = testRect.getFrameRect().width;
  const double height = testRect.getFrameRect().height;
  const double area = testRect.getArea();

  testRect.move(5.0, 6.0);
  BOOST_CHECK_CLOSE(testRect.getFrameRect().width, width, EPS);
  BOOST_CHECK_CLOSE(testRect.getFrameRect().height, height, EPS);
  BOOST_CHECK_CLOSE(testRect.getArea(), area, EPS);

  testRect.move({7.0, 8.0});
  BOOST_CHECK_CLOSE(testRect.getFrameRect().width, width, EPS);
  BOOST_CHECK_CLOSE(testRect.getFrameRect().height, height, EPS);
  BOOST_CHECK_CLOSE(testRect.getArea(), area, EPS);
}
BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  tagiev::Rectangle testRect({1.0, 2.0}, 3.0, 4.0);

  const double area = testRect.getArea();
  const double scale = 5.0;
  testRect.scale(scale);
  BOOST_CHECK_CLOSE(testRect.getArea(), area * scale * scale, EPS);
}
BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(tagiev::Rectangle testRect({1.0, -2.0}, -3.0, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

//triangle

BOOST_AUTO_TEST_SUITE(testsForTriangle)

const double EPS = 0.01;

BOOST_AUTO_TEST_CASE(testOfImmutability)
{
  tagiev::Triangle testTriangle({0.0, 0.0}, {0.0, 4.0}, {3.0, 4.0});

  const double width = testTriangle.getFrameRect().width;
  const double height = testTriangle.getFrameRect().height;
  const double area = testTriangle.getArea();

  testTriangle.move(5.0, 6.0);
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().width, width, EPS);
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().height, height, EPS);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area, EPS);

  testTriangle.move({7.0, 8.0});
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().width, width, EPS);
  BOOST_CHECK_CLOSE(testTriangle.getFrameRect().height, height, EPS);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area, EPS);
}
BOOST_AUTO_TEST_CASE(testOfCorrectScaling)
{
  tagiev::Triangle testTriangle({0.0, 0.0}, {0.0, 4.0}, {3.0, 4.0});

  const double area = testTriangle.getArea();
  const double scale = 5.0;
  testTriangle.scale(scale);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area * scale * scale, EPS);
}
BOOST_AUTO_TEST_CASE(testInvalidValues)
{
  BOOST_CHECK_THROW(tagiev::Triangle testTriangle({0.0, 0.0}, {0.0, 0.0}, {3.0, 4.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
