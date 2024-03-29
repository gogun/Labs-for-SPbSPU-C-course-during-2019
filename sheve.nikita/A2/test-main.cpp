#define BOOST_TEST_MODULE A2
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

const double EPSILON = 0.001;

BOOST_AUTO_TEST_SUITE(rectangle)

BOOST_AUTO_TEST_CASE(create_rectangle)
{
  BOOST_CHECK_THROW(sheve::Rectangle({ -23, -5 }, 2, -35), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(changing_Scale)
{
  sheve::Rectangle rec({ 11, 23 }, 5, 50);
  BOOST_CHECK_THROW(rec.scale(-12), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Moving_by_dx_dy)
{
  sheve::Rectangle rec({ 20, 10 }, 15, 50);
  const double framebeforemove_w = rec.getFrameRect().width;
  const double framebeforemove_h = rec.getFrameRect().height;
  const double areabeforemoving = rec.getArea();
  rec.move(10, -30);
  BOOST_CHECK_CLOSE(framebeforemove_w, rec.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(framebeforemove_h, rec.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areabeforemoving, rec.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(Moving_by_point)
{
  sheve::Rectangle rec({ 20, 10 }, 15, 50);
  const double framebeforemove_w = rec.getFrameRect().width;
  const double framebeforemove_h = rec.getFrameRect().height;
  const double areabeforemoving = rec.getArea();
  rec.move({ -27, 52 });
  BOOST_CHECK_CLOSE(framebeforemove_w, rec.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(framebeforemove_h, rec.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areabeforemoving, rec.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(Scaling)
{
  sheve::Rectangle rec({ 20, 10 }, 15, 50);
  const double areabeforemoving = rec.getArea();
  const double scalefactor = 1.2;
  rec.scale(scalefactor);
  BOOST_CHECK_CLOSE(areabeforemoving * scalefactor * scalefactor, rec.getArea(), EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circle)

BOOST_AUTO_TEST_CASE(invalid_Initialisation)
{
  BOOST_CHECK_THROW(sheve::Circle({ 23, -5 }, -7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_Scale)
{
  sheve::Circle cir({ 1, 1 }, 5);
  BOOST_CHECK_THROW(cir.scale(-15), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Move_dx_dy)
{
  sheve::Circle cir({ 20, 30 }, 13);
  const double framebeforemove_w = cir.getFrameRect().width;
  const double framebeforemove_h = cir.getFrameRect().height;
  const double areabeforemoving = cir.getArea();
  cir.move(-12, 9);
  BOOST_CHECK_CLOSE(framebeforemove_w, cir.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(framebeforemove_h, cir.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areabeforemoving, cir.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(move_point)
{
  sheve::Circle cir({ 20, 30 }, 13);
  const double framebeforemove_w = cir.getFrameRect().width;
  const double framebeforemove_h = cir.getFrameRect().height;
  const double areabeforemoving = cir.getArea();
  cir.move({ 32, -6 });
  BOOST_CHECK_CLOSE(framebeforemove_w, cir.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(framebeforemove_h, cir.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areabeforemoving, cir.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(Scaling)
{
  sheve::Circle cir({ 20, 30 }, 13);
  const double areabeforemoving = cir.getArea();
  const double scalefactor = 0.9;
  cir.scale(scalefactor);
  BOOST_CHECK_CLOSE(areabeforemoving * scalefactor * scalefactor, cir.getArea(), EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(triangle)

BOOST_AUTO_TEST_CASE(invalid_Initialisation)
{
  BOOST_CHECK_THROW(sheve::Triangle({ 1, 2 }, { -13, 2 }, { 1, 2 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_Scale)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  BOOST_CHECK_THROW(tri.scale(-19), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Move_dx_dy)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double framebeforemove_w = tri.getFrameRect().width;
  const double framebeforemove_h = tri.getFrameRect().height;
  const double areabeforemoving = tri.getArea();
  tri.move(10, 20);
  BOOST_CHECK_CLOSE(framebeforemove_w, tri.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(framebeforemove_h, tri.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areabeforemoving, tri.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(move_point)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double framebeforemove_w = tri.getFrameRect().width;
  const double framebeforemove_h = tri.getFrameRect().height;
  const double areabeforemoving = tri.getArea();
  tri.move({ -7, 4 });
  BOOST_CHECK_CLOSE(framebeforemove_w, tri.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(framebeforemove_h, tri.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(areabeforemoving, tri.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(Scaling)
{
  sheve::Triangle tri({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double areabeforemoving = tri.getArea();
  const double scalefactor = 1.63;
  tri.scale(scalefactor);
  BOOST_CHECK_CLOSE(areabeforemoving * scalefactor * scalefactor, tri.getArea(), EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
