#include<stdio.h>
#define MAXSIZE  100
typedef int ElementType;

typedef struct 
{
    ElementType data[MAXSIZE];
    int top;
}Stack;

initstack(Stack* s){
    s->top = -1;
}

int push(Stack* s,ElementType e){
    if(s->top >= MAXSIZE - 1){
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

ElementType pop(Stack* s,ElementType* e){
    if(s->top >= MAXSIZE - 1){
        printf("满了\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}
int getTop(Stack* s,ElementType*e){
    if(s->top == -1){
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
        return 1;
}
int main(){
    Stack s;
    initstack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    ElementType e;
    pop(&s,&e);
    printf("%d\n",e);
    getTop(&s,&e);
    printf("%d\n",e);
    return 0;
}