#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double EPSILON = 0.01;

BOOST_AUTO_TEST_SUITE(suiteTest)

BOOST_AUTO_TEST_CASE(rectangleConstructor)
{
  BOOST_CHECK_THROW(nazarov::Rectangle({ 0, 0 }, 20, -10), std::invalid_argument);
  BOOST_CHECK_THROW(nazarov::Rectangle({ 0, 0 }, -20, 10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(scaleRectangleTimes)
{
  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  BOOST_CHECK_THROW(rectangleTest.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveReactangle)
{
  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  nazarov::point_t pointTest = { 10, 10 };
  rectangleTest.move(pointTest);
  BOOST_CHECK_CLOSE(rectangleTest.getPos().x, pointTest.x, EPSILON);
  BOOST_CHECK_CLOSE(rectangleTest.getPos().y, pointTest.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  const double widthTest = 40;
  const double heightTest = 20;
  const double timesTest = 2;
  rectangleTest.scale(timesTest);
  BOOST_CHECK_CLOSE(rectangleTest.getWidth(), widthTest, EPSILON);
  BOOST_CHECK_CLOSE(rectangleTest.getHeight(), heightTest, EPSILON);
}

BOOST_AUTO_TEST_CASE(rectangleMovedArea)
{
  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  const double testArea = rectangleTest.getArea();
  rectangleTest.move({ 20, 20 });
  BOOST_CHECK_CLOSE(testArea, rectangleTest.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(rectangleFrameRect)
{
  nazarov::Rectangle rectangleTest({ 0, 0 }, 20, 10);
  nazarov::rectangle_t frameRectTest = rectangleTest.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectTest.pos.x, rectangleTest.getPos().x, EPSILON);
  BOOST_CHECK_CLOSE(frameRectTest.pos.y, rectangleTest.getPos().y, EPSILON);
  BOOST_CHECK_CLOSE(frameRectTest.width, rectangleTest.getWidth(), EPSILON);
  BOOST_CHECK_CLOSE(frameRectTest.height, rectangleTest.getHeight(), EPSILON);
}

BOOST_AUTO_TEST_CASE(circleConstructor)
{
  BOOST_CHECK_THROW(nazarov::Circle({ 0, 0 }, -50), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveCircle)
{
  nazarov::Circle circleTest({ 0, 0 }, 50);
  nazarov::point_t pointTest = { 20, 20 };
  circleTest.move(pointTest);
  BOOST_CHECK_CLOSE(circleTest.getPos().x, pointTest.x, EPSILON);
  BOOST_CHECK_CLOSE(circleTest.getPos().y, pointTest.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(scaleCircleTimes)
{
  nazarov::Circle circleTest({ 0, 0 }, 50);
  BOOST_CHECK_THROW(circleTest.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  nazarov::Circle circleTest({ 0, 0 }, 50);
  const double radiusTest = 100;
  const double timesTest = 2;
  circleTest.scale(timesTest);
  BOOST_CHECK_CLOSE(circleTest.getRadius(), radiusTest, EPSILON);
}

BOOST_AUTO_TEST_CASE(circleMovedArea)
{
  nazarov::Circle circleTest({ 0, 0 }, 50);
  const double areaTest = circleTest.getArea();
  circleTest.move({ 20, 20 });
  BOOST_CHECK_CLOSE(areaTest, circleTest.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(circleFrameRect)
{
  nazarov::Circle circleTest({ 0, 0 }, 50);
  nazarov::rectangle_t frameRectTest = circleTest.getFrameRect();
  BOOST_CHECK_CLOSE(frameRectTest.pos.x, circleTest.getPos().x, EPSILON);
  BOOST_CHECK_CLOSE(frameRectTest.pos.y, circleTest.getPos().y, EPSILON);
  BOOST_CHECK_CLOSE(frameRectTest.width, circleTest.getRadius() * 2, EPSILON);
  BOOST_CHECK_CLOSE(frameRectTest.height, circleTest.getRadius() * 2, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
