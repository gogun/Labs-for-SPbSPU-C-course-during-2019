#define BOOST_TEST_MODULE A2

#include "circle.hpp"
#include "rectangle.hpp"
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(A2_test_suite)

  const double Inaccuracy = 0.01;

  BOOST_AUTO_TEST_CASE(circle_invar_after_absolute_move)
  {
    korshunov::Circle testCircle({7, 7}, 7);
    const korshunov::rectangle_t testFrameBefore = testCircle.getFrameRect();
    const double testAreaBefore = testCircle.getArea();

    testCircle.move({23, 49});
    korshunov::rectangle_t testFrameAfter = testCircle.getFrameRect();
    double testAreaAfter = testCircle.getArea();
    BOOST_CHECK_CLOSE(testFrameBefore.width, testFrameAfter.width, Inaccuracy);
    BOOST_CHECK_CLOSE(testFrameBefore.height, testFrameAfter.height, Inaccuracy);
    BOOST_CHECK_CLOSE(testAreaBefore, testAreaAfter, Inaccuracy);
  }

  BOOST_AUTO_TEST_CASE(circle_invar_after_relative_move)
  {
    korshunov::Circle testCircle({ 7, 7 }, 7);
    const korshunov::rectangle_t testFrameBefore = testCircle.getFrameRect();
    const double testAreaBefore = testCircle.getArea();

    testCircle.move(23, 17);
    korshunov::rectangle_t testFrameAfter = testCircle.getFrameRect();
    double testAreaAfter = testCircle.getArea();
    BOOST_CHECK_CLOSE(testFrameBefore.width, testFrameAfter.width, Inaccuracy);
    BOOST_CHECK_CLOSE(testFrameBefore.height, testFrameAfter.height, Inaccuracy);
    BOOST_CHECK_CLOSE(testAreaBefore, testAreaAfter, Inaccuracy);
  }

  BOOST_AUTO_TEST_CASE(rectangle_invar_after_absolute_move)
  {
    korshunov::Rectangle testRectangle({ 7, 7 }, 7, 17);
    const korshunov::rectangle_t testFrameBefore = testRectangle.getFrameRect();
    const double testAreaBefore = testRectangle.getArea();

    testRectangle.move({ 27, 37 });
    korshunov::rectangle_t testFrameAfter = testRectangle.getFrameRect();
    double testAreaAfter = testRectangle.getArea();
    BOOST_CHECK_CLOSE(testFrameBefore.width, testFrameAfter.width, Inaccuracy);
    BOOST_CHECK_CLOSE(testFrameBefore.height, testFrameAfter.height, Inaccuracy);
    BOOST_CHECK_CLOSE(testAreaBefore, testAreaAfter, Inaccuracy);
  }

  BOOST_AUTO_TEST_CASE(rectangle_invar_after_relative_move)
  {
    korshunov::Rectangle testRectangle({ 7, 7 }, 7, 17);
    const korshunov::rectangle_t testFrameBefore = testRectangle.getFrameRect();
    const double testAreaBefore = testRectangle.getArea();

    testRectangle.move(17, 13);
    korshunov::rectangle_t testFrameAfter = testRectangle.getFrameRect();
    double testAreaAfter = testRectangle.getArea();
    BOOST_CHECK_CLOSE(testFrameBefore.width, testFrameAfter.width, Inaccuracy);
    BOOST_CHECK_CLOSE(testFrameBefore.height, testFrameAfter.height, Inaccuracy);
    BOOST_CHECK_CLOSE(testAreaBefore, testAreaAfter, Inaccuracy);
  }

  BOOST_AUTO_TEST_CASE(quadr_change_area_circle)
  {
    korshunov::Circle testCircle({ 7, 7 }, 7);
    const double testAreaBefore = testCircle.getArea();
    const double coefScale = 7;

    testCircle.scale(coefScale);
    BOOST_CHECK_CLOSE(testCircle.getArea(), coefScale * coefScale * testAreaBefore, Inaccuracy);
  }

  BOOST_AUTO_TEST_CASE(quadr_change_area_rectangle)
  {
    korshunov::Rectangle testRectangle({ 7, 7 }, 7, 3);
    const double testAreaBefore = testRectangle.getArea();
    const double coefScale = 7;

    testRectangle.scale(coefScale);
    BOOST_CHECK_CLOSE(testRectangle.getArea(), coefScale * coefScale * testAreaBefore, Inaccuracy);
  }

  BOOST_AUTO_TEST_CASE(throwing_exceptions)
  {
    BOOST_CHECK_THROW(korshunov::Circle({ 3, 6 }, -4), std::invalid_argument);
    BOOST_CHECK_THROW(korshunov::Rectangle({ 8, 5 }, 3, -6), std::invalid_argument);

    korshunov::Rectangle testRectangle({ 7, 3 }, 5, 7);
    BOOST_CHECK_THROW(testRectangle.scale(-7), std::invalid_argument);

    korshunov::Circle testCircle({ 5, 8 }, 2);
    BOOST_CHECK_THROW(testCircle.scale(-7), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
