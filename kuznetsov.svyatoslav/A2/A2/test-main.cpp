#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double INACCURACY = 0.001;

BOOST_AUTO_TEST_SUITE(testingMethods)

  BOOST_AUTO_TEST_CASE(rectangleTestImmutabilityAfterMoving)
  {
    kuznetsov::Rectangle testRect({4.1, 6.4}, 7.0, 2.1);
    const double rectAreaBeforeMoving = testRect.getArea();
    const kuznetsov::rectangle_t rectFrameBeforeMoving = testRect.getFrameRect();

    testRect.move(7.0, 2.1);

    BOOST_CHECK_CLOSE(testRect.getArea(), rectAreaBeforeMoving, INACCURACY);
    BOOST_CHECK_CLOSE(testRect.getFrameRect(), rectFrameBeforeMoving, INACCURACY);

    kuznetsov::rectangle_t rectFrameAfterMoving = testRect.getFrameRect();

    BOOST_CHECK_EQUAL(rectFrameBeforeMoving.height, rectFrameAfterMoving.height);
    BOOST_CHECK_EQUAL(rectFrameBeforeMoving.width, rectFrameAfterMoving.width);
    BOOST_CHECK_CLOSE(testRect.getFrameRect(), rectFrameAfterMoving, INACCURACY);
  }

  BOOST_AUTO_TEST_CASE(rectangleTestImmutabilityAfterMovingTo)
  {
    kuznetsov::Rectangle testRect({4.1, 6.4}, 7.0, 2.1);
    const double rectAreaBeforeMovingTo = testRect.getArea();
    const kuznetsov::rectangle_t rectFrameBeforeMovingTo = testRect.getFrameRect();

    testRect.move({2.7, -1.4});

    BOOST_CHECK_CLOSE(testRect.getArea(), rectAreaBeforeMovingTo, INACCURACY);
    BOOST_CHECK_CLOSE(testRect.getFrameRect(), rectFrameBeforeMovingTo, INACCURACY);

    kuznetsov::rectangle_t rectFrameAfterMovingTo = testRect.getFrameRect();

    BOOST_CHECK_EQUAL(rectFrameBeforeMovingTo.height, rectFrameAfterMovingTo.height);
    BOOST_CHECK_EQUAL(rectFrameBeforeMovingTo.width, rectFrameAfterMovingTo.width);
    BOOST_CHECK_CLOSE(testRect.getFrameRect(), rectFrameAfterMovingTo, INACCURACY);
  }

  BOOST_AUTO_TEST_CASE(rectangleTestScale)
  {
    kuznetsov::Rectangle testRect({3.6, 3.5}, 3.0, 3.1);
    const double rectAreaBeforeScale = testRect.getArea();
    const double coef = 2.5;

    testRect.scale(coef);

    BOOST_CHECK_CLOSE(testRect.getArea(), rectAreaBeforeScale * coef * coef, INACCURACY);
  }

  BOOST_AUTO_TEST_CASE(circleTestImmutabilityAfterMoving)
  {
    kuznetsov::Circle testCircle({4.9, 6.3}, 2.2);
    const double circleAreaBeforeMoving = testCircle.getArea();
    const kuznetsov::rectangle_t circleFrameBeforeMoving = testCircle.getFrameRect();

    testCircle.move(1.8, -4.7);

    BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMoving, INACCURACY);
    BOOST_CHECK_CLOSE(testCircle.getFrameRect(), circleFrameBeforeMoving, INACCURACY);

    kuznetsov::rectangle_t rectFrameAfterMoving = testCircle.getFrameRect();

    BOOST_CHECK_EQUAL(circleFrameBeforeMoving.height, rectFrameAfterMoving.height);
    BOOST_CHECK_EQUAL(circleFrameBeforeMoving.width, rectFrameAfterMoving.width);
    BOOST_CHECK_CLOSE(testCircle.getFrameRect(), rectFrameAfterMoving, INACCURACY);
  }

  BOOST_AUTO_TEST_CASE(circleTestImmutabilityAfterMovingTo)
  {
    kuznetsov::Circle testCircle({4.9, 6.3}, 2.2);
    const double circleAreaBeforeMovingTo = testCircle.getArea();
    const kuznetsov::rectangle_t rectFrameBeforeMovingTo = testCircle.getFrameRect();

    testCircle.move({2.7, -1.4});

    BOOST_CHECK_CLOSE(testCircle.getArea(), circleAreaBeforeMovingTo, INACCURACY);
    BOOST_CHECK_CLOSE(testCircle.getFrameRect(), rectFrameBeforeMovingTo, INACCURACY);

    kuznetsov::rectangle_t rectFrameAfterMovingTo = testCircle.getFrameRect();

    BOOST_CHECK_EQUAL(rectFrameAfterMovingTo.height, rectFrameBeforeMovingTo.height);
    BOOST_CHECK_EQUAL(rectFrameAfterMovingTo.width, rectFrameBeforeMovingTo.width);
    BOOST_CHECK_CLOSE(testCircle.getFrameRect(), rectFrameAfterMovingTo, INACCURACY);
  }

  BOOST_AUTO_TEST_CASE(circleTestCale)
  {
    kuznetsov::Circle testCircle({4.0, 6.0}, 2.0);
    const double rectAreaBeforeScale = testCircle.getArea();
    const double coef = 3.2;

    testCircle.scale(coef);

    BOOST_CHECK_CLOSE(testCircle.getArea(), rectAreaBeforeScale * coef * coef, INACCURACY);
  }

  BOOST_AUTO_TEST_CASE(invalidRectangleValuse)
  {
    BOOST_CHECK_THROW(kuznetsov::Rectangle({4.1, 2.5}, -2.0, 1.5), std::invalid_argument);
    BOOST_CHECK_THROW(kuznetsov::Rectangle({4.1, 2.9}, 3.4, -2.0), std::invalid_argument);

    kuznetsov::Rectangle testRect({3.0, 3.0}, 1.0, 1.0);

    BOOST_CHECK_THROW(testRect.scale(-2.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(invalidCircleValues)
  {
    BOOST_CHECK_THROW(kuznetsov::Circle({3.2, 4.1}, -2.0), std::invalid_argument);

    kuznetsov::Circle testCircle({2.8, 2.9}, 4.5);

    BOOST_CHECK_THROW(testCircle.scale(-2.0), std::invalid_argument);

  }

BOOST_AUTO_TEST_SUITE_END()