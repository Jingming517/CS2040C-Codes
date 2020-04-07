//	2. 栈 (Stack)

ADT (Stack)
Data
	//同线性表
Operation
	InitStack (*S);
	DestroyStack (*S);
	ClearStack (*S);
	StackEmpty (S);
	GetTop (S, *e);
	Push (*S, e);
	Pop (*S, *e);
	StackLength (S);
endADT

//栈的结构定义
typedef int SElementType;
typedef struct
{
	SElemType data [MAXSIZE];
	int top;			//栈顶指针
}SqStack


//两栈共享空间结构
typedef struct
{
	SElemType data [MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;




//栈的创建、出队、入队、栈长度、清空栈、判断栈满、判断栈空、取栈元素
/*  完整代码  */
#include <iostream>
 
using namespace std;
#define MAX_SIZE 5 //数组大小
 
 struct stack {
    int top;
    int ans[MAX_SIZE];
};
typedef struct stack Stack;
 
void InitStack(Stack *ptr) {    //初始化栈
    ptr->top = 0;
}
 
bool StackFull (Stack *ptr) {   //判断栈是否满
    if (ptr->top < MAX_SIZE)
        return false;
    else 
        return true;
}
 
bool StackEmpty (Stack *ptr) {  //判断栈是否空
    if (ptr->top == 0)     
        return true;
    else  
        return false;   
}
 
void Push(Stack *ptr, int item) {   //入栈
    if (StackFull(ptr))
        cerr << "栈满，不能入栈!" << endl;
    else {
        ptr->ans[ptr->top] = item;
        ptr->top ++;
    }
}
 
int GetTop(Stack *ptr) {    //返回栈顶值
    return ptr->ans[ptr->top - 1];
}
 
int Pop(Stack *ptr) {  //出栈,返回栈顶值
    if (StackEmpty(ptr)) {
        cerr << "栈空，不能出栈!" << endl;
        return -1;
    }
    else 
        return ptr->ans[--ptr->top];
}
 
int StackSize (Stack *ptr) {    //返回栈长度
    if (ptr->top == 0)
        return 0;
    else  
        return ptr->top;
}
 
void ClearStack(Stack *ptr) {   //清空栈
    ptr->top = 0;
}
 
 
 
int main(){
    Stack *ptr = (Stack *)malloc(sizeof(Stack));
    InitStack(ptr); //初始化栈
    //入栈
    Push(ptr, 4);
    Push(ptr, 10);
    Push(ptr, 21);
    Push(ptr, 19);
    Push(ptr, 12);
    Push(ptr, 13);
    
    cout << "当前栈顶值为: " << GetTop(ptr) << endl;
    cout << "当前栈顶指针为: " << ptr->top << endl;   //输出栈顶值
 
    cout << "当前栈长度为: " << StackSize(ptr) << endl;
    cout << "栈顶出队: " << Pop(ptr) << endl;   //出栈
 
    cout <<  "当前栈长度为: " << StackSize(ptr) << endl;
 
    ClearStack(ptr);    //清空栈
    cout << "清空栈后栈的长度为: " << StackSize(ptr) << endl;
 
    return 0;    
}













