#include<stdio.h>
//栈的链式结构实现
typedef int ElementType;
typedef struct stack{
    ElementType data;
    struct stack* next;

}Stack;

Stack* initStack(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

int isempty(Stack* s){
    if(s->next == NULL){
        printf("空的\n");
        return 1;
    }
    else{
        return 0;
    }
}

int push(Stack* s,ElementType e){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

int  pop(Stack* s,ElementType* e){
    if(s->next == NULL){
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    Stack* q = s->next;
    s->next = q->next;
    free(q);
    return 1;
}

int gettop(Stack* s,ElementType* e){
    if(s->next == NULL){
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}
int main(){
    Stack *s = initStack();
    push(s,10);
    push(s,20);
    push(s,30);
    ElementType e;
    pop(s,&e);
    printf("%d\n",e);
   
    gettop(s,&e);
    printf("%d\n",e);
    return 0;
}