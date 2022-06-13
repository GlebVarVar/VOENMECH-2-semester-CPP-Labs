#include "testFunction.h"


// Сортировка по возрастанию
template <class T>
void sort (T mas[], int n, int flag) {
    for (int startIndex = 0; startIndex < n - 1; ++startIndex) {

        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < n; ++currentIndex) {
            if (flag == 1) { // в зависимости от флага сортируем по убыванию или возрастанию
                if (mas[currentIndex] < mas[smallestIndex])
                    smallestIndex = currentIndex;
            } else {
                if (mas[currentIndex] > mas[smallestIndex])
                    smallestIndex = currentIndex;
            }
            
        }
        std::swap(mas[startIndex], mas[smallestIndex]);
    }
}


template <class T> 
int printSortedList (T mas[], int n) { 
    
    system("cls"); // очищаем экран
    cout << endl << "Start list" << endl;
    for (int index = 0; index < n; ++index) cout << (int) mas[index] << " ";
    cout << endl;
    sort(mas, n, 1);
    


    int temp;
    // поиск первого элемента, что больше нуля
    for (int startIndex = 0; startIndex < n ; ++startIndex) {
        if (mas[startIndex] > 0) {
            temp = startIndex;   
            break;
        }
    }

    sort(mas, temp, 0);   
    
    // вывод значений массива
    cout << endl << "Sorted list" << endl;
    for (int index = 0; index < n; ++index) cout << (int) mas[index] << " ";

    return n;
}

void testFunction() {
    system("cls");
    // ввод размера массива
    cout << "Enter size of array(0 < Your number <= 10)" << endl << ">";
    int size = getVariant(10);

    // выбор типа массива
    string menu[] = {
        "Choose testing args type",
        "1. int",
        "2. char"};
    printMenu(menu, 3);
    
    int type = getVariant(2);

    cout << endl <<  "Enter " << size <<" Numbers" << endl ;
    if (type == 1) {
        int list[size];
        testFunctionInput(size, 1000000000, list);
    } else {
        char list[size];
        testFunctionInput(size, 128, list);
    }
    cout << endl;
    system("pause");
    
    
}

// Input and mas sorting
template<class T>
void testFunctionInput(int size, int type, T *list) {
    for (int i = 0; i < size; i++) {
        cout <<  "list[" << i << "] = ";
        list[i] = getVariantTemplate(type);
    }
    printSortedList(list, size);
}


// Умный input элементов
int getVariantTemplate(int count) {
    int var;
    cin.clear();
    string s; // строка для считывания введённых данных
    getline(cin, s); // считываем строку
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &var) != 1 || var < (-count+1) || var > count) {
        if (s.size() != 0) {
            cout << "Incorrect input. Try again: "; // выводим сообщение об ошибке
            getline(cin, s); // считываем строку повторно
        } else {
            var = getVariantTemplate(count);
            if (var >= 1 || var <= count) {
                break;
            }
        }
    }

    return var;
}