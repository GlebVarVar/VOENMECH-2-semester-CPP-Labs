#include <iostream>
#include <string>
// #include "factorial.h"
using namespace std;
 



class Human {

    protected:
        

    private:

        

    public:
        string name;
        

};

class Student : public Human {

    public:
        string group;

        void Learn() {
            cout << "I'm learning" << endl;
        }

        void setName(string name) {
            this->name = name;
        }

};

class Professor : public Human {

    public:
        string subject;

};




int main()
{

    Student st;
    st.name = "Ivan";
    return 0;
}

