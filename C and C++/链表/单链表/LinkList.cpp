#include <iostream>

using namespace std;
/**
    单链表的实现，数据结构可以感觉需求修改，
    这里给的是部分基础操作
*/
typedef int ElementTpye;

/**
    结点的存储结构
*/
typedef struct Node
{
    ElementTpye data;   //  存放数据
    struct Node *next;  // 指向下一个结点
}Node, *LinkList;

/**
    创建链表,创建一个头结点
*/
LinkList createList()
{
    // 分配空间
    LinkList L = new Node;
    L->next = NULL;

    return L;
}

/**
    增加结点,头插法
    @return 1 : 添加成功, 0 : 添加失败
*/
int addByHead(LinkList L, ElementTpye x)
{
     Node *newNode = new Node;

     if (newNode == NULL) return 0; // 分配失败

     newNode->data = x; // 保存数据
     newNode->next = L->next; /* 使用头插法添加数据*/
     L->next = newNode;

     return 1;
}

/**
    添加结点，尾插法
    @return 1 : 添加成功, 0 : 添加失败
*/
int addByTail(LinkList L, ElementTpye x)
{
    Node *newNode = new Node;
    Node *pre = L;
    Node *p = L->next;

    if (newNode == NULL) return 0;

    newNode->data = x;
    newNode->next = NULL;

    while(p != NULL)    /* 利用双指针，但p为NULL时，到达链表的末尾，pre所
                            指向的结点就是单链表中的最后一个结点*/
    {
        pre = p;
        p = p->next;
    }
    newNode->next = pre->next;  /* 连接新结点*/
    pre->next = newNode;

    return 1;
}

/**
    返回链表的长度
*/
int getListLen(LinkList L)
{
    Node *p = L->next;
    int count = 0;

    while (p) {
        count++;
        p = p->next;
    }

    return count;
}

/**
    取第i个结点的值,链表从1开始
*/
ElementTpye getElem(LinkList L, int index)
{
    int i = 1;
    Node *p = L->next;

    while (i != index && p != NULL) {
        p = p->next;
        i++;
    }

    if (p) return p->data;     /* 这里没有判断如果没有找到的情况，可以设置一个特别大或者特别小的数用于返回*/

}

/**
    按值查找，并返回该数据的结点指针
*/
Node* locateElem(LinkList L, ElementTpye e)
{
    Node *p = L->next;
    if (p == NULL) return NULL;

    while(p != NULL && p->data != e) p = p->next; /* 当该数据不与要查找的数据相同，
                                                    就一直找下去直到到达链表的末尾*/
    return p;   // 直接返回指针p即可，没找到p就是NULL。
}

/**
    链表的按位置查找,从1开始
*/
Node* getElemByIndex(LinkList L, int index)
{

    int len = getListLen(L);

    if (index > len || index < 1) return NULL;

    Node *p = L->next;
    int i = 1;

    while (i < index) { /* 这里不需要判断p是否为空*/
        p = p->next;
        i++;
    }

    return p;
}

/**
    删除结点,删除第几个结点
*/
int deleteElem(LinkList L, int index)
{

    Node *pre = L;
    Node *p = L->next;
    int i = 1;

    while (p != NULL && i != index) { /* 使用双指针来完成*/
        pre = p;
        p = p->next;
        i++;
    }

    if (p) {    /* 判断是否找到了*/
        pre->next = p->next;
        delete p;

        return 1;
    }

    return 0;
}

/**
    修改结点（值相同的）
*/
int alterNode(LinkList L, ElementTpye x, ElementTpye newData)
{
    Node *p = locateElem(L, x);

    if (p) { /* 判断是否找到数据是x的结点*/
        p->data = newData;

        return 1;
    }

    return 0;
}

/**
    修改节点（按位置）
*/
int alterByNum(LinkList L, int index, ElementTpye newData)
{
    Node *p = getElemByIndex(L, index); //  得到第index个结点的地址

    if (p == NULL) return -1;
    else {
        p->data = newData;
        return 1;
    }
}

/**
    打印结点
*/
void printList(LinkList L)
{
    Node *p = L->next;
    while (p) {
        cout << p->data << ' ';
        p = p->next;
    }
}

int main()
{
    LinkList L = createList(); /* 创建一个链表*/
    //addByHead(L, 1);      /* 头插法建立链表*/
    //addByHead(L, 2);
    //addByHead(L, 3);
    //addByHead(L, 4);

    addByTail(L, 1);    /* 尾插法建立链表*/
    addByTail(L, 2);
    addByTail(L, 3);
    addByTail(L, 4);

    printList(L);   /* 打印链表*/
    cout <<'\n'<<getElem(L,4)<<'\n';    /* 测试得到某个位置的结点*/

    deleteElem(L, 4);   /* 删除链表中指定位置的结点*/
    printList(L);
    cout << '\n';

    alterNode(L, 4, 6); /* 根据结点的值来修改数据*/
    printList(L);

    cout << '\n';
    alterByNum(L, 1, 999); /* 修改某个位置的结点*/
    printList(L);
    return 0;
}
