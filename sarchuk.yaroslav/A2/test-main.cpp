#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

const double Error = 0.01;

BOOST_AUTO_TEST_SUITE(rectangleTest)

  BOOST_AUTO_TEST_CASE(resistanceToMovement)
  {
    sarchuk::Rectangle rectangle({2, 5}, 4, 6);
    const rectangle_t rectFrame = rectangle.getFrameRect();
    const double rectArea = rectangle.getArea();
    rectangle.move({1, 1});
    BOOST_CHECK_EQUAL(rectFrame.width, rectangle.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectFrame.height, rectangle.getFrameRect().height);
    BOOST_CHECK_EQUAL(rectArea, rectangle.getArea());
    rectangle.move(1, 2);
    BOOST_CHECK_EQUAL(rectFrame.width, rectangle.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectFrame.height, rectangle.getFrameRect().height);
    BOOST_CHECK_EQUAL(rectArea, rectangle.getArea());;
  }

  BOOST_AUTO_TEST_CASE(areaScaling)
  {
    sarchuk::Rectangle rect({2, 2}, 4, 8);
    const double area = rect.getArea();
    const double mult = 2.5;
    rect.scale(mult);
    BOOST_CHECK_CLOSE(rect.getArea(), mult * mult * area, Error);
  }

  BOOST_AUTO_TEST_CASE(inncorrectData)
  {
    BOOST_CHECK_THROW(sarchuk::Rectangle rectangle({1, 1}, - 1, 1), std::invalid_argument);
    BOOST_CHECK_THROW(sarchuk::Rectangle rectangle({1, 1}, 1, - 1), std::invalid_argument);

    const rectangle_t rectIncorrectWidth = {{1, 1}, - 1, 1};
    const rectangle_t rectIncorrectHeight = {{1, 1}, 1, - 1};
    BOOST_CHECK_THROW(sarchuk::Rectangle rectangle(rectIncorrectWidth), std::invalid_argument);
    BOOST_CHECK_THROW(sarchuk::Rectangle rectangle(rectIncorrectHeight), std::invalid_argument);

    sarchuk::Rectangle rect({1, 1}, 1, 1);
    BOOST_CHECK_THROW(rect.scale(0), std::invalid_argument);
  }


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ciecleTest)

  BOOST_AUTO_TEST_CASE(resistanceToMovement)
  {
    sarchuk::Circle circle({2, 5}, 5);
    const rectangle_t rectFrame = circle.getFrameRect();
    const double rectArea = circle.getArea();
    circle.move({1, 1});
    BOOST_CHECK_EQUAL(rectFrame.width, circle.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectFrame.height, circle.getFrameRect().height);
    BOOST_CHECK_EQUAL(rectArea, circle.getArea());

    circle.move(1, 2);
    BOOST_CHECK_EQUAL(rectFrame.width, circle.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectFrame.height, circle.getFrameRect().height);
    BOOST_CHECK_EQUAL(rectArea, circle.getArea());;
  }

  BOOST_AUTO_TEST_CASE(areaScaling)
  {
    sarchuk::Circle circle({2, 2}, 5);
    const double area = circle.getArea();
    const double mult = 2.5;
    circle.scale(mult);
    BOOST_CHECK_CLOSE(circle.getArea(), mult * mult * area, Error);
  }

  BOOST_AUTO_TEST_CASE(inncorrectData)
  {
    BOOST_CHECK_THROW(sarchuk::Circle circle({1, 1}, -2), std::invalid_argument);

    sarchuk::Circle circle({1, 2}, 8);
    BOOST_CHECK_THROW(circle.scale(0), std::invalid_argument);
  }


BOOST_AUTO_TEST_SUITE_END()
