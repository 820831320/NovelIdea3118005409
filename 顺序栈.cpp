#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct SNode1
{
	ElementType Data[100]; //�洢Ԫ�ص����� 
	int Top; //�����±�     
}Stack1;
void open(Stack1 *text)
{
	text->Top = -1;
}
void Push(Stack1 *PtrS, ElementType item)//˳�򴢴����
{
	if (PtrS->Top == 100 - 1)
	{
		cout << "��ջ��" << endl;
	}
	else 
	{
		PtrS->Data[++(PtrS->Top)] = item;
	}
}
ElementType Pop(Stack1 *PtrS)//˳�򴢴�ĳ�
{
	ElementType i;
	i = PtrS->Data[(PtrS->Top)--];
	return i;
}
int main()
{
	using namespace std;
	ElementType item;
	int j;
	cout << "��ջ���Գ�����������"<< endl;
	cout << "ѡ�������Ŀ��"  ;
	cout << "1.ѹջ   2.��ջ " << endl;
	cout << "��ɲ�����Ŀ������ 0�������˳�����" << endl;
	SNode1 text;
	open(&text);
	while (1)
	{
		cin >> j;
		if (j == 0)
			 break;
	    else if (j == 1)
		{
			cout << "������ѹջԪ��:";
			cin >> item;
			Push(&text, item);
			cout << "���" << endl;
			cout << "ѡ�������Ŀ��";
			cout << "1.ѹջ   2.��ջ " << endl;
		}
		else if (j == 2)
		{
			if (text.Top == -1)
				cout << "��ջ��" << endl;
			else
				cout << Pop(&text) << endl;
			cout << "ѡ�������Ŀ��";
			cout << "1.ѹջ   2.��ջ " << endl;
		}
	} 
	return 0;
}


