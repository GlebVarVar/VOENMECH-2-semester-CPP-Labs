### Задача
Описать три класса: 
базовый класс «Строка» и 
производные от него класс «Строка-идентификатор» и 
класс, заданный индивидуальным вариантом. -->

Обязательные для всех классов методы: 
1) конструктор без параметров,
2) конструктор, принимающий в качестве параметра Си-строку, 
3) конструктор копирования, 
4) деструктор, 
<!-- 5) перегрузка операции присваивания «=». 

Во всех методах всех классов предусмотреть печать сообщения, содержащего имя
метода. 
Для конструкторов копирования каждого класса дополнительно
предусмотреть диагностическую печать количества его вызовов,
рекомендуется использовать статические члены класса.

Поля класса «Строка»: 
1) указатель на блок динамически выделенной памяти для размещения символов строки, 
2) длина строки в байтах.

Обязательные методы, помимо вышеуказанных:
конструктор, принимающий в качестве параметра символ (char), 
функция получения длины строки.

Строки класса «Строка-идентификатор» строятся по правилам
записи идентификаторов в Си, и могут включать в себя только те символы,
которые могут входить в состав Си-идентификаторов. Если исходные
данные противоречат правилам записи идентификатора, то создается
пустая «Строка-идентификатор».

Помимо обязательных компонентов классов, указанных в общей
постановке задачи и в вариативной его части, при необходимости можно
добавить дополнительные поля и методы.


Написать тестовую программу, которая должна:
* динамически выделить память под массив указателей на базовый класс
(4-6 шт.);
* в режиме диалога заполнить этот массив указателями на производные
классы, при этом экземпляры производных классов должны создаваться
всех разработанных методов с выводом исходных данных и результатов
на дисплей.
* Режим диалога должен обеспечиваться с помощью иерархического
меню. Основные пункты:


<!-- 1 «Инициализация». Подпункты:
1.1. «Число элементов». Задает число элементов в массиве
указателей на базовый класс. После ввода числа элементов пользоваться
этим пунктом меню запрещается.
1.2. «Начальное значение». С помощью этого пункта меню можно
задать номер элемента, его тип и начальное значение. Задавать
начальные значения и работать с другими пунктами меню запрещается до
тех пор, пока не будет задано число элементов. Допускается задать новое
начальное значение несколько раз. -->
2 «Тестирование». Подпункты:
2.1. «Строка».
2.2. «Строка-идентификатор».
2.3. Класс, соответствующий варианту задания.
2.4. «Задать операнды».
После выбора одного из этих пунктов меню предлагается выбрать
один из методов из списка всех обязательных методов (кроме
конструкторов и деструкторов), связанных с выбранным подпунктом.
3 Выход.


### Вариант 12
Дополнительные методы для класса «Строка-идентификатор»: 
перевод всех символов строки (кроме цифр) в нижний регистр, 
переопределение операции индексации [],
переопределение операции больше или равно >=

Производный от «Строки» класс Шестнадцатеричная строка
Строки данного класса могут содержать только символы шестнадцатеричных цифр (как в
верхнем, так и в нижнем регистре) и символы - и +, задающие знак числа, которые могут
находиться только в первой позиции числа, при отсутствии знака число считается
положительным.
Если в составе инициализирующей строки будут встречены любые
символы, отличные от допустимых, Шестнадцатеричная строка принимает нулевое
значение. 
Содержимое данных строк рассматривается как шестнадцатеричное число.
Обязательные методы: 
определение, 
можно ли представить данное число в формате unsigned int, 
проверки на равенство ==,
проверки на больше >

