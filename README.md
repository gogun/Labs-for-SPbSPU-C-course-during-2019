Лабораторные работы
===================

Правила
-------

* Каждый студент размещает свои работы в каталоге со своим именем на
  английском языке, строчными буквами и разделив фамилию и имя
  точкой, например, "lastname.firstname".

* Каждая работа должна находиться в каталоге, имя которого
  представляет собой объединение заглавной латинской буквы,
  обозначающей семестр ("A" или "B") и номера работы, например,
  "lastname.firstname/A1" для первой работы первого семестра или
  "lastname.firstname/B3" для третьей работы второго семестра.

* Все работы должны быть быть написаны в рамках стандарта C++ 14.

* Сроком сдачи работы является дата отправки Merge Request.

* Каждая работа должна быть выполнена в отдельном Merge
  Request. Соответственно, не допускаются следующие ситуации:

    - более одной работы внутри Merge Request, но, если работа
      требует исправления уже сданных работ, такие изменения *должны*
      быть выполнены в том же Merge Request, так как поддерживают
      корректность проекта;

    - несколько Merge Request для одной и той же работы, за
      исключением предыдущего пункта, так как каждый Merge Request
      обеспечивает отслеживание истории изменений и приема работы.

* Изменения в Merge Request должны быть выполнены относительно самого
  свежего коммита в ветке "master" основного проекта. Достигается это
  операциями "merge" и "rebase" (см. документацию по
  [Git](https://git-scm.com/book)).

* Каждый коммит должен:

    - содержать логически единое изменение;

    - обладать комментарием, из которого понятно что (в первой строке)
      и зачем (описание после пустой строки) было сделано;

    - успешно компилироваться и компоноваться;

    - проходить unit-тесты, если они есть;

    - крайне желательно проходить приемочные тесты.

    Категорически не допускается "брать штурмом" систему, создавая
    множество коммитов путем подбора символов в исходных программах,
    которые смогут, наконец, скомпилироваться.

* На проекте используется Continuous Integration (CI), соответственно,
  сборка и тестирование выполняются автоматически. Коммиты, не
  прошедшие CI (с ошибкой или пропустившие CI) не
  принимаются. Результаты тестирования доступны в виде архива
  артефактов сборки и могут быть получены по ссылке "Download
  acceptance artifacts" Web UI, указанной либо в коммите, либо в CI
  pipeline.

Сборка работ
------------

Для сборки и запуска работ присутствует Makefile для
[GNU Make](https://www.gnu.org/software/make/). Все работы
автоматически обнаруживаются и могут быть построены с использованием
нескольких целей.

Идентификатором каждой работы является строка
`lastname.firstname/labnumber`, на которую в дальнейшем ссылаются при
помощи `labid`.

Все исходные тексты в каждой работе идентифицируются по расширению
"cpp". Обнаруженные исходные тексты делятся на группы:

* Исходные тексты работы: все файлы, имена которых _не_ начинаются с
  "test-".

* Исходные тексты тестов: все файлы, исключая файл "main.cpp".

Как видно, файл "main.cpp" стоит особняком: его назначение - функция
`main()` выполненной работы.

Makefile автоматически строит программу для каждой работы. Так как имя
программы в общем случае неизвестно, специальная цель выполняет запуск
построенной программы с передачей параметров.

Общие файлы для нескольких работ должны размещаться в подкаталоге
"common" своего каталога. Они будут автоматически добавлены при сборке
работы. Внутри каталога "common" допустимо создавать подкаталоги для
организации файлов.

Поддерживаемые цели:

* `build-labid`: построение лабораторной работы, например

        $ make build-ivanov.ivan/2

* `run-labid`: запуск построенной программы, например

        $ make run-ivanov.ivan/2

    Для передачи дополнительных параметров используется переменная
    `ARGS` (при помощи GNU Make):

        $ make run-ivanov.ivan/1 ARGS="1 ascending"

    или (c использованием Bourne Shell):

        $ ARGS="1 ascending" make run-ivanov.ivan/1

    или (Bourne Shell, с сохранением в окружении процесса):

        $ export ARGS="1 ascending"
        $ make run-ivanov.ivan/1

* `test-labid`: сборка и запуск тестов работы:

        $ make test-ivanov.ivan/3

    Переменная `TEST_ARGS` используется для передачи параметров тестам
    аналогично `ARGS`.

* `labs`: список всех лабораторных в проекте.

Дополнительной возможностью является запуск динамического анализатора
[Valgrind](http://valgrind.org) для запускаемых программ. Для этого
необходимо указать в переменной `VALGRIND` параметры анализатора так,
как это делается для `ARGS`/`TEST_ARGS`.

Boost
=====

Библиотека [Boost](http://boost.org) может находиться в нестандартном
месте. Для того, чтобы указать его, в корне проекта необходимо
разместить файл `.boost_location`, состоящий из одной строки с путем к
корню библиотеки.

> Путь не должен содержать пробельные символы.

Accepted Labs
=============

| Name                   | A1 | A2 | A3 | A4 | B1 | B2 | B3 | B4 | B5 | B6 | B7 | B8 |
|------------------------|----|----|----|----|----|----|----|----|----|----|----|----|
| Afanasiev Aleksey      | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Akhmedov Abdulla       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Alexandrov Denis       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Andreeva Elizaveta     | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Atamanova Svetlana     | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Barekov Andrey         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Bazoune Mahdi          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Besedin Daniil         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Bessonov Alexandr      | *  |    |    |    |    |    |    |    |    |    |    |    |
| Blyshchik Lyudmila     | *  |    |    |    |    |    |    |    |    |    |    |    |
| Bogdanov Dmitriy       | *  |    |    |    |    |    |    |    |    |    |    |    |
| Bondarev Oleg          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Borshchev Ivan         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Bublyaev Aleksey       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Bushuev Aleksandr      | *  |    |    |    |    |    |    |    |    |    |    |    |
| Che Eduard             | *  |    |    |    |    |    |    |    |    |    |    |    |
| Chizhov Nikita         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Chugaynov Valeriy      | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Drozdov Kirill         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Dyu Vladimir           | *  |    |    |    |    |    |    |    |    |    |    |    |
| Fedorov Danila         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Firsov Daniil          | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Frolov Nikita          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Gluckhov Pasha         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Gnatishin Mikhail      | *  |    |    |    |    |    |    |    |    |    |    |    |
| Golikov George         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Gusarov Ilya           | *  |    |    |    |    |    |    |    |    |    |    |    |
| Ivanenko Egor          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Ivanov Nikita          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Ivleva Anna            | *  |    |    |    |    |    |    |    |    |    |    |    |
| Karpenko Alexey        | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Khismatullin Kamil     | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Klimchuk Daniil        | *  |    |    |    |    |    |    |    |    |    |    |    |
| Konev Ivan             | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Kornilov Daniil        | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Korolev Denis          | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Korshunov Kirill       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Kotov Ivan             | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Kozhin Sergey          | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Kozlov Konstantin      | *  |    |    |    |    |    |    |    |    |    |    |    |
| Krasnopyorov Nikita    | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Kraynov Alexander      | *  |    |    |    |    |    |    |    |    |    |    |    |
| Krinkina Vladislava    | *  |    |    |    |    |    |    |    |    |    |    |    |
| Kurbanova Angela       | *  |    |    |    |    |    |    |    |    |    |    |    |
| Kuxov Grigoriy         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Kuznetsov Svyatoslav   | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Kvashnin Artem         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Lebedev Denis          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Lestsenko Klimenti     | *  |    |    |    |    |    |    |    |    |    |    |    |
| Lukina Valeria         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Lutsenko Dmitrii       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Lyalin Danil           | *  |    |    |    |    |    |    |    |    |    |    |    |
| Lysenko Bogdan         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Magomedalizade Orkhan  | *  |    |    |    |    |    |    |    |    |    |    |    |
| Malinin Ilia           | *  |    |    |    |    |    |    |    |    |    |    |    |
| Malinovskaya Vera      | *  |    |    |    |    |    |    |    |    |    |    |    |
| Marashov Alexander     | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Maschenko Bogdan       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Moiseeva Anastasia     | *  |    |    |    |    |    |    |    |    |    |    |    |
| Moreva Ekaterina       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Moskovskaya Polina     | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Naumov Andrei          | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Nazarov Dmitry         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Neupokoev Dmitry       | *  |    |    |    |    |    |    |    |    |    |    |    |
| Nurtdinov Artur        | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Pavlova Alexandra      | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Pedchenko Elena        | *  |    |    |    |    |    |    |    |    |    |    |    |
| Petrov Artyom          | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Pinaev Nikita          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Ponomarev Stepan       | *  |    |    |    |    |    |    |    |    |    |    |    |
| Potapova Maria         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Prohorova Aleksandra   | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Protasov Maxim         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Purnov Nikita          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Pylaev Yaroslav        | *  |    |    |    |    |    |    |    |    |    |    |    |
| Radkov Georgy          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Rakhmatullin Alexander | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Rodchenkov Simon       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Ryabikin Timofey       | *  |    |    |    |    |    |    |    |    |    |    |    |
| Sachuk Ilya            | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Saltykov Ilya          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Sarchuk Yaroslav       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Sazonov Dmitriy        | *  |    |    |    |    |    |    |    |    |    |    |    |
| Senatova Irina         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Shahbazly Tural        | *  |    |    |    |    |    |    |    |    |    |    |    |
| Shatilov Demid         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Sherman Mark           | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Shestakova Alina       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Sheve Nikita           | *  |    |    |    |    |    |    |    |    |    |    |    |
| Shreder Anastasia      | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Skudar Ilia            | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Smirnov Pavel          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Soprachev Andrei       | *  |    |    |    |    |    |    |    |    |    |    |    |
| Stebnevsky Vladislav   | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Stotskaya Elena        | *  |    |    |    |    |    |    |    |    |    |    |    |
| Sysoeva Olga           | *  |    |    |    |    |    |    |    |    |    |    |    |
| Tagiev Andrey          | *  |    |    |    |    |    |    |    |    |    |    |    |
| Tolstikov Grigoriy     | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Trofimov Philipp       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Troshev Dmitry         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Tsai Georgii           | *  |    |    |    |    |    |    |    |    |    |    |    |
| Tsygarova Irina        | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Ustinov Artyom         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Utin Mihail            | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Uzhegov Dmitry         | *  |    |    |    |    |    |    |    |    |    |    |    |
| Vasilevsky Alexander   | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Vlasenko Nataliia      | *  |    |    |    |    |    |    |    |    |    |    |    |
| Zakharova Alyona       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Zemlyak Artyom         | *  | *  |    |    |    |    |    |    |    |    |    |    |
| Zybkin Vladislav       | *  | *  |    |    |    |    |    |    |    |    |    |    |
| __Total__              | 110|  54|   0|   0|   0|   0|   0|   0|   0|   0|   0|   0|
