#ifndef TRIANGLE_H
#define TRIANGLE_H

// заголовочные файлы
#include "iostream"
#include "memory.h"
#include "cmath"




using namespace std;


class triangle {

    private:
        double side;
        double angle_1;
        double angle_2;

    public:
        string name;
        triangle();///конструктор по умолчанию
        triangle(string, double, double, double);///конструктор с параметром
        triangle(const triangle &);///конструктор копирования
        ~triangle(); // деструктор

        // Геттеры
        double getSide(); 
        double getAngle_1(); 
        double getAngle_2(); 
        // Сеттеры
        void setSide(double);
        void setAngle_1(double);
        void setAngle_2(double);
        
        // Методы
        void set_triangle_properties();
        void calculation_all_angles();
        void calculating_all_sides();
        void calculating_height();
        void type();
        void find_similarity(triangle* , int, int);



        friend ostream& operator<< (ostream &out, const triangle &output);
        friend istream& operator>> (istream &in, triangle &input);

    
        friend string operator^ (const triangle& tr_1, const triangle& tr_2);//вычисление площади

};

#endif // TRIANGLE_H
