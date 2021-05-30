#include <iostream>
/**
    链栈，带头结点的
*/
using namespace std;

typedef int ElementType;

/**
    结构类型
*/
typedef struct Node
{
    ElementType data;
    struct Node * next;
}Node, *LinkStack;

/**
    创建链栈
*/
LinkStack createStack()
{
    LinkStack top = new Node;
    top->next = NULL;

    return top;
}

/**
    进栈
*/
int push(LinkStack top, ElementType e)
{
    Node *newNode = new Node; // 为新节点开辟空间

    if (newNode == NULL) return 0; // 判断是否内存分配失败

    newNode->data = e;
    newNode->next = top->next; /* 头插法加入链表中 */
    top->next = newNode;

    return 1;
}

/**
    出栈
*/
int pop(LinkStack top)
{
    Node *p = top->next;
    if (p == NULL) {  // 判断是否为空栈
        return 0;
    }
    else
    {
        top->next = p->next;  // 头结点指向第二个节点
        delete p;     // 释放第一个节点的空间

        return 1;
    }
}

/**
    取栈顶元素
*/
ElementType top(LinkStack S)
{
    Node *p = S->next;
    if (p != NULL) return p->data; /* 不是空栈就取出元素 */
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
