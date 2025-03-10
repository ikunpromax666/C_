#include<stdio.h>

typedef char ElementType;
typedef struct node{
    ElementType data;
    struct node* next;
}Node;

//初始化链表
Node* initList(){
    Node* head = (Node*)(malloc(sizeof(Node)));
    head->next = NULL;
    head->data = 0;
    return head;
}
//初始化一个节点
Node* initListWithElem(ElementType e){
    Node* head = (Node*)(malloc(sizeof(Node)));
    head->next = NULL;
    head->data = e;
    return head;
}
// 计算节点长度
int ListLength(Node* L){
    Node* p = L->next;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//获取尾部节点
Node* getTail(Node* L){
    Node* p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return  p;
}


 //尾插
Node* insertTail(Node* L,ElementType e){
    Node* p = (Node*)(malloc(sizeof(Node)));
    p->data = e;
    L->next = p;
    p->next = NULL; 
    return p;

} 
//尾插(节点)
Node* insertTailWithNode(Node* L,Node*M){
    L->next = M;
    M->next = NULL;
    return M;
}
//遍历列表
void listNode(Node* L){
    Node* p = L->next;
    while(p != NULL){
        printf("%c",p->data);
        p = p->next;
    }
    printf("\n");
}
//查找两个节点共同后缀的起始位置
Node* findIntersectionNode(Node* headA,Node* headB){
    if(headA == NULL || headB == NULL){
        return 0;
    }
    Node* p = headA;
    int lenA = 0;
    int lenB = 0;
    //遍历链表A，获取链表A的长度；
    while(p != NULL){
        p = p->next;
        lenA++;
    }
    p = headB;
    //遍历链表B，获取链表B的长度；
    while(p != NULL){
        p = p->next;
        lenB++;
    }
    Node* fast;//快指针
    Node* slow;//慢指针
    int step;//两个单词间的差值，可以用于快指针先走的步数
    if(lenA > lenB){
        step = lenA - lenB;
        fast = headA;
        slow = headB;
    }
    else{
        step = lenB -lenA;
        fast = headB;
        slow = headA;
    }
    //让快指针先走step步
    for(int i = 0;i < step; i++){
        fast = fast->next;
    }
    //快慢指针同时走，直到指向同一个节点退出循环
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
int main(){

    Node* listA = initList();
    Node* listB = initList();
    Node* TailA = getTail(listA);
    Node* TailB = getTail(listB);
    TailA = insertTail(TailA,'l');
    TailA = insertTail(TailA,'o');
    TailA = insertTail(TailA,'a');
    TailA = insertTail(TailA,'d');
    TailB = insertTail(TailB,'b');
    TailB = insertTail(TailB,'e');
    listNode(listA);
    listNode(listB);
    Node* I = initListWithElem('i');
    TailA = insertTailWithNode(TailA,I);
    TailB = insertTailWithNode(TailB,I);
    Node* N = initListWithElem('n');
    TailA = insertTailWithNode(TailA,N);
    TailB = insertTailWithNode(TailB,N);
    Node* G = initListWithElem('g');
    TailA = insertTailWithNode(TailA,G);
    TailB = insertTailWithNode(TailB,G);
    listNode(listA);
    listNode(listB);
    printf("%c\n",findIntersectionNode(listA,listB)->data);
    return 0;
   
}