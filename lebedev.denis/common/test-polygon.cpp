#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include "polygon.hpp"

const double FAULT = 0.001;
const double INCORRECT_ARG = -47.0;

BOOST_AUTO_TEST_SUITE(A2TestPolygon)

  BOOST_AUTO_TEST_CASE(TestPolygonAfterMove)
  {
    lebedev::point_t shape[] = {{2.0, 1.0}, {5.0, 1.0}, {5.0, 4.0}, {2.0, 4.0}};
    size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
    lebedev::Polygon testPolygon(qtyVertex, shape);
    const double areaBefore = testPolygon.getArea();
    const lebedev::rectangle_t frameBefore = testPolygon.getFrameRect();
    testPolygon.move(2.00, 5.4);
    const double areaAfterMove = testPolygon.getArea();
    const lebedev::rectangle_t frameAfterMove = testPolygon.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(areaBefore, areaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestPolygonAfterMovePos)
  {
    lebedev::point_t shape[] = {{2.0, 1.0}, {5.0, 1.0}, {5.0, 4.0}, {2.0, 4.0}};
    size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
    lebedev::Polygon testPolygon(qtyVertex, shape);
    const double areaBefore = testPolygon.getArea();
    const lebedev::rectangle_t frameBefore = testPolygon.getFrameRect();
    testPolygon.move({3.00, 4.00});
    const double areaAfterMove = testPolygon.getArea();
    const lebedev::rectangle_t frameAfterMove = testPolygon.getFrameRect();
    BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, FAULT);
    BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, FAULT);
    BOOST_CHECK_CLOSE(areaBefore, areaAfterMove, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestPolygonScale)
  {
    lebedev::point_t shape[] = {{2.0, 1.0}, {5.0, 1.0}, {5.0, 4.0}, {2.0, 4.0}};
    size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
    lebedev::Polygon testPolygon(qtyVertex, shape);
    const double areaBeforeScale = testPolygon.getArea();
    const double multiplier = 2.0;
    testPolygon.scale(multiplier);
    const double areaAfterScale = testPolygon.getArea();
    BOOST_CHECK_CLOSE(areaBeforeScale * multiplier * multiplier, areaAfterScale, FAULT);
  }

  BOOST_AUTO_TEST_CASE(TestPolygonInvalidParametrs)
  {
    lebedev::point_t shape[] = {{4.0, 1.0}, {7.0, 3.0}};
    size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
    BOOST_CHECK_THROW(lebedev::Polygon testPolygon(qtyVertex, shape), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestPolygonInvalidCoefficient)
  {
    lebedev::point_t shape[] = {{2.0, 1.0}, {5.0, 1.0}, {5.0, 4.0}, {2.0, 4.0}};
    size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
    lebedev::Polygon testPolygon(qtyVertex, shape);
    BOOST_CHECK_THROW(testPolygon.scale(INCORRECT_ARG), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestPolygonConstructors)
  {
    lebedev::point_t shape[] = {{2.0, 1.0}, {5.0, 1.0}, {5.0, 4.0}, {2.0, 4.0}};
    size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
    size_t zeroQty = 0;
    lebedev::Polygon testPolygon(qtyVertex, shape);
    lebedev::Polygon copyPolygon(testPolygon);
    BOOST_CHECK_EQUAL(testPolygon.getQuantity(), copyPolygon.getQuantity());

    const size_t qtyBefore = copyPolygon.getQuantity();
    lebedev::Polygon movePolygon(std::move(copyPolygon));
    BOOST_CHECK_EQUAL(copyPolygon.getQuantity(), zeroQty);
    BOOST_CHECK_EQUAL(movePolygon.getQuantity(), qtyBefore);
  }

  BOOST_AUTO_TEST_CASE(testPolygonAsigmentOperator)
  {
    lebedev::point_t shape[] = {{2.0, 1.0}, {5.0, 1.0}, {5.0, 4.0}, {2.0, 4.0}};
    size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
    size_t zeroQty = 0;
    lebedev::Polygon testPolygon(qtyVertex, shape);
    lebedev::Polygon copyPolygon;
    copyPolygon = testPolygon;
    BOOST_CHECK_EQUAL(testPolygon.getQuantity(), copyPolygon.getQuantity());

    const size_t qtyBefore = copyPolygon.getQuantity();
    lebedev::Polygon movePolygon = std::move(copyPolygon);
    BOOST_CHECK_EQUAL(copyPolygon.getQuantity(), zeroQty);
    BOOST_CHECK_EQUAL(movePolygon.getQuantity(), qtyBefore);
  }

BOOST_AUTO_TEST_SUITE_END()
