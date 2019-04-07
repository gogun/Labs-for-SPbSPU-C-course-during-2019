#include "boost/test/included/unit_test.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

#define ACCURACY 1e-10

BOOST_AUTO_TEST_SUITE(figureRectangle)

  BOOST_AUTO_TEST_CASE(RectangleInvariantParametersAfterMove)
  {
    const prohorova::point_t pos{1, 1};
    const double width = 1.0 / 256;
    const double height = 3;
    const double dx = 1.5;
    const double dy = 2.5;

    prohorova::Rectangle testRectangle{pos, width, height};
    const double area = testRectangle.getArea();

    testRectangle.move(dx, dy);

    BOOST_REQUIRE_EQUAL(testRectangle.getWidth(), width);
    BOOST_REQUIRE_EQUAL(testRectangle.getHeight(), height);
    BOOST_REQUIRE_EQUAL(testRectangle.getArea(), area);
}	

  BOOST_AUTO_TEST_CASE(RectangleChangeOfParametersAfterScale)
  {
    const prohorova::point_t pos{10.123, 20.0001};
    const double width = 3.0 / 1024;
    const double height = 3e-20;
    const double factor = 1.0 / 3;
    const double newWidth = 1.0 / 1024;
    const double newHeight = 1e-20;

    prohorova::Rectangle testRectangle{pos, width, height};
    const double area = testRectangle.getArea();
    const double newArea = area * factor * factor;

    testRectangle.scale(factor);

    BOOST_REQUIRE_CLOSE(testRectangle.getWidth(), newWidth, ACCURACY);
    BOOST_REQUIRE_CLOSE(testRectangle.getHeight(), newHeight, ACCURACY);
    BOOST_REQUIRE_CLOSE(testRectangle.getArea(), newArea, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleIncorrectParameters)
  {
    const prohorova::point_t pos {1, 1};
    const double correctWidth = 3;
    const double correctHeight = 5;
    const double incorrectWidth = -3;
    const double incorrectHeight = 0;

    BOOST_CHECK_THROW(prohorova::Rectangle incorrectWidthRectangle(pos, incorrectWidth, correctHeight), std::invalid_argument);
    BOOST_CHECK_THROW(prohorova::Rectangle incorrectHeightRectangle(pos, correctWidth, incorrectHeight), std::invalid_argument);
    BOOST_CHECK_THROW(prohorova::Rectangle incorrectWidthAndHeightRectangle(pos, incorrectWidth, incorrectHeight), std::invalid_argument);
  }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(figureCircle)
  BOOST_AUTO_TEST_CASE(CircleInvariantParametersAfterMove)
  {
    const prohorova::point_t pos{1.0 / 3, 1.0 / 7};
    const double radius = 2e-7;
    const double dx = 1.5;
    const double dy = 2.5;

    prohorova::Circle testCircle{pos, radius};
    const double area = testCircle.getArea();

    testCircle.move(dx, dy);

    BOOST_REQUIRE_EQUAL(testCircle.getRadius(), radius);
    BOOST_REQUIRE_EQUAL(testCircle.getArea(), area);
  }
  BOOST_AUTO_TEST_CASE(CircleChangeOfParametersAfterScale)
  {
    const prohorova::point_t pos{10.0002, 12.0 / 13};
    const double radius = 7e-30;
    const double factor = 1e-10;
    const double newRadius = 7e-40;

    prohorova::Circle testCircle{pos, radius};

    const double area = testCircle.getArea();
    const double newArea = area * factor * factor;

    testCircle.scale(factor);

    BOOST_REQUIRE_CLOSE(testCircle.getRadius(), newRadius, ACCURACY);
    BOOST_REQUIRE_CLOSE(testCircle.getArea(), newArea, ACCURACY);
  }
  BOOST_AUTO_TEST_CASE(CircleIncorrectParameters)
  {
    const prohorova::point_t pos{-1, -1};
    const double incorrectRadius = -1;
    
    BOOST_CHECK_THROW(prohorova::Circle incorrectRectangle(pos, incorrectRadius), std::invalid_argument);
  }
BOOST_AUTO_TEST_SUITE_END()
