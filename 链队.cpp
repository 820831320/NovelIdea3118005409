#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct QNode *Queue;
struct Node//链表结构
{
	ElementType Data;
	struct Node *Next;
};
struct QNode//链队列结构
{
	struct Node *rear;//指向队尾结点
	struct Node *front;//指向队头结点
};
Queue PtrQ;
ElementType DeleteQ(Queue PtrQ)
{
	struct Node *FrontCell;
	ElementType FrontElem;
	FrontCell = PtrQ->front->Next;
	if (PtrQ->front->Next == PtrQ->rear)//若只有一个元素
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
	cout << "本程序为循环队列的测试程序" << endl;
	cout << "请选择测试项目：1.入队  2.出队" << endl;
	cout << "输入0退出程序" << endl;
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
			cout << "请输入入队元素：";
			cin >> item;
			AddQ(Ptrteam, item);
			cout << "完成" << endl;
			cout << "请选择测试项目：1.入队  2.出队" << endl;
		}
		else if (i == 2)
		{
			if (Ptrteam->front == NULL)
				cout << "队列空" << endl;
			else
				cout <<"   " << DeleteQ(Ptrteam) << endl;
			cout << "请选择测试项目：1.入队  2.出队" << endl;
		}
	}
	return 0;
}

				
	


