#include<stdio.h>
typedef int ElementType;
typedef struct node
{
    ElementType data;
    struct node* next;
}Node;

Node* initList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
    return head;
}

Node* gettail(Node* L){
    Node* p = L;
    while (p->next != NULL)
    {
        p =  p->next;
    }
    return p;
}

Node* inserttail(Node* L,ElementType e){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    L->next = p;
    return p;
}

void listnode(Node* L){
    Node* p = L->next;
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    
}
//找到链表环的入口
Node* findBegain(Node* L){
    Node* fast = L;
    Node* slow = L;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            Node* p = fast;
            int count = 1;
            while (p->next != slow)
            {
                count++;
                p = p->next;
            }
            fast = L;
            slow = L;
            for(int i = 0;i<count;i++){
                fast = fast->next;
            }
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(){
    Node* list = initList();
    Node* tail = gettail(list);
    tail = inserttail(tail,1);
    tail = inserttail(tail,2);
    tail = inserttail(tail,3);
    Node* three = tail;
    tail = inserttail(tail,4);
    tail = inserttail(tail,5);
    tail = inserttail(tail,6);
    tail = inserttail(tail,7);
    tail = inserttail(tail,8);
    tail->next = three;
    Node* p = findBegain(list);
    printf("%d\n",p->data);
    return 0;
   
}