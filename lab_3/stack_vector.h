typedef int DataType;

class Stack
{
    int top;
    DataType * data;
    int maxlength;
   
  public:
	Stack (int n=100);
	~Stack ();
	int Empty (void);		//проверка на пустоту
	DataType Top (void);	//неразрушающее чтение
	DataType Pop (void);	//извлечь из стека
	int Push (DataType x);  //поместить в стек 
};


