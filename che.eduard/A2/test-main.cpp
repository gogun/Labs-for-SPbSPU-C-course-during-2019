#define BOOST_TEST_MODULE
#include <stdexcept>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

const double accuracy = 0.0001;

BOOST_AUTO_TEST_SUITE(Circle_Testing)

BOOST_AUTO_TEST_CASE(Circle_Immutability)
{
  che::Circle testCircle({ 2.0, 3.5 }, 1.5);
  const che::rectangle_t circlebeforemoving = testCircle.getFrameRect();
  const double areabeforemoving = testCircle.getArea();
  testCircle.move(1.5, 3.0);
  BOOST_CHECK_CLOSE(circlebeforemoving.width, testCircle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(circlebeforemoving.height, testCircle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(areabeforemoving, testCircle.getArea(), accuracy);

  testCircle.move({ 3.5, 1.2 });
  BOOST_CHECK_CLOSE(circlebeforemoving.width, testCircle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(circlebeforemoving.height, testCircle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(areabeforemoving, testCircle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(Scale_Tetsting)
{
  che::Circle testCircle({2.0, 3.5}, 1.5);
  const double areabeforescaling = testCircle.getArea();
  const double coef = 1.8;
  testCircle.scale(coef);
  BOOST_CHECK_CLOSE(testCircle.getArea(), areabeforescaling * coef * coef, accuracy);
}

BOOST_AUTO_TEST_CASE(Invalid_Values)
{
  BOOST_CHECK_THROW(che::Circle({ 2.0,3.0 }, -1.5), std::invalid_argument);
  che::Circle testCircle1({ 3.0, 3.0 }, 2.0);
  BOOST_CHECK_THROW(testCircle1.scale(-3.0), std::invalid_argument);
  che::Circle testCircle2({ 2.0, 2.0 }, 3.0);
  BOOST_CHECK_THROW(testCircle1.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Rectangle_Testing)

BOOST_AUTO_TEST_CASE(Rectangle_Immutability)
{
  che::Rectangle testRectangle({ 4.0, 9.0,{ 2.0, 4.0}});
  const che::rectangle_t framebeforemoving = testRectangle.getFrameRect();
  const double  areabeforemoving = testRectangle.getArea();
  testRectangle.move(2.0, 3.0);
  BOOST_CHECK_CLOSE(framebeforemoving.height, testRectangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(framebeforemoving.width, testRectangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(areabeforemoving, testRectangle.getArea(), accuracy);

  testRectangle.move({ 2.0, 4.0 });
  BOOST_CHECK_CLOSE(framebeforemoving.width, testRectangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(framebeforemoving.height, testRectangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(areabeforemoving, testRectangle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(Scale_Testing)
{
  che::Rectangle testRectangle({ 4.0, 9.0, {2.0, 5.0}});
  const double areabeforescaling = testRectangle.getArea();
  const double coef = 2.2;
  testRectangle.scale(coef);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), areabeforescaling * coef * coef, accuracy);
}

BOOST_AUTO_TEST_CASE(Invalid_Values)
{
  BOOST_CHECK_THROW(che::Rectangle testRectangle({ -2.0, 4.0, {3.0, 5.0}}), std::invalid_argument);
  BOOST_CHECK_THROW(che::Rectangle testRectangle({ 2.0, -4.0, {2.5, 1.0}}), std::invalid_argument);
  che::Rectangle testRectangle({ 2.0, 2.0,{ 5.0, 10.0}});
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Triangle_Testing)

BOOST_AUTO_TEST_CASE(Triangle_Immutability)
{
  che::Triangle testTriangle({ 4.5, -1.2 }, { 1.3, 3.5 }, { 5.6, 3.2 });
  const che::rectangle_t framebeforemoving = testTriangle.getFrameRect();
  const double  areabeforemoving = testTriangle.getArea();

  testTriangle.move({ 3.4, 4.3 });
  BOOST_CHECK_CLOSE(framebeforemoving.width, testTriangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(framebeforemoving.height, testTriangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(areabeforemoving, testTriangle.getArea(), accuracy);

  testTriangle.move(6, -2.1);
  BOOST_CHECK_CLOSE(framebeforemoving.width, testTriangle.getFrameRect().width, accuracy);
  BOOST_CHECK_CLOSE(framebeforemoving.height, testTriangle.getFrameRect().height, accuracy);
  BOOST_CHECK_CLOSE(areabeforemoving, testTriangle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(Scale_Testing)
{
  che::Triangle testTriangle({ 2.5, -1.5 }, { 1.0, 4.5 }, { 2.6, 5.2 });
  const double areabeforescaling = testTriangle.getArea();
  const double coef = 6.7;

  testTriangle.scale(coef);
  BOOST_CHECK_CLOSE(areabeforescaling * coef * coef, testTriangle.getArea(), accuracy);
}

BOOST_AUTO_TEST_CASE(invalidArguments)
{
  BOOST_CHECK_THROW(che::Triangle({ 0, -2.2 }, { 0, 4.0 }, { 0, 8.0 }), std::invalid_argument);
  che::Triangle testTriangle({ 9.3, -3.2 }, { 10.0, 5.6 }, { 3.6, 2.9 });
  BOOST_CHECK_THROW(testTriangle.scale(-2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

