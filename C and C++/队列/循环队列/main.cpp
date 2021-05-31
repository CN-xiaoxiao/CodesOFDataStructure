#include <iostream>

/**
    队列，通常被设计成循环的，即首尾连接在一起
    在本程序，存储元素的时候，少用一个存储空间
    以此来分辨是否队空、队满
*/
using namespace std;

typedef int ElementType;

// 存储类型
typedef struct
{
    ElementType *array; // 存放数据
    int front;      // 队头指针
    int rear;       // 队尾指针
    int capacity;   // 队列容量
}SeqQueue;

/**
    创建队列
*/
SeqQueue * createQueue(int capacity)
{
    SeqQueue *Q = new SeqQueue;
    Q->front = 0;   // 初始化队头指针为0
    Q->rear = 0;    // 初始化队尾指针为0
    Q->capacity = capacity; // 初始化队列的最大容量
    Q->array = new ElementType[capacity];   // 为存储队列元素的数组初始化空间

    return Q;
}

/**
    判断队列是否为空
*/
int isEmpty(SeqQueue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

/**
    判断队列是否满了
*/
int isFull(SeqQueue *Q)
{
    return ((Q->rear + 1) % Q->capacity == Q->front) ? 1 : 0;
}

/**
    入队
*/
int push(SeqQueue *Q, ElementType x)
{
    if (isFull(Q)) return 0;
    else {
        Q->array[Q->rear] = x;
        Q->rear = (Q->rear + 1) % Q->capacity;

        return 1;
    }
}

/**
    出队
*/
int pop(SeqQueue *Q)
{
    if (isEmpty(Q)) return 0;
    else {
        Q->front = (Q->front + 1) % Q->capacity;

        return 1;
    }
}

/**
    取队头元素
*/
ElementType front(SeqQueue *Q)
{
    if (!isEmpty(Q)) {
        return Q->array[Q->front];
    }
}

int main()
{
    SeqQueue *Q;
    int capacity = 6; // 少用一个位置
    Q = createQueue(capacity);
    push(Q, 5);
    push(Q, 4);
    push(Q, 3);
    push(Q, 2);
    push(Q, 1);

    while(!isEmpty(Q)) {
        cout << front(Q) << ' ';
        pop(Q);
    }
    return 0;
}
