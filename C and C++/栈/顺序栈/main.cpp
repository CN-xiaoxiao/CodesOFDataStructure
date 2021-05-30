#include <iostream>

/**
    栈是一种特殊的数据结构，它只允许在表尾进行操作。这样就会使得栈，
    有一个特点，后进先出即“LIFO”
*/
using namespace std;

typedef int ElementType;
// 栈的存储结构
typedef struct
{
    int top;      // 栈顶元素的下标
    int capacity; // 记录最大容量
    ElementType *array;   // 存放元素的数组，现在ElementType是整型

}SeqStack;

/**
    创建一个栈

    @param capacity 最大容量
*/
SeqStack * createStack(int capacity)
{
    SeqStack *S = new SeqStack;
    S->top = -1;
    S->capacity = capacity;
    S->array = new ElementType[capacity];

    return S;
}

/**
    判断栈是否为空

    @return 1 : 栈为空  0 : 栈不为空
*/
int isEmpty(SeqStack *S)
{
    return S->top == -1 ? 1 : 0;
}

/**
    判断栈是否为满

    @return 1 : 栈满  0 : 栈没有满
*/
int isFull(SeqStack *S)
{
    return (S->top >= S->capacity - 1) ? 1 : 0;
}

/**
    元素进栈

    @param e 待加入栈中的元素
*/
int push(SeqStack *S, ElementType e)
{
    if (isFull(S)) return 0; // 栈满了之后就不能加入元素了

    S->top++;        // top下标+1，指向待加入的元素的位置
    S->array[S->top] = e;  // 加入元素

    return 1;
}

/**
    元素出栈
*/
int pop(SeqStack *S)
{
    if (isEmpty(S)) return 0;

    S->top--;

    return 1;
}

/**
    取栈顶元素
*/
ElementType top(SeqStack *S)
{
    if (!isEmpty(S)) return S->array[S->top];
}

int main()
{
    int size = 5;
    SeqStack * S = createStack(size);
    push(S, 5);
    push(S, 4);
    push(S, 3);
    push(S, 2);
    push(S, 1);

    for (int i = 0; i < size; i++) {
        cout<<top(S)<<' ';
        pop(S);
    }

    return 0;
}
