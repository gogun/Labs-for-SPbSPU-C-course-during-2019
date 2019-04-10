#define BOOST_TEST_MODULE A3_TEST_MODULE

#include <boost/test/included/unit_test.hpp>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

const double INACCURACY = 1e-6;

BOOST_AUTO_TEST_SUITE(a3_composite_shape_test_suite)

BOOST_AUTO_TEST_CASE(composite_shape_adding_t)
{
  rodchenkov::CompositeShape         testComposite{};
  const double                       width  = 2;
  const double                       height = width;
  const double                       radius = width / 2;
  const double                       posX   = 0;
  const double                       posY   = 0;
  std::shared_ptr<rodchenkov::Shape> testRectangle
      = std::make_shared<rodchenkov::Rectangle>(rodchenkov::point_t{posX, posY}, width, height);
  testComposite.add(testRectangle);
  rodchenkov::rectangle_t compositeFrame = testComposite.getFrameRect();
  BOOST_CHECK(testComposite.getSize() == 1);
  BOOST_CHECK_CLOSE(compositeFrame.height, height, INACCURACY);
  BOOST_CHECK_CLOSE(compositeFrame.width, width, INACCURACY);
  BOOST_CHECK_CLOSE(compositeFrame.pos.x, posX, INACCURACY);
  BOOST_CHECK_CLOSE(compositeFrame.pos.y, posY, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getArea(), testRectangle->getArea(), INACCURACY);
  std::shared_ptr<rodchenkov::Shape> testCircle
      = std::make_shared<rodchenkov::Circle>(rodchenkov::point_t{posX, posY}, radius);
  testComposite.add(testCircle);
  BOOST_CHECK(testComposite.getSize() == 2);
  BOOST_CHECK_CLOSE(compositeFrame.height, height, INACCURACY);
  BOOST_CHECK_CLOSE(compositeFrame.width, width, INACCURACY);
  BOOST_CHECK_CLOSE(compositeFrame.pos.x, posX, INACCURACY);
  BOOST_CHECK_CLOSE(compositeFrame.pos.y, posY, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getArea(), testRectangle->getArea() + testCircle->getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(composite_shape_absolute_moving_t)
{
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_shared<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_shared<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
  const double areaBeforeMovement = testComposite.getArea();
  const double widthBeforeMoving  = testComposite.getFrameRect().width;
  const double heightBeforeMoving = testComposite.getFrameRect().height;
  const int    sizeBeforeMoving   = testComposite.getSize();
  testComposite.move({1, 1});
  BOOST_CHECK_CLOSE(testComposite.getArea(), areaBeforeMovement, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().width, widthBeforeMoving, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().height, heightBeforeMoving, INACCURACY);
  BOOST_CHECK_EQUAL(testComposite.getSize(), sizeBeforeMoving);
}

BOOST_AUTO_TEST_CASE(composite_shape_relative_moving_t)
{
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_shared<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_shared<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
  const double areaBeforeMovement = testComposite.getArea();
  const double widthBeforeMoving  = testComposite.getFrameRect().width;
  const double heightBeforeMoving = testComposite.getFrameRect().height;
  const int    sizeBeforeMoving   = testComposite.getSize();
  testComposite.move(1, 1);
  BOOST_CHECK_CLOSE(testComposite.getArea(), areaBeforeMovement, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().width, widthBeforeMoving, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().height, heightBeforeMoving, INACCURACY);
  BOOST_CHECK_EQUAL(testComposite.getSize(), sizeBeforeMoving);
}

BOOST_AUTO_TEST_CASE(composite_shape_upscaling_t)
{
  const double               scalingRatio = 2;
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_shared<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_shared<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
  const double areaBeforeMovement = testComposite.getArea();
  const double widthBeforeMoving  = testComposite.getFrameRect().width;
  const double heightBeforeMoving = testComposite.getFrameRect().height;
  const int    sizeBeforeMoving   = testComposite.getSize();
  testComposite.scale(scalingRatio);
  BOOST_CHECK_CLOSE(testComposite.getArea(), areaBeforeMovement * pow(scalingRatio, 2), INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().width, widthBeforeMoving * scalingRatio, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().height, heightBeforeMoving * scalingRatio, INACCURACY);
  BOOST_CHECK_EQUAL(testComposite.getSize(), sizeBeforeMoving);
}

BOOST_AUTO_TEST_CASE(composite_shape_downscaling_t)
{
  const double               scalingRatio = 0.5;
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_shared<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_shared<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
  const double areaBeforeMovement = testComposite.getArea();
  const double widthBeforeMoving  = testComposite.getFrameRect().width;
  const double heightBeforeMoving = testComposite.getFrameRect().height;
  const int    sizeBeforeMoving   = testComposite.getSize();
  testComposite.scale(scalingRatio);
  BOOST_CHECK_CLOSE(testComposite.getArea(), areaBeforeMovement * pow(scalingRatio, 2), INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().width, widthBeforeMoving * scalingRatio, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().height, heightBeforeMoving * scalingRatio, INACCURACY);
  BOOST_CHECK_EQUAL(testComposite.getSize(), sizeBeforeMoving);
}

BOOST_AUTO_TEST_CASE(composite_shape_adding_exception_t)
{
  rodchenkov::CompositeShape         testComposite{};
  std::shared_ptr<rodchenkov::Shape> testNullPtr;
  BOOST_CHECK_THROW(testComposite.add(testNullPtr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(composite_shape_scaling_exception_t)
{
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_shared<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  BOOST_CHECK_THROW(testComposite.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
