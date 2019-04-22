#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

#define EPSILON 1e-10

BOOST_AUTO_TEST_SUITE(shapeRectangle)
  
  BOOST_AUTO_TEST_CASE(RectangleAfterMove)
  {

    dusaeva::Rectangle testRectangle({5.0, 2.0}, 6.9, 7.0);
    const dusaeva::rectangle_t rectBeforeMove = testRectangle.getFrameRect();
    const double areaBeforeMoving = testRectangle.getArea();

    testRectangle.move(4.5, 6.0);
    
    const dusaeva::rectangle_t rectAfterMove = testRectangle.getFrameRect();
    const double areaAfterMove = testRectangle.getArea();
    
    BOOST_CHECK_CLOSE(rectAfterMove.width, rectBeforeMove.width, EPSILON);
    BOOST_CHECK_CLOSE(rectAfterMove.height, rectBeforeMove.height, EPSILON);
    BOOST_CHECK_CLOSE(areaAfterMove, areaBeforeMoving, EPSILON);

    testRectangle.move({1.3, 5.6});

    BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, rectBeforeMove.width, EPSILON);
    BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, rectBeforeMove.height, EPSILON);
    BOOST_CHECK_CLOSE(areaAfterMove, areaBeforeMoving, EPSILON);

  }

  BOOST_AUTO_TEST_CASE(RectangleAfterScale)
  {
    const double scale = 0.5;
    dusaeva::Rectangle testRectangle{{0.6, 4.5}, 5.0, 6.0};
    const double areaBeforeScale = testRectangle.getArea();

    testRectangle.scale(scale);
  
    const double areaAfterScale = testRectangle.getArea();
  
    BOOST_CHECK_CLOSE((areaBeforeScale * scale * scale), areaAfterScale, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(RectangleIncorrectParameters)
  {
    dusaeva::Rectangle testRectangle({1.0, 6.0}, 5.0, 4.0);

    BOOST_CHECK_THROW(dusaeva::Rectangle incorrectRectangle_1({1.0, 6.0}, 5.0, -4.0), std::invalid_argument);
    BOOST_CHECK_THROW(dusaeva::Rectangle incorrectRectangle_2({1.0, 6.0}, -5.0, 4.0), std::invalid_argument);
    BOOST_CHECK_THROW(testRectangle.scale(-2.0), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(shapeCircle)

  BOOST_AUTO_TEST_CASE(CircleAfterMove)
  {
    const double radius = 6.5;
    dusaeva::Circle testCircle({1.0, 2.0}, radius);
    
    const dusaeva::rectangle_t rectBeforeMove = testCircle.getFrameRect();
    const double areaBeforeMove = testCircle.getArea();

    testCircle.move(3.0, 6.1);
  
    const dusaeva::rectangle_t rectAfterMove = testCircle.getFrameRect();
    const double areaAfterMove = testCircle.getArea();
  
    BOOST_CHECK_CLOSE(rectAfterMove.width, rectBeforeMove.width, EPSILON);
    BOOST_CHECK_CLOSE(rectAfterMove.height, rectBeforeMove.height, EPSILON);
    BOOST_CHECK_CLOSE(areaAfterMove, areaBeforeMove, EPSILON);

    testCircle.move({1.0, 5.0});
  
    BOOST_CHECK_CLOSE(rectAfterMove.width, rectBeforeMove.width, EPSILON);
    BOOST_CHECK_CLOSE(rectAfterMove.height, rectBeforeMove.height, EPSILON);
    BOOST_CHECK_CLOSE(areaAfterMove, areaBeforeMove, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(CircleAfterScale)
  {
    const double scale = 2.0;
    dusaeva::Circle testCircle({8.0, 6.5}, 9.0);
    const double areaBeforeScale = testCircle.getArea();

    testCircle.scale(scale);

    const double areaAfterScale = testCircle.getArea();

    BOOST_CHECK_CLOSE((areaBeforeScale * scale * scale), areaAfterScale, EPSILON);
  }
  
  BOOST_AUTO_TEST_CASE(CircleIncorrectParameters)
  {
    dusaeva::Circle testCircle({2.0, -6.0}, 4.3);

    BOOST_CHECK_THROW(testCircle.scale(-3.0), std::invalid_argument);
    BOOST_CHECK_THROW(dusaeva::Circle wrongCircle({2.0, -6.0}, -4.3), std::invalid_argument);
  }
  
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(shapeTriangle)

  BOOST_AUTO_TEST_CASE(TriangleAfterMove)
  {

    dusaeva::Triangle testTriangle({6.9, 7.0}, {1.2, 0.3}, {3.1, 1.6});
    const dusaeva::rectangle_t rectBeforeMove = testTriangle.getFrameRect();
    const double areaBeforeMove = testTriangle.getArea();

    testTriangle.move(4.5, 6.0);

    const dusaeva::rectangle_t rectAfterMove = testTriangle.getFrameRect();
    const double areaAfterMove = testTriangle.getArea();

    BOOST_CHECK_CLOSE(rectBeforeMove.width, rectAfterMove.width, EPSILON);
    BOOST_CHECK_CLOSE(rectBeforeMove.height, rectAfterMove.height, EPSILON);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, EPSILON);

    testTriangle.move({1.3, 5.6});
  
    BOOST_CHECK_CLOSE(rectBeforeMove.width, rectAfterMove.width, EPSILON);
    BOOST_CHECK_CLOSE(rectBeforeMove.height, rectAfterMove.height, EPSILON);
    BOOST_CHECK_CLOSE(areaBeforeMove, areaAfterMove, EPSILON);

  }

  BOOST_AUTO_TEST_CASE(TriangleAfterScale)
  {
    const double scale = 2.6;
    dusaeva::Triangle testTriangle({4.0, 10.0}, {15.0, 6.0}, {1.0, 1.0});

    const double areaBeforeScale = testTriangle.getArea();

    testTriangle.scale(scale);
    
    const double areaAfterScale = testTriangle.getArea();
  
    BOOST_CHECK_CLOSE((areaBeforeScale * scale * scale), areaAfterScale, EPSILON);
  }
  
  BOOST_AUTO_TEST_CASE(TriangleWrongParameters)
  {
    dusaeva::Triangle testTriangle({6.9, 7.0}, {1.2, 0.3}, {3.1, 1.6});
    BOOST_CHECK_THROW(testTriangle.scale(-2.0), std::invalid_argument);

    BOOST_CHECK_THROW(dusaeva::Triangle incorrectTriangle_1({1.0, 7.0}, {1.0, 6.5}, {1.0, 8.0}), std::invalid_argument);
    BOOST_CHECK_THROW(dusaeva::Triangle incorrectTriangle_2({1.0, 1.0}, {1.0, 1.0}, {1.0, 1.0}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
