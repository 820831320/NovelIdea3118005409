#include <iostream>
using namespace std;
typedef struct TNode *Position;
typedef Position BitTree;
typedef int ElementType;
struct TNode
{
	ElementType Data;
	BitTree Left;
	BitTree Right;
};
BitTree Insert(BitTree T, ElementType X)
{
	if (!T)
	{ // ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� 
		T = new TNode;
		T->Data = X;
		T->Left = T->Right = NULL;
	}
	else
	{ // ��ʼ��Ҫ����Ԫ�ص�λ�� 
		if (X < T->Data)
		{
			T->Left = Insert(T->Left, X);
		}//�ݹ����������
		else  if (X > T->Data)
		{
			T->Right = Insert(T->Right, X);
		}//�ݹ����������
		 //else X�Ѿ����ڣ�ʲô������ 
	}
	return T;
}
void BuildTree(BitTree &T, ElementType a[], int n)//����
{
	int i = 1;
	while (i < n)//ѭ����������
	{
		Insert(T, a[i]);
		i++;
	}
}
Position IterFind(BitTree T,ElementType X)//��ֵ��
{
	if (!T)
	{
		return NULL;
	}
	 else while (T)
	{
		if (X > T->Data)
		{
			T = T->Right;
		}
		else if (X < T->Data)
		{
			T = T->Left;
		}
		else return T;
	}
}
Position FindMin(BitTree T)
{
	if (!T)
	{
		return nullptr;
	}
	else
		if (!T->Left)
		{
			return T;
		}
		else
		{
			return FindMin(T->Left);
		}
}
Position FindMax(BitTree T)
{
	if (!T)
	{
		return nullptr;
	}
	else
		if (!T->Right)
		{
			return T;
		}
		else
		{
			return FindMin(T->Right);
		}
}
BitTree Delete(BitTree T, ElementType X)
{
	Position Tmp;
	if (!T)
	{
		cout << "Ҫɾ����Ԫ��δ�ҵ�" << endl;
	}
	else 
	{
		if (X < T->Data)
		{
			T->Left = Delete(T->Left, X);
		}// ���������ݹ�ɾ�� 
		else if (X > T->Data)
		{
			T->Right = Delete(T->Right, X);
		}// ���������ݹ�ɾ�� 
		else
		{ //T����Ҫɾ���Ľ�� 
			// �����ɾ����������������ӽ�� 
			if (T->Left && T->Right)
			{
				// ��������������С��Ԫ�����ɾ����� 
				Tmp = FindMin(T->Right);
				T->Data = Tmp->Data;
				// ����������ɾ����СԪ�� 
				T->Right = Delete(T->Right, T->Data);
			}
			else 
			{ // ��ɾ�������һ�������ӽ�� 
				Tmp = T;
				if (!T->Left)
				{//ֻ���Һ��ӻ����ӽ�� 
					T = T->Right;
				}
				else
				{//ֻ������ 
					T = T->Left;
				}
				free(Tmp);
			}
		}
	}
	return T;
}
void DisPlay(BitTree T)
{
	if (T)
	{
		DisPlay(T->Left);
		cout << T->Data << " ";
		DisPlay(T->Right);
	}

}
int main()
{
	using namespace std;
	int a[8] = { 2,3,12,5,22,65,32,25 };
	int i;
	ElementType X;
	TNode BST;
	BitTree T = &BST;
	T->Data = a[0];
	T->Left = NULL;
	T->Right = NULL;
	BuildTree(T, a, 8);
	cout << "�����ɹ�" << endl;
	cout << "������Ϊ�� " ;
	DisPlay(T);
	cout << endl;
	cout << "���ֵΪ��";
	BitTree Max = FindMax(T);
	cout << Max->Data << endl;
	cout << "��СֵΪ��";
	BitTree Min = FindMin(T);
	cout << Min->Data << endl;
	cout << "������Ŀ��1.�������� 2.ɾ������ 3.�������� 4.�鿴��ǰ������ 0.�˳�����" << endl;
	while (1)
	{
		cin >> i;
		if (i == 0)
		{
			break;
		}
		if (i == 1)
		{
			cout << "�����������" << endl;
			cin >> X;
			Insert(T, X);
			cout << "����ɹ�" << endl;
		}
		if (i == 2)
		{
			cout << "����ɾ������" << endl;
			cin >> X;
			Delete(T, X);
			cout << "�����ɹ�" << endl;
		}
		if (i == 3)
		{
			cout << "�������Ԫ��" << endl;
			cin >> X;
			if (!IterFind(T, X))
			{
				cout << "����Ԫ�ز�������" << endl;
			}
			else
			{
				cout << "Ԫ�ش�������" << endl;
			}
			
		}
		if (i == 4)
		{
			cout << "������Ϊ��";
			DisPlay(T);
			cout << endl;
		}
	}
	return 0;
}
