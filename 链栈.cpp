#include <iostream >
using namespace std;
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode {
	ElementType Data;
	struct SNode *Next;
};
Stack CreateStack()// 构建一个堆栈的头结点，返回该结点指针 
{ 
	Stack S = new SNode;
	S->Next = NULL;
	return S;
}
int IsEmpty(Stack S)//判断堆栈S是否为空，若是返回1；否则返回0 
{ 
	return (S->Next == NULL);
}
void Push(Stack S, ElementType item)// 将元素item压入堆栈S 
{ 
	Stack TmpCell = new SNode;
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}
ElementType Pop(Stack S) // 删除并返回堆栈S的栈顶元素 
{
	struct SNode *FirstCell;
	ElementType TopElem;
	FirstCell = S->Next;
	TopElem = FirstCell->Data;
	S->Next = FirstCell->Next;
	delete FirstCell;
	return TopElem;
}
int main()
{
	int i;
	ElementType item;
	Stack S = CreateStack();
	cout << "正在进行链式栈的测试程序，请选择测试项目：" << endl;
	cout << "1.压栈   2.出栈" << endl;
	cout << "完成项目后，输入0退出程序" << endl;
	while (1)
	{
		cin >> i;
		if (i == 0)
			break;
		else if (i == 1)
		{
			cout << "请输入压栈元素:";
			cin >> item;
			Push(S, item);
			cout << "成功" << endl;
		}
		else if (i == 2)
		{
			if (IsEmpty(S)) 
				cout << "堆栈空" << endl;
			else
				cout << "弹出元素为" << Pop(S) << endl;
		}
	}
	return 0;
}
