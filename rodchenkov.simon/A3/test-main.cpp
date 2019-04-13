#define BOOST_TEST_MODULE A3_TEST_MODULE

#include <boost/test/included/unit_test.hpp>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

const double INACCURACY = 1e-6;

BOOST_AUTO_TEST_SUITE(a3_composite_shape_test_suite)

BOOST_AUTO_TEST_CASE(composite_shape_copy_constructor_t)
{
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{5, 5}, 4, 4));
  testComposite.add(std::make_unique<rodchenkov::Circle>(rodchenkov::point_t{7, 7}, 2));
  const std::size_t             originSize  = testComposite.getSize();
  const rodchenkov::rectangle_t originFrame = testComposite.getFrameRect();
  const double                  originArea  = testComposite.getArea();
  rodchenkov::CompositeShape    copyComposite{testComposite};
  BOOST_CHECK(originSize == copyComposite.getSize());
  BOOST_CHECK_CLOSE(originFrame.width, copyComposite.getFrameRect().width, INACCURACY);
  BOOST_CHECK_CLOSE(originFrame.height, copyComposite.getFrameRect().height, INACCURACY);
  BOOST_CHECK_CLOSE(originFrame.pos.x, copyComposite.getFrameRect().pos.x, INACCURACY);
  BOOST_CHECK_CLOSE(originFrame.pos.y, copyComposite.getFrameRect().pos.y, INACCURACY);
  BOOST_CHECK_CLOSE(originArea, copyComposite.getArea(), INACCURACY);
  copyComposite.scale(2);
  BOOST_CHECK_CLOSE(originFrame.width, testComposite.getFrameRect().width, INACCURACY);
  BOOST_CHECK_CLOSE(originFrame.height, testComposite.getFrameRect().height, INACCURACY);
  BOOST_CHECK_CLOSE(originFrame.pos.x, testComposite.getFrameRect().pos.x, INACCURACY);
  BOOST_CHECK_CLOSE(originFrame.pos.y, testComposite.getFrameRect().pos.y, INACCURACY);
  BOOST_CHECK_CLOSE(originArea, testComposite.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(composite_shape_adding_t)
{
  rodchenkov::CompositeShape testComposite{};
  const double               width  = 4;
  const double               height = 4;
  const rodchenkov::point_t  pos{10, 10};
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(pos, height, width));
  BOOST_CHECK(testComposite.getSize() == 1);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().width, width, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().height, height, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().pos.x, pos.x, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().pos.y, pos.y, INACCURACY);
  testComposite.add(std::make_unique<rodchenkov::Circle>(rodchenkov::point_t{12, 12}, 2));
  BOOST_CHECK(testComposite.getSize() == 2);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().width, 6, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().height, 6, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().pos.x, 11, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().pos.y, 11, INACCURACY);
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{13, 12}, 10, 12));
  BOOST_CHECK(testComposite.getSize() == 3);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().width, 12, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().height, 10, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().pos.x, 13, INACCURACY);
  BOOST_CHECK_CLOSE(testComposite.getFrameRect().pos.y, 12, INACCURACY);
}

BOOST_AUTO_TEST_CASE(composite_shape_absolute_moving_t)
{
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_unique<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
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
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_unique<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
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
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_unique<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
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
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  testComposite.add(std::make_unique<rodchenkov::Circle>(rodchenkov::point_t{0, 0}, 1));
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
  std::unique_ptr<rodchenkov::Shape> testNullPtr;
  BOOST_CHECK_THROW(testComposite.add(testNullPtr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(composite_shape_scaling_exception_t)
{
  rodchenkov::CompositeShape testComposite{};
  testComposite.add(std::make_unique<rodchenkov::Rectangle>(rodchenkov::point_t{0, 0}, 1, 1));
  BOOST_CHECK_THROW(testComposite.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
