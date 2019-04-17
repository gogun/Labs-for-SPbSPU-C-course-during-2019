#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

const double ACCURACY = 0.001;

BOOST_AUTO_TEST_SUITE(testRectangle)

  BOOST_AUTO_TEST_CASE(testRectImmutabilityValues)
  {
    alexandrov::Rectangle rectangle1({{2.5, 1.3}, 2, 4});
    const alexandrov::rectangle_t init_rectangle = rectangle1.getFrameRect();
    const double init_area = rectangle1.getArea();

    rectangle1.move(5.2, 9.1);
    BOOST_CHECK_CLOSE(init_rectangle.width, rectangle1.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(init_rectangle.height, rectangle1.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(init_area, rectangle1.getArea(), ACCURACY);

    rectangle1.move({12.1, 18.2});
    BOOST_CHECK_CLOSE(init_rectangle.width, rectangle1.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(init_rectangle.height, rectangle1.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(init_area, rectangle1.getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(testRectAreaChange)
  {
    alexandrov::Rectangle rectangle1({{2.2, 5.5}, 2, 4});
    const double init_area = rectangle1.getArea();
    const double scale_factor = 4.5;
    rectangle1.scale(scale_factor);
    BOOST_CHECK_CLOSE(init_area * scale_factor * scale_factor, rectangle1.getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(testRectInit)
  {
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{2, 4}, -1, 1}), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{2, 4}, 1, -1}), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{2, 4}, 0, 1}), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Rectangle rectangle1({{2, 4}, 1, 0}), std::invalid_argument);

    alexandrov::Rectangle rectangle1({{5, 5}, 2, 3});
    BOOST_CHECK_THROW(rectangle1.scale(-2), std::invalid_argument);
    BOOST_CHECK_THROW(rectangle1.scale(0), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(testCircle)

  BOOST_AUTO_TEST_CASE(testCircImmutabilityValues)
  {
    alexandrov::Circle circle1({2.5, 1.3}, 3);
    const alexandrov::rectangle_t init_rectangle = circle1.getFrameRect();
    const double init_area = circle1.getArea();

    circle1.move(5.2, 9.1);
    BOOST_CHECK_CLOSE(init_rectangle.width, circle1.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(init_rectangle.height, circle1.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(init_area, circle1.getArea(), ACCURACY);

    circle1.move({12.1, 18.2});
    BOOST_CHECK_CLOSE(init_rectangle.width, circle1.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(init_rectangle.height, circle1.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(init_area, circle1.getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(testCircAreaChange)
  {
    alexandrov::Circle circle1({{2.2, 5.5}, 2});
    const double init_area = circle1.getArea();
    const double scale_factor = 4.5;
    circle1.scale(scale_factor);
    BOOST_CHECK_CLOSE(init_area * scale_factor * scale_factor, circle1.getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(testCircInit)
  {
    BOOST_CHECK_THROW(alexandrov::Circle circle1({{2, 4}, -1}), std::invalid_argument);
    BOOST_CHECK_THROW(alexandrov::Circle circle1({{2, 4}, 0}), std::invalid_argument);

    alexandrov::Circle circle1({{5, 5}, 2});
    BOOST_CHECK_THROW(circle1.scale(-2), std::invalid_argument);
    BOOST_CHECK_THROW(circle1.scale(0), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();
