#include <iostream>

/**
    ���У�ͨ������Ƴ�ѭ���ģ�����β������һ��
    �ڱ����򣬴洢Ԫ�ص�ʱ������һ���洢�ռ�
    �Դ����ֱ��Ƿ�ӿա�����
*/
using namespace std;

typedef int ElementType;

// �洢����
typedef struct
{
    ElementType *array; // �������
    int front;      // ��ͷָ��
    int rear;       // ��βָ��
    int capacity;   // ��������
}SeqQueue;

/**
    ��������
*/
SeqQueue * createQueue(int capacity)
{
    SeqQueue *Q = new SeqQueue;
    Q->front = 0;   // ��ʼ����ͷָ��Ϊ0
    Q->rear = 0;    // ��ʼ����βָ��Ϊ0
    Q->capacity = capacity; // ��ʼ�����е��������
    Q->array = new ElementType[capacity];   // Ϊ�洢����Ԫ�ص������ʼ���ռ�

    return Q;
}

/**
    �ж϶����Ƿ�Ϊ��
*/
int isEmpty(SeqQueue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

/**
    �ж϶����Ƿ�����
*/
int isFull(SeqQueue *Q)
{
    return ((Q->rear + 1) % Q->capacity == Q->front) ? 1 : 0;
}

/**
    ���
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
    ����
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
    ȡ��ͷԪ��
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
    int capacity = 6; // ����һ��λ��
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
