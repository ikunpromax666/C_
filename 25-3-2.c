#include<stdio.h>
typedef int ElementType;
typedef struct node{
    ElementType data;
    struct node* next;
}Node;

//初始化链表
Node* initList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
int insertHead(Node* L,ElementType e){
    Node* p = (Node*)(malloc(sizeof(Node)));
    p->next = L->next;
    p->data = e;
    L->next = p;
    return 1;
}

//遍历

void listNode(Node* L){
    Node* p = L->next; //跳过头节点
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//获取尾部节点

Node* get_tail(Node* L){
    Node* p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}

//尾插法
Node* insertTail(Node*Tail,ElementType e){
    Node* p = (Node*)(malloc(sizeof(Node)));
    p->data = e;
    Tail->next = p;
    p->next = NULL;
    return p;
}

//指定位置插入
int insertNode(Node* L,int pos,ElementType e){
    //
    Node* p = L;
    for(int i = 0;i < pos;i++){
        p=p->next;
        if(p == NULL ){
            return 0;
        }
    }
    //要插入的新节点
 Node* q = (Node*)(malloc(sizeof(Node)));
    q->data = e;
    q->next  = p->next;
    p->next = q;
    return 1; 
}

//删除节点
int deleteNode(Node* L,int pos){
    Node* p = L;
    int i = 0;
    while(i < pos){
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }
    if(p->next == NULL){
        printf("要删除的位置错误\n");
    }
    //q指向要删除的节点
    Node* q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

//释放链表
void freeList(Node* L){
    Node* p = L->next;
    Node* q;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

//获取链表长度
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
int main(){
    Node* list = initList();
    Node* tail = get_tail(list);
    tail = insertTail(tail,10);
    tail = insertTail(tail,20);
    tail = insertTail(tail,30);
    listNode(list);
    insertNode(list,2,15);
    listNode(list);
    deleteNode(list,2);
    listNode(list);
    printf("%d\n",ListLength(list));
    return 0;
}