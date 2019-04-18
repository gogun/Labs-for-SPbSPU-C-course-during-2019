#define BOOST_TEST_MODULE A2

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#define ACCURACY 0.001

BOOST_AUTO_TEST_SUITE(TestA2)

  struct FixtureCreationRectangle
  {
    FixtureCreationRectangle() :
      rectangle({1.0, 1.0}, 20.0, 30.0)
    {
    }

    bogdanov::Rectangle rectangle;
  };

  struct FixtureCreationCircle
  {
    FixtureCreationCircle() :
      circle({1.0, 1.0}, 10.0)
    {
    }

    bogdanov::Circle circle;
  };

  BOOST_FIXTURE_TEST_CASE(widthHeightAreaOfTheRectangleShouldBePreservedAfterMovingOnDxDy, FixtureCreationRectangle)
  {
    const bogdanov::rectangle_t initialRectangle = rectangle.getFrameRect();
    const double initialAreaRectangle = rectangle.getArea();

    rectangle.move(6.0, 6.0);

    BOOST_CHECK_CLOSE(initialRectangle.width, rectangle.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(initialRectangle.height, rectangle.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(initialAreaRectangle, rectangle.getArea(), ACCURACY);
  }


  BOOST_FIXTURE_TEST_CASE(widthHeightAreaOfTheCircleShouldBePreservedAfterMovingOnDxDy, FixtureCreationCircle)
  {
    const bogdanov::rectangle_t initialCircle = circle.getFrameRect();
    const double initialAreaCircle= circle.getArea();

    circle.move(6.0,6.0);

    BOOST_CHECK_CLOSE(initialCircle.width, circle.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(initialCircle.height, circle.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(initialAreaCircle, circle.getArea(), ACCURACY);
  }

  BOOST_FIXTURE_TEST_CASE(widthHeightAreaOfTheRectangleShouldBePreservedAfterMovingInNewCenter, FixtureCreationRectangle)
  {
    const bogdanov::rectangle_t initialRectangle = rectangle.getFrameRect();
    const double initialAreaRectangle = rectangle.getArea();

    rectangle.move({7.0,7.0});

    BOOST_CHECK_CLOSE(initialRectangle.width, rectangle.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(initialRectangle.height, rectangle.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(initialAreaRectangle, rectangle.getArea(), ACCURACY);
  }

  BOOST_FIXTURE_TEST_CASE(widthHeightAreaOfTheCircleShouldBePreservedAfterMovingInNewCenter, FixtureCreationCircle)
  {
    const bogdanov::rectangle_t initialCircle = circle.getFrameRect();
    const double initialAreaCircle= circle.getArea();

    circle.move({7.0,7.0});

    BOOST_CHECK_CLOSE(initialCircle.width, circle.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(initialCircle.height, circle.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(initialAreaCircle, circle.getArea(), ACCURACY);
  }

  BOOST_FIXTURE_TEST_CASE(AreOfRectangleShouldChangeQuadraticallyAfterScaling,FixtureCreationRectangle)
  {
    const double initialAreaRectangle = rectangle.getArea();
    const double scalingFactor = 0.5;

    rectangle.scale(scalingFactor);

    BOOST_CHECK_CLOSE(initialAreaRectangle * scalingFactor * scalingFactor, rectangle.getArea(), ACCURACY);
  }

  BOOST_FIXTURE_TEST_CASE(AreOfCircleShouldChangeQuadraticallyAfterScaling,FixtureCreationCircle)
  {
    const double initialAreaCircle = circle.getArea();
    const double scalingFactor = 2;

    circle.scale(scalingFactor);

    BOOST_CHECK_CLOSE(initialAreaCircle * scalingFactor * scalingFactor, circle.getArea(), ACCURACY);
  }

  BOOST_FIXTURE_TEST_CASE(shouldReturnAnErrorDueToIncorrectParametersFromRectangle, FixtureCreationRectangle)
  {
    BOOST_CHECK_THROW(bogdanov::Rectangle rec({1, 1}, -1, 1), std::invalid_argument);
    BOOST_CHECK_THROW(bogdanov::Rectangle rec({1, 1}, 1, -1), std::invalid_argument);
    BOOST_CHECK_THROW(bogdanov::Rectangle rec({1, 1}, -1, -1), std::invalid_argument);
    BOOST_CHECK_THROW(bogdanov::Rectangle rec({1, 1}, 0, 1), std::invalid_argument);
    BOOST_CHECK_THROW(bogdanov::Rectangle rec({1, 1}, 1, 0), std::invalid_argument);
    BOOST_CHECK_THROW(bogdanov::Rectangle rec({1, 1}, 0, 0), std::invalid_argument);

    BOOST_CHECK_THROW(rectangle.scale(-2), std::invalid_argument);
  }

  BOOST_FIXTURE_TEST_CASE(shouldReturnAnErrorDueToIncorrectParametersFromCircle, FixtureCreationCircle)
  {
    BOOST_CHECK_THROW(bogdanov::Circle circle1({1, 1}, -1), std::invalid_argument);
    BOOST_CHECK_THROW(bogdanov::Circle circle1({1, 1}, 0), std::invalid_argument);

    BOOST_CHECK_THROW(circle.scale(-2), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
