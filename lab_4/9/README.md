### Практическая работа 3: STL
- Дан файл с английскими словами, разделёнными знаком '-'. Используя std::getline или
regex составить множество (std::set) из уникальных слов в файле. Слова хранить в std::string.

- Также составить словарь (std::map) по следующему принципу:
Ключ - буква, значение - частота встречи в файле слов, начинающихся на эту букву

- Сгенерировать список из 100 структур со следующими полями:
1) Название - случайное слово из множества
2) Основной параметр - используя std::advance получить значения трёх случайных
элементов из словаря и перемножить их
3) Вторичный параметр - квадрат значения из словаря, связанного с названием(в случае
буквы брать первую букву названия)


- Используя функции из библиотеки algorithms
Отсортировать список по возрастанию вторичного параметра 
- Используя std::copy_if, создать новый список, содержащий только:
Элементы с чётным числом букв в названии
- Сгенерировать на основе полученного отфильтрованного списка файл формата json.


- Добавить возможность загрузки файла формата json, создания на основе данных в нём
списка, перетасовки (shuffle) его и отображения полученного результата.


