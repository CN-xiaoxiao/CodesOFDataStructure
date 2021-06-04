#include <iostream>

using namespace std;

typedef char ElementType;

/**
    �������Ĵ洢�ṹ
*/
typedef struct BitNode
{
    ElementType data;   // ��������
    struct BitNode *lChild; // ����
    struct BitNode *rChild; // �Һ���
}BitNode, *BinTree;

/**
    �����������������
*/
void createTree1(BinTree *T)
{
    ElementType ch;
    cin>>ch;

    if (ch == '#') (*T) = NULL;
    else {
        (*T) = new BitNode;
        (*T)->data = ch;

        createTree1(&((*T)->lChild));
        createTree1(&((*T)->rChild));
    }

}

/**
    �����������������
*/
void createTree2(BinTree *T)
{
    ElementType ch;
    cin>>ch;

    if (ch == '#') (*T) = NULL;
    else {
        (*T) = new BitNode;

        createTree2(&((*T)->lChild));
        (*T)->data = ch;
        createTree2(&((*T)->rChild));
    }

}

/**
    �����������������
*/
void createTree3(BinTree *T)
{
    ElementType ch;
    cin>>ch;

    if (ch == '#') (*T) = NULL;
    else {
        (*T) = new BitNode;

        createTree3(&((*T)->lChild));
        createTree3(&((*T)->rChild));
        (*T)->data = ch;
    }

}

/**
    �������������
*/
void preorderTraverse(BinTree T)
{
    if (T == NULL) return;
    else {
        cout << T->data;
        preorderTraverse(T->lChild);
        preorderTraverse(T->rChild);
    }

}

/**
    �������������
*/
void inorderTraverse(BinTree T)
{
    if (T == NULL) return;
    else {
        inorderTraverse(T->lChild);
        cout << T->data;
        inorderTraverse(T->rChild);
    }

}

/**
    �������������
*/
void postorderTraverse(BinTree T)
{
    if (T == NULL) return;
    else {
        postorderTraverse(T->lChild);
        postorderTraverse(T->rChild);
        cout << T->data;
    }

}

/**
    ���ƶ�����
*/
void copyTree(BinTree T, BinTree *newT)
{
    if (T == NULL) {
        (*newT) = NULL;
        return;
    }
    else {
        (*newT) = new BitNode;   /* ��������Կ�������ʵ�������ĸ��ƺʹ������*/
        (*newT)->data = T->data;
        copyTree(T->lChild, &((*newT)->lChild));
        copyTree(T->rChild, &((*newT)->rChild));
    }
}

/**
    ��������������
*/
int depth(BinTree T)
{
    if (T == NULL) return 0;
    else {
        int m = depth(T->lChild);
        int n = depth(T->rChild);

        if (m > n) return (m+1);
        else return (n+1);
    }
}

/**
    ͳ�ƶ������н��ĸ���
*/
int nodeCount(BinTree T)
{
    if (T == NULL) return 0;
    else return nodeCount(T->lChild) + nodeCount(T->rChild) + 1;
}

/**
    ͳ��Ҷ�ӽڵ�ĸ���
*/
int leadCount(BinTree T)
{
    if (T == NULL) return 0;
    if (T->lChild == NULL && T->rChild == NULL) return 1;
    else return leadCount(T->lChild) + leadCount(T->rChild) + 0;
}

/**
    ��������:a#b#cdef#####
*/
int main()
{
    BinTree T; /* ����������*/
    createTree1(&T);
    preorderTraverse(T);
    cout << '\n';
    inorderTraverse(T);
    cout << '\n';
    postorderTraverse(T);
    cout << '\n';

    BinTree T2; /* ���Ը��ƶ�����*/
    copyTree(T, &T2);
    inorderTraverse(T2); /* �������*/
    cout<< "T���ĸ߶�Ϊ:" << depth(T)<<'\n';
    cout<< "T���Ľ�����Ϊ:" << nodeCount(T)<<'\n';
    cout<< "T����Ҷ�ӽ�����Ϊ:" << leadCount(T)<<'\n';

    return 0;
}
