# 堆栈：
栈的顺序储存结构通常由一个一维数组和一个记录栈顶元素位置的变量组成

## 顺序储存：
### 结构：
```
const int MaxSize = //储存数据元素的最大个数
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data[MaxSize]; /* 存储元素的数组 */
    int Top; //数组下标     
};
```

### 入栈：
```
void Push( Stack PtrS, ElementType item )
{
    if ( PtrS->Top == MaxSize-1 )
    {
        cout << "堆栈满" << endl;
        return;
    }
    else {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}
```

### 出栈：
```
ElementType Pop( Stack PtrS )
{
    if ( PtrS->Top == -1)
    {
        cout << "堆栈空" << endl;
        return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else 
        return ( PtrS->Data[(PtrS->Top)--] );
}
```
### 合栈：
一个数组把两头分别作为栈底，向中间填充数据,当两个栈的栈顶指针相遇的时候，表示两个栈都满了。

## 链式储存：
栈的链式存储结构实际上就是一个单链表，叫做链栈。插入和删除只能在链栈的栈顶进行。栈顶指针Top在链表的头。

### 结构：
```
typedef struct SNode *Stack;
struct SNode 
{
    ElementType Data;
    struct SNode *Next;
};
```

### 初始化
```
Stack CreateStack( ) 
{ /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S = new SNode;
    S->Next = NULL;
    return S;
}
 ```
 
### 判断栈S是否为空
```
int IsEmpty ( Stack S )
{ /* 判断堆栈S是否为空，若是返回1；否则返回0 */
    return ( S->Next == NULL );
}
```

### 插入：
```
void Push( Stack S, ElementType item )
{ /* 将元素item压入堆栈S */
    Stack TmpCell = new SNode;
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}
```

### 删除：
```
ElementType Pop( Stack S )  
{ /* 删除并返回堆栈S的栈顶元素 */
    struct SNode *FirstCell;
    ElementType TopElem;
    if( IsEmpty(S) ) {
        cout << "堆栈空" << endl; 
        return NULL;
    }
    else {
        FirstCell = S->Next; 
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        delete FirstCell ;
        return TopElem;
    }
}
```