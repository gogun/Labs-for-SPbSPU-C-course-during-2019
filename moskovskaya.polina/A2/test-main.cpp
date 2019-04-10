#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double errorValue = 0.001;

BOOST_AUTO_TEST_SUITE(rectangleTestingA2);

BOOST_AUTO_TEST_CASE(rectInvariabilityAfterChangingCenter)
{
  moskovskaya::Rectangle recTest1({4,4}, 5, 5);
  const moskovskaya::rectangle_t framesBeforeChange = recTest1.getFrameRect();
  recTest1.move({2, 5});
  const moskovskaya::rectangle_t framesAfterChange = recTest1.getFrameRect();
  BOOST_CHECK_CLOSE(framesBeforeChange.height, framesAfterChange.height, errorValue);
  BOOST_CHECK_CLOSE(framesBeforeChange.width, framesAfterChange.width, errorValue);

  moskovskaya::Rectangle recTest2({2, 5}, 8, 5);
  const double areaBeforeChange = recTest2.getArea();
  recTest2.move({4, 6});
  const double areaAfterChange = recTest2.getArea();
  BOOST_CHECK_CLOSE(areaBeforeChange, areaAfterChange, errorValue);
}

BOOST_AUTO_TEST_CASE(rectInvariabilityAfterDisplacement)
{
  moskovskaya::Rectangle recTest1({4,4}, 5, 5);
  const moskovskaya::rectangle_t framesBeforeDisp = recTest1.getFrameRect();
  recTest1.move(12, 5);
  const moskovskaya::rectangle_t framesAfterDisp = recTest1.getFrameRect();
  BOOST_CHECK_CLOSE(framesBeforeDisp.height, framesAfterDisp.height, errorValue);
  BOOST_CHECK_CLOSE(framesBeforeDisp.width, framesAfterDisp.width, errorValue);

  moskovskaya::Rectangle recTest2({2, 5}, 8, 5);
  const double areaBeforeDisp = recTest2.getArea();
  recTest2.move(4, 3);
  const double areaAfterDisp = recTest2.getArea();
  BOOST_CHECK_CLOSE(areaBeforeDisp, areaAfterDisp, errorValue);
}

BOOST_AUTO_TEST_CASE(rectChangeOfAreaAfterScaling)
{
  moskovskaya::Rectangle recTest1({4, 4}, 7, 8);
  const double areaBeforeScaling = recTest1.getArea();
  const double testFactor = 4;
  const double squareDiff = testFactor * testFactor;
  recTest1.scale(testFactor);
  const double areaAfterScaling = recTest1.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * squareDiff, areaAfterScaling, errorValue);
}

BOOST_AUTO_TEST_CASE(rectChekingInvalidArguments)
{
  BOOST_CHECK_THROW(moskovskaya::Rectangle({5, 6}, -5, 7), std::invalid_argument);
  BOOST_CHECK_THROW(moskovskaya::Rectangle({5, 6}, 8, -13), std::invalid_argument);
  moskovskaya::Rectangle recTest({4,6}, 6, 7.5);
  const double factor = -3;
  BOOST_CHECK_THROW(recTest.scale(factor), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(circleTestingA2);

BOOST_AUTO_TEST_CASE(cirInvariabilityAfterChangingCenter)
  {
    moskovskaya::Circle cirTest1({4,4}, 4.6);
    const moskovskaya::rectangle_t framesBeforeChange = cirTest1.getFrameRect();
    cirTest1.move({2, 5});
    const moskovskaya::rectangle_t framesAfterChange = cirTest1.getFrameRect();
    BOOST_CHECK_CLOSE(framesBeforeChange.height, framesAfterChange.height, errorValue);
    BOOST_CHECK_CLOSE(framesBeforeChange.width, framesAfterChange.width, errorValue);

    moskovskaya::Circle cirTest2({2, 5}, 8.5);
    const double areaBeforeChange = cirTest2.getArea();
    cirTest2.move({4, 6});
    const double areaAfterChange = cirTest2.getArea();
    BOOST_CHECK_CLOSE(areaBeforeChange, areaAfterChange, errorValue);
  }

BOOST_AUTO_TEST_CASE(cirInvariabilityAfterDisplacement)
  {
    moskovskaya::Circle cirTest1({4,4}, 5);
    const moskovskaya::rectangle_t framesBeforeDisp = cirTest1.getFrameRect();
    cirTest1.move(12, 5);
    const moskovskaya::rectangle_t framesAfterDisp = cirTest1.getFrameRect();
    BOOST_CHECK_CLOSE(framesBeforeDisp.height, framesAfterDisp.height, errorValue);
    BOOST_CHECK_CLOSE(framesBeforeDisp.width, framesAfterDisp.width, errorValue);

    moskovskaya::Circle cirTest2({2, 5}, 11);
    const double areaBeforeDisp = cirTest2.getArea();
    cirTest2.move(4, 3);
    const double areaAfterDisp = cirTest2.getArea();
    BOOST_CHECK_CLOSE(areaBeforeDisp, areaAfterDisp, errorValue);
  }

BOOST_AUTO_TEST_CASE(cirChangeOfAreaAfterScaling)
  {
    moskovskaya::Circle cirTest1({4, 4}, 13);
    const double areaBeforeScaling = cirTest1.getArea();
    const double testFactor = 4;
    const double squareDiff = testFactor * testFactor;
    cirTest1.scale(testFactor);
    const double areaAfterScaling = cirTest1.getArea();
    BOOST_CHECK_CLOSE(areaBeforeScaling * squareDiff, areaAfterScaling, errorValue);
  }

BOOST_AUTO_TEST_CASE(cirChekingInvalidArguments)
  {
    BOOST_CHECK_THROW(moskovskaya::Circle({5, 6}, -5), std::invalid_argument);
    moskovskaya::Circle cirTest({4,6}, 6);
    const double factor = -3;
    BOOST_CHECK_THROW(cirTest.scale(factor), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
