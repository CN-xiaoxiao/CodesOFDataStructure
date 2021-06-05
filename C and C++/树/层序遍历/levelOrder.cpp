#include <iostream>
#define CAPATICY 999
using namespace std;

/**
    �������Ĳ��������ʵ��
*/

typedef char ElementType;

/**
    �������Ĵ洢�ṹ
*/
typedef struct Node
{
    ElementType data;
    struct Node* lChild;
    struct Node* rChild;
}Node, *BinTree;

/**
    ���еĴ洢�ṹ
*/
typedef struct
{
    Node* array[CAPATICY]; // ��Ž��.ò��ֻ���þ�̬��ʽ
    int front;  // ��ָ��
    int rear;   // βָ��
}Queue;

/**
    ����������
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
    �������
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
    ��ʼ��һ������
*/
Queue* createQueue()
{
    Queue *Q = new Queue;
    Q->front = 0;
    Q->rear = 0;

    return Q;
}

/**
    �ж϶����Ƿ�Ϊ��
*/
int isEmpty(Queue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

/**
    ���
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
    ����
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
    ȡ��ͷԪ��
*/
Node* front(Queue *Q)
{
    if (Q->rear == Q->front) return 0;
    else return Q->array[Q->front];
}

/**
    ���潫��ʾ�������Ĳ������
*/
void levelTtraverse(BinTree T)
{
    if (T == NULL) return;

    Queue *Q = createQueue();
    push(Q, T); /* �ȰѸ��ڵ����*/

    while (!isEmpty(Q)) {
        Node *p = front(Q);
        pop(Q); // �����е���Ԫ�س���

        cout << p->data << ' ';
        if (p->lChild != NULL) push(Q, p->lChild); /* �������*/
        if (p->rChild != NULL) push(Q, p->rChild); /* �Һ������*/
    }
}

/**
    �������ݣ�ABC##DE#G##F###
              ABC##D##E##

*/
int main()
{
    BinTree T;
    createTree(&T);
    preorderTraverse(T); /* �������*/
    putchar('\n');
    levelTtraverse(T);   /* ��α���*/
    return 0;
}
