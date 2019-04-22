#define BOOST_TEST_MODULE A2

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "Rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

const double EPSILON= 0.001;

BOOST_AUTO_TEST_SUITE(rectangle)

BOOST_AUTO_TEST_CASE(create_rectangle)
{
  BOOST_CHECK_THROW(Rectangle({ -23, -5 }, 2, -35), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(changing_Scale)
{
  sheve::Rectangle rec({ 11, 23 }, 5, 50);
  const double R = -12;
  BOOST_CHECK_THROW(rec.scale(R), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Moving_by_dx_dy)
{
  sheve::Rectangle rec({ -20, 10 }, 15, 50);
  const double width_original_d = rec.getFrameRect().width;
  const double height_original_d = rec.getFrameRect().height;
  const double area_original_d = rec.getArea();
  rec.move(10, -30);
  BOOST_CHECK_EQUAL(width_original_d, rec.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original_d, rec.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original_d, rec.getArea() ,EPSILON);
}

BOOST_AUTO_TEST_CASE(Moving_by_point)
{
  sheve::Rectangle rec({ 20, 10 }, 15, 50);
  const double width_original = rec.getFrameRect().width;
  const double height_original = rec.getFrameRect().height;
  const double area_original = rec.getArea();
  rec.move({ -27, 52 });
  BOOST_CHECK_EQUAL(width_original, rec.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, rec.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, rec.getArea(),EPSILON);
}

BOOST_AUTO_TEST_CASE(Scaling)
{
  sheve::Rectangle rec({ 20, 10 }, 15, 50);
  const double area_original = rec.getArea();
  const double R = 1.2;
  rec.scale(R);
  BOOST_CHECK_CLOSE(area_original * R * R, rec.getArea(), EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circle)

BOOST_AUTO_TEST_CASE(invalid_Initialisation)
{
  BOOST_CHECK_THROW(Circle({ 23, -5 }, -7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_Scale)
{
  sheve::Circle cir({ 1, 1 }, 5);
  const double C = -15;
  BOOST_CHECK_THROW(cir.scale(C), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Move_dx_dy)
{
  sheve::Circle cir({ 20, 30 }, 13);
  const double width_original = cir.getFrameRect().width;
  const double height_original = cir.getFrameRect().height;
  const double area_original = cir.getArea();
  cir.move(-12, 9);
  BOOST_CHECK_EQUAL(width_original, cir.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, cir.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, cir.getArea(),EPSILON);
}

BOOST_AUTO_TEST_CASE(move_point)
{
  sheve::Circle cir({ 20, 30 }, 13);
  const double width_original = cir.getFrameRect().width;
  const double height_original = cir.getFrameRect().height;
  const double area_original = cir.getArea();
  cir.move({ 32, -6 });
  BOOST_CHECK_EQUAL(width_original, cir.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, cir.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, cir.getArea(),EPSILON);
}

BOOST_AUTO_TEST_CASE(Scaling)
{
  sheve::Circle cir({ 20, 30 }, 13);
  const double area_original = cir.getArea();
  const double C = 0.9;
  cir.scale(C);
  BOOST_CHECK_CLOSE(area_original * C * C, cir.getArea(),EPSILON);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(triangle)

BOOST_AUTO_TEST_CASE(invalid_Initialisation)
{
  BOOST_CHECK_THROW(Triangle({ 1, -12 }, { -13, 2 }, { 1, 3 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_Scale)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double T = -19;
  BOOST_CHECK_THROW(tria.scale(T), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Move_dx_dy)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double width_original = tri.getFrameRect().width;
  const double height_original = tri.getFrameRect().height;
  const double area_original = tri.getArea();
  tri.move(10, 20);
  BOOST_CHECK_EQUAL(width_original, tri.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, tri.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, tri.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(move_point)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double width_original = tri.getFrameRect().width;
  const double height_original = tri.getFrameRect().height;
  const double area_original = tri.getArea();
  tri.move({ -7, 4 });
  BOOST_CHECK_EQUAL(width_original, tri.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, tri.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, tri.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(Scaling)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double area_original = tri.getArea();
  const double T = 1.63;
  tri.scale(T);
  BOOST_CHECK_CLOSE(area_original * T * T, tri.getArea(), EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
