#include <iostream>

using namespace std;
/**
    �������ʵ�֣����ݽṹ���Ըо������޸ģ�
    ��������ǲ��ֻ�������
*/
typedef int ElementTpye;

/**
    ���Ĵ洢�ṹ
*/
typedef struct Node
{
    ElementTpye data;   //  �������
    struct Node *next;  // ָ����һ�����
}Node, *LinkList;

/**
    ��������,����һ��ͷ���
*/
LinkList createList()
{
    // ����ռ�
    LinkList L = new Node;
    L->next = NULL;

    return L;
}

/**
    ���ӽ��,ͷ�巨
    @return 1 : ��ӳɹ�, 0 : ���ʧ��
*/
int addByHead(LinkList L, ElementTpye x)
{
     Node *newNode = new Node;

     if (newNode == NULL) return 0; // ����ʧ��

     newNode->data = x; // ��������
     newNode->next = L->next; /* ʹ��ͷ�巨�������*/
     L->next = newNode;

     return 1;
}

/**
    ��ӽ�㣬β�巨
    @return 1 : ��ӳɹ�, 0 : ���ʧ��
*/
int addByTail(LinkList L, ElementTpye x)
{
    Node *newNode = new Node;
    Node *pre = L;
    Node *p = L->next;

    if (newNode == NULL) return 0;

    newNode->data = x;
    newNode->next = NULL;

    while(p != NULL)    /* ����˫ָ�룬��pΪNULLʱ�����������ĩβ��pre��
                            ָ��Ľ����ǵ������е����һ�����*/
    {
        pre = p;
        p = p->next;
    }
    newNode->next = pre->next;  /* �����½��*/
    pre->next = newNode;

    return 1;
}

/**
    ��������ĳ���
*/
int getListLen(LinkList L)
{
    Node *p = L->next;
    int count = 0;

    while (p) count++;

    return count;
}

/**
    ȡ��i������ֵ,�����1��ʼ
*/
ElementTpye getElem(LinkList L, int index)
{
    int i = 1;
    Node *p = L->next;

    while (i != index && p != NULL) {
        p = p->next;
        i++;
    }

    if (p) return p->data;     /* ����û���ж����û���ҵ����������������һ���ر������ر�С�������ڷ���*/

}

/**
    ��ֵ���ң������ظ����ݵĽ��ָ��
*/
Node* locateElem(LinkList L, ElementTpye e)
{
    Node *p = L->next;
    if (p == NULL) return NULL;

    while(p != NULL && p->data != e) p = p->next; /* �������ݲ���Ҫ���ҵ�������ͬ��
                                                    ��һֱ����ȥֱ�����������ĩβ*/
    return p;   // ֱ�ӷ���ָ��p���ɣ�û�ҵ�p����NULL��
}

/**
    ����İ�λ�ò���,��1��ʼ
*/
Node* getElemByIndex(LinkList L, int index)
{
    int len = getListLen(L);

    if (index > len || index < 1) return NULL;

    Node *p = L->next;
    int i = 1;

    while (i < index) { /* ���ﲻ��Ҫ�ж�p�Ƿ�Ϊ��*/
        p = p->next;
        i++;
    }

    return p;
}

/**
    ɾ�����,ɾ���ڼ������
*/
int deleteElem(LinkList L, int index)
{

    Node *pre = L;
    Node *p = L->next;
    int i = 1;

    while (p != NULL && i != index) { /* ʹ��˫ָ�������*/
        pre = p;
        p = p->next;
        i++;
    }

    if (p) {    /* �ж��Ƿ��ҵ���*/
        pre->next = p->next;
        delete p;

        return 1;
    }

    return 0;
}

/**
    �޸Ľ�㣨ֵ��ͬ�ģ�
    ��λ�õĿ��Բο�������
*/
int alterNode(LinkList L, ElementTpye x, ElementTpye newData)
{
    Node *p = L->next;
    if (p == NULL) return -1;

    p = locateElem(L, x);

    if (p) { /* �ж��Ƿ��ҵ�������x�Ľ��*/
        p->data = newData;

        return 1;
    }

    return 0;
}
/**
    ��ӡ���
*/
void printList(LinkList L)
{
    Node *p = L->next;
    while (p) {
        cout << p->data;
        p = p->next;
    }
}

int main()
{
    LinkList L = createList();
    //addByHead(L, 1);
    //addByHead(L, 2);
    //addByHead(L, 3);
    //addByHead(L, 4);

    addByTail(L, 1);
    addByTail(L, 2);
    addByTail(L, 3);
    addByTail(L, 4);

    printList(L);
    cout <<'\n'<<getElem(L,4)<<'\n';

    deleteElem(L, 4);
    printList(L);
    cout << '\n';

    alterNode(L, 4, 6);
    printList(L);


    return 0;
}
