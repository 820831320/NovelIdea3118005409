# 队列：
具有一定操作约束的线性表，插入和删除只能在一段插入另一端删除。

## 顺序存储
队列的顺序存储通常有一个一维数组和一个记录队列头元素位置的变量front以及一个记录队列尾元素位置的变量rear组成

### 结构
```
const int MaxSize =//储存数据最大个数
typedef struct QNode *Queue;
struct QNode
{
    ElementType Data[MaxSize];
    int rear;
    int front;
};
```

### 顺环队列
头尾相连，大小为n的队列判断是否满时
1. 只用n-1个位置，判断front与rear是否相同
2. 使用额外标记：size，插入就加一，删除就减一，判断size与MaxSize是否相同
3. 使用n个位置，判断（rear+1）% MaxSize与front是否相等

### 入队列:
```
void AddQ(Queue PtrQ,ElementType item)
{
    if ((PtrQ->rear + 1)% MaxSize == PtrQ->front)
    {
        cout << "队列满" << endl;
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)% MaxSize;
    PtrQ->Data[PtrQ->rear] = item;
}
```

### 出队列：
```
ElementType DeleteQ(Queue PtrQ)
{
    if (PtrQ->front == PtrQ->rear)
    {
        cout << "队列空" << endl;
        return ERROR;
    }
    else
    {
        PtrQ->front = (PtrQ->front+1)% MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
}
```

## 链式存储
用一个单链表实现，插入和删除分别在链表的两头进行，front只能指向链表的头，rear只能指向链表的尾

### 结构
```
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
```

### 出队列
```
ElementType DeleteQ(Queue PtrQ)
{
    Node *FrontCell;
    ElementType FrontElem;
    FrontCell = PtrQ->front->Next;
    if (PtrQ->front == NULL)
    {
        cout << "队列空" << endl;
        return ERROR;
    }
    if (PtrQ->front->Next == PtrQ->rear)//若只有一个元素
    PtrQ->rear = PtrQ->front;
    else PtrQ->front->Next = PtrQ->front->Next->Next;
    FrontElem = FrontCell->Data;
    delete FrontCell;
    return FrontElem;
}
```

### 入队列
```
void AddQ(Queue PtrQ, ElementType item)
{
	struct Node *RearCell = new struct Node;
	RearCell->Data = item;
	PtrQ->rear->Next = RearCell;
	PtrQ->rear = RearCell;
	PtrQ->rear->Next = NULL;
}
```

