#if !defined(TEST_CLASSES_H)
#define TEST_CLASSES_H

// Заголовочные файлы
#include "string"
#include "iostream"
// функции-помощники
#include "..\..\helpFunctions\functions.h"

using namespace std;



// deque(дек) - double ended queue (с ограниченным выходом)
template <class T>
class Deque {
    public:
        int size;
        int maxlength;

        virtual int Empty (void) = 0; //проверка на пустоту
        virtual int Full (void) = 0; //проверка на полноту заполнения

        virtual void pushBack(T) = 0; // добавление элемента в начало дека
        virtual void pushFront(T) = 0; // добавление элемента в конец дека

        virtual T getFront (void) = 0; // неразрушающее чтение элемента c начала дека
        virtual T getBack (void) = 0; // неразрушающее чтение элемента c конца дека

        
        virtual T popBack (void) = 0; // удаление эоемента с конца дека

        virtual ~Deque();
};

template <class T>
class List: public Deque<T> {
    
    struct Node {
        Node(T data = T(), Node *pPrev = nullptr, Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }

        T data;
        Node * pNext, * pPrev;
    } *head, *tail; //индексы головы и хвоста

    public:

        List (int length = 10);
        ~List ();

        int Empty (void) override;
        int Full (void) override;

        void pushBack(T) override;
        void pushFront(T) override;

        T getFront (void) override;
        T getBack (void) override;

        T popBack (void) override;
        
        
};

template <class T>
class Vector: public Deque<T> {
    int head, tail; //индексы головы и хвоста
    
    T *data; //массив для хранения элементов
    public:

        Vector(int maxlength=10);
        ~Vector();

        int Empty (void) override;
        int Full (void) override;

        void pushBack(T) override;
        void pushFront(T) override;

        T getFront (void) override;
        T getBack (void) override;

        T popBack (void) override;
        

};


// Конструкторы
template <class T>
List<T>::List(int length) {
    this->head = tail = NULL;
    this->maxlength = length;
    this->size = 0;
}

template <class T>
Vector<T>::Vector(int length) {
    this->maxlength = length;
    this->data = new T[this->maxlength];

    this->head = 0;
    this->tail = this->maxlength - 1;
    this->size = 0;
}

// Деструкторы
template <class T>
Deque<T>::~Deque(){}

template <class T>
List<T>::~List () {
    Node * temp = head;
    while (head) {
        temp = head;
        this->head = head->pNext;
        delete temp;
    }
}

template <class T>
Vector<T>::~Vector()
{
   delete[] this->data;
}

// Проверка на пустоту
template <class T>
int List<T>::Empty() {
    return this->head == NULL;
}

template <class T>
int Vector<T>::Empty() {
    return (this->tail + 1 ) % this->maxlength == this->head;
}


// Проверка на полноту заполнения
template <class T>
int List<T>::Full() {
    return this->size == this->maxlength;
}

template <class T>
int Vector<T>::Full() {
    return ( this->tail + 2 ) % this->maxlength == this->head;
}


// Добавление элемента в начало дека
template <class T>
void List<T>::pushFront(T item) {
    if (Full()) {
        cout << "deque is full :(" << endl;
        return;
    }
    if (Empty()) {
        // Создаём первый элемент
        this->head = this->tail = new Node(item);
    } 
    else {
        // Создаём новый элемент
        Node *pNew = new Node(item, nullptr, head);
        this->head->pPrev = pNew;
        // Перемещаем указатель на новый элемент
        this->head = pNew;
    }

    this->size++;
}

template <class T>
void Vector<T>:: pushFront(T item) {
    if (Full()) {
        cout << "deque is full :(" << endl;
        return;
    } else {
        int value;

        this->head = this->head ? this->head - 1 : this->maxlength - 1;
        this->data[this->head] = item;
    }
    
    
    
    this->size++;
}


// Добавление элемента в конец дека
template <class T>
void List<T>::pushBack(T data) {
    if (Full()) {
        cout << "deque is full :(" << endl;
        return;
    }
    if (Empty()) {
        this->head = this->tail = new Node(data);
    } else {
        this->tail->pNext = new Node(data, tail, nullptr);;
        this->tail = tail->pNext;
    }
    this->size++;
}

template <class T>
void Vector<T>::pushBack(T item) {
    if (Full()) {
        cout << "deque is full :(" << endl;
        return;
    }

    this->tail = ( this->tail + 1 ) % this->maxlength;
    this->data[this-> tail] = item;
    this->size++;
}


// Неразрушающее чтение элемента c начала дека
template <class T>
T List<T>::getFront() {
    if (Empty()) {
        cout << "deque is empty :(" << endl;
        return 0;
    }
    return this->head->data;
}

template <class T>
T Vector<T>::getFront() {
    if (Empty()) {
        cout << "deque is empty :(" << endl;
        return 0;
    }
    return this->data[this->head];
}


// Неразрушающее чтение элемента c конца дека
template <class T>
T List<T>::getBack() {
    if (Empty()) {
        cout << "deque is empty :(" << endl;
        return 0;
    }
    return this->tail->data;
}

template <class T>
T Vector<T>::getBack() {
    if (Empty()) {
        cout << "deque is empty :(" << endl;
        return 0;
    }
    return this->data[this->tail];
}


// Удаление эоемента с конца дека
template <class T>
T List<T>::popBack() {
    Node *temp = tail;
    T tempData;

    if (Empty()) {
        cout << "deque is empty :(" << endl;
        return 0;
    } else if (this->size == 1) {
        tempData = this->tail->data;

        this->head = head->pNext;
        this->tail = nullptr;
    } else {
        tempData = tail->data;

        this->tail = tail->pPrev;
        this->tail->pNext = nullptr;
    }

    delete temp;
    this->size--;

    return tempData;
}

template <class T>
T Vector<T>::popBack() {
    if (Empty()) {
        cout << "deque is empty :(" << endl;
        return 0;
    }

    int temp = tail;
    this->tail = this->tail ? this->tail - 1 : this->maxlength - 1;
    this->size--;
    return this->data[temp];
}


template <class T>
void templateClassTest (Deque<T> * );



#endif // TEST_CLASSES_H
