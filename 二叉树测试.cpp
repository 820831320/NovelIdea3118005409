#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BitTree;
struct TNode//树节点
{
	ElementType Data;
	BitTree Left;
	BitTree Right;
}TextTree;
void CreateTree(BitTree &T)//建树
{
	int item;
	cin >> item;
	if (item == -9)
	{
		T = nullptr;
	}
	else
	{
		T = new TNode;//new新用法
		T->Data = item;
		CreateTree(T->Left);
		CreateTree(T->Right);
	}
}
typedef struct SNode *Stack;
struct SNode//栈结构
{
	BitTree Data;
	struct SNode *Next;
};
Stack CreateStack()
{
	Stack S = new SNode;
	S->Next = NULL;
	return S;
}
int IsEmptyS(Stack S)
{
	return (S->Next == NULL);
}
void Push(Stack S, BitTree T)
{
	Stack TmpCell = new SNode;
	TmpCell->Data = T;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}
BitTree Pop(Stack S)
{
	Stack TopCell = new SNode;
	BitTree TopItem;
	TopCell = S->Next;
	TopItem = TopCell->Data;
	S->Next = TopCell->Next;
	delete TopCell;
	return TopItem;
}
//void PreOrderTraversal(BitTree BT)
//{
	//if (BT)
	//{
	//	cout << BT->Data;
	//	PreOrderTraversal(BT->Left);
	//	PreOrderTraversal(BT->Right);
	//}
//}
void PreOrderTraversal(BitTree T)//先序
{
	Stack S = CreateStack();
	while (T || !IsEmptyS(S))
	{
		while (T)
		{
			Push(S, T);
			cout << T->Data;
			T = T->Left;
		}
		if (!IsEmptyS(S))
		{
			T = Pop(S);
			T = T->Right;
		}
	}
}
void InOrderTraversal(BitTree T)//中序
{
	Stack S = CreateStack();
	while (T || !IsEmptyS(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmptyS(S))
		{
			T = Pop(S);
			cout << T->Data;
			T = T->Right;
		}
	}
}
void PostOrderTraversal(BitTree T)//后序
{
	if (T)
	{
		PostOrderTraversal(T->Left);
		PostOrderTraversal(T->Right);
		cout << T->Data;
	}
}
typedef struct QNode *Queue;
struct Node//链表结构
{
	BitTree Data;
	struct Node *Next;
};
struct QNode//链队列结构
{
	struct Node *rear;//指向队尾结点
	struct Node *front;//指向队头结点
};
int IsEmptyQ(Queue PtrQ)
{
	return (PtrQ->front == PtrQ->rear);
}
void AddQ(Queue PtrQ, BitTree item)
{
	struct Node *RearCell = new struct Node;
	RearCell->Data = item;
	PtrQ->rear->Next = RearCell;
	PtrQ->rear = RearCell;
	PtrQ->rear->Next = NULL;
}
BitTree DeleteQ(Queue PtrQ)
{
	Node *FrontCell;
	BitTree FrontElem;
	FrontCell = PtrQ->front->Next;
	if (PtrQ->front->Next == PtrQ->rear)//若只有一个元素
		PtrQ->rear = PtrQ->front;
	else
	{
		PtrQ->front->Next = PtrQ->front->Next->Next;
	}
	FrontElem = FrontCell->Data;
	delete FrontCell;
	return FrontElem;
}
void LevelOrderTraversal(BitTree T, Queue Q)//层序
{
	if (!T)
	{
		return;
	}
	AddQ(Q, T);
	while (!IsEmptyQ(Q))
	{
		T = DeleteQ(Q);
		cout << T->Data;
		if (T->Left)
		{
			AddQ(Q, T->Left);
		}
		if (T->Right)
		{
			AddQ(Q, T->Right);
		}
	}
}
int main()
{
	using namespace std;
	Position T = nullptr;
	QNode FNode;
	Node *First = new Node;
	First->Next = NULL;
	FNode.rear = First;
	FNode.front = First;
	Queue Q = &FNode;
	cout << "输入数据构建二叉树，-1表示无儿子" << endl;
	CreateTree(T);
	cout << "二叉树构建成功" << endl;
	cout << "先序遍历结果为：";
	PreOrderTraversal(T);
	cout << endl;
	cout << "中序遍历结果为：";
	InOrderTraversal(T);
	cout << endl;
	cout << "后序遍历结果为：";
	PostOrderTraversal(T);
	cout << endl;
	cout << "层序遍历结果为：";
	LevelOrderTraversal(T,Q); 
	cout << endl;
	return 0;
}






	
