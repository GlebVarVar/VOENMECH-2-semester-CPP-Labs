#include "stack_list.h"

Stack::Stack ()
{
    pstack = NULL;
}

Stack::~Stack ()
{
    Element * temp;
    while (pstack)
    {
          temp = pstack;
          pstack = pstack->next;
          delete temp;
    }
}

int Stack::Empty()
{
	return pstack == NULL;
}

DataType Stack::Top ()
{
	return pstack->data;
}

DataType Stack::Pop ()
{
	Element *del = pstack;
	DataType temp = pstack->data;
	pstack = pstack->next;
	delete del;
	return temp;
}

int Stack::Push (DataType x)
{
	Element *ins = new (std::nothrow) Element;
	if (ins==NULL) return 0;
	ins->data = x;
	ins->next = pstack;
	pstack = ins;
	return 1;
}
