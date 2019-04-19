#define BOOST_TEST_MODULE A2

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(A2Test)
  const double error = 0.001;
  BOOST_AUTO_TEST_CASE(rectangleMove)
  {
    stotskaya::Rectangle testRect({5.0, 6.5}, 20.0, 10.0);
    const stotskaya::rectangle_t initialFrame = testRect.getFrameRect();
    const double initialArea = testRect.getArea();
    testRect.move({3.0, 5.5});
    BOOST_CHECK_CLOSE(initialFrame.width, testRect.getFrameRect().width, error);
    BOOST_CHECK_CLOSE(initialFrame.height, testRect.getFrameRect().height, error);
    BOOST_CHECK_CLOSE(initialArea, testRect.getArea(), error);
    testRect.move(-3.0, 4.0);
    BOOST_CHECK_CLOSE(initialFrame.width, testRect.getFrameRect().width, error);
    BOOST_CHECK_CLOSE(initialFrame.height, testRect.getFrameRect().height, error);
    BOOST_CHECK_CLOSE(initialArea, testRect.getArea(), error);
  }
  BOOST_AUTO_TEST_CASE(rectangleScale)
  {
    stotskaya::Rectangle testRect({5.0, 6.5}, 20.0, 10.0);
    const stotskaya::rectangle_t initialFrame = testRect.getFrameRect();
    const double initialArea = testRect.getArea();
    const double testRatio = 3.2;
    testRect.scale(testRatio);
    BOOST_CHECK_CLOSE(initialFrame.width * testRatio, testRect.getFrameRect().width, error);
    BOOST_CHECK_CLOSE(initialFrame.height * testRatio, testRect.getFrameRect().height, error);
    BOOST_CHECK_CLOSE(initialArea * testRatio * testRatio, testRect.getArea(), error);
  }
  BOOST_AUTO_TEST_CASE(rectangleIncorrectValues)
  {
    BOOST_CHECK_THROW(stotskaya::Rectangle({1.0, 1.0}, 0.0, 1.0), std::invalid_argument);
    BOOST_CHECK_THROW(stotskaya::Rectangle({1.0, 1.0}, 1.0, -1.0), std::invalid_argument);
    stotskaya::Rectangle testRect({1.0, 3.0}, 5.0, 7.0);
    BOOST_CHECK_THROW(testRect.scale(-1.0), std::invalid_argument);
  }
  BOOST_AUTO_TEST_CASE(circleMove)
  {
    stotskaya::Circle testCircle({2.3, 3.0}, 1.5);
    const stotskaya::rectangle_t initialFrame = testCircle.getFrameRect();
    const double initialArea = testCircle.getArea();
    testCircle.move({3.0, 5.5});
    BOOST_CHECK_CLOSE(initialFrame.width, testCircle.getFrameRect().width, error);
    BOOST_CHECK_CLOSE(initialFrame.height, testCircle.getFrameRect().height, error);
    BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), error);
    testCircle.move(-3.0, 4.0);
    BOOST_CHECK_CLOSE(initialFrame.width, testCircle.getFrameRect().width, error);
    BOOST_CHECK_CLOSE(initialFrame.height, testCircle.getFrameRect().height, error);
    BOOST_CHECK_CLOSE(initialArea, testCircle.getArea(), error);
  }
  BOOST_AUTO_TEST_CASE(circleScale)
  {
    stotskaya::Circle testCircle({5.0, 6.5}, 6.0);
    const stotskaya::rectangle_t initialFrame = testCircle.getFrameRect();
    const double initialArea = testCircle.getArea();
    const double testRatio = 4.5;
    testCircle.scale(testRatio);
    BOOST_CHECK_CLOSE(initialFrame.width * testRatio, testCircle.getFrameRect().width, error);
    BOOST_CHECK_CLOSE(initialFrame.height * testRatio, testCircle.getFrameRect().height, error);
    BOOST_CHECK_CLOSE(initialArea * testRatio * testRatio, testCircle.getArea(), error);
  }
  BOOST_AUTO_TEST_CASE(circleIncorrectValues)
  {
    BOOST_CHECK_THROW(stotskaya::Circle({1.0, 1.0}, 0.0), std::invalid_argument);
    BOOST_CHECK_THROW(stotskaya::Circle({1.0, 1.0}, -1.0), std::invalid_argument);
    stotskaya::Circle testCircle({1.0, 3.0}, 5.0);
    BOOST_CHECK_THROW(testCircle.scale(-1.0), std::invalid_argument);
  }
  BOOST_AUTO_TEST_SUITE_END()
