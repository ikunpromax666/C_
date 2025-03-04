#include<stdio.h>
//使用双指针找到倒数第k个节点
typedef int ElementType;
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

//使用双指针找到第k个节点zz
int findNodeFS(Node* L,int k){
    Node* Fast = L->next;
    Node* Slow = L->next;
    int x = ListLength(L);
    for(int i = 0 ;i < k ;i++){
        Fast = Fast->next;
    }
    while(Fast != NULL){
        Fast = Fast->next;
        Slow = Slow->next;
    }
    printf("倒数第%d个节点值为:%d",k,Slow->data);
}

 //尾插
Node* insertTail(Node* L,ElementType e){
    Node* p = (Node*)(malloc(sizeof(Node)));
    p->data = e;
    L->next = p;
    p->next = NULL; 
    return p;

} 

//遍历列表
void listNode(Node* L){
    Node* p = L->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    Node* List = initList();
    Node* Tail = getTail(List);
    Tail = insertTail(Tail,10);
    Tail = insertTail(Tail,20);
    Tail = insertTail(Tail,30);
    Tail = insertTail(Tail,40);
    Tail = insertTail(Tail,50);
    Tail = insertTail(Tail,60);
    Tail = insertTail(Tail,70);
    Tail = insertTail(Tail,80);
    listNode(List);
    findNodeFS(List,3);
    return 0;
}