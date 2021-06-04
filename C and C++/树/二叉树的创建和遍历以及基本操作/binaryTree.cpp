#include <iostream>

using namespace std;

typedef char ElementType;

/**
    二叉树的存储结构
*/
typedef struct BitNode
{
    ElementType data;   // 保存数据
    struct BitNode *lChild; // 左孩子
    struct BitNode *rChild; // 右孩子
}BitNode, *BinTree;

/**
    先序遍历创建二叉树
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
    中序遍历创建二叉树
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
    后序遍历创建二叉树
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
    先序遍历二叉树
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
    中序遍历二叉树
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
    后序遍历二叉树
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
    复制二叉树
*/
void copyTree(BinTree T, BinTree *newT)
{
    if (T == NULL) {
        (*newT) = NULL;
        return;
    }
    else {
        (*newT) = new BitNode;   /* 从这里可以看到，其实二叉树的复制和创建差不多*/
        (*newT)->data = T->data;
        copyTree(T->lChild, &((*newT)->lChild));
        copyTree(T->rChild, &((*newT)->rChild));
    }
}

/**
    计算二叉树的深度
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
    统计二叉树中结点的个数
*/
int nodeCount(BinTree T)
{
    if (T == NULL) return 0;
    else return nodeCount(T->lChild) + nodeCount(T->rChild) + 1;
}

/**
    统计叶子节点的个数
*/
int leadCount(BinTree T)
{
    if (T == NULL) return 0;
    if (T->lChild == NULL && T->rChild == NULL) return 1;
    else return leadCount(T->lChild) + leadCount(T->rChild) + 0;
}

/**
    测试数据:a#b#cdef#####
*/
int main()
{
    BinTree T; /* 创建二叉树*/
    createTree1(&T);
    preorderTraverse(T);
    cout << '\n';
    inorderTraverse(T);
    cout << '\n';
    postorderTraverse(T);
    cout << '\n';

    BinTree T2; /* 测试复制二叉树*/
    copyTree(T, &T2);
    inorderTraverse(T2); /* 中序遍历*/
    cout<< "T树的高度为:" << depth(T)<<'\n';
    cout<< "T树的结点个数为:" << nodeCount(T)<<'\n';
    cout<< "T树的叶子结点个数为:" << leadCount(T)<<'\n';

    return 0;
}
