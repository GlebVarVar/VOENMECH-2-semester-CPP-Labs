#ifndef MENU_H
#define MENU_H


// подключение заголовочных файлов
#include "string"
#include "iostream"
// подключение функций-помощников
#include "..\helpFunctions\functions.h"


using namespace std;



void printTriangleMenu();
void print_main_menu(int);
void print_all_triagles(triangle* , int);

void init_array(triangle* &, const int ); 
void free_array(triangle* );
void realloc_array(triangle* &,  int& );
void fill_array(triangle* &, const int );  

void triangle_menu(triangle* ,  int, int);


void menu();

#endif // MENU_H