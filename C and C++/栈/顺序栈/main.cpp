#include <iostream>

/**
    ջ��һ����������ݽṹ����ֻ�����ڱ�β���в����������ͻ�ʹ��ջ��
    ��һ���ص㣬����ȳ�����LIFO��
*/
using namespace std;

typedef int ElementType;
// ջ�Ĵ洢�ṹ
typedef struct
{
    int top;      // ջ��Ԫ�ص��±�
    int capacity; // ��¼�������
    ElementType *array;   // ���Ԫ�ص����飬����ElementType������

}SeqStack;

/**
    ����һ��ջ

    @param capacity �������
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
    �ж�ջ�Ƿ�Ϊ��

    @return 1 : ջΪ��  0 : ջ��Ϊ��
*/
int isEmpty(SeqStack *S)
{
    return S->top == -1 ? 1 : 0;
}

/**
    �ж�ջ�Ƿ�Ϊ��

    @return 1 : ջ��  0 : ջû����
*/
int isFull(SeqStack *S)
{
    return (S->top >= S->capacity - 1) ? 1 : 0;
}

/**
    Ԫ�ؽ�ջ

    @param e ������ջ�е�Ԫ��
*/
int push(SeqStack *S, ElementType e)
{
    if (isFull(S)) return 0; // ջ����֮��Ͳ��ܼ���Ԫ����

    S->top++;        // top�±�+1��ָ��������Ԫ�ص�λ��
    S->array[S->top] = e;  // ����Ԫ��

    return 1;
}

/**
    Ԫ�س�ջ
*/
int pop(SeqStack *S)
{
    if (isEmpty(S)) return 0;

    S->top--;

    return 1;
}

/**
    ȡջ��Ԫ��
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
