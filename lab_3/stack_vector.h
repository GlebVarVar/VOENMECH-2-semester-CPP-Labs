typedef int DataType;

class Stack
{
    int top;
    DataType * data;
    int maxlength;
   
  public:
	Stack (int n=100);
	~Stack ();
	int Empty (void);		//�������� �� �������
	DataType Top (void);	//������������� ������
	DataType Pop (void);	//������� �� �����
	int Push (DataType x);  //��������� � ����
};


