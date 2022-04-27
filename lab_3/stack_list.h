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
	int Empty (void);		//�������� �� �������
	DataType Top (void);	//������������� ������
	DataType Pop (void);	//������� �� �����
	int Push (DataType x);  //��������� � ����
};
