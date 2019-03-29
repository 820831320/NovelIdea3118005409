#include <iostream>
using namespace std;
typedef int ElementType;
const int  MaxSize = 10;//储存数据最大个数
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
	cout << "本程序为循环队列的测试程序，大小为10" << endl;
	cout << "请选择测试项目：1.入队  2.出队" << endl;
	cout << "输入0退出程序" << endl;
	while (1)
	{
		cin >> i;
		if (i == 0)
			break;
		else if (i == 1)
		{
			if ((PtrQ->rear + 1) % MaxSize == PtrQ->front)
				cout << "队列满" << endl;
			else
			{
				cout << "请输入入队元素" << endl;
				cin >> item;
				AddQ(PtrQ, item);
				cout << "完成" << endl;
			}
			cout << "请选择测试项目：1.入队  2.出队" << endl;
		}
		else if (i == 2)
		{
			if (PtrQ->front == PtrQ->rear)
			{
				cout << "队列空" << endl;
			}
			else
				cout << DeleteQ(PtrQ) << endl;
			cout << "请选择测试项目：1.入队  2.出队" << endl;
		}
	}
	return 0;
}


