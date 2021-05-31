#include <iostream>

/**
    链队
*/
using namespace std;

typedef int ElementType;

// 队列的链式存储结构
typedef struct Node
{
    ElementType data;   // 保存数据
    struct Node *next; // 指向下一个结点
}Node;

// 存放指针
typedef struct
{
    Node *front;    // 队头指针
    Node *rear;     // 队尾指针
}LinkQueue;

/**
    创建一个链队
*/
LinkQueue * createQueue()
{
    LinkQueue *Q = new LinkQueue;

    Q->front = new Node; /* 分配空间*/
    Q->rear = new Node;  /* 分配空间*/
    Q->rear = Q->front;     // 开始队列为空，应当把尾指针和头指针指向同一个位置
    Q->front->next = NULL;  // 头结点的指针域为空

    return Q;
}

/**
    判断链队是否为空
*/
int isEmpty(LinkQueue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

/**
    入队
*/
int push(LinkQueue *Q, ElementType x)
{
    Node *newNode = new Node;

    if (newNode == NULL) return 0;

    newNode->data = x;
    newNode->next = NULL;

    Q->rear->next = newNode; // Q->rear 此时指向队尾
    Q->rear = newNode;      // 尾指针指向新添加的结点

    return 1;
}

/**
    出队：队头元素出队
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

        if (Q->front->next == NULL) { /* 如果队列为空的时候，要将头指针和尾指针指向同一个位置 */
            Q->rear = Q->front;
        }

        delete p;

        return 1;
    }
}

/**
    取队头元素
*/
ElementType front(LinkQueue *Q)
{
    return Q->front->next->data;
}

/**
    销毁队列
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
