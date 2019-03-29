#include <iostream>
using namespace std;
typedef int ElementType;
const int  MaxSize = 10;//��������������
typedef struct QNode * Queue;
struct QNode
{
	ElementType Data[MaxSize];
	int rear;
	int front;
};
void AddQ(Queue PtrQ, ElementType item)
{
	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
	PtrQ->Data[PtrQ->rear] = item;
}
ElementType DeleteQ(Queue PtrQ)
{
	PtrQ->front = (PtrQ->front + 1) % MaxSize;
	return PtrQ->Data[PtrQ->front];
}
int main()
{
	using namespace std;
	int i;
	ElementType item;
	QNode text;
	text.front = 0;
	text.rear = 0;
	Queue PtrQ = &text;
	cout << "������Ϊѭ�����еĲ��Գ��򣬴�СΪ10" << endl;
	cout << "��ѡ�������Ŀ��1.���  2.����" << endl;
	cout << "����0�˳�����" << endl;
	while (1)
	{
		cin >> i;
		if (i == 0)
			break;
		else if (i == 1)
		{
			if ((PtrQ->rear + 1) % MaxSize == PtrQ->front)
				cout << "������" << endl;
			else
			{
				cout << "���������Ԫ��" << endl;
				cin >> item;
				AddQ(PtrQ, item);
				cout << "���" << endl;
			}
			cout << "��ѡ�������Ŀ��1.���  2.����" << endl;
		}
		else if (i == 2)
		{
			if (PtrQ->front == PtrQ->rear)
			{
				cout << "���п�" << endl;
			}
			else
				cout << DeleteQ(PtrQ) << endl;
			cout << "��ѡ�������Ŀ��1.���  2.����" << endl;
		}
	}
	return 0;
}


