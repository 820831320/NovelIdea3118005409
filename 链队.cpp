#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct QNode *Queue;
struct Node//����ṹ
{
	ElementType Data;
	struct Node *Next;
};
struct QNode//�����нṹ
{
	struct Node *rear;//ָ���β���
	struct Node *front;//ָ���ͷ���
};
Queue PtrQ;
ElementType DeleteQ(Queue PtrQ)
{
	struct Node *FrontCell;
	ElementType FrontElem;
	FrontCell = PtrQ->front->Next;
	if (PtrQ->front->Next == PtrQ->rear)//��ֻ��һ��Ԫ��
	{
		PtrQ->rear = PtrQ->front;
		PtrQ->front = NULL;
	}
	else PtrQ->front->Next = PtrQ->front->Next->Next;
	FrontElem = FrontCell->Data;
	delete FrontCell;
	return FrontElem;
}
void AddQ(Queue PtrQ, ElementType item)
{
	struct Node *RearCell = new struct Node;
	RearCell->Data = item;
	PtrQ->rear->Next = RearCell;
	PtrQ->rear = RearCell;
	PtrQ->rear->Next = NULL;
}
int main()
{
	using namespace std;
	int i;
	Node *list = new Node;
	list->Next = NULL;
	QNode team;
	team.front = list;
	team.rear = list;
	Queue Ptrteam = &team;
	ElementType item;
	cout << "������Ϊѭ�����еĲ��Գ���" << endl;
	cout << "��ѡ�������Ŀ��1.���  2.����" << endl;
	cout << "����0�˳�����" << endl;
	while (1)
	{
		cin >> i;
		if (i == 0)
		{
			delete list;
			break;
		}
		else if (i == 1)
		{
			cout << "���������Ԫ�أ�";
			cin >> item;
			AddQ(Ptrteam, item);
			cout << "���" << endl;
			cout << "��ѡ�������Ŀ��1.���  2.����" << endl;
		}
		else if (i == 2)
		{
			if (Ptrteam->front == NULL)
				cout << "���п�" << endl;
			else
				cout <<"   " << DeleteQ(Ptrteam) << endl;
			cout << "��ѡ�������Ŀ��1.���  2.����" << endl;
		}
	}
	return 0;
}

				
	


