#define BOOST_TEST_MODULE A3
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testImplementationOfCompositeShape)

const double INACCURACY = 0.001;

BOOST_AUTO_TEST_CASE(testWorkingConstructor)
{
  maschenko::Rectangle rectangle({5, 5}, 10, 5);
  maschenko::Shape *p_rect = &rectangle;
  maschenko::CompositeShape composite_shape(p_rect);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.y, rectangle.getFrameRect().pos.y, INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityAreaAfterMovingCentre)
{
  maschenko::Circle circle({5, 5}, 5);
  maschenko::Rectangle rectangle({5, 5}, 10, 5);

  maschenko::Shape *p_circle = &circle;
  maschenko::Shape *p_rect = &rectangle;

  maschenko::CompositeShape composite_shape(p_circle);
  composite_shape.addShape(p_rect);

  const double area = composite_shape.getArea();
  composite_shape.move({20, 20});
  BOOST_CHECK_CLOSE(area, composite_shape.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(immutabilityAreaAfterMovingOnDxAndDy)
{
  maschenko::Circle circle({5, 5}, 5);
  maschenko::Rectangle rectangle({5, 5}, 10, 5);

  maschenko::Shape *p_circle = &circle;
  maschenko::Shape *p_rect = &rectangle;

  maschenko::CompositeShape composite_shape(p_circle);
  composite_shape.addShape(p_rect);

  const double area = composite_shape.getArea();
  composite_shape.move(20, 20);
  BOOST_CHECK_CLOSE(area, composite_shape.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(correctWorkingRemove)
{
  maschenko::Circle circle({5, 5}, 5);
  maschenko::Rectangle rectangle1({5, 5}, 7, 7);
  maschenko::Rectangle rectangle2({5, 5}, 11, 4);
  maschenko::Rectangle rectangle3({5, 5}, 12, 1);

  maschenko::Shape *p_circle = &circle;
  maschenko::Shape *p_rect1 = &rectangle1;
  maschenko::Shape *p_rect2 = &rectangle2;
  maschenko::Shape *p_rect3 = &rectangle3;

  maschenko::CompositeShape composite_shape(p_circle);
  composite_shape.addShape(p_rect1);
  composite_shape.addShape(p_rect2);
  composite_shape.addShape(p_rect3);
  const int quantity_shape = composite_shape.getShapeQuantity();

  composite_shape.removeShape(p_rect1);
  const int quantity_shape_after_remove1 = composite_shape.getShapeQuantity();

  BOOST_CHECK_EQUAL(quantity_shape - 1, quantity_shape_after_remove1);
  BOOST_CHECK_THROW(composite_shape.removeShape(p_rect1), std::invalid_argument);
  BOOST_CHECK_THROW(composite_shape.removeShape(quantity_shape), std::out_of_range);

  composite_shape.removeShape(p_rect2);
  const int quantity_shape_after_remove2 = composite_shape.getShapeQuantity();

  BOOST_CHECK_EQUAL(quantity_shape_after_remove1 - 1, quantity_shape_after_remove2);
  BOOST_CHECK_THROW(composite_shape.removeShape(p_rect2), std::invalid_argument);
  BOOST_CHECK_THROW(composite_shape.removeShape(quantity_shape_after_remove1), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(throwExceptionDuaEntryNull)
{
  maschenko::Shape *shape = nullptr;
  BOOST_CHECK_THROW(maschenko::CompositeShape composite_shape(shape), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(throwExceptionDuaAddNull)
{
  maschenko::Circle circle({5, 5}, 5);
  maschenko::Rectangle rectangle({5, 5}, 10, 5);

  maschenko::Shape *p_circle = &circle;
  maschenko::Shape *p_rect = &rectangle;
  maschenko::Shape *shape = nullptr;

  maschenko::CompositeShape composite_shape(p_circle);
  composite_shape.addShape(p_rect);
  BOOST_CHECK_THROW(composite_shape.addShape(shape), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(AreaScalingIncrease)
{
  maschenko::Circle circle({5, 5}, 5);
  maschenko::Rectangle rectangle({5, 5}, 10, 5);

  maschenko::Shape *p_circle = &circle;
  maschenko::Shape *p_rect = &rectangle;

  maschenko::CompositeShape composite_shape(p_circle);
  composite_shape.addShape(p_rect);

  const double area = composite_shape.getArea();
  const double number_increase = 3;
  composite_shape.scale(number_increase);
  BOOST_CHECK_CLOSE(area * number_increase * number_increase, composite_shape.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(AreaScalingDecrease)
{
  maschenko::Circle circle({5, 5}, 5);
  maschenko::Rectangle rectangle({5, 5}, 10, 5);

  maschenko::Shape *p_circle = &circle;
  maschenko::Shape *p_rect = &rectangle;

  maschenko::CompositeShape composite_shape(p_circle);
  composite_shape.addShape(p_rect);

  const double area = composite_shape.getArea();
  const double number_increase = 0.25;
  composite_shape.scale(number_increase);
  BOOST_CHECK_CLOSE(area * number_increase * number_increase, composite_shape.getArea(), INACCURACY);
}

BOOST_AUTO_TEST_CASE(throwExceptionDuaIncorrectCoefficient)
{
  maschenko::Circle circle({5, 5}, 5);
  maschenko::Rectangle rectangle({5, 5}, 10, 5);

  maschenko::Shape *p_circle = &circle;
  maschenko::Shape *p_rect = &rectangle;

  maschenko::CompositeShape composite_shape(p_circle);
  composite_shape.addShape(p_rect);
  BOOST_CHECK_THROW(composite_shape.scale(-10), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
