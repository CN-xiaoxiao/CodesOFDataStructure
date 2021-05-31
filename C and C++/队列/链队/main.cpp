#include <iostream>

/**
    ����
*/
using namespace std;

typedef int ElementType;

// ���е���ʽ�洢�ṹ
typedef struct Node
{
    ElementType data;   // ��������
    struct Node *next; // ָ����һ�����
}Node;

// ���ָ��
typedef struct
{
    Node *front;    // ��ͷָ��
    Node *rear;     // ��βָ��
}LinkQueue;

/**
    ����һ������
*/
LinkQueue * createQueue()
{
    LinkQueue *Q = new LinkQueue;

    Q->front = new Node; /* ����ռ�*/
    Q->rear = new Node;  /* ����ռ�*/
    Q->rear = Q->front;     // ��ʼ����Ϊ�գ�Ӧ����βָ���ͷָ��ָ��ͬһ��λ��
    Q->front->next = NULL;  // ͷ����ָ����Ϊ��

    return Q;
}

/**
    �ж������Ƿ�Ϊ��
*/
int isEmpty(LinkQueue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

/**
    ���
*/
int push(LinkQueue *Q, ElementType x)
{
    Node *newNode = new Node;

    if (newNode == NULL) return 0;

    newNode->data = x;
    newNode->next = NULL;

    Q->rear->next = newNode; // Q->rear ��ʱָ���β
    Q->rear = newNode;      // βָ��ָ������ӵĽ��

    return 1;
}

/**
    ���ӣ���ͷԪ�س���
*/
int pop(LinkQueue *Q)
{
    if (Q->front == Q->rear) {
        return 0;
    }
    else
    {
        Node *p = Q->front->next;
        Q->front->next = p->next;

        if (Q->front->next == NULL) { /* �������Ϊ�յ�ʱ��Ҫ��ͷָ���βָ��ָ��ͬһ��λ�� */
            Q->rear = Q->front;
        }

        delete p;

        return 1;
    }
}

/**
    ȡ��ͷԪ��
*/
ElementType front(LinkQueue *Q)
{
    return Q->front->next->data;
}

/**
    ���ٶ���
*/
int destroyQueue(LinkQueue *Q)
{
    while (Q->front) {
        Node *p = Q->front->next;
        delete Q->front;
        Q->front = p;
    }

    return 1;
}

int main()
{
    LinkQueue *Q = createQueue();
    push(Q, 5);
    push(Q, 4);
    push(Q, 3);
    push(Q, 2);
    push(Q, 1);

    for (int i = 0; i < 5; i++) {
        cout<<front(Q)<<' ';
        pop(Q);
    }

    destroyQueue(Q);
    cout<<"destroy the Queue";

    for (int i = 0; i < 5; i++) {
        cout<<front(Q)<<' ';
        pop(Q);
    }

    return 0;
}
