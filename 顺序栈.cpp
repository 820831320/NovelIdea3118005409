#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct SNode1
{
	ElementType Data[100]; //存储元素的数组 
	int Top; //数组下标     
}Stack1;
void open(Stack1 *text)
{
	text->Top = -1;
}
void Push(Stack1 *PtrS, ElementType item)//顺序储存的入
{
	if (PtrS->Top == 100 - 1)
	{
		cout << "堆栈满" << endl;
	}
	else 
	{
		PtrS->Data[++(PtrS->Top)] = item;
	}
}
ElementType Pop(Stack1 *PtrS)//顺序储存的出
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
	cout << "堆栈测试程序正在运行"<< endl;
	cout << "选择测试项目："  ;
	cout << "1.压栈   2.出栈 " << endl;
	cout << "完成测试项目后，输入 0，即可退出程序" << endl;
	SNode1 text;
	open(&text);
	while (1)
	{
		cin >> j;
		if (j == 0)
			 break;
	    else if (j == 1)
		{
			cout << "请输入压栈元素:";
			cin >> item;
			Push(&text, item);
			cout << "完成" << endl;
			cout << "选择测试项目：";
			cout << "1.压栈   2.出栈 " << endl;
		}
		else if (j == 2)
		{
			if (text.Top == -1)
				cout << "堆栈空" << endl;
			else
				cout << Pop(&text) << endl;
			cout << "选择测试项目：";
			cout << "1.压栈   2.出栈 " << endl;
		}
	} 
	return 0;
}


