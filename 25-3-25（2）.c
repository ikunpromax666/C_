#include<stdio.h>
typedef int ElemType;
typedef struct QueueNode
{
    ElemType  data;
    struct QueueNode* next;
}QueueNode;

typedef struct 
{
    QueueNode* front;
    QueueNode* rear;
}Queue;
//队列的链式结构-初始化
Queue* initqueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next  = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

int isEmpty(Queue* q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}
//入队
void equeue(Queue*q,ElemType e){
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

//出队
int dequeue(Queue* q,ElemType* e){
    QueueNode* node = q->front->next;
    *e = node->data;
    q->front->next =node->next;
    if(q->rear == q->front){
        q->rear = q->front;
    }
    free(node);
    return 1;
}

//获取队头元素
ElemType getFront(Queue* q){
    if(isEmpty(q)){
        printf("空的\n");
        return 0;
    }
    return q->front->next->data;
}


int main(){
    Queue* q = initqueue();
    equeue(q,10);
    equeue(q,20);
    equeue(q,30);
    equeue(q,40);
    equeue(q,50);
    ElemType e;
    dequeue(q,&e);
    printf("出队%d\n",e);
    dequeue(q,&e);
    printf("出队%d\n",e);
    printf("%d\n",getFront(q));
    return 0;
}