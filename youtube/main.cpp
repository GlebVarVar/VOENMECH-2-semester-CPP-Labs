#include "iostream"
#include "vector"


using namespace std;

template <class T>
class SmartPointer
{
    public:

        SmartPointer(T *ptr) {
            this->ptr = ptr;
        }

        ~SmartPointer() {
            delete ptr;
        } 

        // перегрузка оператора *
        T& operator*() {
            return *ptr;
        }

    private:

        T* ptr;
};



int main()
{
    {
        // vector<int> myVector(20, 34);

    // myVector.push_back(1);
    // myVector.push_back(2);
    // myVector.push_back(3);

    // myVector.reserve(100);
    // cout << myVector[10] << endl; 
    // cout << myVector.at(10) << endl;

    // myVector.shrink_to_fit();
    // myVector.clear();
    // myVector.pop_back();
    // cout << myVector.capacity() << endl;
    // cout << myVector.empty() << endl;
    // myVector.resize(20);

    // myVector.insert();
    // myVector.erase();
    // for (int i = 0; i < myVector.size(); i++)
    // {
    //     cout << myVector[i] << endl;
    // }
    }
    {
        // SmartPointer<int> ptr(new int(10));
        // *ptr = 20;

        // cout << *ptr << endl;
    }
    
   
    vector<int> V = {1,2,3,4,5,6,7,8,9,10};

    vector<int>::iterator it;

    it = V.begin();

    cout << *it << endl;

    return 0;
}