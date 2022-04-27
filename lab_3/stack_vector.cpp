#include "stack_vector.h"

Stack::Stack (int n): maxlength(n)
{
    data = new DataType[maxlength];
	top = -1;
}

Stack::~Stack ()
{
    delete[] data;
}

int Stack::Empty()
{
	return top<0;
}

DataType Stack::Top ()
{
	return data[top];
}

DataType Stack::Pop ()
{
	return data[top--];
}

int Stack::Push (DataType x)
{
	if (top==maxlength-1) return 0;
	data[++top] = x;
	return 1;
}


