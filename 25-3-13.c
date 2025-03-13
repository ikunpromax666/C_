#include<stdio.h>
typedef int ElementTpye;
typedef struct node
{
    ElementTpye data;
    struct node* next;
}Node;
//目标是将链表分成前半部分和后半部分，反转后半部分，然后合并两个链表。例如，原链表1→2→3→4→5→6应该变成1→6→2→5→3→4。
Node* initList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->data =  0;
    return head;
}

Node* gettail(Node* L){
    Node* p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node* insertail(ElementTpye e,Node* L){
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->data = e;
    L->next = p;
    return p;

}

void listNode(Node* L){
    Node* p = L->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void reOrderList(Node* head){
    //找到中间位置
    Node* fast = head->next;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    //倒序后半部分
    Node* first = NULL;
    Node* second = slow->next;
    slow->next = NULL;
    Node* third = NULL;
    while(second != NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    //见缝插针
    Node* p1 = head->next;
    Node* q1 = first;
    Node* p2,*q2;
    while (p1 != NULL && q1 != NULL)
    {
        p2 = p1->next;
        q2 = q1->next;
        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
    

}
int main(){
    Node* list = initList();
    Node* tail = gettail(list);
    tail = insertail(1,tail);
    tail = insertail(2,tail);
    tail = insertail(3,tail);
    tail = insertail(4,tail);
    tail = insertail(5,tail);
    tail = insertail(6,tail);
    
    listNode(list);
    reOrderList(list);
    listNode(list);
    return 0;
}