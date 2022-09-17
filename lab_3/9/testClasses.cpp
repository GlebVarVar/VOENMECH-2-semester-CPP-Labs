#include "testClasses.h"

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
                List<float> *Deque;
                Deque = new List<float>;
                templateClassTest(Deque);
                break;
            }
                
            case 2: {
                Vector<double> *Deque;
                Deque = new Vector<double>(10);
                templateClassTest(Deque);
                break;
            }

            default:
            break;
        }
    } while (variant != 3);
}

template<class T>
void templateClassTest (Deque<T>* expamleMas) {
    int variant;

    do {
        system("cls");

        string menu[] = {
            "What do you want to do?",
            "1. Push front",
            "2. Push back",
            "3. Pop back",
            "4. Get front",
            "5. Get back",
            "6. Empty",
            "7. Full"};
        printMenu(menu, 8);
        exitMenu(8);

        variant = getVariant(8);

        switch (variant) {
            case 1: {
                cout << "Enter value" << endl << ">";
                T temp;
                while (!(cin >> temp) || (cin.peek() != '\n'))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Input error! Repeat please...\n";
                }
                
                expamleMas->pushFront(temp);
                break;
            }

            case 2: {
                cout << "Enter value" << endl << ">";
                T temp;
                while (!(cin >> temp) || (cin.peek() != '\n'))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Input error! Repeat please...\n";
                }
                
                expamleMas->pushBack(temp);
                break;
            }
                
            case 3: {
                expamleMas->popBack();
                system("pause");
                break;
            } 
                
            case 4: {
                T temp = expamleMas->getFront();
                if (temp != -1) {
                    cout << "Front value is " << temp << endl;
                } 
                system("pause");
                break;
            } 

            case 5: {
                T temp = expamleMas->getBack();
                if (temp != -1) {
                    cout << "Back value is " << temp << endl;
                } 
                system("pause");
                break;
            } 
                
            case 6: {
                if (expamleMas->Empty()) {
                    cout << "Deque is empty :(" << endl;
                } else {
                    cout << "Deque is not empty :)" << endl;
                }
                system("pause");
                break;
            
            } 
                
            case 7: {
                if (expamleMas->Full()) {
                    cout << "Deque is full :(" << endl;
                } else {
                    cout << "Deque is not full :)" << endl;
                }
                system("pause");
                break;
            } 
        }
    } while(variant != 8);
}