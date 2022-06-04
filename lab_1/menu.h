#include "triangle.h"

#ifndef MENU_H
#define MENU_H

// подключение функций-помощников
#include "D:\Voenmech-Study\Proga\helpFunctions\functions.h"




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