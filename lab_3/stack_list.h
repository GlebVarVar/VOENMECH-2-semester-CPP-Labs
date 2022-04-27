typedef int DataType;

class Stack
{
 private:
	struct Element
	{
	  DataType data;
	  Element *next;
	} * pstack;
 public:
	Stack ();
	~Stack ();
	int Empty (void);		//проверка на пустоту
	DataType Top (void);	//неразрушающее чтение
	DataType Pop (void);	//извлечь из стека
	int Push (DataType x);  //поместить в стек 
};
