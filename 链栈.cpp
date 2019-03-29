#include <iostream >
using namespace std;
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode {
	ElementType Data;
	struct SNode *Next;
};
Stack CreateStack()// ����һ����ջ��ͷ��㣬���ظý��ָ�� 
{ 
	Stack S = new SNode;
	S->Next = NULL;
	return S;
}
int IsEmpty(Stack S)//�ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���1�����򷵻�0 
{ 
	return (S->Next == NULL);
}
void Push(Stack S, ElementType item)// ��Ԫ��itemѹ���ջS 
{ 
	Stack TmpCell = new SNode;
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}
ElementType Pop(Stack S) // ɾ�������ض�ջS��ջ��Ԫ�� 
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
	cout << "���ڽ�����ʽջ�Ĳ��Գ�����ѡ�������Ŀ��" << endl;
	cout << "1.ѹջ   2.��ջ" << endl;
	cout << "�����Ŀ������0�˳�����" << endl;
	while (1)
	{
		cin >> i;
		if (i == 0)
			break;
		else if (i == 1)
		{
			cout << "������ѹջԪ��:";
			cin >> item;
			Push(S, item);
			cout << "�ɹ�" << endl;
		}
		else if (i == 2)
		{
			if (IsEmpty(S)) 
				cout << "��ջ��" << endl;
			else
				cout << "����Ԫ��Ϊ" << Pop(S) << endl;
		}
	}
	return 0;
}
