#define BOOST_TEST_MODULE A2

#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(A2Testing)

  const double accuracy = 0.01;

  BOOST_AUTO_TEST_CASE(movingCircle)
  {
    andreeva::Circle testCircle({2.5, 3.0}, 2.5);
    const andreeva::rectangle_t rectangleBeforeMoving = testCircle.getFrameRect();
    const double areaBeforeMoving = testCircle.getArea();

    testCircle.move(-1.0, 8.8);
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.width, testCircle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.height, testCircle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(areaBeforeMoving, testCircle.getArea(), accuracy);

    testCircle.move({3.5, 3.6});
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.width, testCircle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.height, testCircle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(areaBeforeMoving, testCircle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(movingRectangle)
  {
    andreeva::Rectangle testRectangle({8.0, 6.0}, 1.5, 1.5);
    const andreeva::rectangle_t rectangleBeforeMoving = testRectangle.getFrameRect();
    const double areaBeforeMoving = testRectangle.getArea();

    testRectangle.move({1.1, 1.2});
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.width, testRectangle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.height, testRectangle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(areaBeforeMoving, testRectangle.getArea(), accuracy);

    testRectangle.move(-4.0, 7.0);
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.width, testRectangle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(rectangleBeforeMoving.height, testRectangle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(areaBeforeMoving, testRectangle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(scalingCircle)
  {
    andreeva::Circle testCircle({1.0, 1.0}, 10.0);
    const double areaBeforeScaling = testCircle.getArea();
    const double factor = 5.2;
    testCircle.scale(factor);
    BOOST_CHECK_CLOSE(testCircle.getArea(), factor * factor * areaBeforeScaling, accuracy);
  }

  BOOST_AUTO_TEST_CASE(scalingRectangle)
  {
    andreeva::Rectangle testRectangle({5.0, 5.0}, 2.0, 2.0);
    const double areaBeforeScaling = testRectangle.getArea();
    const double factor = 3.0;
    testRectangle.scale(factor);
    BOOST_CHECK_CLOSE(testRectangle.getArea(), factor * factor * areaBeforeScaling, accuracy);
  }

  BOOST_AUTO_TEST_CASE(invalidShapesValues)
  {
    BOOST_CHECK_THROW(andreeva::Circle({3.0, 1.5}, -3.5), std::invalid_argument);
    BOOST_CHECK_THROW(andreeva::Circle({4.0, 4.0}, -8.0), std::invalid_argument);

    andreeva::Circle testCircle({4.0, 4.0}, 8.0);
    BOOST_CHECK_THROW(testCircle.scale(-3.6), std::invalid_argument);

    BOOST_CHECK_THROW(andreeva::Rectangle({4.5, 3.2}, -2.0, 5.0), std::invalid_argument);
    BOOST_CHECK_THROW(andreeva::Rectangle({9.0, 4.7}, 5.0, -5.0), std::invalid_argument);

    andreeva::Rectangle testRectangle({4.0, 4.0}, 8.0, 8.0);
    BOOST_CHECK_THROW(testRectangle.scale(-3.6), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
