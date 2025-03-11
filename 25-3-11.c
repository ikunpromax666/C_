#include<stdio.h>
typedef int  ElementType;
typedef  struct node{
    struct node* next;
    ElementType data;
}Node;

//创造头节点
Node* get_list(){
    Node* head = (Node*)(malloc(sizeof(Node)));
    head->next = NULL;
    head->data = 0;
    return head;
}
//获取尾部节点
Node* get_tail(Node* L){
    Node* p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}
//尾插
Node* inserttail(Node* L,ElementType e){
    Node* p = (Node*)malloc(sizeof(L));
    p->next = NULL;
    p->data = e;
    L->next = p;
    return p;
}
//遍历链表
void listNode(Node* L){
    Node* p = L->next;
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//反转链表
Node* reverselist(Node* head){
    Node* first = NULL;
    Node* second = head->next;
    Node* third;
    while(second != NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node* head1 = get_list();
    head1->next = first;
    return head1;
}
//利用快慢指针删除中间的链表
void delMiddleList(Node* L){
    
    Node* fast = L->next;
    Node* slow = L;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* q = slow->next;
    slow->next = q->next;
    free(q);

}
int main(){
    Node* list = get_list();
    Node* tail = get_tail(list);
    tail = inserttail(tail,1);
    tail = inserttail(tail,2);
    tail = inserttail(tail,3);
    tail = inserttail(tail,4);
    tail = inserttail(tail,5);
    tail = inserttail(tail,6);
    tail = inserttail(tail,7);
    listNode(list);
   //Node* head1 = reverselist(list);
    //listNode(head1);
    delMiddleList(list);
    listNode(list);
    return 0;
}