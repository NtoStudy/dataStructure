#include <cstdlib>
#include <stdio.h>

//定义一个单链表节点结构
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 带头节点的单链表初始化
bool InitList(LinkList &L) {
    // 先动态分配一个头结点的地址
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}

// 带头指针的插入一个元素  将e插入到第i个位置处
bool insertNode(LinkList &L, int i ,int e) {
    // 首先要判断这个i合不合理
    LNode *p = L;
    int j = 0; // 记录当前节点的位置 头结点默认为0
    while(p!=NULL && j<i-1) {
        p = p->next;
        j++;
    }
    if(p==NULL)return false;
    // 给插入的新开辟一个地址
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 在p节点后插入一个e
bool insertAfterNode(LNode *p,int e) {
    if(p == NULL) return false;
    // 动态分配一个地址
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool insertBeforeNode(LNode *p,int e) {
    if(p==NULL)return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)return false;
    s->next = p->next;
    s->data = p->data;
    p->data=e;
    p->next = s;
    return true;
}

// 删除第i个位置的元素
bool deletePositionNode(LinkList &L,int i,int &e) {
    LNode *p = L;
    int j = 0;
    while(p!=NULL && j<i-1) {
        p=p->next;
        j++;
    }
    if(p==NULL)return false;
    if(p->next==NULL)return false;

    LNode *q = p->next;
    e = q->data;
    p->next=q->next;
    free(q);
    return true;
}

// 删除p节点
bool deleteNode(LNode *p) {
    if(p ==NULL)return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}