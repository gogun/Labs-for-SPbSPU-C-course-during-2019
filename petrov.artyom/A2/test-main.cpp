#define BOOST_TEST_MODULE labs
#include <boost/test/included/unit_test.hpp>

#include <stdexcept>
#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

#define INACCURACY 0.0001

BOOST_AUTO_TEST_SUITE(CircleTest)

  BOOST_AUTO_TEST_CASE(constructor_ThrowsOnInvalidRadius)
  {
    BOOST_CHECK_THROW(petrov::Circle({5, 5}, -1), std::invalid_argument);
    BOOST_CHECK_THROW(petrov::Circle({5, 5}, -0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(move_WorksCorrectly)
  {
    petrov::point_t centre{10, 20};
    double radius = 15;
    petrov::Circle circle = petrov::Circle(centre, radius);

    double dx = 40;
    double dy = 30;
    circle.move(dx, dy);

    BOOST_CHECK_EQUAL(centre.x + dx, circle.getCentre().x);
    BOOST_CHECK_EQUAL(centre.y + dy, circle.getCentre().y);

    double x = 40;
    double y = 30;
    petrov::point_t destinationPoint {x, y};
    circle.move(destinationPoint);

    BOOST_CHECK_EQUAL(x, circle.getCentre().x);
    BOOST_CHECK_EQUAL(y, circle.getCentre().y);
  }

  BOOST_AUTO_TEST_CASE(move_DoesNotChangeDimentions)
  {
    petrov::point_t centre{10, 20};
    double radius = 15;
    petrov::Circle circle = petrov::Circle(centre, radius);

    double dx = 40;
    double dy = 30;
    circle.move(dx, dy);

    BOOST_CHECK_EQUAL(radius, circle.getRadius());

    double x = 40;
    double y = 30;
    petrov::point_t destinationPoint {x, y};
    circle.move(destinationPoint);

    BOOST_CHECK_EQUAL(radius, circle.getRadius());
  }

  BOOST_AUTO_TEST_CASE(scale_AreaGrowsInSquarePropotion)
  {
    petrov::Circle circle = petrov::Circle({1, 2}, 10);
    double scaleFactor = 5;

    double areaBeforeScaling = circle.getArea();
    circle.scale(scaleFactor);
    double areaAfterScaling = circle.getArea();

    BOOST_CHECK_CLOSE(scaleFactor * scaleFactor,
                      areaAfterScaling / areaBeforeScaling,
                      INACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(TestRect)

  BOOST_AUTO_TEST_CASE(constructor_ThrowsOnInvalidRadius)
  {
    BOOST_CHECK_THROW(petrov::Rectangle({5, 5}, -10, 20), std::invalid_argument);
    BOOST_CHECK_THROW(petrov::Rectangle({5, 5}, 10, -20), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(move_WorksCorrectly)
  {
    petrov::point_t centre{10, 20};
    double width = 10;
    double height = 20;
    petrov::Rectangle rectangle = petrov::Rectangle(centre, width, height);

    double dx = 40;
    double dy = 30;
    rectangle.move(dx, dy);

    BOOST_CHECK_EQUAL(centre.x + dx, rectangle.getCentre().x);
    BOOST_CHECK_EQUAL(centre.y + dy, rectangle.getCentre().y);

    double x = 40;
    double y = 30;
    petrov::point_t destinationPoint {x, y};
    rectangle.move(destinationPoint);

    BOOST_CHECK_EQUAL(destinationPoint.x, rectangle.getCentre().x);
    BOOST_CHECK_EQUAL(destinationPoint.y, rectangle.getCentre().y);
  }

  BOOST_AUTO_TEST_CASE(move_DoesNotChangeDimentions)
  {
    petrov::point_t centre{10, 20};
    double width = 10;
    double height = 20;
    petrov::Rectangle rectangle = petrov::Rectangle(centre, width, height);

    double dx = 40;
    double dy = 30;
    rectangle.move(dx, dy);

    BOOST_CHECK_EQUAL(width, rectangle.getWidth());
    BOOST_CHECK_EQUAL(height, rectangle.getHeight());

    double x = 40;
    double y = 30;
    petrov::point_t destinationPoint {x, y};
    rectangle.move(destinationPoint);

    BOOST_CHECK_EQUAL(width, rectangle.getWidth());
    BOOST_CHECK_EQUAL(height, rectangle.getHeight());
  }

  BOOST_AUTO_TEST_CASE(scale_AreaGrowsInSquarePropotion)
  {
    petrov::Rectangle rectangle = petrov::Rectangle({1, 2}, 10, 20);
    double scaleFactor = 5;

    double areaBeforeScaling = rectangle.getArea();
    rectangle.scale(scaleFactor);
    double areaAfterScaling = rectangle.getArea();

    BOOST_CHECK_CLOSE(scaleFactor * scaleFactor,
                      areaAfterScaling / areaBeforeScaling,
                      INACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()
