#include <iostream>
/**
    ��ջ����ͷ����
*/
using namespace std;

typedef int ElementType;

/**
    �ṹ����
*/
typedef struct Node
{
    ElementType data;
    struct Node * next;
}Node, *LinkStack;

/**
    ������ջ
*/
LinkStack createStack()
{
    LinkStack top = new Node;
    top->next = NULL;

    return top;
}

/**
    ��ջ
*/
int push(LinkStack top, ElementType e)
{
    Node *newNode = new Node; // Ϊ�½ڵ㿪�ٿռ�

    if (newNode == NULL) return 0; // �ж��Ƿ��ڴ����ʧ��

    newNode->data = e;
    newNode->next = top->next; /* ͷ�巨���������� */
    top->next = newNode;

    return 1;
}

/**
    ��ջ
*/
int pop(LinkStack top)
{
    Node *p = top->next;
    if (p == NULL) {  // �ж��Ƿ�Ϊ��ջ
        return 0;
    }
    else
    {
        top->next = p->next;  // ͷ���ָ��ڶ����ڵ�
        delete p;     // �ͷŵ�һ���ڵ�Ŀռ�

        return 1;
    }
}

/**
    ȡջ��Ԫ��
*/
ElementType top(LinkStack S)
{
    Node *p = S->next;
    if (p != NULL) return p->data; /* ���ǿ�ջ��ȡ��Ԫ�� */
}

int main()
{
    LinkStack S = createStack();
    push(S, 5);
    push(S, 4);
    push(S, 3);
    push(S, 2);
    push(S, 1);

    for (int i = 0; i < 5; i++) {
        cout << top(S) << ' ';
        pop(S);
    }

    return 0;
}
