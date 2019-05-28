#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
#include "separation.hpp"

void printMatrix(const gusarov::Matrix<gusarov::Shape> matrix)
{
  for (size_t i = 0; i < matrix.getRows(); i++)
   {
     for (size_t j = 0; j < matrix.getColumns(); j++)
     {
       if (matrix[i][j] != nullptr)
       {
         std::cout << "Layer number " << i + 1 << "\n" << "Figure number " << j + 1 << "\n";
         std::cout << "Area is " << matrix[i][j]->getArea() << "\n";
         const gusarov::rectangle_t frameRect = matrix[i][j]->getFrameRect();
         std::cout << "Center is (" << frameRect.pos.x << "," << frameRect.pos.y << ")\n";
       }
     }
   }
}

int main()
{
  //прямоугольник
  gusarov::Rectangle rec({2, 3}, 1, 2, 0);
  rec.printInfo();
  std::cout << '\n';
  std::cout << "Area of rectangle is " << rec.getArea() << '\n';
  rec.move(2, 3);
  rec.move({-2, -3});
  rec.scale(2);
  rec.rotate(60);
  //Вывод данных после смещения и масштабирования
  rec.printInfo();
  std::cout << '\n';
  //окружность
  gusarov::Circle cir({1, 2}, 1);
  cir.printInfo();
  std::cout << '\n';
  std::cout << "Area of circle is " << cir.getArea() << '\n';
  cir.move(2, 1);
  cir.move({4, -3});
  cir.scale(1);
  //Вывод данных после смещения и масштабирования
  cir.printInfo();
  std::cout << '\n';
  //треугольник
  gusarov::Triangle tri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
  tri.printInfo();
  std::cout << "Area of triangle is " << tri.getArea() << '\n';
  tri.move(2, 3);
  tri.move({-2, -3});
  tri.scale(2);
  std::cout << '\n';
  //Вывод данных после смещения и масштабирования
  tri.printInfo();
  std::cout << '\n';
  //создание составной фигуры
  gusarov::CompositeShape compShape(std::make_shared<gusarov::Rectangle>(rec));
  compShape.add(std::make_shared<gusarov::Circle>(cir));
  compShape.add(std::make_shared<gusarov::Triangle>(tri));
  std::cout << "Area of composite shape is " << compShape.getArea() << '\n';
  compShape.printInfo();
  std::cout << '\n';
  //сдвиг и масштабирование составной фигуры
  compShape.move(2, 3);
  compShape.scale(3);
  compShape.rotate(90);
  std::cout << "Area of composite shape is " << compShape.getArea() << '\n';
  compShape.printInfo();
  std::cout << '\n';
  //демонстрация удаления элемента составной фигуры
  compShape.remove(0);
  compShape.printInfo();
  //создание матрицы из составной фигуры
  gusarov::Matrix<gusarov::Shape> matrix = gusarov::section(compShape);
  std::cout << '\n';
  //вывод информации о слоях и фигурах
  printMatrix(matrix);
  //добавление еще одной фигуры в составную фигуру и далее в матрицу
  compShape.add(std::make_shared<gusarov::Rectangle>(rec));
  matrix = gusarov::section(compShape);
  std::cout << '\n';
  //сравненеи результатов
  printMatrix(matrix);

  return 0;
}
