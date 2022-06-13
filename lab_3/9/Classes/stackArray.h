#include "stack.h"

#include "iostream"

using namespace std;

// класс стека на основе массива
template <class T>
class Array : public Stack<T> {
    
    T * data;
    
    public:

        Array(int maxlength = 10);
        ~Array<T>();
        int Empty() override;
        int Full() override;

        T Top() override;
        T Pop() override;
        int Push(T x) override;
};



// Конструктор 
template <class T>
Array<T>::Array(int maxlength) {
    this->data = new T[maxlength];
    this->maxlength = maxlength;

    this->top = -1;
}

// Деструктор 
template <class T>
Array<T>::~Array<T>() {
    delete[] data;
}

// Проверка на пустоту
template <class T>
int Array<T>::Empty()  {
    return this->top == -1;
}

// Проверка на заполненность
template <class T>
int Array<T>::Full() {
    return this->top == this->maxlength - 1;
}

// неразрушающее чтение
template <class T>
T Array<T>::Top() {
    if (Empty()) {
        cout << "Stack is empty :(" << endl;
        return -1;
    } else {
        return this->data[this->top];
    }
    
}

// извлечь из стека
template <class T>
T Array<T>::Pop() {
    if (Empty()) {
        cout << "Stack is empty :(" << endl;
        return -1;
    } else {
        return this->data[this->top--];
    }
   
}

// поместить в стек 
template <class T>
int Array<T>::Push(T newData) {
    if (Full()) {
        cout << "Stack is full :(" << endl;
        return -1;
    } else {
        data[++this->top] = newData;
        return 1;
    }
}


