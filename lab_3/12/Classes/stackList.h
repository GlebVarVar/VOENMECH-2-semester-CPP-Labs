#include "stack.h"


#include "iostream"

using namespace std;
// класс стека на основе связного списка
template <class T>
class List: public Stack<T> {
    private:
        struct Node {
            T data;
            Node *next;
        };
        Node *pStack;
        int top;
        
    public:
        List(int maxlength = 10);
        ~List();
        int Empty() override;
        int Full() override;
        T Top() override;
        T Pop() override;
        int Push(T x) override;
};


// Конструктор 
template <class T>
List<T>::List(int maxlength) {
    pStack = nullptr;
    this->maxlength = maxlength;
    top = -1;
}

// Деструктор 
template <class T>
List<T>::~List() {
    Node * temp;
    while (pStack) {
        temp = pStack;
        pStack = pStack->next;
        delete temp;
    }
}

// Проверка на пустоту
template <class T>
int List<T>::Empty() {
    return pStack == nullptr;
}

// Проверка на заполненность
template <class T>
int List<T>::Full() {
    return this->top == this->maxlength - 1;
}

// неразрушающее чтение
template <class T>
T List<T>::Top() {
    if (Empty()) {
        cout << "Stack is empty :(" << endl;
        return -1;
    } else {
        return pStack->data;
    }
}

// извлечь из стека
template <class T>
T List<T>::Pop() {
    if (Empty()) {
        cout << "Stack is empty :(" << endl;
        return -1;
    } else {
        T delNodeData = pStack->data; // данные для возврата

        Node *del = pStack;
        pStack = pStack->next;
        delete del;

        return delNodeData;
    }
   
}

// поместить в стек 
template <class T>
int List<T>::Push(T newData) {
    if (Full()) {
        cout << "Stack is full :(" << endl;
        return -1;
    } else {
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->next = pStack;
        pStack = newNode;

        top++;
        return 1;
    }
}


