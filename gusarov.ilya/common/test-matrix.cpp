#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>

#include "composite-shape.hpp"
#include "separation.hpp"
#include "matrix.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

BOOST_AUTO_TEST_SUITE(testsForMatrix)

  BOOST_AUTO_TEST_CASE(testOfConstructors)
  {
    gusarov::Rectangle testingRec({2, 3}, 1, 2, 0);
    gusarov::Circle testingCir({1, 2}, 1);
    gusarov::Triangle testingTri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
    gusarov::CompositeShape testComp(std::make_shared<gusarov::Rectangle>(testingRec));
    testComp.add(std::make_shared<gusarov::Circle>(testingCir));
    testComp.add(std::make_shared<gusarov::Triangle>(testingTri));

    gusarov::Matrix<gusarov::Shape> testMatrix = gusarov::section(testComp);

    BOOST_CHECK_NO_THROW(gusarov::Matrix<gusarov::Shape> testMatrix1(testMatrix));
    BOOST_CHECK_NO_THROW(gusarov::Matrix<gusarov::Shape> testMatrix2(std::move(testMatrix)));
  }

  BOOST_AUTO_TEST_CASE(testsForOperators)
  {
    gusarov::Rectangle testingRec({2, 3}, 1, 2, 0);
    gusarov::Circle testingCir({1, 2}, 1);
    gusarov::Triangle testingTri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
    gusarov::CompositeShape testComp(std::make_shared<gusarov::Rectangle>(testingRec));
    testComp.add(std::make_shared<gusarov::Circle>(testingCir));
    testComp.add(std::make_shared<gusarov::Triangle>(testingTri));

    gusarov::Matrix<gusarov::Shape> testMatrix = gusarov::section(testComp);

    BOOST_CHECK_THROW(testMatrix[10], std::out_of_range);

    BOOST_CHECK_NO_THROW(gusarov::Matrix<gusarov::Shape> testMatrix1 = testMatrix);
    BOOST_CHECK_NO_THROW(gusarov::Matrix<gusarov::Shape> testMatrix2 = std::move(testMatrix));

    gusarov::Triangle testingTri1({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
    gusarov::CompositeShape testComp1(std::make_shared<gusarov::Triangle>(testingTri1));

    gusarov::Matrix<gusarov::Shape> testMatrix3 = gusarov::section(testComp1);
    gusarov::Matrix<gusarov::Shape> testMatrix4 = gusarov::section(testComp1);

    BOOST_CHECK(testMatrix3 == testMatrix4);
    BOOST_CHECK(testMatrix3 != testMatrix);
    BOOST_CHECK(testMatrix4 != testMatrix);
  }

BOOST_AUTO_TEST_SUITE_END()
