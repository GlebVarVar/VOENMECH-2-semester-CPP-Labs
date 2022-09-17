#include "testFunction.h"

// Вычисление суммы положительных элементов массива.
template <class T> 
int printSum (T mas[], int n) { 

    T sum = 0;
    system("cls"); // очищаем экран
    cout << endl << "Start list" << endl;
    for (int index = 0; index < n; ++index) cout << fixed << setprecision(4) << mas[index] << " ";
    cout << endl;
     
    // Суммирование положительных элементов массива mas
    for (int index = 0; index < n; ++index) {
        if (mas[index] > 0) {
            sum += mas[index];
        }
    }
    
    // Вывод суммы положительных элементов массива
    cout << endl << "Sum of positive array elements: " << sum ;
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
        "1. float",
        "2. double"};
    printMenu(menu, 3);
    
    int type = getVariant(2);

    cout << endl <<  "Enter " << size <<" Numbers" << endl ;
    if (type == 1) {
        float list[size];
        testFunctionInput(size,  list);
    } else {
        double list[size];
        testFunctionInput(size, list);
    }
    cout << endl;
    system("pause");
}

// Input and mas sorting
template<class T>
void testFunctionInput(int size, T *list) {
    for (int i = 0; i < size; i++) {
        cout <<  "list[" << i + 1 << "] = ";
        T temp;
        while (!(cin >> temp) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Input error! Repeat please...\n";
        }
        list[i] = temp;
    }
    printSum(list, size);
}