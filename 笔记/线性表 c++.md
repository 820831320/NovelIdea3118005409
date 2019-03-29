# 线性表：
由同类型数据元素构成的有序序列的线性结构。（利用数组实现）

## 顺序存储：

### 结构：
```
 typedef struct LNode*List;
 struct LNode
 {
    ElementType Data[MAXSIZE];
    int Last;
  };
  LNode L;
  List PtrL;
```
### 初始化:
```
List MakeEmpty()
{
    List PtrL = new LNode;
    PtrL->Last = -1;
    return PtrL;
}
```

### 查找：
```
int Find (ElementType X,List PtrL)
{   
   int i =0;
   while(i <=PtrL->Last&& PtrL->Data[i]!=X)
   i++;
   if (i>PtrL->Last) return -1;
   else return i;/*找到后返回的是存储位置*/
}
```

### 插入：
```
void Inset(ElementType X,int i,List PtrL)
{
int j;
if (PtrL->Last ==MAXSIZE-1)
    {
    cout << "表满" << endl；
    return;
    }
if(i<1|| i >PtrL->Last+2)
    {
        cout << "位置不合法" << endl;
        return;
    }
for(j=PtrL->Last; j>=i-1;j--)
        PtrL->Data[j+1] = PtrL->Data[j];//往后挪元素
        PtrL->Data[i-1] = X;
        PtrL->Last++;
        return;
 }
 ```
 
 ### 删除：
 ```
 void Delete(int i,List PtrL)
 {
     int j;
     if(i<1|| i >PtrL->Last+1)
    {
        cout << "不存在第" << i << "个元素" << endl;
        return;
    }
    for (j=i;j<=PtrL->Last;j++)
    PtrL->Data[j-1] = PtrL->Data[j];//往前移动元素
    PtrL->last--;
    return;
 }
```

## 链式存储：
头部方便插入和删除，但是尾部不能进行删除
### 结构：
```
typedef struct LNode*List;
struct LNode
 {
    ElementType Data;
    LIst Next;
 };
    Lnode L;
    List PtrL;
 ```
 
 ### 求表长度：
 ```
 int Length(List PtrL)
 {
     List p = PtrL;
     int j = 0;
     while(p)
     {
         p = p->Next;
         j++;
     }
         return j;
 }
 ```
 
 ### 查找：
 #### 按序号查找
 ```
 List FindKth(int k,List PtrL)
 {
     List p = PtrL;
     int i = 1;
     while(p !=NULL && i<k)
     {
     p = p->Next;
     i++;
     }
     if (i == K)return p;
     else return NULL;
 }
 ```
 #### 按值查找
 ```
 List Find(ElementTypr X,List PtrL)
 {
     List p = PtrL;
     while(p !=NULL && p->Data !=X)
     p = p->Next;
     return p;
 }
 ```
 
 ### 插入
 ```
 List Insert(ElementType X,int i,List PtrL)
 {
     List p,s;
     if (1=i)//插在表头
     {
         List s = new LNode;
         s->Data = X;
         s->Next = PtrL;
         return s;
     }
     p = FindKth(i-1,PtrL);
     if (p == NULL)
     {
         cout << "参数i错" << endl;
         return NULL;
     }
     else
     {
         List s = new LNode;
         s->Data = X;
         s->Next = p->Next;
         p->Next = s;
         return PtrL;
     }
 }
 ```
 
 ### 删除：
 ```
 List Delete(int i,List PtrL)
 {
     List p,s;
     if (i ==1)//第一个节点直接删
     {
         s =PtrL;
         if (PtrL!=NULL) PtrL = PtrL->Next;
         else return NULL;
         delete s ;
         return PtrL;
     }
     p = FindKrh(i-1,PtrL);
     if (p == NULL)
     {
         cout << "第" << i-1 << "个结点不存在" << endl;
         return NULL;
     }
     else if (p->Next == NULL)
     {
        cout << "第" << i << "个结点不存在" << endl;
         return NULL;
     }
     esle 
     {
         s = p->Next;
         p->Next = s->Next;
         delete s ;
         return PtrL;
 }
     
     
 

