#define BOOST_TEST_MODULE A2
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include <boost/test/floating_point_comparison.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double accuracy = 0.01;

BOOST_AUTO_TEST_SUITE(testRectangle)

  BOOST_AUTO_TEST_CASE(unchangedMeasurements)
  {
    stebnevsky::Rectangle rectangle({{1.1, 2.3}, 5, 7});
    const stebnevsky::rectangle_t initial_rectangle = rectangle.getFrameRect();
    const double initial_area = rectangle.getArea();

    rectangle.move(12.0, 21.0);
    BOOST_CHECK_CLOSE(initial_rectangle.width, rectangle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(initial_rectangle.height, rectangle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(initial_area, rectangle.getArea(), accuracy);

    rectangle.move({12.0, 21.0});
    BOOST_CHECK_CLOSE(initial_rectangle.width, rectangle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(initial_rectangle.height, rectangle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(initial_area, rectangle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(squareAreaChange)
  {
    stebnevsky::Rectangle rectangle({{1.1, 2.3}, 5, 7});
    const double initial_area = rectangle.getArea();
    const double scale_parameter = 4.5;
    rectangle.scale(scale_parameter);
    BOOST_CHECK_CLOSE(initial_area * scale_parameter * scale_parameter, rectangle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(ProcessingIncorrectParameters)
  {
    BOOST_CHECK_THROW(stebnevsky::Rectangle rectangle({{12, -12}, -2, 1}), std::invalid_argument);
    BOOST_CHECK_THROW(stebnevsky::Rectangle rectangle({{12, -12}, 2, -1}), std::invalid_argument);
    BOOST_CHECK_THROW(stebnevsky::Rectangle rectangle({{12, -12}, 0, 1}), std::invalid_argument);
    BOOST_CHECK_THROW(stebnevsky::Rectangle rectangle({{12, -12}, 1, 0}), std::invalid_argument);

    stebnevsky::Rectangle rectangle({{12, -12}, 2, 1});
    BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
    BOOST_CHECK_THROW(rectangle.scale(-2), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

  BOOST_AUTO_TEST_CASE(unchangedMeasurements)
  {
    stebnevsky::Circle circle({1.1, 2.3}, 5);
    const stebnevsky::rectangle_t initial_rectangle = circle.getFrameRect();
    const double initial_area = circle.getArea();

    circle.move(12.0, 21.0);
    BOOST_CHECK_CLOSE(initial_rectangle.width, circle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(initial_rectangle.height, circle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(initial_area, circle.getArea(), accuracy);

    circle.move({12.0, 21.0});
    BOOST_CHECK_CLOSE(initial_rectangle.width, circle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(initial_rectangle.height, circle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(initial_area, circle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(squareAreaChange)
  {
    stebnevsky::Circle circle({1.1, 2.3}, 5);
    const double initial_area = circle.getArea();
    const double scale_parameter = 4.5;
    circle.scale(scale_parameter);
    BOOST_CHECK_CLOSE(initial_area * scale_parameter * scale_parameter, circle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(ProcessingIncorrectParameters)
  {
    BOOST_CHECK_THROW(stebnevsky::Circle circle({12, -12}, -2), std::invalid_argument);
    BOOST_CHECK_THROW(stebnevsky::Circle circle({12, -12}, 0), std::invalid_argument);

    stebnevsky::Circle circle({12, -12}, 2);
    BOOST_CHECK_THROW(circle.scale(0), std::invalid_argument);
    BOOST_CHECK_THROW(circle.scale(-2), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
