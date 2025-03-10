#include<stdio.h>
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

//删除绝对值相同的节点
void removeNode(Node* L,int n){
    Node* p = L;
    int index;
    int *q = (int*)(malloc(sizeof(int)*(n+1)));

    //遍历数组，初始化值为0
    for(int i = 0;i < n+1 ;i++){
        *(q+i) = 0;
    }
    while (p->next != NULL){
        //绝对值获取
        index = abs(p->next->data);
        if(*(q + index) == 0){
            *(q + index) = 1;
            p = p->next;
        }
        else{
            Node* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        free(q);
    }

    
    return 0;
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
    Node* list = initList();
    Node* tail = getTail(list);
    tail = insertTail(tail,21);
    tail = insertTail(tail,-15);
    tail = insertTail(tail,-15);
    tail = insertTail(tail,7);
    tail = insertTail(tail,15);
    listNode(list);
    removeNode(list,21);
    listNode(list);
    return 0;
}