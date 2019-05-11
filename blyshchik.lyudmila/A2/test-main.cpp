#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double accuracy = 0.01;

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(testRectMove)
{
  blyshchik::Rectangle testRect({{1, 2}, 3, 4});
  const blyshchik::rectangle_t rectFrameBeforeMove = testRect.getFrameRect();
  const double area = testRect.getArea();

  testRect.move(7, 3);

  BOOST_CHECK_CLOSE(testRect.getWidth(), rectFrameBeforeMove.width, accuracy);
  BOOST_CHECK_CLOSE(testRect.getHeight(), rectFrameBeforeMove.height, accuracy);
  BOOST_CHECK_CLOSE(testRect.getArea(), area, accuracy);
}

BOOST_AUTO_TEST_CASE(testRectScale)
{
  blyshchik::Rectangle testRect({{1, 2}, 3, 4});
  const double coefficient = 2;
  const double newArea = testRect.getArea() * coefficient * coefficient;

  testRect.scale(coefficient);

  BOOST_CHECK_CLOSE(testRect.getArea(), newArea, accuracy);
}

BOOST_AUTO_TEST_CASE(testRectParameters)
{
  const blyshchik::point_t pos{1, 2};
  const double corWidth = 3;
  const double incorWidth = -3;
  const double corHeight = 4;
  const double incorHeight = 0;
  const double incorCoefficient = -2;

  blyshchik::Rectangle testRect{pos, corWidth, corHeight};

  BOOST_CHECK_THROW(blyshchik::Rectangle incorWidthRect(pos, incorWidth, corHeight), std::invalid_argument);
  BOOST_CHECK_THROW(blyshchik::Rectangle incorHeightRect(pos, corWidth, incorHeight), std::invalid_argument);
  BOOST_CHECK_THROW(blyshchik::Rectangle incorWidthAndHeightRect(pos, incorWidth, incorHeight), std::invalid_argument);
  BOOST_CHECK_THROW(testRect.scale(incorCoefficient), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(testCircMove)
{
  const blyshchik::point_t pos{1, 2};
  const double radius = 3;
  const double newX = 1;
  const double newY = 2;

  blyshchik::Circle testCirc{pos, radius};
  const double area = testCirc.getArea();

  testCirc.move(newX, newY);

  BOOST_CHECK_CLOSE(testCirc.getRadius(), radius, accuracy);
  BOOST_CHECK_CLOSE(testCirc.getArea(), area, accuracy);
}

BOOST_AUTO_TEST_CASE(testCircScale)
{
  blyshchik::Circle testCirc{{1, 2}, 3};
  const double coefficient = 1.3;
  const double newArea = testCirc.getArea() * coefficient * coefficient;

  testCirc.scale(coefficient);

  BOOST_CHECK_CLOSE(testCirc.getArea(), newArea, accuracy);
}

BOOST_AUTO_TEST_CASE(testCircParameters)
{
  BOOST_CHECK_THROW(blyshchik::Circle testCirc({1, 2}, 0), std::invalid_argument);
  blyshchik::Circle testCircScale({1, 2}, 3);
  BOOST_CHECK_THROW(testCircScale.scale(-4), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
