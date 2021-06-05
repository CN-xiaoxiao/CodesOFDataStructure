#include <iostream>
#define CAPATICY 999
using namespace std;

/**
    二叉树的层序遍历的实现
*/

typedef char ElementType;

/**
    二叉树的存储结构
*/
typedef struct Node
{
    ElementType data;
    struct Node* lChild;
    struct Node* rChild;
}Node, *BinTree;

/**
    队列的存储结构
*/
typedef struct
{
    Node* array[CAPATICY]; // 存放结点.貌似只能用静态方式
    int front;  // 首指针
    int rear;   // 尾指针
}Queue;

/**
    创建二叉树
*/
void createTree(BinTree *T)
{
    ElementType ch;
    cin >> ch;

    if (ch == '#') {
        (*T) = NULL;
        return;
    }
    else {
        (*T) = new Node;
        (*T)->data = ch;
        createTree(&((*T)->lChild));
        createTree(&((*T)->rChild));
    }
}

/**
    先序遍历
*/
void preorderTraverse(BinTree T)
{
    if (T == NULL) return;
    else {
        cout << T->data << ' ';
        preorderTraverse(T->lChild);
        preorderTraverse(T->rChild);
    }
}

/**
    初始化一个队列
*/
Queue* createQueue()
{
    Queue *Q = new Queue;
    Q->front = 0;
    Q->rear = 0;

    return Q;
}

/**
    判断对列是否为空
*/
int isEmpty(Queue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

/**
    入队
*/
int push(Queue *Q, Node *data)
{
    if ((Q->rear + 1) % CAPATICY == Q->front) return 0;
    else {
        Q->array[Q->rear] = data;
        Q->rear = (Q->rear+1) % CAPATICY;

        return 1;
    }
}

/**
    出队
*/
int pop(Queue *Q)
{
    if (Q->rear == Q->front) return 0;
    else {
        Q->front = (Q->front+1) % CAPATICY;

        return 1;
    }
}

/**
    取队头元素
*/
Node* front(Queue *Q)
{
    if (Q->rear == Q->front) return 0;
    else return Q->array[Q->front];
}

/**
    下面将演示二叉树的层序遍历
*/
void levelTtraverse(BinTree T)
{
    if (T == NULL) return;

    Queue *Q = createQueue();
    push(Q, T); /* 先把根节点入队*/

    while (!isEmpty(Q)) {
        Node *p = front(Q);
        pop(Q); // 队列中的首元素出队

        cout << p->data << ' ';
        if (p->lChild != NULL) push(Q, p->lChild); /* 左孩子入队*/
        if (p->rChild != NULL) push(Q, p->rChild); /* 右孩子入队*/
    }
}

/**
    测试数据：ABC##DE#G##F###
              ABC##D##E##

*/
int main()
{
    BinTree T;
    createTree(&T);
    preorderTraverse(T); /* 先序遍历*/
    putchar('\n');
    levelTtraverse(T);   /* 层次遍历*/
    return 0;
}
