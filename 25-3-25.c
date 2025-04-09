#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct 
{
    ElemType *data;
    int front;
    int rear;
}Queue;
//队列的顺序结构，循环队列
Queue*  initqueuqe(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

int queue(Queue* Q,ElemType e){
    if((Q->rear+1)%MAXSIZE == Q->front ){
        printf("满了\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = ((Q->rear + 1) % MAXSIZE);
    return 1;

}


int dequeue(Queue* Q,ElemType * e){
    if(Q->front == Q->rear){
        printf("空的\n");
        return 0;
    }
    *e =  Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;

}
int main(){
    return 0;
}