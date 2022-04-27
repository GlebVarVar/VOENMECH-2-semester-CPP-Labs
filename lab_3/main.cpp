#include <iostream>
#include <algorithm>


using namespace std;


template <class Tdata, class Tnumber> /* шаблон функции с одним параметром */
Tnumber summa (Tdata mas[], Tnumber n) /* параметры функции одного типа, заданного параметром шаблона, тот же тип будет и у результата */
{

	for (int startIndex = 0; startIndex < n - 1; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < n; ++currentIndex)
		{
			if (mas[currentIndex] < mas[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(mas[startIndex], mas[smallestIndex]);
	}

    int temp;
    for (int startIndex = 0; startIndex < n ; ++startIndex) {
        if (mas[startIndex] > 0) {
            temp = startIndex;   
            break;
        }
    }


    
    for (int startIndex = 0; startIndex < temp; ++startIndex)
	{

		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < temp; ++currentIndex)
		{
			if (mas[currentIndex] > mas[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(mas[startIndex], mas[smallestIndex]);
	}
    
    for (int index = 0; index < n; ++index)
		cout << mas[index] << " ";
 
	
    return n;
}

int main() {
    
    int b = 10;
    double a[b] = {-1., -11.11, 3., 20., 5., 100., -34., 8., 43., -43.} ;


    summa(a, b); 
    
    return 0;
}

