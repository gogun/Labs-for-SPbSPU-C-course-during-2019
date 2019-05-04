#define BOOST_TEST_MODULE A2

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

const double errValue = 0.001;

BOOST_AUTO_TEST_SUITE(rectangleTestingA2);

BOOST_AUTO_TEST_CASE(immutabilityOfRectAfterChangingCenter)
{
  bessonov::Rectangle recTest1({ 8,8 }, 10, 10);
  const bessonov::rectangle_t framesBeforeChange = recTest1.getFrameRect();
  recTest1.move({ 6, 20 });
  const bessonov::rectangle_t framesAfterChange = recTest1.getFrameRect();
  BOOST_CHECK_CLOSE(framesBeforeChange.height, framesAfterChange.height, errValue);
  BOOST_CHECK_CLOSE(framesBeforeChange.width, framesAfterChange.width, errValue);

  bessonov::Rectangle recTest2({ 7, 18 }, 16, 10);
  const double areaBeforeChange = recTest2.getArea();
  recTest2.move({ 10, 20 });
  const double areaAfterChange = recTest2.getArea();
  BOOST_CHECK_CLOSE(areaBeforeChange, areaAfterChange, errValue);
}

BOOST_AUTO_TEST_CASE(immutabilityOfRectAfterMoving)
{
  bessonov::Rectangle recTest1({ 5,5 }, 10, 10);
  const bessonov::rectangle_t framesBeforeDisp = recTest1.getFrameRect();
  recTest1.move(12, 5);
  const bessonov::rectangle_t framesAfterDisp = recTest1.getFrameRect();
  BOOST_CHECK_CLOSE(framesBeforeDisp.height, framesAfterDisp.height, errValue);
  BOOST_CHECK_CLOSE(framesBeforeDisp.width, framesAfterDisp.width, errValue);

  bessonov::Rectangle recTest2({ 2, 5 }, 8, 5);
  const double areaBeforeDisp = recTest2.getArea();
  recTest2.move(4, 3);
  const double areaAfterDisp = recTest2.getArea();
  BOOST_CHECK_CLOSE(areaBeforeDisp, areaAfterDisp, errValue);
}

BOOST_AUTO_TEST_CASE(changeRectAreaAfterScaling)
{
  bessonov::Rectangle recTest1({ 6, 6 }, 10, 12);
  const double areaBeforeScaling = recTest1.getArea();
  const double testFactor = 4;
  const double squareDiff = testFactor * testFactor;
  recTest1.scale(testFactor);
  const double areaAfterScaling = recTest1.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * squareDiff, areaAfterScaling, errValue);
}

BOOST_AUTO_TEST_CASE(checkRectArg)
{
  BOOST_CHECK_THROW(bessonov::Rectangle({ 6, 9 }, -5, -7), std::invalid_argument);
  BOOST_CHECK_THROW(bessonov::Rectangle({ 6, 9 }, 9, -15), std::invalid_argument);
  bessonov::Rectangle recTest({ 9,10 }, 5, 8.5);
  const double factor = -3;
  BOOST_CHECK_THROW(recTest.scale(factor), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(circleTestingA2);

BOOST_AUTO_TEST_CASE(immutabilityOfCircleAfterChangingCenter)
{
  bessonov::Circle cirTest1({ 8,8 }, 5.7);
  const bessonov::rectangle_t framesBeforeChange = cirTest1.getFrameRect();
  cirTest1.move({ 1, 3 });
  const bessonov::rectangle_t framesAfterChange = cirTest1.getFrameRect();
  BOOST_CHECK_CLOSE(framesBeforeChange.height, framesAfterChange.height, errValue);
  BOOST_CHECK_CLOSE(framesBeforeChange.width, framesAfterChange.width, errValue);

  bessonov::Circle cirTest2({ 4, 9 }, 9.4);
  const double areaBeforeChange = cirTest2.getArea();
  cirTest2.move({ 4, 6 });
  const double areaAfterChange = cirTest2.getArea();
  BOOST_CHECK_CLOSE(areaBeforeChange, areaAfterChange, errValue);
}

BOOST_AUTO_TEST_CASE(cirInvariabilityAfterMoving)
{
  bessonov::Circle cirTest1({ 5,5 }, 9);
  const bessonov::rectangle_t framesBeforeDisp = cirTest1.getFrameRect();
  cirTest1.move(12, 5);
  const bessonov::rectangle_t framesAfterDisp = cirTest1.getFrameRect();
  BOOST_CHECK_CLOSE(framesBeforeDisp.height, framesAfterDisp.height, errValue);
  BOOST_CHECK_CLOSE(framesBeforeDisp.width, framesAfterDisp.width, errValue);

  bessonov::Circle cirTest2({ 2, 5 }, 11);
  const double areaBeforeDisp = cirTest2.getArea();
  cirTest2.move(2, 3);
  const double areaAfterDisp = cirTest2.getArea();
  BOOST_CHECK_CLOSE(areaBeforeDisp, areaAfterDisp, errValue);
}

BOOST_AUTO_TEST_CASE(changeCirAreaAfterScaling)
{
  bessonov::Circle cirTest1({ 4, 4 }, 13);
  const double areaBeforeScaling = cirTest1.getArea();
  const double testFactor = 4;
  const double squareDiff = testFactor * testFactor;
  cirTest1.scale(testFactor);
  const double areaAfterScaling = cirTest1.getArea();
  BOOST_CHECK_CLOSE(areaBeforeScaling * squareDiff, areaAfterScaling, errValue);
}

BOOST_AUTO_TEST_CASE(checkCirArg)
{
  BOOST_CHECK_THROW(bessonov::Circle({ 8, 10 }, -4), std::invalid_argument);
  bessonov::Circle cirTest({ 4, 7 }, 9);
  const double factor = -7;
  BOOST_CHECK_THROW(cirTest.scale(factor), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
