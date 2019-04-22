#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/included/floating_point_comparison.hpp>
#include <stdexcept>
#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

const double CORRECTNESS = 0.01;

//Rectangle

BOOST_AUTO_TEST_SUITE(testSuiteRectangle)

BOOST_AUTO_TEST_CASE(testInvariabilityOfDimensions)
{
  pylaev::Rectangle testRectangle({0.0, 0.0}, 10.0, 5.0);

  const double width = testRectangle.getWidth();
  const double height = testRectangle.getHeight();
  const double area = testRectangle.getArea();

  testRectangle.move(5.0, 5.5);
  BOOST_CHECK_CLOSE(testRectangle.getWidth(), width, CORRECTNESS);
  BOOST_CHECK_CLOSE(testRectangle.getHeight(), height, CORRECTNESS);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), area, CORRECTNESS);

  testRectangle.move({100.0, 100.0});
  BOOST_CHECK_CLOSE(testRectangle.getWidth(), width, CORRECTNESS);
  BOOST_CHECK_CLOSE(testRectangle.getHeight(), height, CORRECTNESS);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), area, CORRECTNESS);
}

BOOST_AUTO_TEST_CASE(testSquareChangeAreaAfterScaling)
{
  pylaev::Rectangle testRectangle({0.0, 0.0}, 10.0, 5.0);

  const double area = testRectangle.getArea();
  const double kScaling = 2.5;

  testRectangle.scale(kScaling);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), area * kScaling * kScaling, CORRECTNESS);
}

BOOST_AUTO_TEST_CASE(testIncorrectValues)
{
  BOOST_CHECK_THROW(pylaev::Rectangle testRectangle({0.0, 0.0}, 0.0, -5.0), std::invalid_argument);
  BOOST_CHECK_THROW(pylaev::Rectangle testSquare({0.0, 0.0}, -1.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


//Circle

BOOST_AUTO_TEST_SUITE(testSuiteCircle)

BOOST_AUTO_TEST_CASE(testInvariabilityOfDimensions)
{
  pylaev::Circle testCircle({0.0, 0.0}, 5.0);

  const double radius = testCircle.getRadius();
  const double area = testCircle.getArea();

  testCircle.move(5.0, 5.5);
  BOOST_CHECK_CLOSE(testCircle.getRadius(), radius, CORRECTNESS);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area, CORRECTNESS);

  testCircle.move({100.0, 100.0});
  BOOST_CHECK_CLOSE(testCircle.getRadius(), radius, CORRECTNESS);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area, CORRECTNESS);
}

BOOST_AUTO_TEST_CASE(testSquareChangeAreaAfterScaling)
{
  pylaev::Circle testCircle({0.0, 0.0}, 5.0);

  const double area = testCircle.getArea();
  const double kScaling = 2.5;

  testCircle.scale(kScaling);
  BOOST_CHECK_CLOSE(testCircle.getArea(), area * kScaling * kScaling, CORRECTNESS);
}

BOOST_AUTO_TEST_CASE(testIncorrectValues)
{
  BOOST_CHECK_THROW(pylaev::Circle testCircle({0.0, 0.0}, -1.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


//Triangle

BOOST_AUTO_TEST_SUITE(testSuiteTriangle)

const int N_TOPS = 3;

BOOST_AUTO_TEST_CASE(testInvariabilityOfDimensions)
{
  pylaev::Triangle testTriangle({0.0, 0.0}, {10.0, 5.0}, {3.0, 6.0});

  const double sides[N_TOPS] = {testTriangle.getSide(0), testTriangle.getSide(1), testTriangle.getSide(2)};
  const double area = testTriangle.getArea();

  testTriangle.move(5.0, 5.5);
  for (int i = 0; i < N_TOPS; i++) {
    BOOST_CHECK_CLOSE(testTriangle.getSide(i), sides[i], CORRECTNESS);
  }
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area, CORRECTNESS);

  testTriangle.move({100.0, 100.0});
  for (int i = 0; i < N_TOPS; i++) {
    BOOST_CHECK_CLOSE(testTriangle.getSide(i), sides[i], CORRECTNESS);
  }
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area, CORRECTNESS);
}

BOOST_AUTO_TEST_CASE(testSquareChangeAreaAfterScaling)
{
  pylaev::Triangle testTriangle({0.0, 0.0}, {10.0, 5.0}, {3.0, 6.0});

  const double area = testTriangle.getArea();
  const double kScaling = 2.5;

  testTriangle.scale(kScaling);
  BOOST_CHECK_CLOSE(testTriangle.getArea(), area * kScaling * kScaling, CORRECTNESS);
}

BOOST_AUTO_TEST_CASE(testIncorrectValues)
{
  BOOST_CHECK_THROW(pylaev::Triangle testTriangle({0.0, 0.0}, -1.0, 0.0, 5.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
