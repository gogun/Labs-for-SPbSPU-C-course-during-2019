#include <stdexcept>
#include <boost/test/auto_unit_test.hpp>
#include "separation.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

BOOST_AUTO_TEST_SUITE(testsForSeparation)
  BOOST_AUTO_TEST_CASE(testIntersect)
  {
    gusarov::Rectangle testingRec({2, 3}, 1, 2, 0);
    gusarov::Circle testingCir({1, 2}, 1);
    gusarov::Triangle testingTri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
    BOOST_CHECK(gusarov::intersect(testingRec.getFrameRect(), testingCir.getFrameRect()));
    BOOST_CHECK(gusarov::intersect(testingCir.getFrameRect(), testingTri.getFrameRect()));
    BOOST_CHECK(!gusarov::intersect(testingTri.getFrameRect(), testingRec.getFrameRect()));
  }
BOOST_AUTO_TEST_CASE(testSection)
{
  gusarov::CompositeShape testingComp;
  gusarov::Rectangle testingRec({-2, 3}, 4, 4, 0);
  gusarov::Circle testingCir({0, 0}, 2);
  gusarov::Triangle testingTri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
  testingComp.add(std::make_shared<gusarov::Rectangle>(testingRec));
  testingComp.add(std::make_shared<gusarov::Triangle>(testingTri));
  testingComp.add(std::make_shared<gusarov::Circle>(testingCir));

  gusarov::Matrix<gusarov::Shape> testingMatrix = gusarov::section(testingComp);
  BOOST_CHECK_EQUAL(testingMatrix.getRows(), 2);
  BOOST_CHECK_EQUAL(testingMatrix[0][0], testingComp[0]);
  BOOST_CHECK_EQUAL(testingMatrix[0][1], testingComp[1]);
  BOOST_CHECK_EQUAL(testingMatrix[1][0], testingComp[2]);
}
BOOST_AUTO_TEST_SUITE_END()
