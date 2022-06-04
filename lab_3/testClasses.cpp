#include "testClasses.h"
#include ".\Classes\stackArray.h"
#include ".\Classes\stackList.h"


void testClasses() {
    int variant;

    do {
        system("cls"); // очищаем экран
        
        string menu[] = {
            "Select structures storage",
            "1. Linked list",
            "2. Vector"};
        printMenu(menu, 3);
        exitMenu(3);

        variant = getVariant(3);


        switch (variant) {
            case 1: {
                List<int> *stek;
                stek = new List<int>;
                templateClassTest(stek);
                
                break;
            }
                
            case 2: {
                Array<int> *stek;
                stek = new Array<int>(10);
                templateClassTest(stek);
                
                break;
            }
                
            default:
                break;
        }


    } while (variant != 3);
}



template<class T>
void templateClassTest (Stack<T>* expamleMas) {
    int variant;

    do {
        system("cls");

        string menu[] = {
            "What do you want to do?",
            "1. Push",
            "2. Pop",
            "3. Top",
            "4. Empty",
            "5. Full"};
        printMenu(menu, 6);
        exitMenu(6);

        variant = getVariant(6);

        switch (variant) {
            case 1: {
                cout << "Enter value" << endl << ">";
                int value = getVariant(100);
                expamleMas->Push(value);
                break;
            }
                

            case 2: {
                expamleMas->Pop();
                system("pause");
                break;
            } 
                
            case 3: {
                T temp = expamleMas->Top();
                if (temp != -1) {
                    cout << "Top value is " << temp << endl;
                } 
                system("pause");
                break;
            } 
                
            case 4: {
                if (expamleMas->Empty()) {
                    cout << "Stack is empty :(" << endl;
                } else {
                    cout << "Stack is not empty :)" << endl;
                }
                system("pause");
                break;
            
            } 
                
            case 5: {
                if (expamleMas->Full()) {
                    cout << "Stack is full :(" << endl;
                } else {
                    cout << "Stack is not full :)" << endl;
                }
                system("pause");
                break;
            } 
                
            

        }

    }while(variant != 6);
}