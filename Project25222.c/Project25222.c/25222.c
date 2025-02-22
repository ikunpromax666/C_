#include<stdio.h>
//尝试实现qsort函数
int cmp_arr(const void* e1, const void* e2) {
    return(*(int*)e1 - *(int*)e2);
}
void bubble_sort(void* base, int size, int width, int(*cmp)(const void* e1, const void* e2)) {//这里的void是因为无法确定传入数组的类型
    int i = 0;
    for (i = 0; i < size - 1; i++) {
        //一趟冒泡排序的过程
        int j = 0;
        int flag = 1;//假设数组是排好序
        for (j = 0; j < size - 1 - i; j++) {
            if (cmp((char*)base + width * j, (char*)base + width * (j + 1))) {//强制类型转换为char*最精确
                Swap((char*)base + width * j, (char*)base + width * (j + 1), width);//交换
                flag = 0;
            }
        }
        if (flag == 1) {
            break;
        }
    }
}
void Swap(char* buf1, char* buf2, int width) {
    int  i = 0;
    for (i = 0; i < width; i++) {
        //依次交换每个字符
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}
int main() {

    int i = 0;
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    //qsort(arr,sz,sizeof(arr[0]),cmp_arr);
    bubble_sort(arr, sz, sizeof(arr[0]), cmp_arr);
    for (i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}