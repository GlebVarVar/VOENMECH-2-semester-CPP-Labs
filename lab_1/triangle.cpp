#include "triangle.h"
#include "memory.h"
#include "menu.h"
#include "cmath"


triangle::triangle()
{
    this -> name = "example" ;
    this->side = 5;
    this->angle_1 = 60;
    this->angle_2 = 30;
}

///конструктор с параметром
triangle::triangle(string name, double side, double angle_1, double angle_2)
{
    this->name = name;
    this->side = side;
    this->angle_1 = angle_1;
    this->angle_2 = angle_2;
}

// конструктор копирования
triangle::triangle(const triangle &src)
{
    this->name = src.name;
    this->side = src.side;
    this->angle_1 = src.angle_1;
    this->angle_2 = src.angle_2;
}

// деструктор
triangle::~triangle()
{
    this->name = "";
    this->side = 0;
    this->angle_1 = 0;
    this->angle_2 = 0;
}

// геттеры
double triangle::getSide()
{
    return this->side;
}

double triangle::getAngle_1()
{
    return this->angle_1;
}

double triangle::getAngle_2()
{
    return this->angle_2;
}

// сеттеры
void triangle::setSide(double side)
{
    this->side = side;
}

void triangle::setAngle_1(double angle_1)
{
    this->angle_1 = angle_1;
}

void triangle::setAngle_2(double angle_2)
{
    this->angle_2 = angle_2;
}

// методы
void triangle::set_triangle_properties() {
    int variant;
    do {
    system("cls");

    cout << "1. Change triangle name" << endl;
    cout << "2. Change triangle side" << endl;
    cout << "3. Change angle #1" << endl;
    cout << "4. Change angle #2" << endl;

    cout << string ( 25,  '-' ) << endl;
    cout << "5. Exit" << endl << endl;

    cout << ">" ;

    variant = get_variant(5);
    switch (variant) {
        case 1:
            cout << "Enter new name" << endl;
            cin >> this->name;
            break;
        case 2:
            double side;
            cout << "Enter new triangle side" << endl;
            cin >> side;
            setSide(side);
            break;
        case 3:
            double angle_1;
            cout << "Enter new triangle angle" << endl;
            cin >> angle_1;
            setAngle_1(angle_1);
            break;
        case 4:
            double angle_2;
            cout << "Enter new triangle angle" << endl;
            cin >> angle_2;
            setAngle_2(angle_2);
            break;
        case 5:
            cout << "Exit" << endl;
            break;
    }
    

    } while (variant != 5);
    
    
}
void triangle::calculation_all_angles() {
    cout << "Angle #1 = " << this-> angle_1 << endl;
    cout << "Angle #2 = " << this-> angle_2 << endl;
    double angle_3 = (180 - this->angle_1 - this->angle_2);
    cout << "Angle #3 = " << angle_3 << endl;
}
void triangle::calculating_all_sides() {
    double side_2 = (this->side * sin(this->angle_1 * M_PI / 180));
    double side_3 = (this->side * sin(this->angle_2 * M_PI / 180));

    cout << "Side #1 = " << this-> side << endl;
    cout << "Side #2 = " << side_2 << endl;
    cout << "Side #3 = " << side_3 << endl;
}
void triangle::calculating_height() {
    double height_1 = (this->side * sin(this->angle_2 * M_PI / 180));
    cout << "Height from angle_1" << " = " << height_1 << endl;
    double height_2 = (this->side * sin(this->angle_1 * M_PI / 180));
    cout << "Height from angle_2" <<  " = " << height_2 << endl;
}
void triangle::type() {
    double angle_3 = (180 - this->angle_1 - this->angle_2);
    
    if (this->angle_1 == 90 || this->angle_2 == 90 || angle_3 == 90) {
        cout << "Triangle is right" << endl;
    }
    else if (this->angle_1 == this->angle_2 || this->angle_1 == angle_3 || this->angle_2 == angle_3) {
        cout << "Triangle is isosceles" << endl;
    }
    else if (this->angle_1 > 90 || this->angle_2 > 90 || angle_3 > 90) {
        cout << "Triangle is obtuse" << endl;
    }
    else {
        cout << "Triangle is scalene" << endl;
    }

}
void triangle::find_similarity(triangle* &list, int N,  int current) {
    cout << "Choose triangle" << endl;
    cout << "> ";
    system("cls"); // очищаем экран
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << list[i].name << endl;
    }
    cout << string ( 25,  '-' ) << endl;
    cout << N + 1 << ". Exit" << endl << endl;
    cout << ">";
    int var = get_variant(N + 1);
    int count = N + 1;
    if (var < count) {
        cout << (list[current] ^ list[var-1]) << endl;
    }
}


// оператор вывода
ostream& operator<< (ostream &out, const triangle &output)
{
    out << "Name: " << output.name << endl;
    out << "side: " << output.side << endl;
    out << "angle_1: " << output.angle_1 << endl;
    out << "angle_2: " << output.angle_2 << endl;
    return out;
}

// оператор ввода
istream& operator>> (istream &in, triangle &input)
{
    int flag = 0;
    do {
        cout << "side: ";
        int side_1;
        in >> side_1 ;
        if (side_1 > 0) {
            input.side = side_1;
            flag++;
        }


    } while(flag != 1);
    flag = 0;
    do {
        cout << "angle_1: ";
        int ang_1;
        in >> ang_1 ;
        if (ang_1 > 1 && ang_1 < 180) {
            input.angle_2 = ang_1;
            flag++;
        }
    }while(flag != 1);
    flag = 0;
    do {
        cout << "angle_2: ";
        int ang_2;
        in >> ang_2 ;
        if (ang_2 > 1 && ang_2 < 180) {
            input.angle_2 = ang_2;
            flag++;
        }
    }while(flag != 1);
    
    return in;
}

string operator^ (const triangle &tr_1, const triangle &tr_2)
{
    string result;
    double tr_1_angle_3 = (180 - tr_1.angle_1 - tr_1.angle_2);
    double tr_2_angle_3 = (180 - tr_2.angle_1 - tr_2.angle_2);

    double mas[3];
    if (tr_1.angle_1 == tr_2.angle_1 ) {
        if (tr_1.angle_2 == tr_2.angle_2) {
            result = "Triangles are similar";
        } else if (tr_1.angle_2 == tr_2_angle_3) {
            result = "Triangles are similar";
        } else {
            result = "Triangles are not similar";
        }
    } else if (tr_1.angle_1 == tr_2.angle_2) {
        if (tr_1.angle_2 == tr_2.angle_1) {
            result = "Triangles are similar";
        } else if (tr_1.angle_2 == tr_2_angle_3) {
            result = "Triangles are similar";
        } else {
            result = "Triangles are not similar";
        }
    } else if (tr_1.angle_1 == tr_2_angle_3) {
        if (tr_1.angle_2 == tr_2.angle_1) {
            result = "Triangles are similar";
        } else if (tr_1.angle_2 == tr_2.angle_2) {
            result = "Triangles are similar";
        } else {
            result = "Triangles are not similar";
        }
    } else {
        result = "Triangles are not similar";
    }
    
    return result;
}

