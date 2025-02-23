#include<stdio.h>
#include<string.h>
//尝试实现qsort函数
int cmp_arr( const void*  e1,const void* e2 ){
     return( *(int*)e1 - *(int*)e2);
}
void bubble_sort(void* base,int size ,int width,int(*cmp)(const void* e1,const void* e2)){//这里的void是因为无法确定传入数组的类型
        int i = 0;
        for(i = 0;i < size - 1;i++){
            //一趟冒泡排序的过程
            int j = 0;
            int flag = 1;//假设数组是排好序
            for(j = 0 ;j < size -1 -i;j++){
                if(cmp((char*)base + width * j,(char*)base + width * (j + 1))){//强制类型转换为char*最精确
                    Swap((char*)base + width * j,(char*)base + width * (j + 1),width);//交换
                    flag = 0;
                }
            }
            if(flag == 1){
                break;
            }
        }
    }
void Swap(char* buf1,char* buf2,int width){
    int  i = 0;
    for(i = 0;i<width;i++){
        //依次交换每个字符
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}
struct Stu
{
    char name[20];
    int  age;
};
int cmp_stu_by_name(const void* e1,const void* e2 ){
    returnstrcmp(((struct Stu*)e1)->name,(((struct Stu*)e2)->name));
}
void test(){
    struct Stu s[] = {{"zhangsan",20},{"lisi",30},{"wangwu",25}};
    int sz = sizeof(s) / sizeof(s[0]);
    bubble_sort(s,sz,sizeof(s[0]),cmp_stu_by_name);
}
int main(){
    int i = 0;
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    //qsort(arr,sz,sizeof(arr[0]),cmp_arr);
    bubble_sort(arr,sz,sizeof(arr[0]),cmp_arr);
    for(i = 0;i < sz;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
/*
指针的相关知识：
内存---->内存的单元(1byte)---->编号---->地址--->指针
所以指针就是一个地址
口头语所说的指针一般是：指针变量
指针变量就是一个变量，就是一块内存空间，指针变量用来存放地址
指针的运算:
1.+1,-1的操作，跳过几个字节(步长)
2.解引用操作时的权限
3.+-整数
4.指针-指针
5.指针的运算关系
指针数组： 本质就是数组，数组中存放的是指针(地址)
int* pa;
int* pb;
int* pc;
int* arr[3] = {pa,pb,pc};
数组名：
数组名在大部分情况下表示：数组首元素的地址但是有两个情况例外，下面两个数组名表示整个数组
1.sizeof(数组名)
2。&数组名
&数组名 取出的是数组地址
int arr[10] = {1,2,3};
parr = &arr;

数组指针          int (*parr)[10] = &arr;
int a = 0;
pa 是整型指针
int* pa = &a;
char ch = 'w';
pc 是字符指针
char* pc = &ch;

int add(int x,int y){
    return x + y;
}
int main(){
int (*pf)(int,int) = add;
//函数的地址存放到函数指针变量中

//int sum =  (*pf)(2,3);
int sum = pf(2,3);
int sum =add(2,3);

return 0;
}

函数指针                 存放函数指针的数组
函数也是有地址的         int(*pfarr[4])(int ,int)
                       pfarr数组的每个元素的类型是:
int(*pf)(int,int);      int (*)(int,int);








*/