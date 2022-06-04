#include "triangle.h"
#include "menu.h"



void printTriangleMenu() {
    system("cls"); // очищаем экран

    string menu[] =  { 
        "What do you want to do?",
        "1. Triangle properties", 
        "2. Set triangle properties",
        "3. Calculation of all angles",
        "4. Calculating the lengths of all sides",
        "5. Calculating the height drawn from a given angle",
        "6. Determining the type of triangle",
        "7. Finding similar triangles" };

    printMenu(menu, 8);

    exitMenu(8);
}

void print_main_menu() {
    system("cls"); // очищаем экран

    string menu[] =  { 
        "What do you want to do?",
        "1. Select triangle", 
        "2. Create new triangle" };

    printMenu(menu, 3);

    exitMenu(3);
}

void print_all_triagles(triangle* list, int N) {
    cout << "Choose triangle PLS!" << endl;
    cout << "> ";
    system("cls"); // очищаем экран
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << list[i].name << endl;
    }

    exitMenu(N + 1);
}


void init_array(triangle* &P, const int N){    P = new triangle [N];  } // инициализация массива
// void free_array(triangle* P){
//     delete []P; 
// }  
void realloc_array(triangle* &P,  int& N){ 

    triangle* new_ptr = new triangle [N + 1];
    memmove(new_ptr,P, sizeof(triangle) * N);  //Копирование старых данных в новое формирование
   
    // free_array(P);
    P = new_ptr; 
}

void fill_array(triangle* &P, const int N) {  
    
    string name;

    cout << "Enter the name of the triangle: ";
    
    getline(cin, name);
    P[N].name =  name;
    cin >> P[N];
    
    cout << endl << "Triagle created" << endl;
    
} 



void menu () {
    int variant_menu;
    
    
    triangle *list = 0;
    int N = 0;
    init_array(list,N);

    do {
        print_main_menu();
        variant_menu = getVariant(3);
        switch (variant_menu) {
            case 1: {
                // выбор треугольника
                
                if (N == 0) {
                    cout << "There are no triangles" << endl;
                    system("pause");

                } else {
                    print_all_triagles(list, N);
                    cout << ">";

                    int count = N + 1;
                    int var;

                    var = getVariant(count);
                    if (var < count) {
                        triangle_menu(list, var, N);
                    }
                    
                }
                
                break;
            }
                
            case 2: {
                realloc_array(list,N);
                fill_array(list,N);
                
                N++;
                system("pause");
                
                break;
            }
                
            case 3:
                break;
        }

    } while (variant_menu != 3);

}


void triangle_menu(triangle* P,  int var, int N) {
    int variant;
    var--;

    do {
        printTriangleMenu();
        variant = getVariant(8);
        system("cls");
        switch (variant) {
            case 1:
                cout << P[var] << endl;
                break;
            case 2:
                P[var].set_triangle_properties();
                break;
            case 3:
                P[var].calculation_all_angles();
                break;
            case 4:
                P[var].calculating_all_sides();
                break;
            case 5:
                P[var].calculating_height();
                break;
            case 6:
                P[var].type();
                break;
            case 7:
                P[var].find_similarity(P,N,var);
                break;
            case 8:
                cout << "Exit" << endl;
                break;
        }
        
        variant != 8 ? system("pause") : 0;

    } while (variant != 8);
}

