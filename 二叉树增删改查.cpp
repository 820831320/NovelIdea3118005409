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
	{ // 若原树为空，生成并返回一个结点的二叉搜索树 
		T = new TNode;
		T->Data = X;
		T->Left = T->Right = NULL;
	}
	else
	{ // 开始找要插入元素的位置 
		if (X < T->Data)
		{
			T->Left = Insert(T->Left, X);
		}//递归插入左子树
		else  if (X > T->Data)
		{
			T->Right = Insert(T->Right, X);
		}//递归插入右子树
		 //else X已经存在，什么都不做 
	}
	return T;
}
void BuildTree(BitTree &T, ElementType a[], int n)//建树
{
	int i = 1;
	while (i < n)//循环插入数据
	{
		Insert(T, a[i]);
		i++;
	}
}
Position IterFind(BitTree T,ElementType X)//按值查
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
		cout << "要删除的元素未找到" << endl;
	}
	else 
	{
		if (X < T->Data)
		{
			T->Left = Delete(T->Left, X);
		}// 从左子树递归删除 
		else if (X > T->Data)
		{
			T->Right = Delete(T->Right, X);
		}// 从右子树递归删除 
		else
		{ //T就是要删除的结点 
			// 如果被删除结点有左右两个子结点 
			if (T->Left && T->Right)
			{
				// 从右子树中找最小的元素填充删除结点 
				Tmp = FindMin(T->Right);
				T->Data = Tmp->Data;
				// 从右子树中删除最小元素 
				T->Right = Delete(T->Right, T->Data);
			}
			else 
			{ // 被删除结点有一个或无子结点 
				Tmp = T;
				if (!T->Left)
				{//只有右孩子或无子结点 
					T = T->Right;
				}
				else
				{//只有左孩子 
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
	cout << "创建成功" << endl;
	cout << "二叉树为： " ;
	DisPlay(T);
	cout << endl;
	cout << "最大值为：";
	BitTree Max = FindMax(T);
	cout << Max->Data << endl;
	cout << "最小值为：";
	BitTree Min = FindMin(T);
	cout << Min->Data << endl;
	cout << "操作项目：1.插入数据 2.删除数据 3.查找数据 4.查看当前二叉树 0.退出程序" << endl;
	while (1)
	{
		cin >> i;
		if (i == 0)
		{
			break;
		}
		if (i == 1)
		{
			cout << "输入插入数据" << endl;
			cin >> X;
			Insert(T, X);
			cout << "插入成功" << endl;
		}
		if (i == 2)
		{
			cout << "输入删除数据" << endl;
			cin >> X;
			Delete(T, X);
			cout << "操作成功" << endl;
		}
		if (i == 3)
		{
			cout << "输入查找元素" << endl;
			cin >> X;
			if (!IterFind(T, X))
			{
				cout << "查找元素不在树中" << endl;
			}
			else
			{
				cout << "元素处于树中" << endl;
			}
			
		}
		if (i == 4)
		{
			cout << "二叉树为：";
			DisPlay(T);
			cout << endl;
		}
	}
	return 0;
}
