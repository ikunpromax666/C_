#include<stdio.h>
int fibonacci(int n){
    int last1 = 1;
    int last2 = 1;
    int result =  0;
    for(int i = 3; i<= n;i++){
        result = last1 + last2;
        last2 = last1;
        last1 = result;
    }
    return result;
}

int fibonacci2(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fibonacci2(n-1) + fibonacci2(n-2);
    }
}
int main(){
    int n = 0;
    scanf("%d",&n);
    int sum1 = fibonacci(n);
    int sum2 = fibonacci2(n);
    printf("%d\n",sum1);
    printf("%d\n",sum2);
    return 0;
}