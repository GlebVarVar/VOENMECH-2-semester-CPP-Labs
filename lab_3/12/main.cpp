#include "main.h"


int main() {
    

    int variant = 0;
    do {

        system("cls"); // очищаем экран

        string menu[] = {
            "What do you want to do?",
            "1. Test function template",
            "2. Test class template"};
        printMenu(menu, 3);
        exitMenu(3);

        variant = getVariant(3);

        

        switch (variant) {
            case 1: {
                testFunction();
                break;
            }
            case 2: {
                testClasses();
                break;
            }
                

            case 3:
                break;
        }

    } while(variant != 3);

     
    
    return 0;
}




