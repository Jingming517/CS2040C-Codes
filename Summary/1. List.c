//	1. 线性表
//零个或多个数据元素的有限排列

ADT (List)
Data
	{a1, a2, ..., an}
Operation
	InitList (*L);		//初始化
	ListEmpty (L);		// true / false
	ClearList (*L);		//清空
	LocateElem (L, e);	
	ListInsert (*L, i, e);
	ListDelete (*L, i, *e);
	ListLength (L);
endADT


//将所有的在线性表Lb中但不在La中的数据元素插入到La中
void union (List *La, List Lb)
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLength (La);
	Lb_len = ListLength (Lb);
	for (i=1; i<=Lb_len; i++)
	{
		GetElem (Lb, i, e);
		if (!LocateElem(La,e,equal))
			ListInsert (La, ++La_len, e);
	} 
}

//顺序存储结构
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;


//单链表存储结构
typedef  struct Node
{
	ElemType data;
	struct Node *next;
}  Node;
typedef struct Node *LinkList
//p->data 的值是一个数据结构
//p->next 的值是一个指针



//静态链表存储结构
#define MAXSIZE 1000
typedef struct
{
	ElemType data;
	int cur; 				//cursor 游标
} Component, StaticLinkList[MAXSIZE];









