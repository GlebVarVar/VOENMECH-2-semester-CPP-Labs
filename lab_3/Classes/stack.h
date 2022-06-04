#if !defined(Stack_H)
#define Stack_H

// абстрактный класс стека
template <class T>
class Stack {
    public:
        int maxlength;
        int top;
        // =0 тк это абстрактный класс
        virtual int Empty() = 0;
        virtual int Full() = 0;
        virtual T Top() = 0;
        virtual T Pop() = 0;
        virtual int Push(T x) = 0;
    
};

#endif // Stack_H















